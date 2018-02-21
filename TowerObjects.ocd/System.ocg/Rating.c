// Keeps track of players rating the rooms.

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