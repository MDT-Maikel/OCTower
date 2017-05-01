// Several functions which are useful in the template scenario.

// This function is called from the template scenario and all its derivatives.
global func InitializeTemplate()
{
	// Create room control object and warn if there exist multiple.
	var def, index, room_def;
	while (def = GetDefinition(++index))
	{
		if (def->~IsRoom() && def != RoomBase)
		{
			if (!room_def)
				room_def = def;
			else
				Log("$MsgWarningMultipleRoomDefinitions$", def, room_def);
		}
	}
	if (room_def)
	{
		var room_control = CreateObject(room_def);
		room_control->InitRoom();
	}
	else
	{
		Log("$MsgWarningNoRoomDefinition$");
	}
	
	// Create basic rules, but do not save them in a scenario.
	var relaunch_rule = GetRelaunchRule();
	relaunch_rule->SetAllowPlayerRestart(true);
	relaunch_rule->SetPerformRestart(false);
	relaunch_rule.SaveScenarioObject = Global.NoSave;
	return;
}

// To prevent certain objects from being saved for a room.
global func NoSave() { return false; }

// Run in the template scenario to check all settings.
global func TestRoom(bool no_logging)
{
	// Find room object and test the settings.
	var def, index, room_def;
	while (def = GetDefinition(++index))
	{
		if (def->~IsRoom() && def != RoomBase)
		{
			room_def = def;
			break;		
		}
	}
	
	// Log room properties.
	if (!no_logging)
	{
		Log("$MsgRoomHasName$", room_def->GetRoomName());
		Log("$MsgRoomHasDescription$", room_def->GetRoomDescription());
		Log("$MsgRoomHasAuthor$", room_def->GetRoomAuthor());
	}
	
	// Check the number of room entrances.
	if (ObjectCount(Find_ID(RoomEntrance)) == 0)
		Log("$MsgWarningNoEntrances$");
	else if (ObjectCount(Find_ID(RoomEntrance)) > 1)
		Log("$MsgWarningTooManyEntrances$");
		
	// Check the number of room exits.
	if (ObjectCount(Find_ID(RoomExit)) == 0)
		Log("$MsgWarningNoExits$");
	else if (ObjectCount(Find_ID(RoomExit)) > 1)
		Log("$MsgWarningTooManyExits$");

	// Check if the author has added a tablet both in the room and the settings.
	var tablet_cnt = ObjectCount(Find_ID(AncientTablet));
	var has_tablet = room_def->HasTablet();
	if (tablet_cnt > 1)
		Log("$MsgWarningTooManyTablets$", tablet_cnt);
	else if (tablet_cnt > 0 && !has_tablet)
		Log("$MsgWarningTabletFoundNotControl$", tablet_cnt);
	else if (tablet_cnt == 0 && has_tablet)
		Log("$MsgWarningNoTabletFound$", tablet_cnt);

	// Check if the author has added a joker both in the room and the settings.
	var joker_cnt = ObjectCount(Find_ID(Joker));
	var has_joker = room_def->HasJoker();
	if (joker_cnt > 1)
		Log("$MsgWarningTooManyJokers$", joker_cnt);
	else if (joker_cnt > 0 && !has_joker)
		Log("$MsgWarningJokerFoundNotControl$", joker_cnt);
	else if (joker_cnt == 0 && has_joker)
		Log("$MsgWarningNoJokerFound$", joker_cnt);
	return;
}

// Called from the engine when a scenario is saved.
global func SaveScenarioObjects(f, duplicate_objects)
{
	// Display problems with the current room when saving it.
	if (GameCall("IsTemplateRoom"))
		TestRoom(true);
	return _inherited(f, duplicate_objects, ...);
}

