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
				Log("WARNING: Multiple room control definitions found (%i), creating first found %i", def, room_def);
		}
	}
	if (room_def)
	{
		var room_control = CreateObject(room_def);
		room_control->InitRoom();
	}
	else
	{
		Log("WARNING: No room control definition found.");
	}
	
	// Create basic rules.
	var rule_restart = CreateObject(Rule_Restart);
	rule_restart.SaveScenarioObject = Global.NoSave;
	return;
}

// To prevent certain objects from being saved for a room.
global func NoSave() { return true; }

// Run in the template scenario to check all settings.
global func TestRoom()
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
	Log("Your room has name: %s", room_def->GetRoomName());
	Log("Your room has description: %s", room_def->GetRoomDescription());
	Log("Your room has author: %s", room_def->GetRoomAuthor());
	
	// Check if the author has added a joker both in the room and the settings.
	// TODO
	
	// Check the number of room entrances.
	if (ObjectCount(Find_ID(RoomEntrance)) == 0)
		Log("WARNING: Room has no entrances, create one.");
	else if (ObjectCount(Find_ID(RoomEntrance)) > 1)
		Log("WARNING: Room has more than one entrances, remove the superfluous ones.");
		
	// Check the number of room exits.
	if (ObjectCount(Find_ID(RoomExit)) == 0)
		Log("WARNING: Room has no exits, create one.");
	else if (ObjectCount(Find_ID(RoomExit)) > 1)
		Log("WARNING: Room has more than one exits, remove the superfluous ones.");
	return;
}