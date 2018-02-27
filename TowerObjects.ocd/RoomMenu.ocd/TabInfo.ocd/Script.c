/**
	Room Menu: Tab Info
	@author Maikel
*/

public func ShowRoomMenuInformation(int plr)
{
	this->CloseRoomMenu();
	var menu_obj = CreateObject(RoomMenu, 0, 0, plr);
	menu_obj->OpenRoomMenu(plr, "information");
	return;
}

public func MakeInformationMenu(proplist menu, int plr)
{
	// The basic panels for the menu.
	menu.informationdesc = 
	{
		Target = this,
		ID = 1,
		Right = "70%",
		Bottom = "2em",
		BackgroundColor = ROOMMENU_Color_Area1,
		text = 
		{
			Text = "$RoomMenuInformationText$",
			Style = GUI_TextVCenter,
			Margin = ["0.2em"]
		}
	};
	menu.information = 
	{
		Target = this,
		ID = 2,
		Top = "2em",		
		Style = GUI_VerticalLayout,
		BackgroundColor = ROOMMENU_Color_Area2
	};
	AddInformationMenuEntries(menu.information);
	return;
}

public func AddInformationMenuEntries(proplist info)
{
	var info_entries = [];
	// Get room specific entries.
	var current_room = GetCurrentRoom();
	if (current_room != nil)
	{
		var hints = current_room->~GetRoomHints();
		if (hints)
			info_entries = hints;	
	}
	// Get tower entries: are there all the time.
	for (var cnt = 1; cnt <= 4; cnt++)
		PushBack(info_entries, Translate(Format("RoomMenuInformationEntry%d", cnt))); 
	// Add the entries to the list.
	var cnt = 1;	
	for (var entry in info_entries)
	{
		var prop_entry = 
		{
			Bottom = "2em",
			Priority = cnt,
			symbol = 
			{
				Right = "2em",
				Symbol = Icon_QuestionMark
			},
			text =
			{
				Left = "2em",
				Text = entry
			}
		};
		this->MakeNumberMenuEntry(prop_entry.symbol, cnt, 40);
		info[Format("entry%d", cnt)] = prop_entry;		
		cnt++;
	}
	return;
}