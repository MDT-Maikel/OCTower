/**
	Ancient Tablet
	Collect these tablets just in case they contain useful information.
	
	@author Maikel	
*/

public func IsAncientTablet() { return true; }

public func Hit(int x, int y)
{
	StonyObjectHit(x, y);
	return;
}

public func Entrance()
{
	var room = GetCurrentRoom();
	this.Description = GetRoomDescription(room);
	return;
}

public func GetRoomDescription(id room)
{
	if (!room)
		return "$Description$";
	return Format("$Description$ $DescriptionBackSide$", GetTabletCode(room->GetRoomID()));
}


/*-- Secret Code --*/

static tablet_code_offset;

// Returns a number between 0 and 9 which belongs to the tablet.
// This number depends on an offset and the room the tablet has 
// been obtained in. The offset is random in every round such that
// the final code consisting of multiple tablets is random as 
// well and at least in league mode can't be cheated.
public func GetTabletCode(string room_identifier)
{
	if (GetLength(room_identifier) != 2)
		return;	
	// Initialize offset if needed.
	if (tablet_code_offset == nil)
		tablet_code_offset = Random(2**10);
	var c1 = GetChar(room_identifier, 1);
	var c2 = GetChar(room_identifier, 2);
	return (c1 * 256 + c2 + tablet_code_offset) % 9 + 1;
}


/*-- Properties --*/

local Name = "$Name$";
local Description = "$Description$";
local Collectible = true;