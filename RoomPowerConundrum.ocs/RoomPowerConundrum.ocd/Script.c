/**
	Room Control
	This object's script contains the properties and the functions of the room.

	@author See contents of GetRoomAuthor().
*/

#include RoomBase


/*-- Room Properties --*/
// Overload these properties if needed.

// The name of the room, appears in menus and the room start.
// Add both an English and German version.
public func GetRoomName() { return "$RoomName$"; }

// The description of the room, appears in menus and the room start.
// Add both an English and German version.
public func GetRoomDescription() { return "$RoomDescription$"; }

// The name of the author of the room, separate multiple authors with comma's or & (like "John, Jane & Wipf").
// Names may not contain comma's or &.
public func GetRoomAuthor() { return "Maikel"; }

// The map section that needs to be loaded for this room, usually equal to the name of the room.
public func GetRoomSection() { return "PowerConundrum"; }

// A unique ID for the room which is used for saving player progress. It must be two characters
// long which can be chosen from the set [A-Za-z].
public func GetRoomID() { return "PC"; }

// The difficulty of this room, ranges from 0 to 999.
public func GetRoomDifficulty() { return 50; }

// Whether or not the room has an ancient tablet which can be found.
public func HasTablet() { return true; }

// Whether or not the room has a joker which can be found.
public func HasJoker() { return false; }


/*-- Room Scripts --*/

// Called when the room is initialized.
// Here you can create effects and extra objects that are needed for the room.
public func OnRoomInit()
{
	return;
}

// Called when the player starts its room attempt.
// Here you can create effects and extra objects that are needed for the player and its crew.
public func OnPlayerInit(int plr)
{
	return;
}