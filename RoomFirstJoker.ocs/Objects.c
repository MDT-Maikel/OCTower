/* Automatically created objects file */

func InitializeObjects()
{
	var Trunk001 = CreateObject(Trunk, 331, 347);
	Trunk001->SetCon(99);
	Trunk001->SetR(30);
	Trunk001->SetPosition(331, 347);
	var Trunk002 = CreateObject(Trunk, 106, 317);
	Trunk002->SetCon(112);
	Trunk002->SetR(166);
	Trunk002->SetPosition(106, 317);

	var LargeCaveMushroom001 = CreateObject(LargeCaveMushroom, 483, 220);
	LargeCaveMushroom001->SetCon(110);
	LargeCaveMushroom001->SetR(-145);
	LargeCaveMushroom001->SetClrModulation(0xffe8e2d5);
	LargeCaveMushroom001->SetPosition(483, 220);

	var Branch001 = CreateObject(Branch, 269, 300);
	Branch001->SetCon(115);
	Branch001->SetR(-134);
	Branch001->SetPosition(269, 300);

	var Rule_NoPowerNeed001 = CreateObject(Rule_NoPowerNeed, 244, 441);
	Rule_NoPowerNeed001->SetPosition(244, 441);

	var LargeCaveMushroom002 = CreateObject(LargeCaveMushroom, 259, 62);
	LargeCaveMushroom002->SetCon(110);
	LargeCaveMushroom002->SetR(-145);
	LargeCaveMushroom002->SetClrModulation(0xffe8e2d5);
	LargeCaveMushroom002->SetPosition(259, 62);

	var Trunk003 = CreateObject(Trunk, 506, 164);
	Trunk003->SetCon(97);
	Trunk003->SetR(28);
	Trunk003->SetPosition(506, 164);

	var Branch002 = CreateObject(Branch, 131, 73);
	Branch002->SetCon(84);
	Branch002->SetR(-157);
	Branch002->SetPosition(131, 73);
	var Branch003 = CreateObject(Branch, 431, 76);
	Branch003->SetCon(99);
	Branch003->SetR(144);
	Branch003->SetPosition(431, 76);
	var Branch004 = CreateObject(Branch, 461, 63);
	Branch004->SetCon(85);
	Branch004->SetR(-175);
	Branch004->SetPosition(461, 63);
	var Branch005 = CreateObject(Branch, 405, 230);
	Branch005->SetR(25);
	Branch005->SetPosition(405, 230);
	var Branch006 = CreateObject(Branch, 577, 90);
	Branch006->SetCon(95);
	Branch006->SetR(-72);
	Branch006->SetPosition(577, 90);
	var Branch007 = CreateObject(Branch, 571, 139);
	Branch007->SetCon(134);
	Branch007->SetR(-118);
	Branch007->SetPosition(571, 139);
	var RoomEntrance001 = CreateObjectAbove(RoomEntrance, 288, 455);
	RoomEntrance001->SetColor(0xff32c832);

	var RoomExit001 = CreateObjectAbove(RoomExit, 587, 376);
	RoomExit001->SetColor(0xffc83232);

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
	PlayerStart001->SetPosition(268, 442);
	PlayerStart001->SetStartingMaterial([]);
	PlayerStart001->SetViewLock(true);
	PlayerStart001->SetZoomSet(500);

	var Mooq001 = CreateObjectAbove(Mooq, 491, 398);
	Mooq001->SetComDir(COMD_UpLeft);
	Mooq001->SetXDir(-10);
	Mooq001->Unstick(7);
	var Mooq002 = CreateObjectAbove(Mooq, 508, 398);
	Mooq002->SetComDir(COMD_UpLeft);
	Mooq002->SetXDir(-10);
	Mooq002->Unstick(7);
	var Metal001 = CreateObject(Metal, 142, 285);
	Metal001->SetR(-17);
	Metal001->SetPosition(142, 285);
	Metal001->Unstick(7);
	var Metal002 = CreateObject(Metal, 165, 290);
	Metal002->SetR(34);
	Metal002->SetRDir(-2);
	Metal002->SetPosition(165, 290);
	Metal002->Unstick(7);

	var Boompack001 = CreateObject(Boompack, 68, 284);
	Boompack001->SetR(8);
	Boompack001->SetPosition(68, 284);
	Boompack001->Unstick(7);
	var Boompack002 = CreateObject(Boompack, 135, 276);
	Boompack002->SetR(3);
	Boompack002->SetPosition(135, 276);
	Boompack002->Unstick(7);

	var Shovel001 = CreateObject(Shovel, 306, 367);
	Shovel001->SetR(-130);
	Shovel001->SetPosition(306, 367);

	var Joker001 = Chest001->CreateContents(Joker);
	Joker001->SetPosition(46, 68);

	var AncientTablet001 = Chest002->CreateContents(AncientTablet);
	AncientTablet001->SetPosition(598, 52);

	var Lantern001 = ToolsWorkshop001->CreateContents(Lantern);
	Lantern001->SetPosition(332, 252);
	Lantern001->TurnOn();
	var Lantern002 = ChemicalLab001->CreateContents(Lantern);
	Lantern002->SetPosition(70, 199);
	Lantern002->TurnOn();
	var Lantern003 = Foundry001->CreateContents(Lantern);
	Lantern003->SetPosition(342, 118);
	Lantern003->TurnOn();
	return true;
}
