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
public func GetRoomAuthor() { return "Clonkonaut"; }

// The map section that needs to be loaded for this room, usually equal to the name of the room.
public func GetRoomSection() { return "TheLadder"; }

// A unique ID for the room which is used for saving player progress. It must be two characters
// long which can be chosen from the set [A-Za-z].
public func GetRoomID() { return "Tl"; }

// The difficulty of this room, ranges from 0 to 999.
public func GetRoomDifficulty() { return 5; }

// Whether or not the room has an ancient tablet which can be found.
public func HasTablet() { return true; }

// Whether or not the room has a joker which can be found.
public func HasJoker() { return false; }

// Hints and tricks shown in the help menu when currently playing this room.
// Pass a list of strings which represent the hints, each is shown separately.
public func GetRoomHints() { return nil; }


/*-- Room Scripts --*/

local CheckDamage = new Effect
{
	Damage = func(int damage, int cause, int by_player)
	{
		if (by_player != NO_OWNER)
		{
			Dialogue->MessageBoxAll("$Ouch$", Target, true);
			var ladder = FindObject(Find_ID(MetalLadder));
			if (ladder)
				ladder->SetLength(219, 1);
			this->Remove();
		}
		return damage;
	}
};

// Called when the room is initialized.
// Here you can create effects and extra objects that are needed for the room.
public func OnRoomInit()
{
	var npc = FindObject(Find_ID(Clonk), Find_Owner(NO_OWNER));
	npc->CreateEffect(CheckDamage, 1);
	return;
}

// Called when the player starts its room attempt.
// Here you can create effects and extra objects that are needed for the player and its crew.
public func OnPlayerInit(int plr)
{	
	return;
}