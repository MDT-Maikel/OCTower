/**
	Room Control
	This object's script contains the properties and the functions of the room.

	@author See contents of GetRoomAuthor().
*/

#include RoomBase


/*-- Room Properties --*/
// Overload these properties if needed.

// The name of the room, appears in menus and the room start.
// Add both an English and German version.
public func GetRoomName() { return "$RoomName$"; }

// The description of the room, appears in menus and the room start.
// Add both an English and German version.
public func GetRoomDescription() { return "$RoomDescription$"; }

// The name of the author of the room, separate multiple authors with comma's or & (like "John, Jane & Wipf").
// Names may not contain comma's or &.
public func GetRoomAuthor() { return "Clonkonaut"; }

// The map section that needs to be loaded for this room, usually equal to the name of the room.
public func GetRoomSection() { return "WheelOfFortune"; }

// A unique ID for the room which is used for saving player progress. It must be two characters
// long which can be chosen from the set [A-Za-z].
public func GetRoomID() { return "WF"; }

// The difficulty of this room, ranges from 0 to 999.
public func GetRoomDifficulty() { return 333; }

// Whether or not the room has an ancient tablet which can be found.
public func HasTablet() { return true; }

// Whether or not the room has a joker which can be found.
public func HasJoker() { return false; }

// Hints and tricks shown in the help menu when currently playing this room.
// Pass a list of strings which represent the hints, each is shown separately.
public func GetRoomHints() { return nil; }


/*-- Room Scripts --*/

static g_brick;

// Called when the room is initialized.
// Here you can create effects and extra objects that are needed for the room.
public func OnRoomInit()
{
	g_brick = CreateObject(MovingBrick, 65, 446);
	var RoomEntrance001 = CreateObjectAbove(RoomEntrance, 56, 440);
	RoomEntrance001->SetColor(0xff32c832);
	
	var contest_reward = CreateObjectAbove(RoomSign, 72, 432);
	contest_reward->SetInscription("$MsgContestReward$");
	contest_reward->SetReward("Bronze");
	contest_reward->SetPosition(g_brick->GetX() - 4, g_brick->GetY() - 12);
	contest_reward->CreateEffect(FxMoveContestReward, 1, 1);

	ItemSpawn->Create(Club, 122, 252);
	ItemSpawn->Create(Shield, 65, 282);
	
	Scenario->CreateEffect(FxBossController, 1, 5, 200, 9);
	Scenario->CreateEffect(FxBatController, 1, 0);
	return;
}

// Called when the player starts its room attempt.
// Here you can create effects and extra objects that are needed for the player and its crew.
public func OnPlayerInit(int plr)
{
	Scenario->CreateEffect(FxStartupDelay, 1, 70);
	var clnk = GetCrew(plr);
	clnk->CreateEffect(FxFightController, 1, 5);
	clnk.MaxEnergy = 100000;
	clnk->DoEnergy(1000);
	return;
}

local FxStartupDelay = new Effect
{
	Timer = func()
	{
		g_brick->MoveVertical(260, 300, 9);
		return FX_Execute_Kill;
	}
};

local FxMoveContestReward =  new Effect
{
	Timer = func()
	{
		if (!g_brick)
		{
			Target->RemoveObject();
			return FX_Execute_Kill;
		}
		Target->SetPosition(g_brick->GetX() + 12, g_brick->GetY() - 18);
		return FX_OK;
	}
};

local FxFightController = new Effect
{
	Timer = func()
	{
		if (!this.Target->FindContents(Club))
			return FX_OK;

		FindObject(Find_ID(ItemSpawn))->RemoveObject();
		FindObject(Find_ID(ItemSpawn))->RemoveObject();
		GetEffect("FxBossController", Scenario)->StartMovement();
		g_brick->MoveVertical(480, 520, 15);
		Sound("BossFight", true);
		return FX_Execute_Kill;
	}
};

local FxBossController = new Effect
{
	Construction = func(int at_radius, int brick_count)
	{
		this.bricks = CreateArray();
		this.prec = 1000;
		this.angle = 180 * this.prec;
		this.color = 0;
		this.radius = at_radius;
		this.moving = false;
		this.ended = false;

		var angle_part = 360 * this.prec / brick_count;
		var current_angle = this.angle;
		for (var i = 0; i < brick_count; i++)
		{
			var x = Sin(current_angle, this.radius, this.prec);
			var y = -Cos(current_angle, this.radius, this.prec);
			var brick = CreateObject(MovingBrick, LandscapeWidth() / 2 + x, LandscapeHeight() / 2 + y, NO_OWNER);
			brick->MakeInvincible();
			brick->SetClrModulation(HSL(current_angle % 255, 220, 150));
			PushBack(this.bricks, brick);
			current_angle += angle_part;
		}

		this.particles =
		{
			Prototype = Particles_Air(),
			Size = PV_Linear(2, 0),
			R = PV_Random(20, 200),
			G = PV_Random(20, 200),
			B = PV_Random(20, 200),
			BlitMode = GFX_BLIT_Additive
		};
	},
	StartMovement = func()
	{
		this.moving = true;
		this.spawning_time = 0;

		this.enemies = CreateArray();
		SetSkyParallax(0, 10,10, 0, 2);
		this.spawned = 0;
		this.spawned_brick = 7;
	},
	Timer = func()
	{
		if (!this.moving)
			return FX_OK;

		if (this.spawned < GetLength(this.bricks) - 1)
			this.spawning_time += 5;
		if (this.spawning_time >= 200)
			this->SpawnEnemy();

		this.angle += 2 * this.prec;
		var angle_part = 360 * this.prec / GetLength(this.bricks);
		var current_angle = this.angle;
		for (var i = 0; i < GetLength(this.bricks); i++)
		{
			var x = Sin(current_angle, this.radius, this.prec);
			var y = -Cos(current_angle, this.radius, this.prec);
			var brick_x = this.bricks[i]->GetX();
			var brick_y = this.bricks[i]->GetY();
			var target_angle = Angle(brick_x, brick_y, LandscapeWidth() / 2 + x, LandscapeHeight() / 2 + y);
			var speed_x =  Sin(target_angle, 1 * this.prec);
			var speed_y = -Cos(target_angle, 1 * this.prec);
			this.bricks[i]->SetXDir(speed_x, this.prec);
			this.bricks[i]->SetYDir(speed_y, this.prec);
			current_angle += angle_part;
		}

		if (!this.ended)
		{
			this.color++;
			if (this.color > 255)
				this.color = 1;
			SetSkyAdjust(HSL(this.color, 150, 128));
			if (!Random(20))
				this->SpawnTree();
			if (!Random(20))
				this->SpawnObject();
		}

		if (this.spawned >= GetLength(this.bricks) - 1 && !this.ended)
		{
			RemoveHoles(this.enemies);
			if (!GetLength(this.enemies))
			{
				// Hooray!
				var x = this.bricks[2]->GetX();
				var y = this.bricks[2]->GetY() - 16;
				CreateObject(RoomExit, x, y);
				SpawnEffect(x, y);
				var x = this.bricks[7]->GetX();
				var y = this.bricks[7]->GetY() - 8;
				GetEffect("FxBatController", Scenario)->SpawnBat();
				SpawnEffect(x, y);
				SetSkyParallax(0, 0, 0, 0, 0);
				SetSkyAdjust(HSL(0, 0, 220));
				this.ended = true;
			}
		}
		return FX_OK;
	},
	SpawnEnemy = func()
	{
		var x = this.bricks[this.spawned_brick]->GetX();
		var y = this.bricks[this.spawned_brick]->GetY() - 14;

		var clnk = CreateObject(Clonk, x, y);
		clnk->SetSkin(Random(4));
		clnk->CreateContents(Bow)->CreateContents(Arrow)->SetInfiniteStackCount();
		clnk->CreateContents(Helmet)->ControlUse(clnk);
		clnk->SetColor(0x111);
		AI->AddAI(clnk);
		AI->SetGuardRange(clnk, 0, 0, LandscapeWidth(), LandscapeHeight());

		PushBack(this.enemies, clnk);

		this->SpawnEffect(x, y);

		this.spawned++;
		this.spawning_time = 0;
		this.spawned_brick++;

		if (this.spawned_brick >= GetLength(this.bricks))
			this.spawned_brick = 0;
		if (this.spawned_brick == 2)
			this.spawned_brick++;
	},
	SpawnEffect = func(int x, int y)
	{
		for (var i = 0; i < 40; i++)
		{
			var r = Random(360);
			var d = Random(100) + 20 + RandomX(-2, 2);
			var xoff = +Sin(r, d);
			var yoff = -Cos(r, d);

			CreateParticle("Air", x + xoff, y + yoff, PV_Random(xoff - 3, xoff + 3), PV_Random(yoff - 3, yoff + 3), PV_Random(5, 10), this.particles, 2);
		}
	},
	SpawnTree = func()
	{
		var tree = CreateObject([Tree_Coniferous, Tree_Coniferous2, Tree_Coniferous3, Tree_Coniferous4, Tree_Deciduous][Random(5)], RandomX(50, LandscapeWidth() - 50), -100);
		tree->SetCategory(tree->GetCategory()&~C4D_StaticBack);
		tree->SetR(Random(360));
		for (var i = 0; i < tree->GetVertexNum(); i++)
			tree->SetVertex(0, VTX_Y, 0, i);
		while (tree->GetVertexNum())
		{
			tree->RemoveVertex(0);
			tree->RemoveVertex(1);
			tree->RemoveVertex(2);
			tree->RemoveVertex(3);
		}
		Schedule(tree, "SetRDir(RandomX(-2,2))", 2);
	},
	SpawnObject = func()
	{
		var obj = CreateObject([Rock, Loam, Firestone, Metal, Wood, Coal][Random(6)], RandomX(50, LandscapeWidth() - 50), -100);
		obj->SetCategory(obj->GetCategory()&~C4D_Object);
		while (obj->GetVertexNum())
		{
			obj->RemoveVertex(0);
			obj->RemoveVertex(1);
		}
	}
};

local FxBatController = new Effect
{
	SpawnBat = func()
	{
		this.bat = CreateObject(Bat, LandscapeWidth() / 2, LandscapeHeight() / 2);
		this.bat->DoEnergy(-19);
		this.tablet = CreateObject(AncientTablet, this.bat->GetX(), this.bat->GetY()+5);
		this.tablet->SetCategory(C4D_StaticBack);
		this.tablet.Collectible = false;
		var color = RGB(255, 128, 0);
		this.particles =
		{
			Prototype = Particles_Trajectory(),
			Size = 4,
			R = (color >> 16) & 0xff,
			G = (color >>  8) & 0xff,
			B = (color >>  0) & 0xff,
			Alpha = (color >> 24) & 0xff
		};

		GetEffect("FxBossController", Scenario)->SpawnEffect(LandscapeWidth() / 2, LandscapeHeight() / 2);

		this.Interval = 1;

		this.killed = false;
	},
	Timer = func(int time)
	{
		var wdt = LandscapeWidth();
		var hgt = LandscapeHeight();
		if (!this.bat || !this.bat->GetAlive())
		{
			if (!this.killed)
			{
				if (this.tablet)
				{
					this.tablet->SetCategory(C4D_Object);
					this.tablet.Collectible = true;
				}
				this.killed = true;
			}
			else
			{
				return FX_Execute_Kill;
			}
		}
		if (!this.tablet) // ???
			return FX_Execute_Kill;

		this.tablet->SetPosition(this.bat->GetX(), this.bat->GetY()+5);
		if (!time % 7)
			this.bat->CreateParticle("Magic", 0, 0, 0, 0, 70, this.particles, 1);
		// Get out of the center
		if (Distance(this.bat->GetX(), this.bat->GetY(), wdt / 2, hgt / 2) < 60)
		{
			var angle = Angle(this.bat->GetX(), this.bat->GetY(), wdt / 2, hgt / 2);
			var x = -Sin(angle, 10);
			var y = +Cos(angle, 10);
			this.bat->ChangeMovementDirection(x, y);
		}
		// Get out of the border
		else if (Distance(this.bat->GetX(), this.bat->GetY(), wdt / 2, hgt / 2) > 170)
		{
			var angle = Angle(this.bat->GetX(), this.bat->GetY(), wdt / 2, hgt / 2);
			var x = +Sin(angle, 10);
			var y = -Cos(angle, 10);
			this.bat->ChangeMovementDirection(x, y);
		}
		else if (!Random(14))
		{
			this.bat->ChangeMovementDirection(RandomX(-2, 2), RandomX(-2, 2));
		}
	}
};