/* Automatically created objects file */

func InitializeObjects()
{
	var Trunk001 = CreateObject(Trunk, 331, 346);
	Trunk001->SetCon(99);
	Trunk001->SetR(30);
	var Trunk002 = CreateObject(Trunk, 106, 320);
	Trunk002->SetCon(112);
	Trunk002->SetR(166);

	var LargeCaveMushroom001 = CreateObject(LargeCaveMushroom, 483, 307);
	LargeCaveMushroom001->SetCon(110);
	LargeCaveMushroom001->SetR(-145);
	LargeCaveMushroom001->SetClrModulation(0xffe8e2d5);

	var Branch001 = CreateObject(Branch, 269, 301);
	Branch001->SetCon(115);
	Branch001->SetR(-134);

	CreateObject(Rule_NoPowerNeed, 244, 441);
	var LargeCaveMushroom002 = CreateObject(LargeCaveMushroom, 259, 65);
	LargeCaveMushroom002->SetCon(110);
	LargeCaveMushroom002->SetR(-145);
	LargeCaveMushroom002->SetClrModulation(0xffe8e2d5);

	var Trunk003 = CreateObject(Trunk, 506, 163);
	Trunk003->SetCon(97);
	Trunk003->SetR(28);

	CreateObjectAbove(RoomEntrance, 288, 455);

	CreateObjectAbove(RoomExit, 587, 376);

	var ToolsWorkshop001 = CreateObjectAbove(ToolsWorkshop, 332, 271);

	var Chest001 = CreateObjectAbove(Chest, 46, 79);
	var Chest002 = CreateObjectAbove(Chest, 598, 63);

	CreateObjectAbove(Armory, 142, 231);

	var ChemicalLab001 = CreateObjectAbove(ChemicalLab, 70, 224);

	CreateObjectAbove(Kitchen, 218, 239);

	var Foundry001 = CreateObjectAbove(Foundry, 342, 143);

	CreateObjectAbove(Pump, 176, 119);

	var Catapult001 = CreateObjectAbove(Catapult, 144, 431);
	Catapult001->SetDir(DIR_Right);
	Catapult001->SetRDir(2);
	Catapult001->SetColor(0xff8e0b0b);

	var PlayerStart001 = CreateObject(PlayerStart, 268, 442);
	PlayerStart001->SetStartingMaterial([]);
	PlayerStart001->SetViewLock(true);

	var Mooq001 = CreateObjectAbove(Mooq, 547, 398);
	Mooq001->SetDir(DIR_Right);
	Mooq001->SetComDir(COMD_UpRight);
	Mooq001->SetXDir(10);
	Mooq001->Unstick(7);
	var Mooq002 = CreateObjectAbove(Mooq, 491, 398);
	Mooq002->SetDir(DIR_Right);
	Mooq002->SetComDir(COMD_UpRight);
	Mooq002->SetXDir(10);
	Mooq002->Unstick(7);
	var Metal001 = CreateObject(Metal, 142, 286);
	Metal001->SetR(-17);
	var Metal002 = CreateObject(Metal, 165, 290);
	Metal002->SetR(26);
	Metal002->Unstick(7);

	var Boompack001 = CreateObject(Boompack, 68, 284);
	Boompack001->SetR(8);
	Boompack001->Unstick(7);
	var Boompack002 = CreateObject(Boompack, 135, 276);
	Boompack002->SetR(3);
	Boompack002->Unstick(7);

	var Shovel001 = CreateObject(Shovel, 306, 367);
	Shovel001->SetR(-130);

	Chest001->CreateContents(Joker);

	Chest002->CreateContents(AncientTablet);

	var Lantern001 = ToolsWorkshop001->CreateContents(Lantern);
	Lantern001->TurnOn();
	var Lantern002 = ChemicalLab001->CreateContents(Lantern);
	Lantern002->TurnOn();
	var Lantern003 = Foundry001->CreateContents(Lantern);
	Lantern003->TurnOn();
	return true;
}
