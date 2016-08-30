/**
	Room Base
	Base object for the room which contains the room's settings and scripts.

	@author Anonymous
*/


/*-- Room Properties (Adjustable) --*/

public func GetRoomAuthor() { return "Anonymous"; }

public func GetRoomSection() { return nil; }

public func GetRoomDifficulty() { return nil; }


/*-- Room Properties (Fixed) --*/

public func IsRoom() { return true; }


/*-- Player Control --*/

public func InitializePlayer(int plr)
{
	JoinPlayer(plr);
	return;
}

public func RelaunchPlayer(int plr)
{
	JoinPlayer(plr);
	return;
}

protected func JoinPlayer(int plr)
{
	// Get crew member or create new one.
	var clonk = GetCrew(plr);
	if (!clonk)
	{
		var clonk = CreateObjectAbove(Clonk, 0, 0, plr);
		clonk->MakeCrewMember(plr);
		SetCursor(plr, clonk);
	}
	
	// Move crew member to room entrance.
	var room_entrance = FindObject(Find_ID(RoomEntrance));
	if (room_entrance)
		GetCrew(plr)->SetPosition(room_entrance->GetX(), room_entrance->GetY());
	
	// Give clonk its maximum energy.
	clonk->DoEnergy(clonk.MaxEnergy / 1000);
	return;
}


/*-- Goal Control --*/

public func OnRoomExitEntered(object obj)
{
	Log("reached room exit");
	return;
}


/*-- Properties --*/

local Name = "$Name$";
local Description = "$Description$";