/**
	Room Menu: Tab Credits
	@author Maikel
*/

public func ShowRoomMenuCredits(int plr)
{
	this->CloseRoomMenu();
	var menu_obj = CreateObject(RoomMenu, 0, 0, plr);
	menu_obj->OpenRoomMenu(plr, "credits");
	return;
}

public func MakeCreditsMenu(proplist menu, int plr)
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
		this->MakeNumberMenuEntry(author.symbol, cnt + 1, 60, [0, 20]);
		authors[Format("room%d", cnt)] = author;		
		cnt++;
	}
	return authors;
}

public func ShowAuthorSelectionInformation(proplist pars)
{
	var menu = this->GetMenu();
	var menu_id = this->GetMenuID();
	
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
	var menu = this->GetMenu();
	var menu_id = this->GetMenuID();
	
	if (menu.authorinfo.pars == pars)
	{
		GuiClose(menu_id, menu.authorinfo.author.ID, menu.authorinfo.author.Target);
		menu.authorinfo.author = nil;
	}
	return;
}