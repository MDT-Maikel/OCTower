// Keeps track of the player progress for the rooms.

static g_tower_plr_progress;

// Returns the rooms the player has completed.
global func GetPlayerCompletedRooms(int plr)
{
	var plrid = GetPlayerID(plr);
	if (g_tower_plr_progress == nil)
		g_tower_plr_progress = [];
	if (g_tower_plr_progress[plrid] == nil)
		g_tower_plr_progress[plrid] = [];
	return g_tower_plr_progress[plrid][:];
}

// Add the given room to the completed rooms of the player.
global func AddPlayerCompletedRoom(int plr, id room)
{
	var plrid = GetPlayerID(plr);
	// Safety: check if progress entry already exists.
	if (g_tower_plr_progress == nil)
		g_tower_plr_progress = [];
	if (g_tower_plr_progress[plrid] == nil)
		g_tower_plr_progress[plrid] = [];
	// Add the room, but don't add twice.
	if (!IsValueInArray(g_tower_plr_progress[plrid], room))
		PushBack(g_tower_plr_progress[plrid], room);
	return;
}

// Loads the completed rooms and stores it as the current progress.
global func InitPlayerCompletedRooms(int plr)
{
	var rooms = LoadPlayerCompletedRooms(plr);
	for (var room in rooms)
		room->AddPlayerCompletedRoom(plr, room);
	return;
}

// Reset the rooms the player has completed.
global func ResetPlayerCompletedRooms(int plr, bool remove_save)
{
	if (GetLeague())
		return;
	if (g_tower_plr_progress == nil)
		return;
	var plrid = GetPlayerID(plr);
	g_tower_plr_progress[plrid] = nil;
	if (remove_save)
		ResetPlayerSavedCompletedRooms(plr);
	return;
}