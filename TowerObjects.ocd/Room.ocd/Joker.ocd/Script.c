/**
	Joker
	Collect and deliver to the level entry or exit to free them.
	Once freed, you can use them to skip a room.
	
	@author Sven2, Maikel	
*/

public func IsJoker() { return true; }

public func Entrance(object clonk)
{
	var room = GetCurrentRoom();
	if (clonk->GetOCF() & OCF_CrewMember)
		GameCall("OnRoomJokerCollected", clonk, room);
	return;
}


/*-- Properties --*/

local Name = "$Name$";
local Description = "$Description$";
local Collectible = true;