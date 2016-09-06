// All progress is saved in a string of maximally 2048 characters. The first four characters specify the version at which is saved.
// Then all remaining characters represent the completed rooms. Each room is represented by an ID which is constructed out of two
// characters from the set [A-Za-z] appended by digits of arbitrary length to store additional information like a collected joker.

// Load the player progress from extra data or league data.
global func LoadPlayerCompletedRooms(int plr)
{
	var plr_id = GetPlayerID(plr);
	var load_string;
	if (GetLeague())
		load_string = GetLeagueProgressData(plr_id);
	else
		load_string = GetPlrExtraData(plr, "OCTowerProgress");
	if (GetType(load_string) != C4V_String)
		return [];
	var load_version = 1000 * GetChar(load_string, 0) + 100 * GetChar(load_string, 1) + 10 * GetChar(load_string, 2) + GetChar(load_string, 3);
	
	var rooms = [];
	var index = 4;
	while (index < GetLength(load_string))
	{
		// Get room id from the next two characters.
		var room_id = Format("%c%c", GetChar(load_string, index), GetChar(load_string, index + 1));
		PushBack(rooms, room_id);
		index += 2;
		// Find any number of digits and increase index.
		var test_index = 0;
		while (CharIsDigit(GetChar(load_string, index + test_index)))
			test_index++;
		index += test_index;
	}
	for (var index = 0; index < GetLength(rooms); index++)
		rooms[index] = GetRoomFromID(rooms[index]);
	//Log("Load: plr %d, version %d, load_string %s, rooms %v", plr, load_version, load_string, rooms);
	return rooms;
}

// Save the player progress to extra data or league data.
global func SavePlayerCompletedRooms(int plr)
{
	var plr_id = GetPlayerID(plr);
	
	var rooms = GetPlayerCompletedRooms(plr);
	var tower_version = Format("%04d", GetTowerVersion());
	var save_string = tower_version;
	for (var room in rooms)
		save_string = Format("%s%s", save_string, room->GetRoomID());
	//Log("Save: plr %d rooms %v save_string %s", plr, rooms, save_string);
	// If league is active store progress there, otherwise store the progress in the player file.
	if (GetLeague())
		SetLeagueProgressData(save_string, plr_id);
	else
		SetPlrExtraData(plr, "OCTowerProgress", save_string);		
	return;
}

// Reset the saved player progress in extra data.
global func ResetPlayerSavedCompletedRooms(int plr)
{
	if (GetLeague())
		return;
	SetPlrExtraData(plr, "OCTowerProgress", nil);
	return;
}
