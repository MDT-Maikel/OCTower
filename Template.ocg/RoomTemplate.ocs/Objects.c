// Room template default objects.

public func InitializeObjects()
{
	CreateObjectAbove(RoomEntrance, 80, 456);
	CreateObjectAbove(RoomExit, LandscapeWidth() - 80, 456);	
	CreateObjectAbove(PlayerStart, 100, 456);
	return true;
}
