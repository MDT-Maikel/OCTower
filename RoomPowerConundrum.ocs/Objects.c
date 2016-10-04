/* Automatically created objects file */

func InitializeObjects()
{
	var Branch001 = CreateObject(Branch, 605, 314);
	Branch001->SetCon(139);
	Branch001->SetR(-52);

	var Pipe001 = CreateObject(Pipe, 138, 693);

	var SteamEngine001 = CreateObject(SteamEngine, 67, 336);
	SteamEngine001.MakeRoomPlayerOwner = true;
	SteamEngine001->SetColor(0xff8e0b0b);
	SteamEngine001->SetNeutralPipe(Pipe001);

	var Pipe002 = CreateObjectAbove(Pipe, 148, 455);
	Pipe002->SetName("Source pipe");
	Pipe002->SetSourcePipe();

	var Pump001 = CreateObjectAbove(Pump, 134, 359);
	Pump001->SetYDir(16);
	Pump001->SetColor(0xff8e0b0b);
	Pump001->SetDrainPipe(Pipe001);
	Pump001->SetSourcePipe(Pipe002);

	var PipeLine001 = CreateObject(PipeLine, 134, 359);
	PipeLine001.LineColors = [-1153536,-1153536];
	PipeLine001->SetAction("Connect", SteamEngine001, Pump001);
	PipeLine001->SetPipeKit(Pipe001);
	Pipe001->SetName("Drain pipe");
	Pipe001->SetDrainPipe();
	Pipe001->Enter(PipeLine001);

	var PipeLine002 = CreateObject(PipeLine, 134, 359);
	PipeLine002.LineColors = [-10057694,-10057694];
	PipeLine002->SetAction("Connect", Pipe002, Pump001);
	PipeLine002->SetPipeKit(Pipe002);

	var Wheat001 = CreateObjectAbove(Wheat, 467, 216);
	Wheat001->SetMeshMaterial("wheat_material_ripe", 0);
	var Wheat002 = CreateObjectAbove(Wheat, 448, 216);
	Wheat002->SetMeshMaterial("wheat_material_ripe", 0);
	var Wheat003 = CreateObjectAbove(Wheat, 436, 216);
	Wheat003->SetMeshMaterial("wheat_material_ripe", 0);
	var Wheat004 = CreateObjectAbove(Wheat, 331, 246);
	Wheat004->SetMeshMaterial("wheat_material_ripe", 0);
	var Wheat005 = CreateObjectAbove(Wheat, 344, 247);
	Wheat005->SetMeshMaterial("wheat_material_ripe", 0);
	CreateObjectAbove(RoomExit, 46, 104);

	CreateObjectAbove(RoomEntrance, 173, 360);

	var Chest001 = CreateObjectAbove(Chest, 324, 392);
	Chest001->SetColor(0xff8e0b0b);
	var Chest003 = CreateObjectAbove(Chest, 593, 56);
	var Chest002 = CreateObjectAbove(Chest, 89, 248);
	Chest002->SetColor(0xff8e0b0b);

	var Sawmill001 = CreateObjectAbove(Sawmill, 279, 352);
	Sawmill001->SetYDir(16);
	Sawmill001->SetColor(0xff8e0b0b);

	CreateObjectAbove(Ruin_Windmill, 290, 248);

	var Compensator001 = CreateObject(Compensator, 352, 342);
	Compensator001.MakeRoomPlayerOwner = true;
	Compensator001->SetColor(0xff8e0b0b);
	Compensator001->SetYDir(16);
	var Compensator002 = CreateObject(Compensator, 318, 342);
	Compensator002.MakeRoomPlayerOwner = true;
	Compensator002->SetColor(0xff8e0b0b);
	Compensator002->SetYDir(16);

	var Flagpole001 = CreateObject(Flagpole, 76, 69);
	Flagpole001.MakeRoomPlayerOwner = true;
	var Elevator001 = CreateObjectAbove(Elevator, 116, 103);
	Elevator001->SetColor(0xff8e0b0b);
	Elevator001->CreateShaft(3);
	Elevator001->SetCasePosition(94);
	var Elevator002 = CreateObjectAbove(Elevator, 211, 103);
	Elevator002->SetDir(DIR_Right);
	Elevator002->SetColor(0xff8e0b0b);
	Elevator002->CreateShaft(5);
	Elevator002->SetCasePosition(96);
	CreateObjectAbove(StrawMan, 430, 215);
	CreateObjectAbove(StrawMan, 462, 216);
	CreateObjectAbove(StrawMan, 339, 248);

	var PlayerStart001 = CreateObject(PlayerStart, 192, 347);
	PlayerStart001->SetStartingKnowledge();
	PlayerStart001->SetStartingMaterial([Shovel]);
	PlayerStart001->SetViewLock(false);

	var Clonk001;
	CreateObject(Coal, 326, 448);
	CreateObject(Coal, 431, 448);
	CreateObject(Coal, 378, 448);
	CreateObject(Coal, 346, 451);
	CreateObject(Coal, 401, 444);
	CreateObject(Coal, 452, 451);
	CreateObject(Coal, 304, 445);

	Chest001->CreateContents(Loam);

	var Axe001 = CreateObject(Axe, 83, 456);
	Axe001->SetR(-65);
	Axe001->Unstick(7);

	Chest003->CreateContents(AncientTablet);

	CreateObject(Club, 602, 444);

	Chest001->CreateContents(Lantern);

	Chest002->CreateContents(Dynamite, 3);
	return true;
}
