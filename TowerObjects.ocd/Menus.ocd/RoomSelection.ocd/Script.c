/**
	Room Menu
	Let's the player pick the next room to attempt.
	
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
	
	// Medal menu proplist.
	menu =
	{
		Target = this,
		Decoration = GUI_MenuDeco,
		Margin = ["1em", "2em"],
		BackgroundColor = {Std = ROOMMENU_BackgroundColor},
	};
	// A header showing the contents of this menu and close button.
	menu.header = 
	{
		Target = this,
		ID = 1,
		Bottom = "1.5em",
		header_text = 
		{
			Target = this,
			ID = 2,
			Right = "100%-3em",
			Text = "$RoomMenuCaption$",
		},
		header_close = 
		{
			Target = this,
			ID = 5,
			Left = "100%-1.5em",
			Right = "100%",
			Bottom = "1.5em",
			Symbol = Icon_Cancel,
			Tooltip = "$RoomMenuClose$",
			BackgroundColor = {Std = 0, Hover = ROOMMENU_HoverColor},
			OnMouseIn = GuiAction_SetTag("Hover"),
			OnMouseOut = GuiAction_SetTag("Std"),
			OnClick = GuiAction_Call(this, "CloseRoomMenu")
		}
	};
	
	var rooms = 
	{
		Top = "1.5em",
		Left = "70%",
		Style = GUI_VerticalLayout,
		BackgroundColor = {Std = ROOMMENU_BackgroundColor},
	};
	menu.rooms = MenuShowRooms(rooms, plr);
	// Menu ID.
	menu_id = GuiOpen(menu);
	// Notify the clonk and set the menu to be uncloseable.
	clonk->SetMenu(this);
	return;
}

public func MenuShowRooms(proplist rooms, int plr)
{
	// Show all the active medals in this round.
	var room_list = GetRoomList();
	var cnt = 0;
	for (var room_id in room_list)
	{
		var room =
		{
			Target = this,
			ID = cnt + 1000,
			Priority = cnt,
			Bottom = "1.5em",
			BackgroundColor = {Std = 0, Hover = ROOMMENU_HoverColor},
			OnMouseIn = [GuiAction_SetTag("Hover"), GuiAction_Call(this, "OnRoomHoverIn", room_id)],
			OnMouseOut = [GuiAction_SetTag("Std"), GuiAction_Call(this, "OnRoomHoverOut", room_id)],
			OnClick = GuiAction_Call(this, "OnRoomClick", room_id),
			symbol = 
			{
				Right = "1.5em",
				Symbol = room_id
			},
			text = 
			{
				Left = "1.5em",
				Text = room_id->GetRoomName()			
			}
		};
		rooms[Format("room%d", cnt)] = room;		
		cnt++;
	}
	return rooms;
}

public func OnRoomHoverIn(id room_id)
{

	return;
}

public func OnRoomHoverOut(id room_id)
{

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