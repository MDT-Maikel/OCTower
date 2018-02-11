/**
	Room Colored Smoke
	Distributes some colored smoke in the room.

	@author Maikel
*/

public func Construction()
{
	SetPosition(0, 0);
	CreateEffect(FxRoomColoredClouds, 100, 90);
	return;
}

local FxRoomColoredClouds = new Effect
{
	Timer = func()
	{
		var border = 40;
		var x = RandomX(border, LandscapeWidth() - border);
		var y = RandomX(border, LandscapeHeight() - border);
		Target->CreateEffect(Target.FxTrailingCloud, 100, 2, x, y);
		return FX_OK;
	}
};

local FxTrailingCloud = new Effect
{
	Construction = func(int x, int y)
	{
		this.particle =
		{
			DampingX = 900,
			DampingY = 900,
			Alpha = PV_KeyFrames(0, 0, 20, 500, 100, 1000, 20),
			R = 100, G = 100, B = 100,
			Size = PV_Linear(PV_Random(36, 48), PV_Random(36, 48)),
			Phase = PV_Random(0, 15)
		};
		this.x = x;
		this.y = y;
		return FX_OK;
	},
	Timer = func(int time)
	{
		if (time >= 250 + Random(250))
			return FX_Execute_Kill;
		// Find a clonk to follow.
		if (!this.clonk)
			this.clonk = FindObject(Find_OCF(OCF_CrewMember), Find_NoContainer(), Find_Not(Find_Property("IsTrailFollowed")), Find_Distance(300, this.x, this.y), Sort_Distance(this.x, this.y));
		if (this.clonk)
			this.clonk.IsTrailFollowed = true;
		
		// Move to clonk, or randomly.
		var angle = Random(360);
		if (this.clonk)
			angle = Angle(this.x, this.y, this.clonk->GetX() + RandomX(-60, 60), this.clonk->GetY() + RandomX(-60, 60));
		this.x += Sin(angle, 8);
		this.y -= Cos(angle, 8);

		// Create particles at new position.
		var color = HSL(time % 255, 180, 100);
		color = SplitRGBaValue(color);
		AddProperties(this.particle, color);
		this.particle.Alpha = PV_KeyFrames(0, 0, 20, 500, 100, 1000, 20);
		if (!Random(4))
			CreateParticle("Smoke", this.x, this.y, 0, 0, 80 + Random(45), this.particle);
		return FX_OK;
	},
	Destruction = func()
	{
		if (this.clonk)
			this.clonk.IsTrailFollowed = false;
		return FX_OK;	
	}
};


/*-- Saving --*/

// Do not save this object as it is recreated on the loading of a new room.
public func SaveScenarioObject() { return false; }


/*-- Properties --*/

local Name = "$Name$";
local Description = "$Description$";