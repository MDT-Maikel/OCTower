/**
	Room Menu
	Lets the player select the next room to attempt.

	The different menu parts can be selected by buttons. While 
	in the different submenus areas are separated by colors.
	
	@author Maikel
*/


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
	
	// Make the room/credits/tablet menu.
	menu_type = new_menu_type;
	if (menu_type == "rooms")
		MakeRoomMenu(plr, selection);
	else if (menu_type == "credits")
		MakeCreditsMenu(plr);
	else if	(menu_type == "tablets")
		MakeTabletsMenu(plr);
	else if	(menu_type == "information")
		MakeInformationMenu(plr);
	
	// Open the menu and store the menu ID.
	menu_id = GuiOpen(menu);
	// Notify the clonk and set the menu.
	clonk->SetMenu(this);
	return;
}

// Returns the menu type currently opened for this menu.
public func GetMenuType() { return menu_type; }


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


/*-- Room Menu --*/

public func ShowRoomMenuRooms(int plr)
{
	CloseRoomMenu();
	var menu_obj = CreateObject(RoomMenu, 0, 0, plr);
	menu_obj->OpenRoomMenu(plr, "rooms");
	return;
}

public func MakeRoomMenu(int plr, proplist selection)
{
	// The basic panels for the menu.
	menu.roominfo = 
	{
		Target = this,
		ID = 1,
		Right = "70%",
		Bottom = "50%",
		BackgroundColor = ROOMMENU_Color_Area1
	};
	menu.roomsel = 
	{
		Target = this,
		ID = 3,
		Left = "70%",
		Top = "2em",
		BackgroundColor = ROOMMENU_Color_Area2
	};
	menu.selinfo = 
	{
		Target = this,
		ID = 4,
		Right = "70%",
		Top = "50%",
		BackgroundColor = ROOMMENU_Color_Area3
	};
	
	// Display info on current room.
	GetCurrentRoomInfo(menu.roominfo, plr);
	
	// Room selection: header.
	menu.roomsel.header = 
	{
		Target = this,
		ID = 31,
		Bottom = "1.5em",
		header_text = 
		{
			Target = this,
			ID = 32,
			Margin = ["0.2em"],
			Text = "$RoomMenuSelectRoom$",
			Style = GUI_TextVCenter
		}
	};
	// Buttons.
	menu.buttons = CreateMenuButtons(plr, "rooms"); 
	
	// Room selection: add a list of available rooms.
	var rooms = 
	{
		Top = "1.5em",
		Style = GUI_VerticalLayout
	};
	menu.roomsel.rooms = MenuShowRoomSelectionList(rooms, plr);

	// Pre-select a room if given.
	var for_room = nil;
	if (selection && selection.pre_select_room)
		for_room = selection.pre_select_room;
	UpdateRoomSelectionInformation({plr = plr, room_id = for_room});
	return;
}

public func GetCurrentRoomInfo(proplist roominfo, int plr)
{
	// Get lobby info text.
	var current_room = GetCurrentRoom();
	var menu_key = GetPlayerControlAssignment(plr, CON_RoomMenu, true, true);
	var room_info = Format("$RoomMenuInLobby$", menu_key);
	// Get rooms completed and jokers found.
	var nr_rooms = GetRoomCount();
	var completed = GetLength(GetPlayerCompletedRooms(plr));
	var total_jokers = GetRoomCount(true);
	var found_jokers = GetLength(GetPlayerFoundJokers(plr));
	var used_jokers = GetLength(GetPlayerUsedJokers(plr));
	var completed_info = Format("$RoomMenuRoomsCompleted$", completed - used_jokers, nr_rooms);
	var joker_info = Format("$RoomMenuJokersFound$", found_jokers, total_jokers, found_jokers - used_jokers);
	
	// Do stuff differently for outside tower or when attempting a room.
	if (current_room == nil)
	{
		// Add the lobby text to the menu.
		roominfo.info_text =
		{
			text = 
			{
				Margin = ["0.2em"],
				Text = Format("%s\n\n%s\n%s", room_info, completed_info, joker_info)
			}
		};
	}
	else
	{
		// Add current room info and progress text to the menu.
		roominfo.info_text =
		{
			Bottom = "4.4em",
			info = 
			{
				Margin = ["0.2em"],
				current_room =
				{
					Bottom = "2em",
					icon =
					{
						Right = "2em",
						Symbol = current_room
					},
					name = 
					{
						Left = "2em",
						Bottom = "1em",
						Text = Format("$RoomMenuInfoCurrentRoom$", current_room->GetRoomName())
					},
					author = 
					{
						Left = "2em",
						Top = "1em",
						Text = Format("$RoomMenuInfoAuthor$", current_room->GetRoomAuthor())
					}
				},
				text = 
				{
					Top = "2em",
					Text = Format("%s\n%s", completed_info, joker_info)
				}
			}
		};
		MakeNumberMenuEntry(roominfo.info_text.info.current_room.icon, GetRoomNumber(current_room), 40);
		// Add information about current attempt.
		roominfo.current_attempt = 
		{
			Top = "4.4em",
			BackgroundColor = ROOMMENU_Color_Area4,
			info = 
			{
				Bottom = "4.4em",
				Margin = ["0.2em"],				
				current_player = 
				{
					Bottom = "1em",
					Text = Format("$RoomMenuCurrentPlayer$", GetTaggedPlayerName(GetActivePlayer()))
				},
				player_queue =
				{
					Top = "1em",
					Bottom = "2em",
					Text = Format("$RoomMenuPlayerQueue$", GetPlayerQueueTaggedString() ?? "$RoomMenuPlayersNone$")
				},
				watch_list =
				{
					Top = "2em",
					Bottom = "3em",
					Text = Format("$RoomMenuPlayerWatchList$", GetPlayerWatchListTaggedString() ?? "$RoomMenuPlayersNone$")
				},
				attempt_votes = 
				{
					Top = "3em",
					Bottom = "4em",
					Text = Format("$RoomMenuAttemptVotes$", GetAbortVotesTaggedString() ?? "$RoomMenuPlayersNone$", RequiredAbortAttemptVoteCount())
				}
			}
		};
	
		// Add option to abandon or vote against current attempt.
		roominfo.current_attempt.buttons =
		{
			Top = "4.4em",
			Bottom = "6em"
		};
	 	if (IsActivePlayer(plr))
		{
			roominfo.current_attempt.buttons.abandon =
			{
				Right = "50%",
				BackgroundColor = {Std = 0, Hover = ROOMMENU_Color_Hover},
				OnMouseIn = GuiAction_SetTag("Hover"),
				OnMouseOut = GuiAction_SetTag("Std"),
				OnClick = GuiAction_Call(Rule_Relaunch, "Activate", plr),
				symbol = 
				{
					Right = "2em",
					Symbol = Icon_Cancel
				},
				text =
				{
					Left = "2em",	
					Text = "$RoomMenuAbandonAttempt$",
					Style = GUI_TextVCenter
				}	
			};
		}
		else
		{
			roominfo.current_attempt.buttons.abort_attempt = 
			{
				Right = "50%",
				BackgroundColor = {Std = 0, Hover = ROOMMENU_Color_Hover},
				OnMouseIn = GuiAction_SetTag("Hover"),
				OnMouseOut = GuiAction_SetTag("Std"),
				OnClick = GuiAction_Call(Global, "RegisterAbortAttemptVote", plr),
				symbol = 
				{
					Right = "2em",
					Symbol = Icon_Cancel
				},
				text =
				{
					Left = "2em",	
					Text = "$RoomMenuAbortAttemptVote$",
					Style = GUI_TextVCenter
				}	
			};
			if (HasVotedForAttemptAbortion(plr))
			{
				roominfo.current_attempt.buttons.abort_attempt.OnClick = GuiAction_Call(Global, "UnregisterAbortAttemptVote", plr);
				roominfo.current_attempt.buttons.abort_attempt.text.Text = "$RoomMenuAbortAttemptUnvote$";
			}
			roominfo.current_attempt.buttons.watchlist = 
			{
				Left = "50%",
				BackgroundColor = {Std = 0, Hover = ROOMMENU_Color_Hover},
				OnMouseIn = GuiAction_SetTag("Hover"),
				OnMouseOut = GuiAction_SetTag("Std"),
				OnClick = [GuiAction_Call(Global, "RemovePlayerFromQueue", plr), GuiAction_Call(Global, "AddPlayerToWatchList", plr)],
				symbol = 
				{
					Right = "2em",
					Symbol = Icon_Lightbulb
				},
				text =
				{
					Left = "2em",	
					Text = "$RoomMenuJoinWatchList$",
					Style = GUI_TextVCenter
				}	
			};
			if (IsPlayerOnWatchList(plr))
			{
				roominfo.current_attempt.buttons.watchlist.OnClick = [GuiAction_Call(Global, "AppendPlayerToQueue", plr), GuiAction_Call(Global, "RemovePlayerFromWatchList", plr)];
				roominfo.current_attempt.buttons.watchlist.text.Text = "$RoomMenuLeaveWatchList$";
			}
		}
	}
	return;
}

public func MenuShowRoomSelectionList(proplist rooms, int plr)
{
	// Add an option to exit the tower for currently playing player.
	if (GetCurrentRoom() != nil && IsActivePlayer(plr))
	{
		rooms.lobby =
		{
			Target = this,
			ID = 1000,
			Priority = 0,
			Bottom = "1.6em",
			BackgroundColor = {Std = 0, Hover = ROOMMENU_Color_Hover},
			OnMouseIn = GuiAction_SetTag("Hover"),
			OnMouseOut = GuiAction_SetTag("Std"),
			OnClick = GuiAction_Call(Global, "LoadMain"),
			symbol = 
			{
				Target = this,
				ID = 2000,
				Left = "0.4em",
				Right = "2.0em",
				Symbol = Icon_Exit
			},
			text = 
			{
				Target = this,
				ID = 4000,
				Left = "2.5em",
				Text = "$RoomMenuExitTower$",
				Style = GUI_TextVCenter
			}
		};
	}	
	// Show all the active rooms in this round.
	var room_list = SortRoomList(GetPlayerCompletedRooms(nil));
	var next_room = GetPlayerNextOpenRoom(nil);
	if (next_room)
		PushBack(room_list, next_room);
	SortRoomList(room_list);
	// Put all rooms into the selection menu.
	var cnt = 1;
	for (var room_id in room_list)
	{
		var room_completed = nil;
		if (HasPlayerCompletedRoom(plr, room_id))
		{
			room_completed = Icon_Ok;
			if (HasPlayerUsedJoker(plr, room_id))
				room_completed = Joker;
		}
		var room =
		{
			Target = this,
			ID = cnt + 1000,
			Priority = cnt,
			Bottom = "1.6em",
			BackgroundColor = {Std = 0, Hover = ROOMMENU_Color_Hover},
			OnMouseIn = GuiAction_SetTag("Hover"),
			OnMouseOut = GuiAction_SetTag("Std"),
			OnClick = GuiAction_Call(this, "UpdateRoomSelectionInformation", {plr = plr, room_id = room_id}),
			symbol = 
			{
				Target = this,
				ID = cnt + 2000,
				Right = "1.6em",
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
				Left = "2.5em",
				Text = room_id->GetRoomName(),
				Style = GUI_TextVCenter
			}
		};
		MakeNumberMenuEntry(room.symbol, GetRoomNumber(room_id), 40);

		// Tablet found information.
		if (room_id->HasTablet())
		{
			room.tablet = 
			{
				Target = this,
				ID = cnt + 5000,
				Left = "1.6em",
				Right = "2.4em",
				Bottom = "0.8em",
				Priority = 0,
				Symbol = AncientTablet
			};
			if (!HasPlayerFoundTablet(plr, room_id))
				room.tablet.GraphicsName = "Gray";
		}
		// Joker found information.
		if (room_id->HasJoker())
		{
			room.joker = 
			{
				Target = this,
				ID = cnt + 6000,
				Left = "1.6em",
				Right = "2.4em",
				Top = "0.8em",
				Priority = 0,
				Symbol = Joker
			};
			if (!HasPlayerFoundJoker(plr, room_id))
				room.joker.GraphicsName = "Gray";
		}
		// Rating request alert.
		if ((IsNetwork() || IsEditor()) && HasPlayerCompletedRoom(plr, room_id) && !HasPlayerUsedJoker(plr, room_id) && GetPlayerRoomRating(room_id, plr) == nil)
		{
			room.rating_alert =
			{
				Target = this,
				ID = cnt + 7000,
				Left = "1.6em",
				Right = "2.4em",
				Priority = 1,
				Symbol = Dialogue
			};
		}
		rooms[Format("room%d", cnt)] = room;		
		cnt++;
	}
	return rooms;
}

public func UpdateRoomSelectionInformation(proplist pars)
{
	var plr = pars.plr;
	var room_id = pars.room_id;
	// Set the selection info.
	menu.selinfo.currently_selected_room = room_id;
	// Reset the menu selection info.
	if (menu.selinfo.room != nil)
	{
		GuiClose(menu_id, menu.selinfo.room.ID, menu.selinfo.room.Target);
		menu.selinfo.room = nil;
	}
	// If no room is specified display a message where to select a room.
	if (room_id == nil)
	{
		menu.selinfo.room = 
		{
			Target = this,
			ID = 41,
			Margin = ["0.2em"],
			text = 
			{
				Text = "$RoomMenuSelectPanel$"
			}
		};
		GuiUpdate(menu.selinfo, menu_id, menu.selinfo.ID, this);
		return;
	}
	
	menu.selinfo.room_id = room_id;	
	var room_completed = nil;
	if (HasPlayerCompletedRoom(plr, room_id))
	{
		room_completed = Icon_Ok;
		if (HasPlayerUsedJoker(plr, room_id))
			room_completed = Joker;
	}
	menu.selinfo.room =
	{
		Target = this,
		ID = 41,
		icon =
		{
			Target = this,
			ID = 42,
			Right = "4em",
			Bottom = "4em",
			Symbol = room_id,
			completed = 
			{
				Target = this,
				ID = 43,
				Left = "50%",
				Top = "50%",
				Symbol = room_completed				
			}
		},
		name = 
		{
			Target = this,
			ID = 44,
			Left = "4em",
			Bottom = "1em",
			Style = GUI_TextVCenter,
			Text = Format("$RoomMenuInfoRoom$", room_id->GetRoomName())
		},
		author = 
		{
			Target = this,
			ID = 45,
			Left = "4em",
			Top = "1em",
			Bottom = "2em",
			Style = GUI_TextVCenter,
			Text = Format("$RoomMenuInfoAuthor$", room_id->GetRoomAuthor())
		},
		desc =
		{
			Target = this,
			ID = 46,
			Left = "4em",
			Top = "2em",
			Bottom = "4em",
			Text = Format("$RoomMenuInfoDescription$", room_id->GetRoomDescription())
		},
		options =
		{
			Target = this,
			ID = 47,
			Top = "4em",
			Style = GUI_VerticalLayout
		}
	};
	MakeNumberMenuEntry(menu.selinfo.room.icon, GetRoomNumber(room_id));
	
	// Add a play button for the active player or when not in a room.
	if (!GetCurrentRoom() || IsActivePlayer(plr))
	{
		menu.selinfo.room.options.play = 
		{
			Target = this,
			ID = 48,
			Priority = 1,
			Bottom = "2em",
			icon = 
			{
				Right = "2em",
				Symbol = Icon_Play,
				BackgroundColor = {Std = 0, Hover = ROOMMENU_Color_Hover},
				OnMouseIn = GuiAction_SetTag("Hover"),
				OnMouseOut = GuiAction_SetTag("Std"),
				OnClick = GuiAction_Call(this, "OnRoomClickPlay", room_id),
			},
			text =
			{
				Left = "2em",
				Style = GUI_TextVCenter,
				Text = "$RoomMenuInfoPlayRoom$"				
			}
		};
	}

	// Add tablet information to the room if available.
	if (room_id->HasTablet())
	{
		var tablet_text = "$RoomMenuInfoRoomHasTablet$";
		var tablet_completed = nil;
		if (HasPlayerFoundTablet(plr, room_id))
		{
			tablet_text = "$RoomMenuInfoRoomFoundTablet$";
			tablet_completed = Icon_Ok;
		}
		menu.selinfo.room.options.tablet = 
		{
			Target = this,
			ID = 49,
			Priority = 4,
			Bottom = "2em",
			icon = 
			{
				Right = "2em",
				Symbol = AncientTablet,
				completed = 
				{
					Left = "50%",
					Top = "50%",
					Symbol = tablet_completed				
				}
			},
			text =
			{
				Left = "2em",
				Style = GUI_TextVCenter,
				Text = tablet_text				
			}		
		};
	}
	
	// Add joker information to the room if available.
	if (room_id->HasJoker())
	{
		var joker_text = "$RoomMenuInfoRoomHasJoker$";
		var joker_completed = nil;
		if (HasPlayerFoundJoker(plr, room_id))
		{
			joker_text = "$RoomMenuInfoRoomFoundJoker$";
			joker_completed = Icon_Ok;
		}
		menu.selinfo.room.options.joker = 
		{
			Target = this,
			ID = 50,
			Priority = 3,
			Bottom = "2em",
			icon = 
			{
				Right = "2em",
				Symbol = Joker,
				completed = 
				{
					Left = "50%",
					Top = "50%",
					Symbol = joker_completed				
				}
			},
			text =
			{
				Left = "2em",
				Style = GUI_TextVCenter,
				Text = joker_text				
			}		
		};
	}
	
	// Add skip button if jokers are available.
	if (GetPlayerAvailableJokers(plr) > 0 && !HasPlayerCompletedRoom(plr, room_id))
	{
		menu.selinfo.room.options.skip = 
		{
			Target = this,
			ID = 51,
			Priority = 2,
			Bottom = "2em",
			icon = 
			{
				Right = "2em",
				Symbol = Joker,
				BackgroundColor = {Std = 0, Hover = ROOMMENU_Color_Hover},
				OnMouseIn = GuiAction_SetTag("Hover"),
				OnMouseOut = GuiAction_SetTag("Std"),
				OnClick = GuiAction_Call(this, "OnRoomClickSkip", {plr = plr, room_id = room_id}),
				completed = 
				{
					Left = "50%",
					Top = "50%",
					Symbol = Icon_Grab	
				}
			},
			text =
			{
				Left = "2em",
				Style = GUI_TextVCenter,
				Text = "$RoomMenuInfoSkipRoom$"				
			}		
		};
	}
	
	// Add a vote button if the player has finished the room in this session and only in network games.
	if ((IsNetwork() || IsEditor()) && HasPlayerCompletedRoom(plr, room_id) && !HasPlayerUsedJoker(plr, room_id))
	{
		menu.selinfo.room.options.rating = 
		{
			Target = this,
			ID = 52,
			Priority = 5,
			Bottom = "2em",
			icon = 
			{
				Right = "2em",
				icon = 
				{
					Margin = ["0.1em"],
					Symbol = Icon_Star,
					GraphicsName = "Gold"
				}
			},
			text = 
			{
				Left = "2em",
				Right = "8em",
				Style = GUI_TextVCenter,
				Text = "$RoomMenuInfoRateRoom$"
			},
			stars = 
			{
				Left = "8em",
				Right = "18em",
				OnMouseOut = GuiAction_Call(this, "OnRoomHoverRating", {plr = plr, room_id = room_id, rating = nil, in = false}),
			}
		};
		// Add attention sign if no rating has been given yet.
		if (GetPlayerRoomRating(room_id, plr) == nil)
		{
			menu.selinfo.room.options.rating.icon.attention = 
			{
				Target = this,
				ID = 53,
				Priority = 1,
				Left = "1em",
				Symbol = Dialogue
			};
		}
		var current_rating = GetPlayerRoomRating(room_id, plr);
		for (var cnt = 1; cnt <= 5; cnt ++)
		{
			var graphics = nil;
			if (cnt <= current_rating)		
				graphics = "Gold";
			menu.selinfo.room.options.rating.stars[Format("star%d", cnt)] = 
			{
				Left = Format("%dem", 2 * (cnt - 1)),
				Right = Format("%dem", 2 * cnt),
				icon = 
				{
					Margin = ["0.2em"],
					Symbol = Icon_Star,
					OnMouseIn = GuiAction_Call(this, "OnRoomHoverRating", {plr = plr, room_id = room_id, rating = cnt, in = true}),
					OnClick = GuiAction_Call(this, "OnRoomClickRating", {plr = plr, room_id = room_id, rating = cnt}),
					GraphicsName = graphics
				}
			};
		}
	}
	
	// Update this part of the menu.
	GuiUpdate(menu.selinfo, menu_id, menu.selinfo.ID, this);
	return;
}

public func OnRoomClickPlay(id room_id)
{
	CloseRoomMenu();
	LoadRoom(room_id);
	return;
}

public func OnRoomClickSkip(proplist pars)
{
	var plr = pars.plr;
	var room_id = pars.room_id;
	AddPlayerUsedJoker(plr, room_id);
	AddPlayerCompletedRoom(plr, room_id);
	// Save the progress.
	SavePlayerRoomData(plr);
	// Update selection.
	UpdateRoomSelectionInformation(pars);
	// Update open room menus.
	UpdateRoomMenus("rooms");
	return;
}

public func OnRoomHoverRating(proplist pars)
{
	var plr = pars.plr;
	var room_id = pars.room_id;
	var rating = pars.rating;
	var in = pars.in;
	var current_rating = GetPlayerRoomRating(room_id, plr);
	// Update the amount of colored stars.	
	for (var cnt = 1; cnt <= 5; cnt ++)
	{
		var graphics = nil;
		if ((in && cnt <= rating) || (!in && cnt <= current_rating))		
			graphics = "Gold";
		menu.selinfo.room.options.rating.stars[Format("star%d", cnt)].icon.GraphicsName = graphics;
	}	
	GuiUpdate(menu.selinfo.room.options.rating, menu_id, menu.selinfo.room.options.rating.ID, this);
	return;
}

public func OnRoomClickRating(proplist pars)
{
	var plr = pars.plr;
	var room_id = pars.room_id;
	var rating = pars.rating;
	// Remove attention symbols if it was the first rating.
	if (GetPlayerRoomRating(room_id, plr) == nil)
	{
		GuiClose(menu_id, menu.selinfo.room.options.rating.icon.attention.ID, this);
		menu.selinfo.room.options.rating.icon.attention = nil;
		for (var room in GetProperties(menu.roomsel.rooms))
		{
			if (GetType(menu.roomsel.rooms[room]) == C4V_PropList && room_id == menu.roomsel.rooms[room].symbol.Symbol)
			{
				GuiClose(menu_id, menu.roomsel.rooms[room].rating_alert.ID, this);
				menu.roomsel.rooms[room].rating_alert = nil;
			}
		}
	}
	// Update and store rating.
	UpdatePlayerRoomRating(room_id, plr, rating);
	return;
}


/*-- Credits --*/

public func ShowRoomMenuCredits(int plr)
{
	CloseRoomMenu();
	var menu_obj = CreateObject(RoomMenu, 0, 0, plr);
	menu_obj->OpenRoomMenu(plr, "credits");
	return;
}

public func MakeCreditsMenu(int plr)
{
	// The basic panels for the menu.
	menu.authordesc = 
	{
		Target = this,
		ID = 1,
		Right = "70%",
		Bottom = "2em",		
		BackgroundColor = ROOMMENU_Color_Area1,
		text = 
		{
			Margin = ["0.2em"],
			Text = "$RoomMenuCreditsText$",
			Style = GUI_TextVCenter
		}
	};
	menu.authorlist = 
	{
		Target = this,
		ID = 2,
		Top = "2em",
		Right = "70%",
		Style = GUI_VerticalLayout,
		BackgroundColor = ROOMMENU_Color_Area2
	};
	menu.authorinfo = 
	{
		Target = this,
		ID = 4,
		Left = "70%",
		Top = "2em",
		BackgroundColor = ROOMMENU_Color_Area3
	};
	
	// Create the list of authors.
	menu.authorlist = MenuShowRoomAuthors(menu.authorlist);
		
	// Room selection: header with close button.
	menu.buttons = CreateMenuButtons(plr, "credits");
	return;
}

public func MenuShowRoomAuthors(proplist authors)
{
	// Put all authors into the selection menu.
	var cnt = 0;
	var room_authors = GetAuthorList();
	SortArrayByArrayElement(room_authors, 1, true);
	for (var author in room_authors)
	{
		var author =
		{
			Target = this,
			ID = cnt + 1000,
			Priority = cnt,
			Bottom = "1.5em",
			BackgroundColor = {Std = 0, Hover = ROOMMENU_Color_Hover},
			OnMouseIn = [GuiAction_SetTag("Hover"), GuiAction_Call(this, "ShowAuthorSelectionInformation", {author = author[0], rooms = author[2]})],
			OnMouseOut = [GuiAction_SetTag("Std"), GuiAction_Call(this, "CloseAuthorSelectionInformation", {author = author[0], rooms = author[2]})],
			symbol = 
			{
				Target = this,
				ID = cnt + 2000,
				Right = "1.5em",
			},
			text = 
			{
				Target = this,
				ID = cnt + 4000,
				Left = "1.5em",
				Text = Format("%s: %d $RoomMenuCreditsRooms$", author[0], author[1]),
				Style = GUI_TextVCenter
			}
		};
		MakeNumberMenuEntry(author.symbol, cnt + 1, 60, [0, 20]);
		authors[Format("room%d", cnt)] = author;		
		cnt++;
	}
	return authors;
}

public func ShowAuthorSelectionInformation(proplist pars)
{
	menu.authorinfo.pars = pars;
	var author_rooms = Format("$RoomMenuCreditsAuthor$", pars.author);
	for (var index = 0; index < GetLength(pars.rooms); index++)
	{
		var room = pars.rooms[index];
		if (index < GetLength(pars.rooms) - 1)
			author_rooms = Format("%s %s,", author_rooms, room->GetRoomName());
		else
			author_rooms = Format("%s %s.", author_rooms, room->GetRoomName());
	}
	
	menu.authorinfo.author =
	{
		Target = this,
		ID = 41,
		Margin = ["0.2em"],
		Text = author_rooms
	};	
	GuiUpdate(menu.authorinfo, menu_id, menu.authorinfo.ID, this);
	return;
}

public func CloseAuthorSelectionInformation(proplist pars)
{
	if (menu.authorinfo.pars == pars)
	{
		GuiClose(menu_id, menu.authorinfo.author.ID, menu.authorinfo.author.Target);
		menu.authorinfo.author = nil;
	}
	return;
}


/*-- Tablets --*/

public func ShowRoomMenuTablets(int plr)
{
	CloseRoomMenu();
	var menu_obj = CreateObject(RoomMenu, 0, 0, plr);
	menu_obj->OpenRoomMenu(plr, "tablets");
	return;
}

public func MakeTabletsMenu(int plr)
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
	
	// Room selection: header with close button.
	menu.buttons = CreateMenuButtons(plr, "tablets"); 
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
		MakeNumberMenuEntry(tablet, cnt + 1);
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


/*-- Information --*/

public func ShowRoomMenuInformation(int plr)
{
	CloseRoomMenu();
	var menu_obj = CreateObject(RoomMenu, 0, 0, plr);
	menu_obj->OpenRoomMenu(plr, "information");
	return;
}

public func MakeInformationMenu(int plr)
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
	
	// Room selection: header with close button.
	menu.buttons = CreateMenuButtons(plr, "information"); 
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
		MakeNumberMenuEntry(prop_entry.symbol, cnt, 40);
		info[Format("entry%d", cnt)] = prop_entry;		
		cnt++;
	}
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
