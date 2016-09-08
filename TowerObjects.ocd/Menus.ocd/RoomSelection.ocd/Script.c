/**
	Room Menu
	Let's the player select the next room to attempt.
	
	@author Maikel
*/

// Background colors for hovering and bars and description.
static const ROOMMENU_BackgroundColor = 0x77000000;
static const ROOMMENU_HoverColor = 0x99888888;
static const ROOMMENU_BarColor = 0x99888888;

local menu, menu_id, menu_controller;


protected func Initialize()
{

	return;
}

// Creates the room menu for the given player.
public func Create(int plr)
{
	// Safety: is a definition call.
	if (this != RoomMenu)
		return;	
	var menu_obj = CreateObject(RoomMenu, 0, 0, plr);
	menu_obj->OpenRoomMenu(plr);
	return menu_obj;
}


/*-- Room Menu --*/

public func OpenRoomMenu(int plr)
{
	// Needs the cursor as command object.
	var clonk = GetCursor(plr);
	
	// If the menu is already open, don't open another instance.
	if (clonk->GetMenu() && clonk->GetMenu().ID == menu_id)
		return;
		
	// This object functions as menu target and for visibility.
	this.Visibility = VIS_Owner;
	menu_controller = clonk;
	
	// Room menu proplist.
	menu =
	{
		Target = this,
		Decoration = GUI_MenuDeco,
		Margin = ["1em", "2em"],
		BackgroundColor = {Std = ROOMMENU_BackgroundColor},
	};
	// The three basic panels for the menu.
	menu.roominfo = 
	{
		Target = this,
		ID = 1,
		Right = "70%-0.5em",
		Bottom = "40%-0.5em",
		Margin = ["0.1em"]
	};
	menu.roomsel = 
	{
		Target = this,
		ID = 2,
		Left = "70%",
		Margin = ["0.1em"]
	};
	menu.selinfo = 
	{
		Target = this,
		ID = 3,
		Right = "70%",
		Top = "40%",
		Margin = ["0.1em"]
	};
	// Make the borders between the submenus.
	menu.vert_border =
	{
		Target = this,
		ID = 4,
		Left = "70%-0.5em",
		Right = "70%",
		BackgroundColor = {Std = ROOMMENU_BarColor},
	};
	menu.hor_border =
	{
		Target = this,
		ID = 5,
		Right = "70%-0.5em",
		Top = "40%-0.5em",
		Bottom = "40%",
		BackgroundColor = {Std = ROOMMENU_BarColor},
	};
	
	// Display info on current room.
	GetCurrentRoomInfo(menu.roominfo);
	
	// Room selection: header with close button.
	menu.roomsel.header = 
	{
		Target = this,
		ID = 21,
		Bottom = "1.5em",
		header_text = 
		{
			Target = this,
			ID = 22,
			Right = "100%-1.5em",
			Text = "$RoomMenuSelectRoom$",
			Style = GUI_TextVCenter
		},
		header_close = 
		{
			Target = this,
			ID = 23,
			Left = "100%-1.5em",
			Symbol = Icon_Cancel,
			Tooltip = "$RoomMenuClose$",
			BackgroundColor = {Std = 0, Hover = ROOMMENU_HoverColor},
			OnMouseIn = GuiAction_SetTag("Hover"),
			OnMouseOut = GuiAction_SetTag("Std"),
			OnClick = GuiAction_Call(this, "CloseRoomMenu")
		}	
	};
	// Room selection: add a list of available rooms.
	var rooms = 
	{
		Top = "1.5em",
		Style = GUI_VerticalLayout,
		BackgroundColor = {Std = ROOMMENU_BackgroundColor},
	};
	menu.roomsel.rooms = MenuShowRooms(rooms, plr);
	
	// Open the menu and store the menu ID.
	menu_id = GuiOpen(menu);
	// Notify the clonk and set the menu.
	clonk->SetMenu(this);
	return;
}

public func GetCurrentRoomInfo(proplist roominfo)
{
	var current_room = GetCurrentRoom();
	if (!current_room)
	{
		roominfo.lobby =
		{
			Bottom = "1.5em",
			Text = "$RoomMenuInLobby$",
			Style = GUI_TextVCenter	
		};
	}
	else
	{
		roominfo.roomname =
		{
			Bottom = "1.5em",
			Text = Format("$RoomMenuInRoom$", current_room->GetRoomName()),
			Style = GUI_TextVCenter	
		};	
	}
	return;
}

public func MenuShowRooms(proplist rooms, int plr)
{
	// Show all the active medals in this round.
	var room_list = SortRoomList(GetPlayerCompletedRooms(plr));
	var next_room = GetPlayerNextOpenRoom(plr);
	if (next_room)
		PushBack(room_list, next_room);
	SortRoomList(room_list);
	// Put all rooms into the selection menu.
	var cnt = 0;
	for (var room_id in room_list)
	{
		var room_completed = nil;
		if (HasPlayerCompletedRoom(plr, room_id))
			room_completed = Icon_Ok;
		var room =
		{
			Target = this,
			ID = cnt + 1000,
			Priority = cnt,
			Bottom = "1.5em",
			BackgroundColor = {Std = 0, Hover = ROOMMENU_HoverColor},
			OnMouseIn = [GuiAction_SetTag("Hover"), GuiAction_Call(this, "OnRoomHoverIn", {plr = plr, room_id = room_id})],
			OnMouseOut = [GuiAction_SetTag("Std"), GuiAction_Call(this, "OnRoomHoverOut", {plr = plr, room_id = room_id})],
			OnClick = GuiAction_Call(this, "OnRoomClick", room_id),
			symbol = 
			{
				Target = this,
				ID = cnt + 2000,
				Right = "1.5em",
				Symbol = room_id,
				completed = 
				{
					Target = this,
					ID = cnt + 3000,
					Left = "50%",
					Top = "50%",
					Symbol = room_completed				
				}
			},
			text = 
			{
				Target = this,
				ID = cnt + 4000,
				Left = "1.5em",
				Text = room_id->GetRoomName(),
				Style = GUI_TextVCenter
			}
		};
		MakeNumberMenuEntry(room.symbol, GetRoomNumber(room_id));
		rooms[Format("room%d", cnt)] = room;		
		cnt++;
	}
	return rooms;
}

public func MakeNumberMenuEntry(proplist parent, int number)
{
	var hundreds = (number % 1000) / 100;
	var tens = (number % 100) / 10;
	var ones = number % 10;
	var separator = 0;
	if (hundreds)
	{
		parent.hundreds = 
		{
			Target = this,
			ID = Random(500000),
			Right = Format("%d%%", separator + 33),
			Bottom = "33%",
			Symbol = Icon_Number,
			GraphicsName = Format("%d", hundreds)
		};
		separator += 33;
	}
	if (tens)
	{
		parent.tens = 
		{
			Target = this,
			ID = Random(500000),
			Left = Format("%d%%", separator),
			Right = Format("%d%%", separator + 33),
			Bottom = "33%",
			Symbol = Icon_Number,
			GraphicsName = Format("%d", tens)
		};
		separator += 33;
	}
	parent.ones = 
	{
		Target = this,
		ID = Random(500000),
		Left = Format("%d%%", separator),
		Right = Format("%d%%", separator + 33),
		Bottom = "33%",
		Symbol = Icon_Number,
		GraphicsName = Format("%d", ones)
	};
	return;
}

public func OnRoomHoverIn(proplist pars)
{
	UpdateRoomSelectionInformation(pars.plr, pars.room_id);
	return;
}

public func OnRoomHoverOut(proplist pars)
{
	UpdateRoomSelectionInformation(pars.plr, nil);
	return;
}

public func UpdateRoomSelectionInformation(int plr, id room_id)
{
	if (room_id == nil)
	{
		if (menu.selinfo.room != nil)
		{
			GuiClose(menu_id, menu.selinfo.room.ID, menu.selinfo.room.Target);
			menu.selinfo.room = nil;
		}
		return;	
	}
	var room_completed = nil;
	if (HasPlayerCompletedRoom(plr, room_id))
		room_completed = Icon_Ok;
	menu.selinfo.room =
	{
		Target = this,
		ID = 31,
		icon =
		{
			Target = this,
			ID = 32,
			Right = "3em",
			Bottom = "3em",
			Symbol = room_id,
			completed = 
			{
				Target = this,
				ID = 33,
				Left = "50%",
				Top = "50%",
				Symbol = room_completed				
			}
		},
		name = 
		{
			Target = this,
			ID = 35,
			Left = "3em",
			Bottom = "1.5em",
			Style = GUI_TextVCenter,
			Text = Format("$RoomMenuInfoRoom$", room_id->GetRoomName())
		},
		author = 
		{
			Target = this,
			ID = 36,
			Left = "3em",
			Top = "1.5em",
			Bottom = "3em",
			Style = GUI_TextVCenter,
			Text = Format("$RoomMenuInfoAuthor$", room_id->GetRoomAuthor())
		},
		desc =
		{
			Target = this,
			ID = 37,
			Top = "3em",
			Bottom = "6em",
			Text = Format("$RoomMenuInfoDescription$", room_id->GetRoomDescription())
		}
	};
	MakeNumberMenuEntry(menu.selinfo.room.icon, GetRoomNumber(room_id));
	GuiUpdate(menu.selinfo, menu_id, menu.selinfo.ID, this);
	return;
}

public func OnRoomClick(id room_id)
{
	CloseRoomMenu();
	LoadRoom(room_id);
	return;
}

public func CloseRoomMenu()
{
	// Close the menu and inform the controller.
	GuiClose(menu_id, nil, this);
	menu_id = nil;
	if (menu_controller)
		menu_controller->MenuClosed();
	menu_controller = nil;
	return;
}

public func Close() { return RemoveObject(); }


// UI not saved.
public func SaveScenarioObject() { return false; }


/*-- Proplist --*/

local Name = "$Name$";
local Description = "$Description$";