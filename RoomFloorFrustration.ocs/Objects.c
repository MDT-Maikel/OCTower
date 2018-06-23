/* Automatically created objects file */

func InitializeObjects()
{
	var Chest001 = CreateObjectAbove(Chest, 271, 144);
	Chest001->SetCategory(C4D_StaticBack);
	Chest001.Plane = 40;
	var Trunk001 = CreateObject(Trunk, 272, 124);
	Trunk001->SetCon(184);
	Trunk001->SetR(154);
	Trunk001->SetPosition(272, 124);

	var RoomEntrance001 = CreateObjectAbove(RoomEntrance, 320, 192);
	RoomEntrance001->SetColor(0xff32c832);

	var RoomExit001 = CreateObjectAbove(RoomExit, 320, 240);
	RoomExit001->SetColor(0xffc83232);

	var PlayerStart001 = CreateObject(PlayerStart, 400, 200);
	PlayerStart001->SetPosition(400, 200);
	PlayerStart001->SetStartingMaterial([]);
	PlayerStart001->SetStartingWealth(42);
	PlayerStart001->SetClonkMaxContentsCount(1);
	PlayerStart001->SetClonkMaxEnergy(1);
	PlayerStart001->SetViewLock(false);
	var WindBag001 = Chest001->CreateContents(WindBag);
	WindBag001->DoFullLoad();
	WindBag001->SetPosition(31, 37);
	return true;
}
