// Keeps track of the player progress for the rooms.

static g_tower_plr_progress;
static g_tower_plr_found_tablets;
static g_tower_plr_found_jokers;
static g_tower_plr_used_jokers;


/*-- Completed Rooms --*/

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

// Returns whether the player has completed this room.
global func HasPlayerCompletedRoom(int plr, id room)
{
	var plrid = GetPlayerID(plr);
	if (g_tower_plr_progress == nil)
		return false;
	if (g_tower_plr_progress[plrid] == nil)
		return false;
	return IsValueInArray(g_tower_plr_progress[plrid], room);
}

// Returns the next room available for the player.
global func GetPlayerNextOpenRoom(int plr)
{
	for (var room in GetRoomList())
		if (!HasPlayerCompletedRoom(plr, room))
			return room;
	return nil;
}


/*-- Found Tablets --*/

// Returns the rooms in which the player has found a tablet.
global func GetPlayerFoundTablets(int plr)
{
	var plrid = GetPlayerID(plr);
	if (g_tower_plr_found_tablets == nil)
		g_tower_plr_found_tablets = [];
	if (g_tower_plr_found_tablets[plrid] == nil)
		g_tower_plr_found_tablets[plrid] = [];
	return g_tower_plr_found_tablets[plrid][:];
}

// Add the given room to the rooms where the player has found a tablet.
global func AddPlayerFoundTablet(int plr, id room)
{
	var plrid = GetPlayerID(plr);
	// Safety: check if progress entry already exists.
	if (g_tower_plr_found_tablets == nil)
		g_tower_plr_found_tablets = [];
	if (g_tower_plr_found_tablets[plrid] == nil)
		g_tower_plr_found_tablets[plrid] = [];
	// Add the tablet, but don't add twice.
	if (!IsValueInArray(g_tower_plr_found_tablets[plrid], room))
		PushBack(g_tower_plr_found_tablets[plrid], room);
	return;
}

// Returns whether the player has found the tablet in this room.
global func HasPlayerFoundTablet(int plr, id room)
{
	var plrid = GetPlayerID(plr);
	if (g_tower_plr_found_tablets == nil)
		return false;
	if (g_tower_plr_found_tablets[plrid] == nil)
		return false;
	return IsValueInArray(g_tower_plr_found_tablets[plrid], room);
}


/*-- Found Jokers --*/

// Returns the rooms in which the player has found a joker.
global func GetPlayerFoundJokers(int plr)
{
	var plrid = GetPlayerID(plr);
	if (g_tower_plr_found_jokers == nil)
		g_tower_plr_found_jokers = [];
	if (g_tower_plr_found_jokers[plrid] == nil)
		g_tower_plr_found_jokers[plrid] = [];
	return g_tower_plr_found_jokers[plrid][:];
}

// Add the given room to the rooms where the player has found a joker.
global func AddPlayerFoundJoker(int plr, id room)
{
	var plrid = GetPlayerID(plr);
	// Safety: check if progress entry already exists.
	if (g_tower_plr_found_jokers == nil)
		g_tower_plr_found_jokers = [];
	if (g_tower_plr_found_jokers[plrid] == nil)
		g_tower_plr_found_jokers[plrid] = [];
	// Add the joker, but don't add twice.
	if (!IsValueInArray(g_tower_plr_found_jokers[plrid], room))
		PushBack(g_tower_plr_found_jokers[plrid], room);
	return;
}

// Returns whether the player has found the joker in this room.
global func HasPlayerFoundJoker(int plr, id room)
{
	var plrid = GetPlayerID(plr);
	if (g_tower_plr_found_jokers == nil)
		return false;
	if (g_tower_plr_found_jokers[plrid] == nil)
		return false;
	return IsValueInArray(g_tower_plr_found_jokers[plrid], room);
}


/*-- Used Jokers --*/

// Returns the rooms in which the player has used a joker.
global func GetPlayerUsedJokers(int plr)
{
	var plrid = GetPlayerID(plr);
	if (g_tower_plr_used_jokers == nil)
		g_tower_plr_used_jokers = [];
	if (g_tower_plr_used_jokers[plrid] == nil)
		g_tower_plr_used_jokers[plrid] = [];
	return g_tower_plr_used_jokers[plrid][:];
}

// Add the given room to the rooms where the player has used a joker.
global func AddPlayerUsedJoker(int plr, id room)
{
	var plrid = GetPlayerID(plr);
	// Safety: check if progress entry already exists.
	if (g_tower_plr_used_jokers == nil)
		g_tower_plr_used_jokers = [];
	if (g_tower_plr_used_jokers[plrid] == nil)
		g_tower_plr_used_jokers[plrid] = [];
	// Add the joker, but don't add twice.
	if (!IsValueInArray(g_tower_plr_used_jokers[plrid], room))
		PushBack(g_tower_plr_used_jokers[plrid], room);
	return;
}

// Add the given room to the rooms where the player has used a joker.
global func RemovePlayerUsedJoker(int plr, id room)
{
	var plrid = GetPlayerID(plr);
	// Safety: check if progress entry already exists.
	if (g_tower_plr_used_jokers == nil)
		g_tower_plr_used_jokers = [];
	if (g_tower_plr_used_jokers[plrid] == nil)
		g_tower_plr_used_jokers[plrid] = [];
	// Remove the joker.
	RemoveArrayValue(g_tower_plr_used_jokers[plrid], room);
	return;
}

// Returns whether the player has found the joker in this room.
global func HasPlayerUsedJoker(int plr, id room)
{
	var plrid = GetPlayerID(plr);
	if (g_tower_plr_used_jokers == nil)
		return false;
	if (g_tower_plr_used_jokers[plrid] == nil)
		return false;
	return IsValueInArray(g_tower_plr_used_jokers[plrid], room);
}


/*-- Available Jokes --*/

global func GetPlayerAvailableJokers(int plr)
{
	return GetLength(GetPlayerFoundJokers(plr)) - GetLength(GetPlayerUsedJokers(plr));
}


/*-- Init Data --*/

// Loads the completed rooms and stores it as the current progress.
global func InitPlayerRoomData(int plr)
{
	for (var room in LoadPlayerCompletedRooms(plr))
		room->AddPlayerCompletedRoom(plr, room);
	for (var room in LoadPlayerFoundTablets(plr))
		room->AddPlayerFoundTablet(plr, room);	
	for (var room in LoadPlayerFoundJokers(plr))
		room->AddPlayerFoundJoker(plr, room);		
	for (var room in LoadPlayerUsedJokers(plr))
		room->AddPlayerUsedJoker(plr, room);
	return;
}

// Reset the rooms the player has completed.
global func ResetPlayerRoomProgress(int plr, bool remove_save)
{
	if (GetLeague())
		return;
	if (g_tower_plr_progress == nil)
		return;
	var plrid = GetPlayerID(plr);
	g_tower_plr_progress[plrid] = nil;
	if (remove_save)
		ResetPlayerRoomData(plr);
	return;
}