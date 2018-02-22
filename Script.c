/**
	Tower of Despair
	A big tower filled with riddle rooms.

	@author Sven2, Maikel
*/


public func Initialize()
{
	// Gather statistics.
	CreateObject(Statistics_TowerData);
	CreateObject(Statistics_RoomDuration);
	CreateObject(Statistics_RoomAttempts);
	CreateObject(Statistics_RoomRating);
	return;
}

public func InitializePlayer(int plr)
{
	// Init the room data for this player from the saved data.
	InitPlayerRoomData(plr);
	// Join the player with its crew.
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
	
	// Move clonk to position outside the tower.
	crew->SetPosition(40 + RandomX(80), 350);
	// Move directly to entrance in editor mode.
	if (IsEditor())
		crew->SetPosition(596, 294);
	crew->SetDir(DIR_Right);
	
	// Add the player to the playing queue.
	AppendPlayerToQueue(plr);
	return;
}

public func RemovePlayer(int plr)
{
	if (GetPlayerCount(C4PT_User) <= 1)
		return GameOver();
	return;
}

public func OnGameOver()
{
	HideSettlementScoreInEvaluation(true);
	AddEvaluationData("$MsgEvaluationData$", 0);
}

public func InitMain()
{
	SetCurrentRoom(nil);
	for (var plr in GetPlayers())
		JoinPlayer(plr);
	return;
}

public func OnRoomEntranceEntered(object crew)
{
	// Only open room menu if entering the tower.
	if (GetCurrentRoom() == nil)
		RoomMenu->Create(crew->GetController());
	return;
}

public func OnRoomJokerCollected(object crew, object joker)
{
	// Message for all players that the joker has been collected.
	if (GetPlayerType(crew->GetOwner()) == C4PT_User)
		CustomMessage("$MsgJokerCollected$", nil, NO_OWNER, 90, 70, 0xffffff, GUI_MenuDeco, {Source = Joker});
	return;
}

public func OnRoomJokerCompleted(object crew, id room)
{
	// Share the progress among all playing players.
	for (var for_plr in GetPlayers(C4PT_User))
	{
		// Add the joker of this room to the player's completion list.
		AddPlayerFoundJoker(for_plr, room);
		// Save the progress.
		SavePlayerRoomData(for_plr);
	}
	// Message for all players that the joker is available.
	var menu_key = GetPlayerControlAssignment(crew->GetOwner(), CON_RoomMenu, true, true);
	var msg = Format("$MsgJokerSecured$", menu_key);
	CustomMessage(msg, nil, NO_OWNER, 90, 70, 0xffffff, GUI_MenuDeco, {Source = Joker});
	return;
}

public func OnRoomTabletCollected(object crew, object tablet)
{
	// Message for all players that the tablet has been collected.
	if (GetPlayerType(crew->GetOwner()) == C4PT_User)
		CustomMessage("$MsgTabletCollected$", nil, NO_OWNER, 90, 70, 0xffffff, GUI_MenuDeco, {Source = AncientTablet});
	return;
}

public func OnRoomTabletCompleted(object crew, id room)
{
	// Share the progress among all playing players.
	for (var for_plr in GetPlayers(C4PT_User))
	{
		// Add the tablet of this room to the player's completion list.
		AddPlayerFoundTablet(for_plr, room);
		// Save the progress.
		SavePlayerRoomData(for_plr);
	}
	// Message for all players that the tablet is available.
	var menu_key = GetPlayerControlAssignment(crew->GetOwner(), CON_RoomMenu, true, true);
	var msg = Format("$MsgTabletSecured$", menu_key);
	CustomMessage(msg, nil, NO_OWNER, 90, 70, 0xffffff, GUI_MenuDeco, {Source = AncientTablet});
	return;
}

public func OnRoomCompleted(object crew, id room)
{
	var plr = crew->GetOwner();
	// Share the progress among all playing players.
	for (var for_plr in GetPlayers(C4PT_User))
	{
		// Add this room to the player's completion list.
		AddPlayerCompletedRoom(for_plr, room);
		// Remove a possible used joker for this room.
		RemovePlayerUsedJoker(for_plr, room);
		// Save the progress.
		SavePlayerRoomData(for_plr);
	}
	
	// Append player to the end of playing queue.	
	AppendPlayerToQueue(plr);
	
	// Get the next room and load that.
	var next_room = GetNextRoom(room);
	if (next_room)
		return next_room->LoadRoom();

	// Load main if no next room is found.		
	return LoadMain();
}
