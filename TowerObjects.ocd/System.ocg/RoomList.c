// List of rooms ordered according to difficulty.

// Global variable to store the room list.
static g_tower_room_list;

// Returns a list of the loaded rooms sorted according to difficulty.
global func GetRoomList()
{
	// Do a lazy initialization of the room list.
	if (g_tower_room_list == nil)
	{
		g_tower_room_list = [];
		// Loop over all definitions to find rooms.
		var def, index;
		while (def = GetDefinition(++index))
			if (def->~IsRoom() && def != RoomBase)
				PushBack(g_tower_room_list, def);
		// Sort rooms according to difficulty.
	}	
	return g_tower_room_list;
}
