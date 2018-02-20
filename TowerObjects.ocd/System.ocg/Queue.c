// Keeps track of the queue of player's who want to attempt the room.

static g_tower_plr_queue;
static g_tower_plr_watchlist;
static g_current_plr;

// Append a player to the room queue.
global func AppendPlayerToQueue(int plr)
{
	var plr_id = GetPlayerID(plr);
	if (g_tower_plr_queue == nil)
	{
		g_tower_plr_queue = [plr_id];
		return;
	}
	if (IsValueInArray(g_tower_plr_queue, plr_id))
		return;
	PushBack(g_tower_plr_queue, plr_id);
	return;	
}

// Prepend a player to the room queue.
global func PrependPlayerToQueue(int plr)
{
	var plr_id = GetPlayerID(plr);
	if (g_tower_plr_queue == nil)
	{
		g_tower_plr_queue = [plr_id];
		return;
	}
	if (IsValueInArray(g_tower_plr_queue, plr_id))
		return;
	PushFront(g_tower_plr_queue, plr_id);
	return;
}

// Removes the player from the queue completely.
global func RemovePlayerFromQueue(int plr)
{
	if (g_tower_plr_queue == nil)
		return;
	var plr_id = GetPlayerID(plr);
	RemoveArrayValue(g_tower_plr_queue, plr_id);
	return;
}

// Returns whether the player is in the room queue.
global func IsPlayerInQueue(int plr)
{
	if (g_tower_plr_queue == nil)
		return false;
	var plr_id = GetPlayerID(plr);
	return IsValueInArray(g_tower_plr_queue, plr_id);
}

// Returns the player who is first in the room queue and removes that player.
// Every time this function is called a new player next in the queue is returned.
global func GetNextPlayerInQueue()
{
	if (g_tower_plr_queue == nil)
		return nil;
	// Loop over the player queue until an active player has been found.
	var plr_id;	
	while ((plr_id = PopFront(g_tower_plr_queue)) != nil)
	{
		var plr = GetPlayerByID(plr_id);
		// Take player name as an indication of active.
		if (GetPlayerName(plr))
		{
			g_current_plr = plr;
			return plr;
		}
	}
	return;
}

global func GetPlayerQueueTaggedString()
{
	if (g_tower_plr_queue == nil)
		return;
	var first =  GetPlayerByID(g_tower_plr_queue[0]);
	var queue = GetTaggedPlayerName(first);
	for (var index = 1; index < GetLength(g_tower_plr_queue); index++)
	{
		var plr = GetPlayerByID(g_tower_plr_queue[index]);
		queue = Format("%s, %s", queue, GetTaggedPlayerName(plr));
	}
	return queue;
}

// Returns the player that is currently attempting the room.
global func GetActivePlayer()
{
	return g_current_plr;
}

// Returns whether the given player is currently attempting a room.
global func IsActivePlayer(int plr)
{
	return plr == g_current_plr;
}

// Add a player to the watch list.
global func AddPlayerToWatchList(int plr)
{
	var plr_id = GetPlayerID(plr);
	if (g_tower_plr_watchlist == nil)
		g_tower_plr_watchlist = [];
	if (IsValueInArray(g_tower_plr_watchlist, plr_id))
		return;
	PushBack(g_tower_plr_watchlist, plr_id);
	// Update room menus.
	UpdateRoomMenus("rooms");
	// Log joining watchlist.
	Log("$MsgJoinsWatchList$", GetTaggedPlayerName(plr));
	return;	
}

// Removes the player from the watch list.
global func RemovePlayerFromWatchList(int plr)
{
	if (g_tower_plr_watchlist == nil)
		return;
	var plr_id = GetPlayerID(plr);
	if (!IsValueInArray(g_tower_plr_watchlist, plr_id))
		return;
	RemoveArrayValue(g_tower_plr_watchlist, plr_id);
	// Update room menus.
	UpdateRoomMenus("rooms");
	// Log leaving watchlist.
	Log("$MsgLeavesWatchList$", GetTaggedPlayerName(plr));
	return;
}

global func IsPlayerOnWatchList(int plr)
{
	if (g_tower_plr_watchlist == nil)
		return false;	
	var plr_id = GetPlayerID(plr);	
	return IsValueInArray(g_tower_plr_watchlist, plr_id);
}

global func GetPlayerWatchListTaggedString()
{
	if (g_tower_plr_watchlist == nil)
		return;
	var first =  GetPlayerByID(g_tower_plr_watchlist[0]);
	var watchlist = GetTaggedPlayerName(first);
	for (var index = 1; index < GetLength(g_tower_plr_watchlist); index++)
	{
		var plr = GetPlayerByID(g_tower_plr_watchlist[index]);
		watchlist = Format("%s, %s", watchlist, GetTaggedPlayerName(plr));
	}
	return watchlist;
}
