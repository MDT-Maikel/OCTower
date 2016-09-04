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

public func OnRoomCompleted(object crew, id room)
{
	// Add this room to the player's completion list.
	AddPlayerCompletedRoom(crew->GetOwner(), room);
	
	// Get the next room and load that.
	var next_room = GetNextRoom(room);
	if (next_room)
		return next_room->LoadRoom();

	// Load main if no next room is found.		
	return LoadMain();
}