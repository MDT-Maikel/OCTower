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
public func GetRoomSection() { return "AnimalFarm"; }

// A unique ID for the room which is used for saving player progress. It must be two characters
// long which can be chosen from the set [A-Za-z].
public func GetRoomID() { return "AF"; }

// The difficulty of this room, ranges from 0 to 999.
public func GetRoomDifficulty() { return 30; }

// Whether or not the room has an ancient tablet which can be found.
public func HasTablet() { return true; }

// Whether or not the room has a joker which can be found.
public func HasJoker() { return false; }

// Hints and tricks shown in the help menu when currently playing this room.
// Pass a list of strings which represent the hints, each is shown separately.
public func GetRoomHints() { return ["$Hint1$", "$Hint2$"]; }


/*-- Room Scripts --*/

// Called when the room is initialized.
// Here you can create effects and extra objects that are needed for the room.
public func OnRoomInit()
{
	// Animals and keypads + doors are created in script.	
	InitAnimals();
	InitKeypads();
	return;
}

// Called when the player starts its room attempt.
// Here you can create effects and extra objects that are needed for the player and its crew.
public func OnPlayerInit(int plr)
{
	return;
}

public func InitAnimals()
{
	// Create a set of different animal counts.
	var small_counts = [1, 2, 3, 4, 5, 6, 7, 8];
	var large_counts = [11, 12, 13, 14, 15];
	ShuffleArray(small_counts);
	ShuffleArray(large_counts);
	
	// Place animals with small counts.
	Wipf->Place(small_counts[0], Rectangle(120, 40, 116, 56));
	Fish->Place(small_counts[1], Rectangle(384, 24, 160, 72));
	Bat->Place(small_counts[2], Rectangle(576, 72, 40, 176));
	Shark->Place(small_counts[3], Rectangle(272, 176, 248, 96));
	for (var cnt = small_counts[4]; cnt > 0; cnt--)
		CreateObject(Mooq, RandomX(32, 116), RandomX(416, 440));
	for (var cnt = small_counts[5]; cnt > 0; cnt--)
		CreateObject(Chippie, RandomX(180, 300), RandomX(416, 440));
	Puka->Place(small_counts[6], Rectangle(80, 240, 160, 80));

	// Place animals with large counts.		
	Piranha->Place(large_counts[0], Rectangle(272, 176, 248, 96));
	Butterfly->Place(large_counts[1], Rectangle(120, 40, 56, 96));
	Firefly->Place(1, large_counts[2], Rectangle(120, 148, 56, 120));
	
	// Disable reproduction.
	for (var animal in FindObjects(Find_Func("IsAnimal")))
		animal->~SetReproductionRate();
		
	// Make it night for the fireflies.
	Time->Init();
	Time->SetTime(22 * 60 + 30);
	Time->SetCycleSpeed(0);	
	return;
}

public func InitKeypads()
{
	// The standard doors open automatically.
	for (var door in FindObjects(Find_ID(StoneDoor)))
		door->SetAutoControl(0);	
	
	// Tablet keypad: total number of animals.
	var tablet_door = CreateObject(StoneDoor, 68, 195);
	var tablet_keypad = CreateObject(Keypad, 88, 204);
	tablet_keypad->SetStoneDoor(tablet_door);
	// Determine code according to animals.
	var animal_count = ObjectCount(Find_Func("IsAnimal"));
	tablet_keypad->SetKeypadCode(Format("%d", animal_count));
	
	// Main keypad: ordered by number of animals.
	var main_door = CreateObject(StoneDoor, 556, 435);
	var main_keypad = CreateObject(Keypad, 538, 442);
	main_keypad->SetStoneDoor(main_door);
	// Determine code according to animals.
	var animals = [Puka, Wipf, Butterfly, Fish, Bat, Shark, Piranha, Mooq, Chippie, Firefly];
	main_keypad->SetReplacementImages(animals);
	var ordered_animals = animals[:];
	for (var index = 0; index < GetLength(ordered_animals); index++)
		ordered_animals[index] = [ordered_animals[index], ObjectCount(Find_ID(ordered_animals[index]))];
	SortArrayByArrayElement(ordered_animals, 1, true);
	for (var index = 0; index < GetLength(ordered_animals); index++)
		ordered_animals[index] = ordered_animals[index][0];
	var main_code = "";
	for (var index = 0; index < GetLength(ordered_animals); index++)
		main_code = Format("%s%d", main_code, GetIndexOf(animals, ordered_animals[index]));
	main_keypad->SetKeypadCode(main_code);
	return;
}
