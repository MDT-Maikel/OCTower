/**
	Room Menu: Tab Rooms
	@author Maikel
*/

public func ShowRoomMenuRooms(int plr)
{
	this->CloseRoomMenu();
	var menu_obj = CreateObject(RoomMenu, 0, 0, plr);
	menu_obj->OpenRoomMenu(plr, "rooms");
	return;
}

public func MakeRoomMenu(proplist menu, int plr, proplist selection)
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
		this->MakeNumberMenuEntry(roominfo.info_text.info.current_room.icon, GetRoomNumber(current_room), 40);
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
	// In editor mode show all rooms to allow testing access.
	if (IsEditor())
		room_list = GetRoomList();
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
		this->MakeNumberMenuEntry(room.symbol, GetRoomNumber(room_id), 40);

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
		if ((IsNetwork() || IsEditor()) && HasPlayerCompletedRoom(plr, room_id) && !HasPlayerUsedJoker(plr, room_id) && (GetPlayerRoomRating(room_id, plr) == nil || GetPlayerRoomDifficulty(room_id, plr) == nil))
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
	var menu = this->GetMenu();
	var menu_id = this->GetMenuID();
	
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
	this->MakeNumberMenuEntry(menu.selinfo.room.icon, GetRoomNumber(room_id));
	
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
			Bottom = "3em",
			icon = 
			{
				Right = "2em",
				Top = "0.5em",
				Bottom = "2.5em",
				icon = 
				{
					Margin = ["0.1em"],
					Symbol = Icon_Star,
					GraphicsName = "Gold"
				}
			},
			text_rate = 
			{
				Left = "2em",
				Right = "8em",
				Bottom = "1.5em",
				Style = GUI_TextVCenter,
				Text = "$RoomMenuInfoRateRoom$"
			},
			text_diff = 
			{
				Left = "2em",
				Right = "8em",
				Top = "1.5em",
				Style = GUI_TextVCenter,
				Text = "$RoomMenuInfoRateDifficulty$"
			},
			stars = 
			{
				Left = "8em",
				Right = "16.5em",
				Bottom = "1.5em",
				OnMouseOut = GuiAction_Call(this, "OnRoomHoverRating", {plr = plr, room_id = room_id, rating = nil, in = false}),
			},
			difficulty = 
			{
				Left = "8em",
				Right = "16.5em",
				Top = "1.5em",
				OnMouseOut = GuiAction_Call(this, "OnRoomHoverDifficulty", {plr = plr, room_id = room_id, difficulty = nil, in = false}),
			}
		};
		// Add attention sign if no rating has been given yet.
		if (GetPlayerRoomRating(room_id, plr) == nil || GetPlayerRoomDifficulty(room_id, plr) == nil)
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
				Left = ToEmString(17 * (cnt - 1)),
				Right = ToEmString(17 * cnt),
				icon = 
				{
					Margin = ["0.1em", "0.0em"],
					Symbol = Icon_Star,
					OnMouseIn = GuiAction_Call(this, "OnRoomHoverRating", {plr = plr, room_id = room_id, rating = cnt, in = true}),
					OnClick = GuiAction_Call(this, "OnRoomClickRating", {plr = plr, room_id = room_id, rating = cnt}),
					GraphicsName = graphics
				}
			};
		}
		var current_difficulty = GetPlayerRoomDifficulty(room_id, plr);
		for (var cnt = 1; cnt <= 5; cnt ++)
		{
			var graphics = ["Trivial", "Easy", "Medium", "Hard", "Extreme"][cnt - 1];
			if (cnt <= current_difficulty)
				graphics = Format("%sWhite", graphics);
			menu.selinfo.room.options.rating.difficulty[Format("diff%d", cnt)] = 
			{
				
				Left = ToEmString(17 * (cnt - 1)),
				Right = ToEmString(17 * cnt),
				icon = 
				{
					Margin = ["0.1em", "0.0em"],
					Symbol = Icon_Difficulty,
					OnMouseIn = GuiAction_Call(this, "OnRoomHoverDifficulty", {plr = plr, room_id = room_id, difficulty = cnt, in = true}),
					OnClick = GuiAction_Call(this, "OnRoomClickDifficulty", {plr = plr, room_id = room_id, difficulty = cnt}),
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
	this->CloseRoomMenu();
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
	var menu = this->GetMenu();
	var menu_id = this->GetMenuID();
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
	// Update and store rating.
	UpdatePlayerRoomRating(room_id, plr, rating);
	// Update attention symbols.
	UpdateRoomRatingAlert(room_id, plr);
	return;
}

public func OnRoomHoverDifficulty(proplist pars)
{
	var plr = pars.plr;
	var room_id = pars.room_id;
	var difficulty = pars.difficulty;
	var in = pars.in;
	var menu = this->GetMenu();
	var menu_id = this->GetMenuID();
	var current_difficulty = GetPlayerRoomDifficulty(room_id, plr);
	// Update the amount of colored stars.	
	for (var cnt = 1; cnt <= 5; cnt ++)
	{
		var graphics = ["Trivial", "Easy", "Medium", "Hard", "Extreme"][cnt - 1];
		if ((in && cnt <= difficulty) || (!in && cnt <= current_difficulty))		
			graphics = Format("%sWhite", graphics);
		menu.selinfo.room.options.rating.difficulty[Format("diff%d", cnt)].icon.GraphicsName = graphics;
	}	
	GuiUpdate(menu.selinfo.room.options.rating, menu_id, menu.selinfo.room.options.rating.ID, this);
	return;
}

public func OnRoomClickDifficulty(proplist pars)
{
	var plr = pars.plr;
	var room_id = pars.room_id;
	var difficulty = pars.difficulty;
	// Update and store rating.
	UpdatePlayerRoomDifficulty(room_id, plr, difficulty);
	// Update attention symbols.
	UpdateRoomRatingAlert(room_id, plr);
	return;
}

public func UpdateRoomRatingAlert(id room_id, int plr)
{
	if (GetPlayerRoomDifficulty(room_id, plr) == nil || GetPlayerRoomRating(room_id, plr) == nil) 
		return;
	var menu = this->GetMenu();
	var menu_id = this->GetMenuID();
	if (menu.selinfo.room.options.rating.icon.attention == nil)
		return;
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
	return;
}