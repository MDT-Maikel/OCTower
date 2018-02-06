/**
	Joker
	Collect and deliver to the level entry or exit to free them.
	Once freed, you can use them to skip a room.
	
	@author Sven2, Maikel	
*/

public func IsJoker() { return true; }

public func Entrance(object clonk)
{
	GameCall("OnRoomJokerCollected", clonk, this);
	return;
}


/*-- Properties --*/

local Name = "$Name$";
local Description = "$Description$";
local Collectible = true;