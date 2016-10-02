/**
	Tower of Despair
	Map script which is activated in some of the rooms.

	@author Maikel
*/


// Called be the engine: forward to room here.
public func InitializeMap(proplist map)
{
	// Find current room definition and forward if possible.
	var current_room = GetCurrentRoom();
	if (current_room)
	{
		//Log("[%d]Attempting to create Map.c for room %v", FrameCounter(), current_room);
		return current_room->~InitializeMap(map);
	}
	// Don't do anything.
	return false;
}