// Tablet codes for the special paths of the tower.

global func InitTabletKeypads()
{
	var nr_rooms = GetLength(GetRoomList());
	// The dungeon can be accessed if the first N tablets have been found.
	var keypad_dungeon = FindObject(Find_ID(Keypad), Sort_Reverse(Sort_Func("GetY")));
	var code_rooms = CreateTabletKeypadCode(keypad_dungeon, nil, nr_rooms / 2);
	CreateTabletStoneSigns(code_rooms, 622, 316);
	// The upstairs can be accessed if the final N tablets have been found.
	var keypad_upstairs = FindObject(Find_ID(Keypad), Sort_Func("GetY"));
	var code_rooms = CreateTabletKeypadCode(keypad_upstairs, nr_rooms / 2, nil);
	CreateTabletStoneSigns(code_rooms, 622, 260, true);
	return;
}

global func CreateTabletKeypadCode(object keypad, int room_start, int room_end)
{
	var rooms = GetRoomList()[:];
	if (room_start != nil)
		rooms = rooms[room_start:];
	if (room_end != nil)
		rooms = rooms[:room_end];
	// Shuffle rooms and take an amount of them corresponding the keypad code max length.
	ShuffleArray(rooms);
	rooms = rooms[:Keypad.CodeMaxLength];
	var code = "";
	for (var room in rooms)
		code = Format("%s%d", code, AncientTablet->GetTabletCode(room->GetRoomID()));
	keypad->SetKeypadHashedCode(Crypto->ComputeHash(code));
	return rooms;
}

global func CreateTabletStoneSigns(array rooms, int x, int y, bool reverse)
{
	var dy = 0;
	for (var room in rooms)
	{
		var sign = CreateObject(StoneSign, x, y + dy);
		sign->SetInscription(Format("%s", room->GetRoomName()));
		sign->SetGraphics(nil, room, GFX_Overlay, GFXOV_MODE_IngamePicture);
		sign->SetObjDrawTransform(800, 0, 0, 0, 800, 0, GFX_Overlay);
		if (reverse)
			dy -= 12;
		else
			dy += 12;
	}
	return;
}