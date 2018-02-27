/**
	Room Menu
	Lets the player select the next room to attempt.

	The different menu parts can be selected by buttons. While 
	in the different submenus areas are separated by colors.
	
	@author Maikel
*/


#include RoomMenu_TabRooms
#include RoomMenu_TabTablets
#include RoomMenu_TabCredits
#include RoomMenu_TabInfo


static const ROOMMENU_Color_Bkg = -16777216; // RGB(0, 0, 0)
static const ROOMMENU_Color_Hover = -2139062144; // RGBa(128, 128, 128, 128)
static const ROOMMENU_Color_Buttons = -13631488; // RGB(48, 0, 0)
static const ROOMMENU_Color_Area1 = -16764928; // RGB(0, 48, 0)
static const ROOMMENU_Color_Area2 = -16777168; // RGB(0, 0, 48)
static const ROOMMENU_Color_Area3 = -13619200; // RGB(48, 48, 0)
static const ROOMMENU_Color_Area4 = -13631440; // RGB(48, 0, 48)
static const ROOMMENU_Color_Area5 = -16764880; // RGB(0, 48, 48)

// Variables to keep track of whom is controlling the menu.
local menu, menu_id, menu_controller, menu_type;


// Creates the room menu for the given player.
public func Create(int plr)
{
	// Safety: is a definition call.
	if (this != RoomMenu)
		return;	
	var menu_obj = CreateObject(RoomMenu, 0, 0, plr);
	menu_obj->OpenRoomMenu(plr, "rooms");
	return menu_obj;
}

public func OpenRoomMenu(int plr, string new_menu_type, proplist selection)
{
	// Needs the cursor as command object.
	var clonk = GetCursor(plr);
	
	// If the menu is already open, don't open another instance.
	if (clonk->GetMenu() && menu_id != nil && clonk->GetMenu().ID == menu_id)
		return;
		
	// This object functions as menu target and for visibility.
	this.Visibility = VIS_Owner;
	menu_controller = clonk;

	// Basic menu proplist.
	menu =
	{
		Target = this,
		Decoration = GUI_MenuDeco,
		Margin = ["1em", "2em"],
		BackgroundColor = ROOMMENU_Color_Bkg,
	};
	
	// Make the room/credits/tablet/info menu.
	menu_type = new_menu_type;
	if (menu_type == "rooms")
		this->MakeRoomMenu(menu, plr, selection);
	else if (menu_type == "credits")
		this->MakeCreditsMenu(menu, plr);
	else if	(menu_type == "tablets")
		this->MakeTabletsMenu(menu, plr);
	else if	(menu_type == "information")
		this->MakeInformationMenu(menu, plr);
	
	// Tab selection: header with tabs and close button.
	menu.buttons = this->CreateMenuButtons(plr, menu_type); 
	
	// Open the menu and store the menu ID.
	menu_id = GuiOpen(menu);
	// Notify the clonk and set the menu.
	clonk->SetMenu(this);
	return;
}

// Returns the menu type currently opened for this menu.
public func GetMenuType() { return menu_type; }

public func GetMenu() { return menu; }

public func GetMenuID() { return menu_id; }


/*-- Player Control --*/

// Called then the player hits a control with RoomMenu as spec_id, in this case CON_RoomMenu.
public func ForwardedPlayerControl(int plr, int ctrl, int x, int y, int strength, bool repeat, bool release)
{
	if (release)
		return;
	if (ctrl == CON_RoomMenu)
	{
		if (RoomMenu->HasPlrRoomMenuOpen(plr))
		{
			RoomMenu->ClosePlrRoomMenu(plr);
		}
		else
		{
			if (RoomMenu->CanPlrRoomMenuOpen(plr))
			{
				RoomMenu->OpenPlrRoomMenu(plr);
			}
			else
			{
				var cursor = GetCursor(plr);
				if (cursor)
					cursor->PlayerMessage(plr, "$RoomMenuUnableToOpen$");
			}	
		}
	}
	return;
}

// Definition call: opens the room menu for the player.
public func OpenPlrRoomMenu(int plr)
{
	var cursor = GetCursor(plr);
	if (!cursor)
		return false;
	RoomMenu->Create(plr);	
	return;
}

// Definition call: closes the room menu for the player.
public func ClosePlrRoomMenu(int plr)
{
	var cursor = GetCursor(plr);
	if (!cursor)
		return false;
	var plr_menu = cursor->GetMenu();
	if (!plr_menu || !plr_menu->~IsRoomMenu())
		return;
	plr_menu->CloseRoomMenu();
	return;
}

// Definition call: tells whether the player has a room menu open.
public func HasPlrRoomMenuOpen(int plr)
{
	var cursor = GetCursor(plr);
	if (!cursor)
		return false;
	var plr_menu = cursor->GetMenu();
	return plr_menu && plr_menu->~IsRoomMenu();
}

// Definition call: tells whether the player is allowed to open a room menu.
public func CanPlrRoomMenuOpen(int plr)
{
	var cursor = GetCursor(plr);
	if (!cursor)
		return false;
	// Not allowed if not yet entered the tower entrance.
	if (GetCurrentRoom() == nil)
	{
		var entrance = cursor->Contained();
		return entrance && entrance->GetID() == RoomEntrance;
	}	
	return true;
}


/*-- Updating --*/

global func UpdateRoomMenus(string to_update)
{
	for (var plr in GetPlayers(C4PT_User))
	{
		// Check if the cursor has a room menu open.
		var cursor = GetCursor(plr);
		if (!cursor)
			continue;
		var plr_menu = cursor->GetMenu();
		if (!plr_menu || !plr_menu->~IsRoomMenu())
			continue;
		// Check if updating is needed for this menu type.
		if (to_update != nil && to_update != plr_menu->GetMenuType())
			continue;
		plr_menu->UpdateMenu();
	}
	return;
}

public func IsRoomMenu() { return true; }

public func UpdateMenu()
{
	// Get information about currently open menu.
	var plr = menu_controller->GetOwner();
	var type = GetMenuType();
	var selection = { pre_select_room = menu.selinfo.currently_selected_room };
	// Close current menu.
	CloseRoomMenu();
	// Open new menu with old information.
	var menu_obj = CreateObject(RoomMenu, 0, 0, plr);
	menu_obj->OpenRoomMenu(plr, type, selection);
	return;
}


/*-- Closing --*/

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


/*-- Saving --*/

// UI not saved.
public func SaveScenarioObject() { return false; }


/*-- Misc Functionality --*/

private func CreateMenuButtons(int plr, string current_menu)
{
	var buttons =
	{
		Target = this,
		BackgroundColor = ROOMMENU_Color_Buttons,
		ID = 9,
		Left = "70%",
		Bottom = "2em"
	};
	buttons.close = 
	{
		Target = this,
		ID = 91,
		Left = "100%-2em",
		Symbol = Icon_Cancel,
		Tooltip = "$RoomMenuClose$",
		BackgroundColor = {Std = 0, Hover = ROOMMENU_Color_Hover},
		OnMouseIn = GuiAction_SetTag("Hover"),
		OnMouseOut = GuiAction_SetTag("Std"),
		OnClick = GuiAction_Call(this, "CloseRoomMenu")
	};
	var room_def = GetCurrentRoom();
	if (room_def == nil)
	{
		var index = 0, r;
		var rooms = [];
		while (r = GetDefinition(index++))
			if (r->~IsRoom() && r != RoomBase)
				 PushBack(rooms, r);
		room_def = RandomElement(rooms);
	}
	buttons.rooms = 
	{
		Target = this,
		ID = 92,
		Left = "100%-4em",
		Right = "100%-2em",
		Symbol = room_def,
		Tooltip = "$RoomMenuBackToRooms$",
		BackgroundColor = {Std = 0, Hover = ROOMMENU_Color_Hover},
		OnMouseIn = GuiAction_SetTag("Hover"),
		OnMouseOut = GuiAction_SetTag("Std"),
		OnClick = GuiAction_Call(this, "ShowRoomMenuRooms", plr)
	};
	buttons.credits = 
	{
		Target = this,
		ID = 93,
		Left = "100%-6em",
		Right = "100%-4em",
		Symbol = Icon_Wealth,
		Tooltip = "$RoomMenuCredits$",
		BackgroundColor = {Std = 0, Hover = ROOMMENU_Color_Hover},
		OnMouseIn = GuiAction_SetTag("Hover"),
		OnMouseOut = GuiAction_SetTag("Std"),
		OnClick = GuiAction_Call(this, "ShowRoomMenuCredits", plr)
	};
	buttons.tablets = 
	{
		Target = this,
		ID = 94,
		Left = "100%-8em",
		Right = "100%-6em",
		Symbol = AncientTablet,
		Tooltip = "$RoomMenuTablets$",
		BackgroundColor = {Std = 0, Hover = ROOMMENU_Color_Hover},
		OnMouseIn = GuiAction_SetTag("Hover"),
		OnMouseOut = GuiAction_SetTag("Std"),
		OnClick = GuiAction_Call(this, "ShowRoomMenuTablets", plr)
	};
	buttons.information = 
	{
		Target = this,
		ID = 95,
		Left = "100%-10em",
		Right = "100%-8em",
		Symbol = Icon_QuestionMark,
		Tooltip = "$RoomMenuInformation$",
		BackgroundColor = {Std = 0, Hover = ROOMMENU_Color_Hover},
		OnMouseIn = GuiAction_SetTag("Hover"),
		OnMouseOut = GuiAction_SetTag("Std"),
		OnClick = GuiAction_Call(this, "ShowRoomMenuInformation", plr)
	};
	return buttons;
}

private func CreateBarMenuEntry(string left, string right, string top, string bottom)
{
	return
	{
		Left = left,
		Right = right,
		Top = top,
		Bottom = bottom
	};
}

// Adds a number to an existing menu entry, the size is specified in percent of the parent.
// This means that the height of a number will be adjusted to the total size of the parent.
// The position is also in percentage relative to the top-left corner of the parent.
private func MakeNumberMenuEntry(proplist parent, int number, int size, array position)
{
	// Default settings.
	if (size == nil)
		size = 33;
	if (position == nil)
		position = [0, 0];
	var pos_x = position[0];
	var pos_y = position[1];
	// Get the digits.
	var hundreds = (number % 1000) / 100;
	var tens = (number % 100) / 10;
	var ones = number % 10;
	// Positioning variables.	
	var off_edge = 6;
	var overlap = 16;
	var separator = 0;
	
	if (hundreds)
	{
		parent.hundreds = 
		{
			Left = Format("%d%%", pos_x - off_edge),
			Right = Format("%d%%", pos_x + separator - off_edge + size),
			Top = Format("%d%%", pos_y),
			Bottom = Format("%d%%", pos_y + size),
			Symbol = Icon_Number,
			GraphicsName = Format("%d", hundreds)
		};
		separator += size - overlap;
	}
	if (tens)
	{
		parent.tens = 
		{
			Left = Format("%d%%", pos_x + separator - off_edge),
			Right = Format("%d%%", pos_x + separator - off_edge + size),	
			Top = Format("%d%%", pos_y),
			Bottom = Format("%d%%", pos_y + size),
			Symbol = Icon_Number,
			GraphicsName = Format("%d", tens)
		};
		separator += size - overlap;
	}
	parent.ones = 
	{
		Left = Format("%d%%", pos_x + separator - off_edge),
		Right = Format("%d%%", pos_x + separator  - off_edge + size),
		Top = Format("%d%%", pos_y),
		Bottom = Format("%d%%", pos_y + size),
		Symbol = Icon_Number,
		GraphicsName = Format("%d", ones)
	};
	return;
}


/*-- Proplist --*/

local Name = "$Name$";
local Description = "$Description$";
