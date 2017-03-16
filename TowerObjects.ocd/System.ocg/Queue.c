// Keeps track of the queue of player's who want to attempt the room.

static g_tower_plr_queue;
static g_current_plr;

// Append a player to the room queue.
global func AppendPlayerToQueue(int plr)
{
	var plrid = GetPlayerID(plr);
	if (g_tower_plr_queue == nil)
	{
		g_tower_plr_queue = [plrid];
		return;
	}
	if (IsValueInArray(g_tower_plr_queue, plrid))
		return;
	PushBack(g_tower_plr_queue, plrid);
	return;	
}

// Prepend a player to the room queue.
global func PrependPlayerToQueue(int plr)
{
	var plrid = GetPlayerID(plr);
	if (g_tower_plr_queue == nil)
	{
		g_tower_plr_queue = [plrid];
		return;
	}
	if (IsValueInArray(g_tower_plr_queue, plrid))
		return;
	PushFront(g_tower_plr_queue, plrid);
	return;
}

// Returns whether the player is in the room queue.
global func IsPlayerInQueue(int plr)
{
	if (g_tower_plr_queue == nil)
		return false;
	var plrid = GetPlayerID(plr);
	return IsValueInArray(g_tower_plr_queue, plrid);
}

// Returns the player who is first in the room queue and removes that player.
// Every time this function is called a new player next in the queue is returned.
global func GetNextPlayerInQueue()
{
	if (g_tower_plr_queue == nil)
		return nil;
	// Loop over the player queue until an active player has been found.
	var plrid;	
	while ((plrid = PopFront(g_tower_plr_queue)) != nil)
	{
		var plr = GetPlayerByID(plrid);
		// Take player name as an indication of active.
		if (GetPlayerName(plr))
		{
			g_current_plr = plr;
			return plr;
		}
	}
	return;
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
