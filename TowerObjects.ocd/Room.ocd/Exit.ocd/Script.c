/**
	Room Entrance
	Provides the entrance to a tower room.

	@author Maikel
*/


/*-- Entering --*/

public func Construction()
{
	SetEntrance(true);
	return true;
}

public func Collection2(object obj)
{
	GameCallEx("OnRoomExitEntered", obj);
	return;
}


/*-- Properties --*/

local Name = "$Name$";
local Description = "$Description$";
local Plane = 200;