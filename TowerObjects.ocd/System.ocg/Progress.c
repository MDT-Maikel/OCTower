// Keeps track of the player progress for the rooms.

static g_tower_plr_progress;

global func GetPlayerCompletedRooms(int plr)
{
	var plrid = GetPlayerID(plr);
	if (g_tower_plr_progress == nil)
		g_tower_plr_progress = [];
	if (g_tower_plr_progress[plrid] == nil)
		g_tower_plr_progress[plrid] = [];
	return g_tower_plr_progress[plrid][:];
}

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