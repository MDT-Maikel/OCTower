/* Automatically created objects file */

func InitializeObjects()
{
	var Grass001 = CreateObjectAbove(Grass, 348, 236);
	Grass001.Plane = 1;
	var Grass002 = CreateObjectAbove(Grass, 356, 237);
	Grass002.Plane = 1;
	var Grass003 = CreateObjectAbove(Grass, 364, 236);
	Grass003.Plane = 1;
	var Grass004 = CreateObjectAbove(Grass, 371, 236);
	Grass004.Plane = 1;
	var Grass005 = CreateObjectAbove(Grass, 376, 235);
	Grass005.Plane = 1;
	var Grass006 = CreateObjectAbove(Grass, 383, 237);
	Grass006.Plane = 1;
	var Grass007 = CreateObjectAbove(Grass, 386, 235);
	Grass007.Plane = 1;
	var Grass008 = CreateObjectAbove(Grass, 388, 236);
	Grass008.Plane = 1;
	var Grass009 = CreateObjectAbove(Grass, 392, 237);
	Grass009.Plane = 1;
	var Grass010 = CreateObjectAbove(Grass, 359, 237);
	Grass010.Plane = 1;

	var Torch001 = CreateObjectAbove(Torch, 372, 212);
	Torch001->AttachToWall(false);
	Torch001->SetMeshMaterial("Torch", 0);
	Torch001->SetState(2);

	var Grass011 = CreateObjectAbove(Grass, 473, 341);
	Grass011.Plane = 1;
	var Grass012 = CreateObjectAbove(Grass, 457, 341);
	Grass012.Plane = 1;
	var Grass013 = CreateObjectAbove(Grass, 451, 340);
	Grass013.Plane = 1;
	var Grass014 = CreateObjectAbove(Grass, 487, 342);
	Grass014.Plane = 1;
	var Grass015 = CreateObjectAbove(Grass, 482, 340);
	Grass015.Plane = 1;
	var Grass016 = CreateObjectAbove(Grass, 476, 342);
	Grass016.Plane = 1;
	var Grass017 = CreateObjectAbove(Grass, 470, 343);
	Grass017.Plane = 1;
	var Grass018 = CreateObjectAbove(Grass, 463, 341);
	Grass018.Plane = 1;
	var Grass019 = CreateObjectAbove(Grass, 455, 341);
	Grass019.Plane = 1;

	var Flower001 = CreateObjectAbove(Flower, 350, 246);
	var Flower002 = CreateObjectAbove(Flower, 364, 246);
	var Flower003 = CreateObjectAbove(Flower, 375, 245);
	var Flower004 = CreateObjectAbove(Flower, 385, 245);

	var Rule_NoPowerNeed001 = CreateObject(Rule_NoPowerNeed, 273, 263);
	Rule_NoPowerNeed001->SetPosition(273, 263);

	var Flower005 = CreateObject(Flower, 369, 239);
	Flower005->SetCon(24);
	Flower005->SetPosition(369, 239);

	CreateObjectAbove(Keypad, 487, 194);

	var LargeCaveMushroom001 = CreateObject(LargeCaveMushroom, 279, 61);
	LargeCaveMushroom001->SetCon(95);
	LargeCaveMushroom001->SetR(150);
	LargeCaveMushroom001->SetClrModulation(0xffebecd3);
	LargeCaveMushroom001->SetPosition(279, 61);

	var SteamEngine001 = CreateObject(SteamEngine, 583, 320);
	SteamEngine001.MakeRoomPlayerOwner = true;
	SteamEngine001->SetPosition(583, 320);

	var Oil001 = SteamEngine001->CreateContents(Oil);
	Oil001->SetStackCount(300);
	Oil001->SetPosition(583, 320);

	CreateObjectAbove(Vine, 252, 343);
	CreateObjectAbove(Fern, 466, 344);

	CreateObjectAbove(Cotton, 476, 342);

	var Wheat001 = CreateObjectAbove(Wheat, 463, 344);
	Wheat001->SetMeshMaterial("wheat_material_ripe", 0);

	var Branch001 = CreateObject(Branch, 390, 312);
	Branch001->SetCon(109);
	Branch001->SetR(178);
	Branch001->SetPosition(390, 312);
	var Branch002 = CreateObject(Branch, 86, 45);
	Branch002->SetCon(122);
	Branch002->SetR(-55);
	Branch002->SetPosition(86, 45);

	var Trunk001 = CreateObject(Trunk, 116, 337);
	Trunk001->SetCon(157);
	Trunk001->SetR(64);
	Trunk001->SetPosition(116, 337);

	var Rule_BuyAtFlagpole001 = CreateObject(Rule_BuyAtFlagpole, 331, 266);
	Rule_BuyAtFlagpole001->SetPosition(331, 266);
	var Branch003 = CreateObject(Branch, 369, 410);
	Branch003->SetCon(109);
	Branch003->SetR(178);
	Branch003->SetPosition(369, 410);

	var BoilingLava001 = CreateObject(BoilingLava, 242, 265);
	BoilingLava001->SetPosition(242, 265);
	BoilingLava001->SetIntensity(4);
	BoilingLava001->SetArea(Shape->Rectangle(12, 360, 319, 101));

	CreateObjectAbove(Vine, 552, 96);
	CreateObjectAbove(EnvPack_Guidepost2, 442, 417);

	CreateObjectAbove(EnvPack_Rail, 180, 153);

	CreateObjectAbove(EnvPack_FenceRustic, 482, 346);

	CreateObjectAbove(EnvPack_Painting, 562, 262);

	var RoomEntrance001 = CreateObjectAbove(RoomEntrance, 273, 239);
	RoomEntrance001->SetColor(0xff32c832);

	var StoneDoor001 = CreateObject(StoneDoor, 316, 220);
	StoneDoor001->SetComDir(COMD_Down);
	StoneDoor001->MakeInvincible(false);
	StoneDoor001->SetPosition(316, 220);
	StoneDoor001->SetPlrViewOnSignalChange(true);

	var RoomExit001 = CreateObjectAbove(RoomExit, 401, 239);
	RoomExit001->SetColor(0xffc83232);

	CreateObjectAbove(Ruin_WoodenCabin, 301, 151);

	var ChemicalLab001 = CreateObjectAbove(ChemicalLab, 143, 151);

	var ToolsWorkshop001 = CreateObjectAbove(ToolsWorkshop, 523, 343);

	var Kitchen001 = CreateObjectAbove(Kitchen, 374, 456);

	CreateObjectAbove(SpinWheel, 597, 457);

	var Armory001 = CreateObjectAbove(Armory, 539, 150);
	Armory001->SetXDir(2);

	var Loom001 = CreateObjectAbove(Loom, 365, 151);

	var Chest001 = CreateObjectAbove(Chest, 357, 55);

	var Idol001 = CreateObjectAbove(Idol, 434, 344);
	Idol001->SetMeshMaterial("IdolGrayColor", 0);
	Idol001->SetAction("ItemLeftHigh");
	Idol001->EditorSetItemLeft({Bone="Javelin",MeshTransformation=[-1500,0,0,0,0,-1500,0,0,0,0,1500,0],Type=Javelin});
	Idol001->EditorSetItemRight({Bone="main",MeshTransformation=nil,Type=nil});

	CreateObjectAbove(Pump, 496, 271);

	var Compensator001 = CreateObject(Compensator, 481, 142);
	Compensator001.MakeRoomPlayerOwner = true;
	Compensator001->SetStoredPower(0);
	Compensator001->SetPosition(481, 142);
	var Compensator002 = CreateObject(Compensator, 386, 46);
	Compensator002.MakeRoomPlayerOwner = true;
	Compensator002->SetStoredPower(0);
	Compensator002->SetPosition(386, 46);
	var Compensator003 = CreateObject(Compensator, 416, 46);
	Compensator003.MakeRoomPlayerOwner = true;
	Compensator003->SetStoredPower(0);
	Compensator003->SetPosition(416, 46);
	var Compensator004 = CreateObject(Compensator, 446, 46);
	Compensator004.MakeRoomPlayerOwner = true;
	Compensator004->SetStoredPower(0);
	Compensator004->SetPosition(446, 46);

	var Hatch001 = CreateObject(Hatch, 605, 154);
	Hatch001->SetCategory(C4D_StaticBack);
	Hatch001->SetPosition(605, 154);
	var Hatch002 = CreateObject(Hatch, 448, 153);
	Hatch002->SetCategory(C4D_StaticBack);
	Hatch002->SetPosition(448, 153);
	var MetalLadder001 = CreateObject(MetalLadder, 1193, 175);
	MetalLadder001->SetPosition(1193, 175);
	MetalLadder001->SetLength(10);
	var MetalLadder002 = CreateObjectAbove(MetalLadder, 473, 111);
	MetalLadder002->SetLength(7);

	var Elevator001 = CreateObjectAbove(Elevator, 227, 151);
	Elevator001.MakeRoomPlayerOwner = true;
	Elevator001->SetDir(DIR_Right);
	Elevator001->CreateShaft(94);
	Elevator001->SetCasePosition(233);
	CreateObjectAbove(Switch, 194, 64);

	CreateObjectAbove(StrawMan, 378, 239);

	var Lorry001 = CreateObjectAbove(Lorry, 411, 151);
	Lorry001->SetYDir(-2);

	CreateObjectAbove(Locomotive, 44, 239);

	var Cannon001 = CreateObjectAbove(Cannon, 533, 455);
	CreateObjectAbove(Airship_Burnt, 594, 90);

	var StrawMan001 = CreateObject(StrawMan, 37, 182);
	StrawMan001->SetR(108);
	StrawMan001->SetPosition(37, 182);

	var PlayerStart001 = CreateObject(PlayerStart, 303, 263);
	PlayerStart001->SetPosition(303, 263);
	PlayerStart001->SetStartingBaseMaterial([]);
	PlayerStart001->SetStartingWealth(500);
	PlayerStart001->SetViewLock(false);

	var Clonk001 = CreateObjectAbove(Clonk, 499, 342);
	Clonk001->SetDir(DIR_Right);
	Clonk001->SetColor(0xff81e4ff);
	Clonk001->Unstick(7);
	Clonk001->SetName("Anra");
	Clonk001->MakeInvincible(false);
	Clonk001->SetSkin(3);
	var Clonk002 = CreateObjectAbove(Clonk, 298, 238);
	Clonk002->SetColor(0xa0a050);
	Clonk002->SetMeshMaterial("Clonk_Guard", 0);
	Clonk002->SetName("Peter");
	Clonk002->MakeInvincible(false);
	Clonk002->Unstick(7);
	Clonk002->SetDir(DIR_Left);
	Clonk002->SetAlternativeSkin("Guard");
	var Clonk003 = CreateObjectAbove(Clonk, 162, 238);
	Clonk003->SetDir(DIR_Right);
	Clonk003->SetColor(0xffffff4b);
	Clonk003->Unstick(7);
	Clonk003->SetName("Lila");
	Clonk003->MakeInvincible(false);
	Clonk003->SetSkin(3);
	var Clonk004 = CreateObjectAbove(Clonk, 166, 63);
	Clonk004->SetColor(0x4040ff);
	Clonk004->SetMeshMaterial("Clonk_MaleBlackHair", 0);
	Clonk004->SetName("Harry");
	Clonk004->MakeInvincible(false);
	Clonk004->Unstick(7);
	Clonk004->SetDir(DIR_Left);
	Clonk004->SetAlternativeSkin("MaleBlackHair");
	var Clonk005 = CreateObjectAbove(Clonk, 556, 151);
	Clonk005->SetColor(0xa0a020);
	Clonk005->Unstick(7);
	Clonk005->SetName("Gerard");
	Clonk005->MakeInvincible(false);
	Clonk005->SetDir(DIR_Left);
	Clonk005->SetAlternativeSkin("Leather");
	var Clonk006 = CreateObjectAbove(Clonk, 70, 325);
	Clonk006->SetDir(DIR_Right);
	Clonk006->SetColor(0xba8e37);
	Clonk006->SetMeshMaterial("Clonk_Youngster", 0);
	Clonk006->MakeInvincible(false);
	Clonk006->Unstick(7);
	Clonk006->SetAlternativeSkin("Youngster");

	var Wipf001 = CreateObjectAbove(Wipf, 333, 239);
	Wipf001->SetComDir(COMD_Left);
	Wipf001->SetXDir(-20);
	Wipf001->Unstick(7);
	var Wipf002 = CreateObjectAbove(Wipf, 411, 230);
	Wipf002->SetDir(DIR_Right);
	Wipf002->SetComDir(COMD_Right);
	Wipf002->SetXDir(8);
	Wipf002->SetYDir(-2);
	Wipf002->Unstick(7);

	var Fish001 = CreateObjectAbove(Fish, 117, 257);
	Fish001->Unstick(7);
	var Fish002 = CreateObjectAbove(Fish, 142, 243);
	Fish002->Kill(Fish002, true);
	Fish002->SetDir(DIR_Right);
	Fish002->DoEnergy(-40);
	var Fish003 = CreateObjectAbove(Fish, 97, 255);
	Fish003->Unstick(7);

	var Mosquito001 = CreateObjectAbove(Mosquito, 89, 180);
	Mosquito001->SetComDir(COMD_Up);
	Mosquito001->Unstick(7);
	var Mosquito002 = CreateObjectAbove(Mosquito, 35, 145);
	Mosquito002->Unstick(7);
	var Mosquito003 = CreateObjectAbove(Mosquito, 42, 119);
	Mosquito003->SetDir(DIR_Right);
	Mosquito003->SetComDir(COMD_Right);
	Mosquito003->Unstick(7);

	var Chippie001 = CreateObjectAbove(Chippie, 494, 199);
	Chippie001->Unstick(7);
	var Chippie002 = CreateObjectAbove(Chippie, 546, 199);
	Chippie002->SetDir(DIR_Right);
	Chippie002->Unstick(7);
	var Chippie003 = CreateObjectAbove(Chippie, 552, 199);
	Chippie003->SetDir(DIR_Right);
	Chippie003->Unstick(7);
	var Chippie004 = CreateObjectAbove(Chippie, 550, 199);
	Chippie004->Unstick(7);

	var Dialogue001 = Clonk001->SetDialogue("Editor",false);
	Dialogue001->SetUserDialogue({Actions=[{AfterMessage="next",Function="message",Options=[],Speaker={Function="triggering_clonk"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Hallo! Ich suche Hanswurst.",Function="Translate",US="Hi! I am looking for Hanswurst."}}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Er ist mein Freund, aber liegt uns weit vorne im Turm.",Function="Translate",US="He is my boyfriend, but is way ahead of us in the tower."}}}],Function="sequence"}, nil);

	var Lantern001 = Clonk004->CreateContents(Lantern);
	Lantern001->SetPosition(166, 54);
	Lantern001->TurnOn();

	var Dialogue002 = Clonk004->SetDialogue("Editor",false);
	Dialogue002->SetUserDialogue({Actions=[{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Dieser Schalter steckt fest...",Function="Translate",US="This switch is stuck..."}}}],Function="sequence"}, nil);

	var DivingHelmet001 = Clonk003->CreateContents(DivingHelmet);
	DivingHelmet001->SetPosition(162, 229);

	var Dialogue003 = Clonk003->SetDialogue("Editor",false);
	Dialogue003->SetUserDialogue({Actions=[{AfterMessage="next",Function="message",Options=[],Speaker={Function="triggering_object"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Hallo! Bist du Hanswurst?",Function="Translate",US="Hi! Are you Hanswurst?"}}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Depp, ich bin eine Frau!",Function="Translate",US="Idiot, I am a woman!"}}}],Function="sequence"}, nil);

	var Blunderbuss001 = Clonk002->CreateContents(Blunderbuss);
	Blunderbuss001->SetPosition(298, 229);

	var Dialogue004 = Clonk002->SetDialogue("Editor",false);
	Dialogue004->SetUserDialogue({Actions=[{AfterMessage="next",Function="message",Options=[],Speaker={Function="triggering_clonk"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Hallo, ich möchte rein.",Function="Translate",US="Hi, I wan't to enter."}}},{Condition={Context={Function="triggering_clonk"},Function="Boolean_script",Script={Function="string_constant",Value={Function="Translate",US="Crypto->ComputeHash(GetName()) == \"7AZzom^UAEiyoq>D#Z[Al]8kq\""}}},FalseEvaluator={Function="goto",Index={Function="int_constant",Value=2}},Function="if",TrueEvaluator={Function="goto",Index={Function="int_constant",Value=6}}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Nein! Hanswurst lebt hier, nur er darf rein!",Function="Translate",US="No! Hanswurst lives here, only he may enter!"}}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="triggering_clonk"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Wo ist er denn?",Function="Translate",US="Where is he?"}}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Nicht hier!",Function="Translate",US="Not here!"}}},{Function="stop_sequence"},{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Guten Tag Hanswurst, ich öffne sofort die Tür!",Function="Translate",US="Good day Hanswurst, I'll open the gate sir!"}}},{Door={Function="object_constant",Value=StoneDoor001},Function="open_door"},{Function="stop_sequence"}],Function="sequence"}, nil);
	var Dialogue005 = Clonk005->SetDialogue("Editor",false);
	Dialogue005->SetUserDialogue({Actions=[{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Du kannst dir jede meiner Waffen nehmen.",Function="Translate",US="You can have any of my weapons."}}}],Function="sequence"}, nil);
	var Dialogue006 = Clonk006->SetDialogue("Editor",false);
	Dialogue006->SetUserDialogue({Actions=[{AfterMessage="next",Function="message",Options=[],Speaker={Function="triggering_clonk"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Tag, wie bist du hierhin gekommen?",Function="Translate",US="Hi, how did you get up here?"}}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Gute Frage! Aber wichtiger, wie komme ich zum nächsten Raum?",Function="Translate",US="Good question! But more important, how do I get to the next room?"}}}],Function="sequence"}, nil);

	var LavaCore001 = CreateObjectAbove(LavaCore, 297, 398);
	LavaCore001->SetComDir(COMD_None);
	LavaCore001->SetCon(70);
	LavaCore001->SetXDir(-16);
	LavaCore001->Unstick(7);
	var LavaCore002 = CreateObjectAbove(LavaCore, 100, 390);
	LavaCore002->SetCon(70);
	LavaCore002->Unstick(7);
	var LavaCore003 = CreateObjectAbove(LavaCore, 198, 390);
	LavaCore003->SetComDir(COMD_None);
	LavaCore003->SetCon(70);
	LavaCore003->SetXDir(-13);
	LavaCore003->Unstick(7);
	var Coal001 = ChemicalLab001->CreateContents(Coal);
	Coal001->SetPosition(143, 126);
	var Coal002 = ChemicalLab001->CreateContents(Coal);
	Coal002->SetPosition(143, 126);
	var Coal003 = ChemicalLab001->CreateContents(Coal);
	Coal003->SetPosition(143, 126);
	var Coal004 = ChemicalLab001->CreateContents(Coal);
	Coal004->SetPosition(143, 126);
	var Coal005 = Lorry001->CreateContents(Coal);
	Coal005->SetPosition(411, 144);
	var Coal006 = Lorry001->CreateContents(Coal);
	Coal006->SetPosition(411, 144);
	var Coal007 = Lorry001->CreateContents(Coal);
	Coal007->SetPosition(411, 144);
	var Coal008 = Lorry001->CreateContents(Coal);
	Coal008->SetPosition(411, 144);
	var Coal009 = Lorry001->CreateContents(Coal);
	Coal009->SetPosition(411, 144);
	var Coal010 = Lorry001->CreateContents(Coal);
	Coal010->SetPosition(411, 144);

	var CottonSeed001 = Loom001->CreateContents(CottonSeed);
	CottonSeed001->SetPosition(365, 132);
	var CottonSeed002 = Loom001->CreateContents(CottonSeed);
	CottonSeed002->SetPosition(365, 132);
	var CottonSeed003 = Loom001->CreateContents(CottonSeed);
	CottonSeed003->SetPosition(365, 132);
	var CottonSeed004 = Loom001->CreateContents(CottonSeed);
	CottonSeed004->SetPosition(365, 132);

	var Wood001 = ToolsWorkshop001->CreateContents(Wood);
	Wood001->SetPosition(523, 324);
	var Wood002 = ToolsWorkshop001->CreateContents(Wood);
	Wood002->SetPosition(523, 324);
	var Wood003 = ToolsWorkshop001->CreateContents(Wood);
	Wood003->SetPosition(523, 324);
	var Wood004 = ToolsWorkshop001->CreateContents(Wood);
	Wood004->SetPosition(523, 324);
	var Wood005 = ToolsWorkshop001->CreateContents(Wood);
	Wood005->SetPosition(523, 324);
	var Wood006 = ToolsWorkshop001->CreateContents(Wood);
	Wood006->SetPosition(523, 324);
	var Wood007 = Armory001->CreateContents(Wood);
	Wood007->SetPosition(539, 126);
	var Wood008 = Armory001->CreateContents(Wood);
	Wood008->SetPosition(539, 126);
	var Wood009 = Armory001->CreateContents(Wood);
	Wood009->SetPosition(539, 126);
	var Wood010 = Armory001->CreateContents(Wood);
	Wood010->SetPosition(539, 126);
	var Wood011 = ChemicalLab001->CreateContents(Wood);
	Wood011->SetPosition(143, 126);
	var Wood012 = ChemicalLab001->CreateContents(Wood);
	Wood012->SetPosition(143, 126);
	var Wood013 = ChemicalLab001->CreateContents(Wood);
	Wood013->SetPosition(143, 126);
	var Wood014 = Lorry001->CreateContents(Wood);
	Wood014->SetPosition(411, 144);
	var Wood015 = Lorry001->CreateContents(Wood);
	Wood015->SetPosition(411, 144);
	var Wood016 = Lorry001->CreateContents(Wood);
	Wood016->SetPosition(411, 144);
	var Wood017 = Lorry001->CreateContents(Wood);
	Wood017->SetPosition(411, 144);
	var Wood018 = Lorry001->CreateContents(Wood);
	Wood018->SetPosition(411, 144);
	var Wood019 = Lorry001->CreateContents(Wood);
	Wood019->SetPosition(411, 144);
	var Wood020 = Lorry001->CreateContents(Wood);
	Wood020->SetPosition(411, 144);
	var Wood021 = Lorry001->CreateContents(Wood);
	Wood021->SetPosition(411, 144);

	var Metal001 = ChemicalLab001->CreateContents(Metal);
	Metal001->SetPosition(143, 126);
	var Metal002 = ChemicalLab001->CreateContents(Metal);
	Metal002->SetPosition(143, 126);
	var Metal003 = Armory001->CreateContents(Metal);
	Metal003->SetPosition(539, 126);
	var Metal004 = Armory001->CreateContents(Metal);
	Metal004->SetPosition(539, 126);
	var Metal005 = Armory001->CreateContents(Metal);
	Metal005->SetPosition(539, 126);
	var Metal006 = ToolsWorkshop001->CreateContents(Metal);
	Metal006->SetPosition(523, 324);
	var Metal007 = ToolsWorkshop001->CreateContents(Metal);
	Metal007->SetPosition(523, 324);
	var Metal008 = ToolsWorkshop001->CreateContents(Metal);
	Metal008->SetPosition(523, 324);
	var Metal009 = ToolsWorkshop001->CreateContents(Metal);
	Metal009->SetPosition(523, 324);

	var Amethyst001 = Chest001->CreateContents(Amethyst);
	Amethyst001->SetPosition(357, 44);
	var Amethyst002 = Chest001->CreateContents(Amethyst);
	Amethyst002->SetPosition(357, 44);

	var Ruby001 = Chest001->CreateContents(Ruby);
	Ruby001->SetPosition(357, 44);
	var Ruby002 = Chest001->CreateContents(Ruby);
	Ruby002->SetPosition(357, 44);

	var Blunderbuss002 = Armory001->CreateContents(Blunderbuss);
	Blunderbuss002->SetPosition(539, 126);

	CreateObjectAbove(DivingHelmet, 113, 263);

	var Lantern002 = ChemicalLab001->CreateContents(Lantern);
	Lantern002->SetPosition(143, 126);
	Lantern002->TurnOn();
	var Lantern003 = ToolsWorkshop001->CreateContents(Lantern);
	Lantern003->SetPosition(523, 324);
	Lantern003->TurnOn();
	var Lantern004 = Kitchen001->CreateContents(Lantern);
	Lantern004->SetPosition(374, 431);
	Lantern004->TurnOn();
	var Lantern005 = Armory001->CreateContents(Lantern);
	Lantern005->SetPosition(539, 126);
	Lantern005->TurnOn();
	var Lantern006 = Loom001->CreateContents(Lantern);
	Lantern006->SetPosition(365, 132);
	Lantern006->TurnOn();

	CreateObjectAbove(Mushroom, 358, 238);

	var AncientTablet001 = Wipf002->CreateContents(AncientTablet);
	AncientTablet001->SetPosition(411, 225);

	CreateObjectAbove(Seaweed, 86, 264);
	CreateObjectAbove(Seaweed, 102, 264);
	CreateObjectAbove(Seaweed, 114, 263);
	CreateObjectAbove(Seaweed, 122, 264);

	var WindBag001 = CreateObject(WindBag, 46, 331);
	WindBag001->SetR(-41);
	WindBag001->SetPosition(46, 331);

	var TeleGlove001 = CreateObject(TeleGlove, 231, 433);
	TeleGlove001->SetPosition(231, 433);

	var Bread001 = CreateObjectAbove(Bread, 50, 333);
	Bread001->Unstick(7);
	var Bread002 = Kitchen001->CreateContents(Bread);
	Bread002->SetPosition(374, 431);
	var Bread003 = Kitchen001->CreateContents(Bread);
	Bread003->SetPosition(374, 431);

	var Barrel001 = CreateObject(Barrel, 38, 329);
	Barrel001->SetR(105);
	Barrel001->SetXDir(-2);
	Barrel001->SetColor(0xff000000);
	Barrel001->SetPosition(38, 329);
	Barrel001->Unstick(7);

	var MetalBarrel001 = CreateObject(MetalBarrel, 570, 268);
	MetalBarrel001->SetR(-75);
	MetalBarrel001->SetColor(0xff000000);
	MetalBarrel001->SetPosition(570, 268);
	MetalBarrel001->Unstick(7);

	var DynamiteBox001 = ChemicalLab001->CreateContents(DynamiteBox);
	DynamiteBox001->SetPosition(143, 126);
	var DynamiteBox002 = ChemicalLab001->CreateContents(DynamiteBox);
	DynamiteBox002->SetPosition(143, 126);
	var GrenadeLauncher001 = Armory001->CreateContents(GrenadeLauncher);
	GrenadeLauncher001->SetPosition(539, 126);

	var IronBomb001 = Armory001->CreateContents(IronBomb);
	IronBomb001->SetPosition(539, 126);
	var IronBomb002 = Armory001->CreateContents(IronBomb);
	IronBomb002->SetPosition(539, 126);

	var Helmet001 = Armory001->CreateContents(Helmet);
	Helmet001->SetPosition(539, 126);

	var LeadBullet001 = Armory001->CreateContents(LeadBullet);
	LeadBullet001->SetPosition(539, 126);
	var LeadBullet002 = Armory001->CreateContents(LeadBullet);
	LeadBullet002->SetPosition(539, 126);

	var Chippie_Egg001 = CreateObjectAbove(Chippie_Egg, 550, 199);
	Chippie_Egg001->SetCon(65);
	Chippie_Egg001->Unstick(7);
	var Chippie_Egg002 = CreateObjectAbove(Chippie_Egg, 575, 200);
	Chippie_Egg002->SetCon(65);

	var WallKit001 = ToolsWorkshop001->CreateContents(WallKit);
	WallKit001->SetPosition(523, 324);
	var WallKit002 = ToolsWorkshop001->CreateContents(WallKit);
	WallKit002->SetPosition(523, 324);

	var Diamond001 = Chest001->CreateContents(Diamond);
	Diamond001->SetPosition(357, 44);
	var Diamond002 = Chest001->CreateContents(Diamond);
	Diamond002->SetPosition(357, 44);

	var PowderKeg001 = CreateObjectAbove(PowderKeg, 75, 63);
	PowderKeg001->Unstick(7);
	var PowderKeg002 = Cannon001->CreateContents(PowderKeg);
	PowderKeg002->SetPosition(533, 448);

	var Balloon001 = ToolsWorkshop001->CreateContents(Balloon);
	Balloon001->SetPosition(523, 324);

	var Bucket001 = ToolsWorkshop001->CreateContents(Bucket);
	Bucket001->SetPosition(523, 324);

	var Pickaxe001 = ToolsWorkshop001->CreateContents(Pickaxe);
	Pickaxe001->SetPosition(523, 324);
	var Pickaxe002 = CreateObject(Pickaxe, 489, 446);
	Pickaxe002->SetR(-35);
	Pickaxe002->SetPosition(489, 446);

	var Javelin001 = Armory001->CreateContents(Javelin);
	Javelin001->SetPosition(539, 126);

	var Flour001 = Kitchen001->CreateContents(Flour);
	Flour001->SetPosition(374, 431);
	var Flour002 = Kitchen001->CreateContents(Flour);
	Flour002->SetPosition(374, 431);

	var Pipe001 = ToolsWorkshop001->CreateContents(Pipe);
	Pipe001->SetNeutralPipe();
	Pipe001->SetPosition(523, 324);
	var Pipe002 = ToolsWorkshop001->CreateContents(Pipe);
	Pipe002->SetNeutralPipe();
	Pipe002->SetPosition(523, 324);

	var GrappleBow001 = CreateObject(GrappleBow, 449, 449);
	GrappleBow001->SetPosition(449, 449);

	var FishRoe001 = CreateObjectAbove(FishRoe, 77, 259);
	FishRoe001->SetComDir(COMD_None);
	FishRoe001->SetCategory(C4D_None);
	var FishRoe002 = CreateObjectAbove(FishRoe, 86, 260);
	FishRoe002->SetComDir(COMD_None);
	FishRoe002->SetCategory(C4D_None);
	var FishRoe003 = CreateObjectAbove(FishRoe, 85, 258);
	FishRoe003->SetComDir(COMD_None);
	FishRoe003->SetCategory(C4D_None);
	var FishRoe004 = CreateObjectAbove(FishRoe, 100, 255);
	FishRoe004->SetComDir(COMD_None);
	FishRoe004->SetCategory(C4D_None);
	var FishRoe005 = CreateObjectAbove(FishRoe, 118, 261);
	FishRoe005->SetComDir(COMD_None);
	FishRoe005->SetCategory(C4D_None);
	var Key001 = Chest001->CreateContents(Key);
	Key001->SetPosition(357, 44);

	var Stalactite001 = CreateObject(Stalactite, 407, 283);
	Stalactite001->SetPosition(407, 283);

	var Club001 = CreateObjectAbove(Club, 605, 455);
	Club001->Unstick(7);

	var SmokeBomb001 = CreateObject(SmokeBomb, 546, 31);
	SmokeBomb001->SetR(19);
	SmokeBomb001->SetPosition(546, 31);
	var Firestone001 = ChemicalLab001->CreateContents(Firestone);
	Firestone001->SetPosition(143, 126);
	var Firestone002 = ChemicalLab001->CreateContents(Firestone);
	Firestone002->SetPosition(143, 126);
	var Firestone003 = ChemicalLab001->CreateContents(Firestone);
	Firestone003->SetPosition(143, 126);

	var Deco_TunnelSupport001 = CreateObjectAbove(Deco_TunnelSupport, 176, 240);
	Deco_TunnelSupport001->Extend(63);
	var Deco_TunnelSupport002 = CreateObjectAbove(Deco_TunnelSupport, 353, 345);
	Deco_TunnelSupport002->Extend(51);
	return true;
}
