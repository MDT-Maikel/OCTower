// Loading of the different scenario sections.

static g_tower_current_room;

// Load the tower entrance (main section).
global func LoadMain()
{
	AddEffect("IntScheduleLoadMain", nil, 1, 1);
	return;
}

global func FxIntScheduleLoadMainStop(object target, proplist fx, int reason, bool temp)
{
	if (temp || reason != FX_Call_Normal)
		return FX_OK;
	g_tower_current_room = nil;
	//Log("[%d]Load section main", FrameCounter());
	//LogCallStack();
	LoadScenarioSection("main");
	Scenario->InitMain();
	return FX_OK;
}

// Load a given room.
global func LoadRoom(id room)
{
	if (!room->~IsRoom() || room == RoomBase)
		return;
	g_tower_current_room = room;	
	room->LoadRoom();
	return;
}

// Returns the current room.
global func GetCurrentRoom() { return g_tower_current_room; }