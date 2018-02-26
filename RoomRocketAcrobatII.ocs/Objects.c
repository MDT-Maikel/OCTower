/* Automatically created objects file */

func InitializeObjects()
{
	var ItemSpawn001 = ItemSpawn->Create(Boompack,531,416);
	ItemSpawn001->SetPosition(531, 416);

	var JetStream001 = CreateObject(JetStream, 596, 71);
	JetStream001->Create(0, 0, 0, 64, nil, 40, 40);
	JetStream001->SetPosition(596, 71);

	var ItemSpawn002 = ItemSpawn->Create(Boompack,78,416);
	ItemSpawn002->SetPosition(78, 416);

	var Branch001 = CreateObject(Branch, 37, 79);
	Branch001->SetCon(156);
	Branch001->SetR(177);
	Branch001->SetPosition(37, 79);
	var Branch002 = CreateObject(Branch, 90, 29);
	Branch002->SetCon(131);
	Branch002->SetR(139);
	Branch002->SetPosition(90, 29);
	var Branch003 = CreateObject(Branch, 584, 249);
	Branch003->SetCon(131);
	Branch003->SetR(-115);
	Branch003->SetPosition(584, 249);
	var Trunk001 = CreateObject(Trunk, 324, 227);
	Trunk001->SetCon(97);
	Trunk001->SetR(21);
	Trunk001->SetPosition(324, 227);

	var Branch004 = CreateObject(Branch, 273, 297);
	Branch004->SetCon(109);
	Branch004->SetR(-147);
	Branch004->SetPosition(273, 297);

	var RoomEntrance001 = CreateObjectAbove(RoomEntrance, 627, 447);
	RoomEntrance001->SetColor(0xff32c832);

	var RoomExit001 = CreateObjectAbove(RoomExit, 626, 47);
	RoomExit001->SetColor(0xffc83232);

	var PlayerStart001 = CreateObject(PlayerStart, 627, 401);
	PlayerStart001->SetPosition(627, 401);
	PlayerStart001->SetStartingMaterial([WindBag]);
	PlayerStart001->SetViewLock(false);
	PlayerStart001->SetZoomSet(700);
	var Joker001 = CreateObject(Joker, 303, 268);
	Joker001->SetPosition(303, 268);
	var AncientTablet001 = CreateObject(AncientTablet, 64, 36);
	AncientTablet001->SetPosition(64, 36);
	return true;
}
