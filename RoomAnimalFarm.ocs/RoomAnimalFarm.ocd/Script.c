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
	// Normal animals.
	Wipf->Place(RandomX(1, 9), Rectangle(120, 40, 116, 56));
	Fish->Place(RandomX(1, 9), Rectangle(384, 24, 160, 72));
	Bat->Place(RandomX(1, 4), Rectangle(576, 72, 40, 176));
	Shark->Place(RandomX(1, 9), Rectangle(272, 176, 248, 96));
	Piranha->Place(RandomX(1, 9), Rectangle(272, 176, 248, 96));
	for (var cnt = RandomX(1, 5); cnt > 0; cnt--)
		CreateObject(Mooq, RandomX(32, 116), RandomX(416, 448));
	for (var cnt = RandomX(1, 9); cnt > 0; cnt--)
		CreateObject(Chippie, RandomX(180, 300), RandomX(416, 448));
	// Insects.
	for (var cnt = RandomX(1, 9); cnt > 0; cnt--)
		CreateObject(Butterfly, RandomX(120, 176), RandomX(40, 88));
	//Firefly->SpawnSwarm(FindObject(Find_Func("IsTree"), RandomX(1, 9)));
	
	// Disable reproduction.
	for (var animal in FindObjects(Find_Func("IsAnimal")))
	{
		animal->SetReproductionRate();
	}
	return;
}

public func InitKeypads()
{
	// Tablet keypad.
	var tablet_door = CreateObject(StoneDoor, 68, 195);
	var tablet_keypad = CreateObject(Keypad, 88, 204);
	tablet_keypad->SetStoneDoor(tablet_door);
	// Determine code according to animals.
	var tablet_animals = [Butterfly/*, Firefly*/];
	ShuffleArray(tablet_animals);
	var tablet_code = "", tablet_cnt = 0;
	for (var animal in tablet_animals)
	{
		DrawWallAnimal(animal, 108 + 20 * tablet_cnt, 204);
		tablet_cnt++;
		tablet_code = Format("%s%d", tablet_code, ObjectCount(Find_ID(animal)));
	}
	tablet_keypad->SetKeypadCode(tablet_code);
	
	// Main keypad.
	var main_door = CreateObject(StoneDoor, 556, 435);
	var main_keypad = CreateObject(Keypad, 538, 442);
	main_keypad->SetStoneDoor(main_door);
	// Determine code according to animals.
	var main_animals = [Wipf, Fish, Bat, Shark, Piranha, Mooq, Chippie];
	ShuffleArray(main_animals);
	var main_code = "", main_cnt = 0;
	for (var animal in main_animals)
	{
		DrawWallAnimal(animal, 392 + 20 * main_cnt, 440);
		main_cnt++;
		main_code = Format("%s%d", main_code, ObjectCount(Find_ID(animal)));
	}
	main_keypad->SetKeypadCode(main_code);
	return;
}

public func DrawWallAnimal(id animal, int x, int y)
{
	var dummy = CreateObject(Dummy, x, y);
	dummy.Visibility = VIS_All;
	dummy.Plane = 100;
	dummy->SetGraphics(nil, animal, GFX_Overlay, GFXOV_MODE_Base);
	dummy->SetClrModulation(RGBa(255, 255, 255, 128), GFX_Overlay);
	var scale = Min(1000, 1000 * 16 / Max(animal->GetDefWidth(), animal->GetDefHeight()));
	dummy->SetObjDrawTransform(scale, 0, 0, 0, scale, 0, GFX_Overlay);
	return;
}
