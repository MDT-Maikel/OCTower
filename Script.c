/**
	Tower of Despair
	A big tower filled with riddle rooms.

	@author Sven2, Maikel
*/

// List of global variables.
static g_tower_current_room;
static g_tower_loading_scheduled;


public func Initialize()
{
	g_tower_current_room = 0;
	g_tower_loading_scheduled = false;

	return;
}

public func InitializePlayer(int plr)
{


	JoinPlayer(plr);
	return;
}

public func JoinPlayer(int plr)
{
	// Get crew member or create new one.
	var crew = GetCrew(plr);
	if (!crew)
	{
		var crew = CreateObjectAbove(Clonk, 0, 0, plr);
		crew->MakeCrewMember(plr);
		SetCursor(plr, crew);
	}

	// Give clonk its maximum energy.
	crew->DoEnergy(crew.MaxEnergy / 1000);
	
	// Move clonk to position outside the castle.
	//crew->SetPosition(40 + RandomX(100), 350);
	crew->SetPosition(620, 294);
	return;
}

public func InitMain()
{
	for (var plr in GetPlayers())
		JoinPlayer(plr);
	return;
}

public func OnRoomEntranceEntered(object crew)
{
	g_tower_current_room = 0;
	LoadRoom(GetRoomList()[g_tower_current_room]);
	return;
}