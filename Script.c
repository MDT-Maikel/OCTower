/**
	Tower of Despair
	A big tower filled with riddle rooms.

	@author Sven2, Maikel
*/


public func Initialize()
{
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
	RoomMenu->Create(crew->GetController());
	return;
}

public func OnRoomCompleted(object crew)
{
	var room_list = GetRoomList();
	var current_index = GetIndexOf(room_list, g_tower_current_room);
	current_index++;
	
	// All rooms completed: return to main.
	if (current_index >= GetLength(room_list))
		return LoadMain();
	
	// Load the next room.
	var new_room = room_list[current_index];
	new_room->LoadRoom();
	return;
}