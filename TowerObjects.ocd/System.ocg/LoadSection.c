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
	SetCurrentRoom(nil);
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
	room->LoadRoom();
	return;
}

// Sets the current room.
global func SetCurrentRoom(id room)
{
	g_tower_current_room = room;
	return;
}

// Returns the current room. Nil means in the lobby.
global func GetCurrentRoom() { return g_tower_current_room; }