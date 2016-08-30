/**
	Room Template
	Template object for the room which contains the room's settings and scripts.

	@author Anonymous
*/

#include RoomBase


/*-- Room Properties --*/
// Overload these properties if needed.

// The name of the author of the room, separate multiple authors with comma's.
public func GetRoomAuthor() { return "Anonymous"; }

// The map section that needs to be loaded for this room, usually equal to the name of the room.
public func GetRoomSection() { return "TODO"; }

// The difficulty of this room, ranges from 0 to 9999.
public func GetRoomDifficulty() { return 0; }


/*-- Properties --*/

local Name = "$Name$";
local Description = "$Description$";