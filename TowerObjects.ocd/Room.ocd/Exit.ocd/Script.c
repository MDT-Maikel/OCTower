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

public func Collection2(object crew)
{
	// Check if the clonk is carrying a joker.
	var joker = FindObject(Find_Container(crew), Find_Func("IsJoker"));
	// Notify goals and scenario scripts a joker has been collected.
	if (joker)
		GameCallEx("OnJokerCollected", crew, joker);
	// Check if the clonk is carrying a tablet.
	var tablet = FindObject(Find_Container(crew), Find_Func("IsAncientTablet"));
	// Notify goals and scenario scripts a joker has been collected.
	if (tablet)
		GameCallEx("OnTabletCollected", crew, tablet);
	// Let goal and scenario know the exit has been entered.
	GameCallEx("OnRoomExitEntered", crew);
	return;
}


/*-- Properties --*/

local Name = "$Name$";
local Description = "$Description$";
local Plane = 200;