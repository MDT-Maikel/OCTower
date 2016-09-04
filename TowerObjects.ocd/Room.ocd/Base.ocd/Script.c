/**
	Room Base
	Base object for the room which contains the room's settings and scripts.

	@author Anonymous
*/


/*-- Basic Room Properties (Adjustable) --*/

public func GetRoomName() { return nil; }

public func GetRoomDescription() { return nil; }

public func GetRoomAuthor() { return nil; }

public func GetRoomSection() { return nil; }

public func GetRoomDifficulty() { return nil; }

public func HasJoker() { return false; }


/*-- Advanced Room Properties (Adjustable) --*/

public func GetRoomKnowledge() { return nil; }

public func GetRoomPumpSpeed() { return nil; }


/*-- Room Properties (Fixed) --*/

public func IsRoom() { return true; }


/*-- Room Control --*/

public func LoadRoom(bool reload)
{
	var fx = AddEffect("IntScheduleLoadRoom", nil, 1, 1, nil, this);
	fx.reload = reload;
	return;
}

public func FxIntScheduleLoadRoomStop(object target, proplist fx, int reason, bool temp)
{
	if (temp || reason != FX_Call_Normal)
		return FX_OK;
	DoLoadRoom(fx.reload);
	return FX_OK;
}

public func DoLoadRoom(bool reload)
{
	var sect = GetRoomSection();
	if (!sect)
		return;
		
	// Load the room from its scenario section.
	if (reload)
	{
		//Log("[%d]Load section Empty", FrameCounter());
		//LogCallStack();
		LoadScenarioSection("Empty");
	}
	//Log("[%d]Load section %v", FrameCounter(), sect);
	//LogCallStack();
	LoadScenarioSection(sect);
	
	// Create the room control object and init.
	var room_control = CreateObject(this);
	room_control->InitRoom();
	return;
}

public func InitRoom()
{
	// Create basic rules.
	CreateObject(Rule_Restart);	
	// Call to the specific room object to init objects.
	OnRoomInit();
	// Initialize players in this room.
	for (var plr in GetPlayers())
	{
		InitializePlayer(plr);
		for (var plr_start in FindObjects(Find_ID(PlayerStart)))
			plr_start->InitializePlayer(plr);
	}
	return;
}

public func OnRoomInit()
{
	// Implemented in the specific room control object.
	return;
}

public func OnPlayerInit(int plr)
{
	// Implemented in the specific room control object.
	return;
}


/*-- Player Control --*/

public func InitializePlayer(int plr)
{
	// Give player all knowledge or as specified by room.
	var knowledge = GetRoomKnowledge();
	if (knowledge)
	{
		for (var def in knowledge)
			SetPlrKnowledge(plr, def);
	}
	else
	{
		var index = 0, def;
		while (def = GetDefinition(index++))
			SetPlrKnowledge(plr, def);
	}
	
	// Join the player with its crew.
	JoinPlayer(plr);
	// Call to the specific room object to init the players.
	OnPlayerInit(plr);	
	return;
}

public func RelaunchPlayer(int plr)
{
	// Reset the room.
	if (!GetEffect("IntScheduleLoad*"))
		GetID()->LoadRoom(true);
	return;
}

protected func JoinPlayer(int plr)
{
	// Get crew member or create new one.
	var crew = GetCrew(plr);
	if (!crew)
	{
		var crew = CreateObjectAbove(Clonk, 0, 0, plr);
		crew->MakeCrewMember(plr);
		SetCursor(plr, crew);
	}
	
	// Move crew member to room entrance.
	var room_entrance = FindObject(Find_ID(RoomEntrance));
	if (room_entrance)
		crew->SetPosition(room_entrance->GetX(), room_entrance->GetY());
	
	// Give clonk its maximum energy.
	crew->DoEnergy(crew.MaxEnergy / 1000);
	return;
}


/*-- Goal Control --*/

public func OnRoomExitEntered(object obj)
{
	GameCall("OnRoomCompleted", obj, GetID());
	return;
}


/*-- Saving --*/

// Do not save this object as it is recreated on the loading of a new room.
public func SaveScenarioObject() { return false; }


/*-- Properties --*/

local Name = "$Name$";
local Description = "$Description$";