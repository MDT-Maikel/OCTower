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
				PushBack(g_tower_room_list, {room = def, difficulty = def->GetRoomDifficulty()});
		// Sort rooms according to difficulty.
		SortArrayByProperty(g_tower_room_list, "difficulty");
		for (var index = 0; index < GetLength(g_tower_room_list); index++)
			g_tower_room_list[index] = g_tower_room_list[index].room;
	}	
	return g_tower_room_list;
}

// Sorts a list of room ids according to difficulty.
global func SortRoomList(array room_list)
{
	for (var index = 0; index < GetLength(room_list); index++)
		room_list[index] = {room = room_list[index], difficulty = room_list[index]->GetRoomDifficulty()};
	SortArrayByProperty(room_list, "difficulty");
	for (var index = 0; index < GetLength(room_list); index++)
			room_list[index] = room_list[index].room;
	return room_list;
}

// Returns the next room in the list after the given room.
global func GetNextRoom(id room)
{
	var room_list = GetRoomList();
	// Safety: return first room if no room is given.
	if (room == nil)
		return room_list[0];
	// Find the next room and return it.
	var index = GetIndexOf(room_list, room);
	if (index == -1 || index >= GetLength(room_list) - 1)
		return nil;
	return room_list[index + 1];
}