/* Automatically created objects file */

func InitializeObjects()
{
	var Torch001 = CreateObjectAbove(Torch, 568, 187);
	Torch001->AttachToWall(false);

	CreateWaterfall(50, 165, 12, "Water");
	CreateLiquidDrain(52, 478, 30);

	var Branch001 = CreateObject(Branch, 101, 203);
	Branch001->SetCon(113);
	Branch001->SetR(173);
	var Branch002 = CreateObject(Branch, 88, 332);
	Branch002->SetCon(116);
	Branch002->SetR(146);
	var Branch003 = CreateObject(Branch, 38, 346);
	Branch003->SetCon(112);
	Branch003->SetR(160);
	var Branch004 = CreateObject(Branch, 207, 233);
	Branch004->SetCon(108);
	Branch004->SetR(-161);
	var Branch005 = CreateObject(Branch, 150, 183);
	Branch005->SetCon(105);
	Branch005->SetR(168);
	var Branch006 = CreateObject(Branch, 308, 48);
	Branch006->SetCon(113);
	Branch006->SetR(173);
	var Branch007 = CreateObject(Branch, 338, 52);
	Branch007->SetCon(95);
	Branch007->SetR(-124);

	var LargeCaveMushroom001 = CreateObject(LargeCaveMushroom, 204, 271);
	LargeCaveMushroom001->SetR(-91);
	LargeCaveMushroom001->SetClrModulation(0xffdcf3ee);
	var LargeCaveMushroom002 = CreateObject(LargeCaveMushroom, 210, 331);
	LargeCaveMushroom002->SetR(-112);
	LargeCaveMushroom002->SetClrModulation(0xffdcf3ee);

	var Rule_FastPump001 = CreateObject(Rule_FastPump, 77, 261);
	Rule_FastPump001->SetPumpSpeed(200);
	CreateObjectAbove(RoomEntrance, 49, 296);

	CreateObjectAbove(RoomExit, 592, 192);

	var Chest001 = CreateObjectAbove(Chest, 42, 423);

	var Kitchen001 = CreateObjectAbove(Kitchen, 83, 63);

	var Loom001 = CreateObjectAbove(Loom, 125, 63);

	CreateObjectAbove(Ruin_ChemicalLab, 324, 94);

	var PlayerStart001 = CreateObject(PlayerStart, 49, 261);
	PlayerStart001->SetStartingMaterial([]);
	PlayerStart001->SetViewLock(false);

	var PiranhaSmall001 = CreateObjectAbove(PiranhaSmall, 445, 212);
	PiranhaSmall001->Unstick(7);
	var PiranhaSmall002 = CreateObjectAbove(PiranhaSmall, 429, 216);
	PiranhaSmall002->Unstick(7);
	var PiranhaSmall003 = CreateObjectAbove(PiranhaSmall, 492, 83);
	PiranhaSmall003->Unstick(7);
	var PiranhaSmall004 = CreateObjectAbove(PiranhaSmall, 434, 83);
	PiranhaSmall004->Unstick(7);
	var PiranhaSmall005 = CreateObjectAbove(PiranhaSmall, 515, 106);
	PiranhaSmall005->Unstick(7);
	var PiranhaSmall006 = CreateObjectAbove(PiranhaSmall, 487, 81);
	PiranhaSmall006->Unstick(7);
	var PiranhaSmall007 = CreateObjectAbove(PiranhaSmall, 487, 82);
	PiranhaSmall007->Unstick(7);
	var PiranhaSmall008 = CreateObjectAbove(PiranhaSmall, 410, 131);
	PiranhaSmall008->Unstick(7);
	var PiranhaSmall009 = CreateObjectAbove(PiranhaSmall, 396, 117);
	PiranhaSmall009->Unstick(7);
	var PiranhaSmall010 = CreateObjectAbove(PiranhaSmall, 441, 118);
	PiranhaSmall010->Unstick(7);
	var PiranhaSmall011 = CreateObjectAbove(PiranhaSmall, 388, 207);
	PiranhaSmall011->Unstick(7);
	var PiranhaSmall012 = CreateObjectAbove(PiranhaSmall, 387, 134);
	PiranhaSmall012->Unstick(7);
	var PiranhaSmall013 = CreateObjectAbove(PiranhaSmall, 392, 97);
	PiranhaSmall013->Unstick(7);
	var PiranhaSmall014 = CreateObjectAbove(PiranhaSmall, 394, 69);
	PiranhaSmall014->Unstick(7);
	var PiranhaSmall015 = CreateObjectAbove(PiranhaSmall, 563, 68);
	PiranhaSmall015->Unstick(7);
	var PiranhaSmall016 = CreateObjectAbove(PiranhaSmall, 454, 69);
	PiranhaSmall016->Unstick(7);
	var PiranhaSmall017 = CreateObjectAbove(PiranhaSmall, 439, 61);
	PiranhaSmall017->Unstick(7);
	var PiranhaSmall018 = CreateObjectAbove(PiranhaSmall, 397, 192);
	PiranhaSmall018->Unstick(7);
	var PiranhaSmall019 = CreateObjectAbove(PiranhaSmall, 520, 71);
	PiranhaSmall019->Unstick(7);
	var PiranhaSmall020 = CreateObjectAbove(PiranhaSmall, 422, 211);
	PiranhaSmall020->Unstick(7);
	var PiranhaSmall021 = CreateObjectAbove(PiranhaSmall, 413, 141);
	PiranhaSmall021->Unstick(7);
	var PiranhaSmall022 = CreateObjectAbove(PiranhaSmall, 492, 131);
	PiranhaSmall022->Unstick(7);
	var PiranhaSmall023 = CreateObjectAbove(PiranhaSmall, 391, 62);
	PiranhaSmall023->Unstick(7);
	var PiranhaSmall024 = CreateObjectAbove(PiranhaSmall, 394, 71);
	PiranhaSmall024->Unstick(7);
	var PiranhaSmall025 = CreateObjectAbove(PiranhaSmall, 494, 145);
	PiranhaSmall025->Unstick(7);
	var PiranhaSmall026 = CreateObjectAbove(PiranhaSmall, 434, 107);
	PiranhaSmall026->Unstick(7);
	var PiranhaSmall027 = CreateObjectAbove(PiranhaSmall, 437, 91);
	PiranhaSmall027->Unstick(7);
	var PiranhaSmall028 = CreateObjectAbove(PiranhaSmall, 506, 143);
	PiranhaSmall028->Unstick(7);
	var PiranhaSmall029 = CreateObjectAbove(PiranhaSmall, 566, 67);
	PiranhaSmall029->Unstick(7);
	var PiranhaSmall030 = CreateObjectAbove(PiranhaSmall, 396, 178);
	PiranhaSmall030->Unstick(7);
	var PiranhaSmall031 = CreateObjectAbove(PiranhaSmall, 506, 111);
	PiranhaSmall031->Unstick(7);
	var PiranhaSmall032 = CreateObjectAbove(PiranhaSmall, 602, 91);
	PiranhaSmall032->Unstick(7);
	var PiranhaSmall033 = CreateObjectAbove(PiranhaSmall, 529, 63);
	PiranhaSmall033->Unstick(7);
	var PiranhaSmall034 = CreateObjectAbove(PiranhaSmall, 416, 209);
	PiranhaSmall034->Unstick(7);
	var PiranhaSmall035 = CreateObjectAbove(PiranhaSmall, 395, 70);
	PiranhaSmall035->Unstick(7);
	var PiranhaSmall036 = CreateObjectAbove(PiranhaSmall, 386, 201);
	PiranhaSmall036->Unstick(7);
	var PiranhaSmall037 = CreateObjectAbove(PiranhaSmall, 562, 79);
	PiranhaSmall037->Unstick(7);
	var PiranhaSmall038 = CreateObjectAbove(PiranhaSmall, 516, 58);
	PiranhaSmall038->Unstick(7);
	var PiranhaSmall039 = CreateObjectAbove(PiranhaSmall, 464, 121);
	PiranhaSmall039->Unstick(7);
	var PiranhaSmall040 = CreateObjectAbove(PiranhaSmall, 395, 120);
	PiranhaSmall040->Unstick(7);
	var PiranhaSmall041 = CreateObjectAbove(PiranhaSmall, 445, 139);
	PiranhaSmall041->Unstick(7);
	var PiranhaSmall042 = CreateObjectAbove(PiranhaSmall, 512, 120);
	PiranhaSmall042->Unstick(7);
	var PiranhaSmall043 = CreateObjectAbove(PiranhaSmall, 613, 131);
	PiranhaSmall043->Unstick(7);
	var PiranhaSmall044 = CreateObjectAbove(PiranhaSmall, 465, 88);
	PiranhaSmall044->Unstick(7);
	var PiranhaSmall045 = CreateObjectAbove(PiranhaSmall, 506, 67);
	PiranhaSmall045->Unstick(7);
	var PiranhaSmall046 = CreateObjectAbove(PiranhaSmall, 459, 110);
	PiranhaSmall046->Unstick(7);

	var Fish001 = CreateObjectAbove(Fish, 59, 155);
	Fish001->Unstick(7);
	var Fish002 = CreateObjectAbove(Fish, 43, 149);
	Fish002->Unstick(7);
	var Fish003 = CreateObjectAbove(Fish, 37, 158);
	Fish003->Unstick(7);
	CreateObjectAbove(Bone, 312, 384);

	CreateObject(Rock, 318, 314);
	CreateObject(Rock, 312, 413);
	CreateObject(Rock, 429, 363);
	CreateObject(Rock, 383, 298);
	CreateObject(Rock, 391, 255);
	CreateObject(Rock, 492, 253);
	CreateObject(Rock, 514, 344);
	CreateObject(Rock, 563, 385);
	CreateObject(Rock, 606, 308);
	CreateObject(Rock, 274, 300);
	CreateObject(Rock, 274, 231);

	CreateObject(Coal, 569, 311);
	CreateObject(Coal, 526, 244);

	Chest001->CreateContents(Metal, 14);

	Chest001->CreateContents(Wood, 10);

	CreateObject(Loam, 361, 415);
	CreateObject(Loam, 407, 264);
	CreateObject(Loam, 577, 417);

	Chest001->CreateContents(Dynamite, 4);

	Kitchen001->CreateContents(Bread, 5);

	Chest001->CreateContents(Hammer);

	var Pipe001 = CreateObjectAbove(Pipe, 428, 223);
	Pipe001->Unstick(7);

	CreateObjectAbove(TeleGlove, 301, 128);

	var Lantern001 = Loom001->CreateContents(Lantern);
	Lantern001->TurnOn();

	Chest001->CreateContents(Shovel);

	CreateObjectAbove(Seaweed, 368, 223);
	CreateObjectAbove(Seaweed, 418, 223);
	CreateObjectAbove(Seaweed, 440, 223);
	CreateObjectAbove(Seaweed, 491, 159);
	CreateObjectAbove(Seaweed, 557, 159);
	CreateObjectAbove(Seaweed, 590, 159);
	CreateObjectAbove(Seaweed, 494, 223);
	var Seaweed001 = CreateObjectAbove(Seaweed, 606, 191);
	Seaweed001->SetCon(1);
	var Seaweed002 = CreateObject(Seaweed, 470, 239);
	Seaweed002->SetCon(1);
	var Seaweed003 = CreateObjectAbove(Seaweed, 531, 191);
	Seaweed003->SetCon(1);

	var Coral001 = CreateObjectAbove(Coral, 464, 224);
	Coral001->SetCon(169);
	var Coral002 = CreateObjectAbove(Coral, 514, 157);
	Coral002->SetCon(141);
	var Coral003 = CreateObject(Coral, 558, 146);
	Coral003->SetCon(152);
	Coral003->SetR(-90);
	var Coral004 = CreateObjectAbove(Coral, 395, 66);
	Coral004->SetCon(153);

	var CoralSeed001 = CreateObjectAbove(CoralSeed, 545, 151);
	CoralSeed001->SetComDir(COMD_None);
	CoralSeed001->SetCategory(C4D_None);
	CoralSeed001->SetXDir(1);
	CoralSeed001->SetYDir(-1);
	var CoralSeed002 = CreateObjectAbove(CoralSeed, 561, 148);
	CoralSeed002->SetComDir(COMD_None);
	CoralSeed002->SetCategory(C4D_None);
	CoralSeed002->SetXDir(-1);
	CoralSeed002->SetYDir(-1);
	var CoralSeed003 = CreateObjectAbove(CoralSeed, 562, 151);
	CoralSeed003->SetComDir(COMD_None);
	CoralSeed003->SetCategory(C4D_None);
	CoralSeed003->SetYDir(1);
	var CoralSeed004 = CreateObjectAbove(CoralSeed, 557, 142);
	CoralSeed004->SetComDir(COMD_None);
	CoralSeed004->SetCategory(C4D_None);
	CoralSeed004->SetXDir(-1);
	CoralSeed004->SetYDir(-1);
	var CoralSeed005 = CreateObjectAbove(CoralSeed, 546, 147);
	CoralSeed005->SetComDir(COMD_None);
	CoralSeed005->SetCategory(C4D_None);
	CoralSeed005->SetYDir(1);

	CreateObjectAbove(AncientTablet, 606, 64);

	var Coral005 = CreateObjectAbove(Coral, 610, 68);
	Coral005->SetCon(145);
	Coral005.Plane = 550;
	Coral005->Unstick(7);
	var Coral006 = CreateObjectAbove(Coral, 608, 65);
	Coral006->SetCon(135);
	Coral006.Plane = 550;
	Coral006->Unstick(7);
	var Coral007 = CreateObjectAbove(Coral, 604, 159);
	Coral007->SetCon(143);
	Coral007.Plane = 550;

	var Trunk001 = CreateObject(Trunk, 293, 142);
	Trunk001->SetCon(94);
	Trunk001->SetR(-152);
	Trunk001.Plane = 550;
	var Trunk002 = CreateObject(Trunk, 106, 441);
	Trunk002->SetCon(107);
	Trunk002->SetR(-80);
	Trunk002.Plane = 550;
	return true;
}
