/**
	Room Entrance
	Provides the entrance to a tower room.

	@author Maikel
*/

#include RoomDoor


public func Construction()
{
	SetGraphics(nil, RoomDoor);
	SetColor(RGB(50, 200, 50));
	return;
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
	// Let goal and scenario know the entrance has been entered.
	GameCallEx("OnRoomEntranceEntered", crew);
	return;
}


/*-- Properties --*/

local Name = "$Name$";
local Description = "$Description$";
