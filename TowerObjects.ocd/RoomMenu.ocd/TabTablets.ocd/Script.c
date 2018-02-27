/**
	Room Menu: Tab Tablets
	@author Maikel
*/

public func ShowRoomMenuTablets(int plr)
{
	this->CloseRoomMenu();
	var menu_obj = CreateObject(RoomMenu, 0, 0, plr);
	menu_obj->OpenRoomMenu(plr, "tablets");
	return;
}

public func MakeTabletsMenu(proplist menu, int plr)
{
	// The basic panels for the menu.
	menu.tabletdesc = 
	{
		Target = this,
		ID = 1,
		Right = "70%",
		Bottom = "2em",
		BackgroundColor = ROOMMENU_Color_Area1,
		text = 
		{
			Margin = ["0.2em"],	
			Text = "$RoomMenuTabletsText$",
			Style = GUI_TextVCenter,
		}
	};
	menu.tabletlist = 
	{
		Target = this,
		ID = 2,
		Top = "2em",
		Bottom = "80%",
		Style = GUI_GridLayout,
		BackgroundColor = ROOMMENU_Color_Area2
	};
	menu.tabletinfo = 
	{
		Target = this,
		ID = 4,
		Top = "80%",
		BackgroundColor = ROOMMENU_Color_Area3
	};
	
	menu.tabletlist = MenuShowRoomTablets(menu.tabletlist, plr);
	return;
}

public func MenuShowRoomTablets(proplist tablets, int plr)
{
	var cnt = 0;
	for (var room in GetRoomList())
	{
		var tablet_symbol = nil;
		var room_part = nil;
		var tablet_found = false;
		if (HasPlayerFoundTablet(plr, room))
		{
			tablet_symbol = AncientTablet;
			room_part = 
			{
				Left = "1.5em",
				Top = "1.5em",
				Symbol = room
			};
			tablet_found = true;
		}
		var tablet =
		{
			Target = this,
			ID = cnt + 1000,
			Priority = cnt,
			Right = "3em",
			Bottom = "3em",
			Symbol = tablet_symbol,
			BackgroundColor = {Std = 0, Hover = ROOMMENU_Color_Hover},
			OnMouseIn = GuiAction_SetTag("Hover"),
			OnMouseOut = GuiAction_SetTag("Std"),
			OnClick = GuiAction_Call(this, "UpdateTabletSelectionInformation", [room, tablet_found]),
			room_symbol = room_part
		};
		this->MakeNumberMenuEntry(tablet, cnt + 1);
		tablets[Format("room%d", cnt)] = tablet;		
		cnt++;
	}
	return tablets;
}

public func UpdateTabletSelectionInformation(array pars)
{
	var room = pars[0];
	var found = pars[1];
	var text = Format("$RoomMenuTabletsNotFound$", room->GetRoomName());
	if (found)
		text = Format("$RoomMenuTabletsFound$", room->GetRoomName(), AncientTablet->GetTabletCode(room->GetRoomID()));

	var menu = this->GetMenu();
	var menu_id = this->GetMenuID();

	menu.tabletinfo.tablet =
	{
		Target = this,
		ID = 41,
		Margin = ["0.2em"],
		Text = text
	};	
	GuiUpdate(menu.tabletinfo, menu_id, menu.tabletinfo.ID, this);
	return;
}