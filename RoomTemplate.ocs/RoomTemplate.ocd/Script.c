/**
	Room Template
	Template object for the room which contains the room's settings and scripts.

	@author Anonymous
*/

#include RoomBase


/*-- Basic Room Properties --*/
// Overload these properties if needed.

// The name of the room, appears in menus and the room start.
// Add both an English and German version.
public func GetRoomName() { return "$RoomName$"; }

// The description of the room, appears in menus and the room start.
// Add both an English and German version.
public func GetRoomDescription() { return "$RoomDescription$"; }

// The name of the author of the room, separate multiple authors with comma's or & (like "John, Jane & Wipf").
// Names may not contain comma's or &.
public func GetRoomAuthor() { return "Anonymous"; }

// The map section that needs to be loaded for this room, usually equal to the name of the room.
public func GetRoomSection() { return "TODO"; }

// A unique ID for the room which is used for saving player progress. It must be two characters
// long which can be chosen from the set [A-Za-z].
public func GetRoomID() { return "__"; }

// The difficulty of this room, ranges from 0 to 999.
public func GetRoomDifficulty() { return 0; }

// Whether or not the room has an ancient tablet which can be found.
public func HasTablet() { return false; }

// Whether or not the room has a joker which can be found.
public func HasJoker() { return false; }


/*-- Advanced Room Properties --*/
// Overload these properties if needed.

// Adapt the default pump speed to prevent long waiting (the default pump speed is 50).
public func GetRoomPumpSpeed() { return nil; }


/*-- Room Scripts --*/

public func OnRoomInit()
{
	// Here you can create effects, extra objects that are needed for the room.
	return;
}

public func OnPlayerInit(int plr)
{
	// Here you can create effects, extra objects that are needed for the player and its crew.
	return;
}