// Keeps track of players rating the rooms. Handles both the rating of how players liked
// the room as well as their rating of the difficulty of the room.

// Updates the rating of the room by this player.
global func UpdatePlayerRoomRating(id room, int plr, int rating)
{
	// Check if rating changed.
	var old_rating = GetPlayerRoomRating(room, plr);
	if (old_rating == rating)
		return;
	// Save the rating.
	SavePlayerRoomRatingData(room, plr, rating);
	// Log that the room has been rated.
	if (old_rating == nil)
		Log("$MsgRatingGiven$", GetTaggedPlayerName(plr), room->GetRoomName(), rating);
	else
		Log("$MsgRatingUpdated$", GetTaggedPlayerName(plr), room->GetRoomName(), rating);
	// Notify about room rating change.
	GameCallEx("OnRoomRatingChanged", room, plr, rating);
	return;
}

// Returns the current rating of the room by this player.
global func GetPlayerRoomRating(id room, int plr)
{
	var rating_data = LoadPlayerRoomRatingData(plr);
	for (var check_room in rating_data)
		if (check_room[0] == room)
			return check_room[1];
	return nil;
}

// Load the player room rating data from extra data.
global func LoadPlayerRoomRatingData(int plr)
{
	var load_string = GetPlrExtraData(plr, "OCTowerPlayerRoomRating");
	if (GetType(load_string) != C4V_String)
		return [];	
	// Get the version of the loaded save data.
	var load_version = ParseInt(TakeString(load_string, 0, 4));
	// Get a list of the rooms of the form letter letter digits.
	var rooms = RegexMatch(load_string, "[a-zA-Z]{2}[0-9]*");
	// Convert this form to the room id and room rating.
	for (var index = 0; index < GetLength(rooms); index++)
	{
		var room_id = GetRoomFromID(TakeString(rooms[index][0], 0, 2));
		// Make sure the saved room still exists in the tower.
		if (room_id == nil)
			continue;
		var room_rating = ParseInt(TakeString(rooms[index][0], 2));
		rooms[index] = [room_id, room_rating];	
	}
	return rooms;
}

// Save the player room rating data from extra data.
global func SavePlayerRoomRatingData(id room, int plr, int rating)
{
	var save_string = Format("%04d", GetTowerVersion());
	for (var save_room in GetRoomList())
	{
		var save_rating = GetPlayerRoomRating(save_room, plr);
		if (save_room == room)
			save_rating = rating;
		// Only add rating if it exists.
		if (save_rating != nil)
			save_string = Format("%s%s%d", save_string, save_room->GetRoomID(), save_rating);	
	}
	SetPlrExtraData(plr, "OCTowerPlayerRoomRating", save_string);
	return;
}

// Updates the difficulty of the room by this player.
global func UpdatePlayerRoomDifficulty(id room, int plr, int difficulty)
{
	// Check if difficulty changed.
	var old_difficulty = GetPlayerRoomDifficulty(room, plr);
	if (old_difficulty == difficulty)
		return;
	// Save the difficulty.
	SavePlayerRoomDifficultyData(room, plr, difficulty);
	// Log that the room difficulty has been rated.
	var msg_difficulty = ["$MsgDifficultyTrivial$", "$MsgDifficultyEasy$", "$MsgDifficultyMedium$", "$MsgDifficultyHard$", "$MsgDifficultyExtreme$"][difficulty - 1];
	if (old_difficulty == nil)
		Log("$MsgDifficultyRatingGiven$", GetTaggedPlayerName(plr), room->GetRoomName(), msg_difficulty);
	else
		Log("$MsgDifficultyRatingUpdated$", GetTaggedPlayerName(plr), room->GetRoomName(), msg_difficulty);
	// Notify about room difficulty change.
	GameCallEx("OnRoomDifficultyChanged", room, plr, difficulty);
	return;
}

// Returns the current difficulty rating of the room by this player.
global func GetPlayerRoomDifficulty(id room, int plr)
{
	var difficulty_data = LoadPlayerRoomDifficultyData(plr);
	for (var check_room in difficulty_data)
		if (check_room[0] == room)
			return check_room[1];
	return nil;
}

// Load the player room difficulty rating data from extra data.
global func LoadPlayerRoomDifficultyData(int plr)
{
	var load_string = GetPlrExtraData(plr, "OCTowerPlayerRoomDifficulty");
	if (GetType(load_string) != C4V_String)
		return [];	
	// Get the version of the loaded save data.
	var load_version = ParseInt(TakeString(load_string, 0, 4));
	// Get a list of the rooms of the form letter letter digits.
	var rooms = RegexMatch(load_string, "[a-zA-Z]{2}[0-9]*");
	// Convert this form to the room id and room difficulty rating.
	for (var index = 0; index < GetLength(rooms); index++)
	{
		var room_id = GetRoomFromID(TakeString(rooms[index][0], 0, 2));
		// Make sure the saved room still exists in the tower.
		if (room_id == nil)
			continue;
		var room_rating = ParseInt(TakeString(rooms[index][0], 2));
		rooms[index] = [room_id, room_rating];	
	}
	return rooms;
}

// Save the player room difficulty rating data from extra data.
global func SavePlayerRoomDifficultyData(id room, int plr, int difficulty)
{
	var save_string = Format("%04d", GetTowerVersion());
	for (var save_room in GetRoomList())
	{
		var save_difficulty = GetPlayerRoomDifficulty(save_room, plr);
		if (save_room == room)
			save_difficulty = difficulty;
		// Only add difficulty rating if it exists.
		if (save_difficulty != nil)
			save_string = Format("%s%s%d", save_string, save_room->GetRoomID(), save_difficulty);	
	}
	SetPlrExtraData(plr, "OCTowerPlayerRoomDifficulty", save_string);
	return;
}