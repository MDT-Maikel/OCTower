// Loading of the different scenario sections.

// Load the tower entrance (main section).
global func LoadMain()
{
	AddEffect("IntScheduleLoadMain", nil, 1, 1);
	return;
}

global func FxIntScheduleLoadMainStop(object target, proplist fx)
{
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