/* Automatically created objects file */

func InitializeObjects()
{
	var Grass001 = CreateObjectAbove(Grass, 412, 254);
	var Grass002 = CreateObjectAbove(Grass, 460, 239);
	var Grass003 = CreateObjectAbove(Grass, 457, 239);
	var Grass004 = CreateObjectAbove(Grass, 262, 254);
	var Grass005 = CreateObjectAbove(Grass, 273, 254);
	var Grass006 = CreateObjectAbove(Grass, 277, 254);
	var Grass007 = CreateObjectAbove(Grass, 282, 254);
	var Grass008 = CreateObjectAbove(Grass, 290, 254);
	var Grass009 = CreateObject(Grass, 300, 253);
	Grass009->SetPosition(300, 253);
	var Grass010 = CreateObjectAbove(Grass, 303, 253);
	var Grass011 = CreateObjectAbove(Grass, 294, 255);
	var Grass012 = CreateObjectAbove(Grass, 275, 254);
	var Grass013 = CreateObjectAbove(Grass, 266, 253);
	var JetStream001 = CreateObject(JetStream, 127, 283);
	JetStream001->Create(0, 0, -54, 80, nil, 32, 120);
	JetStream001->SetPosition(127, 283);

	CreateObjectAbove(Deco_Tree_Deciduous4, 474, 243);

	var LargeCaveMushroom001 = CreateObject(LargeCaveMushroom, 353, 423);
	LargeCaveMushroom001->SetCon(84);
	LargeCaveMushroom001->SetR(-8);
	LargeCaveMushroom001->SetClrModulation(0xffe5d3e1);
	LargeCaveMushroom001->SetPosition(353, 423);

	CreateObjectAbove(Fern, 338, 448);
	CreateObjectAbove(Fern, 355, 448);
	CreateObjectAbove(Fern, 380, 327);

	CreateObjectAbove(Trunk, 286, 260);

	var Wheat001 = CreateObjectAbove(Wheat, 290, 255);
	Wheat001->SetMeshMaterial("wheat_material_ripe", 0);
	var Wheat002 = CreateObjectAbove(Wheat, 294, 255);
	Wheat002->SetMeshMaterial("wheat_material_ripe", 0);

	CreateObjectAbove(Flower, 273, 263);

	var Cotton001 = CreateObjectAbove(Cotton, 414, 256);
	Cotton001->GrowBranch(true, 0);
	Cotton001->GrowBranch(true, 1);
	Cotton001->GrowBranch(true, 2);
	var Cotton002 = CreateObjectAbove(Cotton, 432, 256);
	Cotton002->GrowBranch(true, 0);
	Cotton002->GrowBranch(true, 1);

	CreateObjectAbove(Tree_Deciduous, 297, 259);
	var Tree_Deciduous001 = CreateObjectAbove(Tree_Deciduous, 387, 248);
	Tree_Deciduous001->SetCon(102);

	var Tree_Coniferous2001 = CreateObjectAbove(Tree_Coniferous2, 391, 252);
	Tree_Coniferous2001->SetCon(103);

	var Tree_Coniferous4001 = CreateObjectAbove(Tree_Coniferous4, 318, 243);
	Tree_Coniferous4001->SetCon(104);

	var Time001 = CreateObject(Time, 116, 207);
	Time001->SetPosition(116, 207);
	Time001->SetTime(201);
	Time001->SetCycleSpeed(60);

	CreateObjectAbove(Vine, 418, 101);
	CreateObjectAbove(Vine, 453, 100);
	var Branch001 = CreateObject(Branch, 396, 49);
	Branch001->SetCon(112);
	Branch001->SetR(-120);
	Branch001->SetPosition(396, 49);
	var Branch002 = CreateObject(Branch, 446, 72);
	Branch002->SetCon(95);
	Branch002->SetR(154);
	Branch002->SetPosition(446, 72);
	var Branch003 = CreateObject(Branch, 292, 133);
	Branch003->SetCon(117);
	Branch003->SetR(123);
	Branch003->SetPosition(292, 133);

	var JetStream002 = CreateObject(JetStream, 583, 145);
	JetStream002->Create(0, 0, -79, 48, nil, 40, 40);
	JetStream002->SetPosition(583, 145);

	var Wheat003 = CreateObjectAbove(Wheat, 320, 240);
	Wheat003->SetMeshMaterial("wheat_material_ripe", 0);

	var JetStream003 = CreateObject(JetStream, 283, 135);
	JetStream003->Create(0, 0, 96, -37, nil, 40, 64);
	JetStream003->SetPosition(283, 135);

	var Waterfall001 = CreateObject(Waterfall, 229, 369);
	Waterfall001->SetPosition(229, 369);
	Waterfall001->AddSourceEffect(191, 381, 10, "Water");
	Waterfall001->SetSoundLocation(229, 369);
	Waterfall001->SetDirection(-11, 12, 5, 6);
	Waterfall001->AddDrainEffect(200, 426, 10);

	var Trunk001 = CreateObject(Trunk, 204, 381);
	Trunk001->SetCon(98);
	Trunk001->SetR(91);
	Trunk001->MakeInvincible(false);
	Trunk001->SetPosition(204, 381);

	var Rule_NoPowerNeed001 = CreateObject(Rule_NoPowerNeed, 144, 206);
	Rule_NoPowerNeed001->SetPosition(144, 206);

	var Rule_BuyAtFlagpole001 = CreateObject(Rule_BuyAtFlagpole, 171, 206);
	Rule_BuyAtFlagpole001->SetPosition(171, 206);

	var Rule_FastPump001 = CreateObject(Rule_FastPump, 66, 204);
	Rule_FastPump001->SetPosition(66, 204);
	Rule_FastPump001->SetPumpSpeed(50);

	var Branch004 = CreateObject(Branch, 61, 182);
	Branch004->SetCon(125);
	Branch004->SetR(144);
	Branch004->SetPosition(61, 182);

	var Barrel001 = CreateObject(Barrel, 547, 248);
	Barrel001->SetR(31);
	Barrel001->SetColor(0xff2e4161);
	Barrel001->SetName("Wooden Barrel with Water");
	Barrel001->SetPosition(547, 248);

	var Water001 = Barrel001->CreateContents(Water);
	Water001->SetStackCount(300);
	Water001->SetPosition(547, 248);

	var JetStream004 = CreateObject(JetStream, 181, 328);
	JetStream004->Create(0, 0, -57, 68, nil, 24, 60);
	JetStream004->SetPosition(181, 328);
	var JetStream005 = CreateObject(JetStream, 493, 31);
	JetStream005->Create(0, 0, -2, 91, nil, 28, 88);
	JetStream005->SetPosition(493, 31);

	var Flower001 = CreateObject(Flower, 252, 259);
	Flower001->SetCon(13);
	Flower001->SetPosition(252, 259);
	var ToolsWorkshop001 = CreateObjectAbove(ToolsWorkshop, 351, 231);

	var Basement001 = CreateObject(Basement, 352, 236);
	Basement001->SetParent(ToolsWorkshop001);
	Basement001->SetPosition(352, 236);

	var RoomEntrance001 = CreateObjectAbove(RoomEntrance, 65, 255);
	RoomEntrance001->SetColor(0xff32c832);

	var RoomExit001 = CreateObjectAbove(RoomExit, 170, 304);
	RoomExit001->SetColor(0xffc83232);

	var StoneDoor001 = CreateObject(StoneDoor, 204, 236);
	StoneDoor001->SetComDir(COMD_Down);
	StoneDoor001->SetPosition(204, 236);
	StoneDoor001->SetPlrViewOnSignalChange(true);

	var Chest001 = CreateObjectAbove(Chest, 603, 151);

	var ChemicalLab001 = CreateObjectAbove(ChemicalLab, 150, 128);

	var Armory001 = CreateObjectAbove(Armory, 45, 127);

	var Idol001 = CreateObjectAbove(Idol, 275, 88);
	Idol001->SetMeshMaterial("IdolGrayColor", 0);
	Idol001->SetAction("ItemLeftHigh");
	Idol001->EditorSetItemLeft({Bone="main",MeshTransformation=[-1200,0,0,0,0,-1200,0,0,0,0,1200,0],Type=Club});

	var WindGenerator001 = CreateObject(WindGenerator, 370, 198);
	WindGenerator001.MakeRoomPlayerOwner = true;
	WindGenerator001->SetPosition(370, 198);

	var Hatch001 = CreateObject(Hatch, 99, 151);
	Hatch001->SetCategory(C4D_StaticBack);
	Hatch001->SetPosition(99, 151);
	var Hatch002 = CreateObject(Hatch, 99, 129);
	Hatch002->SetCategory(C4D_StaticBack);
	Hatch002->SetPosition(99, 129);

	var Flagpole001 = CreateObject(Flagpole, 415, 222);
	Flagpole001.MakeRoomPlayerOwner = true;
	Flagpole001->SetPosition(415, 222);
	var Switch001 = CreateObjectAbove(Switch, 134, 257);
	Switch001->SetSwitchTarget(StoneDoor001);
	Switch001->SetSwitchDir(1);
	var Switch002 = CreateObjectAbove(Switch, 582, 456);
	Switch002->SetSwitchDir(-1);
	Switch002->SetActions(nil, {Actions=[{Context={Function="object_constant",Value=Hatch001},Function="Action_script",Script={Function="string_constant",Value={DE="DoOpen()",Function="Translate",US="DoOpen()"}}},{Context={Function="object_constant",Value=Hatch002},Function="Action_script",Script={Function="string_constant",Value={DE="DoOpen()",Function="Translate",US="DoOpen()"}}},{Context={Function="action_object"},Function="Action_script",Script={Function="string_constant",Value="ScheduleCall(this, \"SetAction\", 14, 0, \"SwitchLeft\")"}}],Function="sequence"});

	var Lorry001 = CreateObject(Lorry, 386, 319);
	Lorry001->SetR(55);
	Lorry001->SetPosition(386, 319);

	CreateObjectAbove(Locomotive, 101, 255);

	var PlayerStart001 = CreateObject(PlayerStart, 91, 205);
	PlayerStart001->SetPosition(91, 205);
	PlayerStart001->SetStartingKnowledge("allexcept", [WallKit,IronBomb]);
	PlayerStart001->SetStartingBaseMaterial([{count=5,id=DynamiteBox},{count=5,id=Pickaxe}]);
	PlayerStart001->SetStartingWealth(200);
	PlayerStart001->SetViewLock(false);

	var Fish001 = CreateObjectAbove(Fish, 541, 289);
	Fish001->Unstick(7);
	var Fish002 = CreateObjectAbove(Fish, 565, 287);
	Fish002->Unstick(7);
	var Fish003 = CreateObjectAbove(Fish, 557, 277);
	Fish003->Unstick(7);

	var Butterfly001 = CreateObjectAbove(Butterfly, 302, 251);
	Butterfly001->SetDir(DIR_Right);
	Butterfly001->SetComDir(COMD_None);
	Butterfly001->Unstick(7);
	Butterfly001->SetAction("Fly");
	var Butterfly002 = CreateObjectAbove(Butterfly, 282, 251);
	Butterfly002->SetComDir(COMD_None);
	Butterfly002->Unstick(7);
	Butterfly002->SetAction("Fly");
	var Butterfly003 = CreateObjectAbove(Butterfly, 290, 252);
	Butterfly003->SetDir(DIR_Right);
	Butterfly003->SetComDir(COMD_None);
	Butterfly003->Unstick(7);
	Butterfly003->SetAction("Fly");
	var Butterfly004 = CreateObjectAbove(Butterfly, 274, 251);
	Butterfly004->SetComDir(COMD_None);
	Butterfly004->Unstick(7);
	Butterfly004->SetAction("SlowFly");
	var Butterfly005 = CreateObjectAbove(Butterfly, 388, 114);
	Butterfly005->SetDir(DIR_Right);
	Butterfly005->SetComDir(COMD_DownLeft);
	Butterfly005->SetXDir(1);
	Butterfly005->SetYDir(-1);
	Butterfly005->Unstick(7);
	Butterfly005->SetCommand("Call", Butterfly005, nil, 0, nil, "SleepComplete");
	Butterfly005->SetAction("SlowFly");
	var Butterfly006 = CreateObjectAbove(Butterfly, 461, 236);
	Butterfly006->SetComDir(COMD_None);
	Butterfly006->Unstick(7);
	Butterfly006->SetAction("SlowFly");
	var Butterfly007 = CreateObjectAbove(Butterfly, 452, 241);
	Butterfly007->SetDir(DIR_Right);
	Butterfly007->SetComDir(COMD_None);
	Butterfly007->Unstick(7);
	Butterfly007->SetAction("Fly");
	var Butterfly008 = CreateObjectAbove(Butterfly, 454, 236);
	Butterfly008->SetDir(DIR_Right);
	Butterfly008->SetComDir(COMD_None);
	Butterfly008->Unstick(7);
	Butterfly008->SetAction("SlowFly");
	var Butterfly009 = CreateObjectAbove(Butterfly, 275, 253);
	Butterfly009->SetDir(DIR_Right);
	Butterfly009->SetComDir(COMD_None);
	Butterfly009->Unstick(7);
	Butterfly009->SetAction("Fly");
	var Butterfly010 = CreateObjectAbove(Butterfly, 416, 251);
	Butterfly010->SetDir(DIR_Right);
	Butterfly010->SetComDir(COMD_None);
	Butterfly010->Unstick(7);
	Butterfly010->SetAction("SlowFly");
	var Butterfly011 = CreateObjectAbove(Butterfly, 274, 252);
	Butterfly011->SetComDir(COMD_None);
	Butterfly011->Unstick(7);
	Butterfly011->SetAction("Fly");
	var Butterfly012 = CreateObjectAbove(Butterfly, 282, 251);
	Butterfly012->SetDir(DIR_Right);
	Butterfly012->SetComDir(COMD_None);
	Butterfly012->Unstick(7);
	Butterfly012->SetAction("SlowFly");

	var Bat001 = CreateObjectAbove(Bat, 325, 410);
	Bat001->Unstick(7);
	var Bat002 = CreateObjectAbove(Bat, 336, 419);
	Bat002->SetComDir(COMD_None);
	Bat002->SetXDir(-12);
	Bat002->SetYDir(12);
	Bat002->Unstick(7);
	var Bat003 = CreateObjectAbove(Bat, 359, 407);
	Bat003->SetComDir(COMD_None);
	Bat003->Unstick(7);
	var Bat004 = CreateObjectAbove(Bat, 324, 414);
	Bat004->SetComDir(COMD_None);
	Bat004->SetCon(96);
	Bat004->SetYDir(12);
	Bat004->Unstick(7);
	var Bat005 = CreateObjectAbove(Bat, 341, 416);
	Bat005->SetComDir(COMD_None);
	Bat005->SetCon(60);
	Bat005->SetXDir(-12);
	Bat005->SetYDir(12);
	Bat005->Unstick(7);
	var Rock001 = CreateObject(Rock, 279, 290);
	Rock001->SetPosition(279, 290);
	var Rock002 = CreateObject(Rock, 377, 266);
	Rock002->SetPosition(377, 266);
	var Rock003 = CreateObject(Rock, 303, 366);
	Rock003->SetPosition(303, 366);
	var Rock004 = CreateObject(Rock, 298, 436);
	Rock004->SetPosition(298, 436);
	var Rock005 = CreateObject(Rock, 406, 441);
	Rock005->SetPosition(406, 441);
	var Rock006 = CreateObject(Rock, 385, 377);
	Rock006->SetPosition(385, 377);
	var Rock007 = CreateObject(Rock, 546, 379);
	Rock007->SetPosition(546, 379);
	var Rock008 = CreateObject(Rock, 591, 367);
	Rock008->SetPosition(591, 367);
	var Rock009 = CreateObject(Rock, 423, 353);
	Rock009->SetPosition(423, 353);
	var Rock010 = CreateObject(Rock, 417, 276);
	Rock010->SetPosition(417, 276);
	var Rock011 = CreateObject(Rock, 247, 311);
	Rock011->SetPosition(247, 311);
	var Rock012 = CreateObject(Rock, 429, 321);
	Rock012->SetPosition(429, 321);
	var Rock013 = CreateObject(Rock, 261, 442);
	Rock013->SetPosition(261, 442);
	var Rock014 = ToolsWorkshop001->CreateContents(Rock);
	Rock014->SetPosition(351, 212);
	var Rock015 = ToolsWorkshop001->CreateContents(Rock);
	Rock015->SetPosition(351, 212);

	var Ore001 = CreateObject(Ore, 471, 381);
	Ore001->SetPosition(471, 381);
	var Ore002 = CreateObject(Ore, 480, 377);
	Ore002->SetPosition(480, 377);

	var Metal001 = CreateObject(Metal, 503, 372);
	Metal001->SetPosition(503, 372);
	var Metal002 = CreateObject(Metal, 436, 290);
	Metal002->SetPosition(436, 290);
	var Metal003 = ToolsWorkshop001->CreateContents(Metal);
	Metal003->SetPosition(351, 212);
	var Metal004 = ToolsWorkshop001->CreateContents(Metal);
	Metal004->SetPosition(351, 212);
	var Metal005 = ToolsWorkshop001->CreateContents(Metal);
	Metal005->SetPosition(351, 212);
	var Metal006 = ToolsWorkshop001->CreateContents(Metal);
	Metal006->SetPosition(351, 212);

	var Wood001 = CreateObject(Wood, 274, 440);
	Wood001->SetPosition(274, 440);
	var Wood002 = CreateObject(Wood, 262, 369);
	Wood002->SetPosition(262, 369);
	var Wood003 = CreateObject(Wood, 549, 362);
	Wood003->SetPosition(549, 362);
	var Wood004 = CreateObject(Wood, 542, 393);
	Wood004->SetPosition(542, 393);
	var Wood005 = CreateObject(Wood, 410, 291);
	Wood005->SetPosition(410, 291);
	var Wood006 = ToolsWorkshop001->CreateContents(Wood);
	Wood006->SetPosition(351, 212);
	var Wood007 = ToolsWorkshop001->CreateContents(Wood);
	Wood007->SetPosition(351, 212);
	var Wood008 = ToolsWorkshop001->CreateContents(Wood);
	Wood008->SetPosition(351, 212);
	var Wood009 = ToolsWorkshop001->CreateContents(Wood);
	Wood009->SetPosition(351, 212);
	var Wood010 = ToolsWorkshop001->CreateContents(Wood);
	Wood010->SetPosition(351, 212);

	var Loam001 = CreateObject(Loam, 500, 399);
	Loam001->SetPosition(500, 399);

	var Nugget001 = CreateObject(Nugget, 457, 312);
	Nugget001->SetPosition(457, 312);

	var GoldBar001 = CreateObject(GoldBar, 339, 447);
	GoldBar001->SetPosition(339, 447);

	var Diamond001 = CreateObject(Diamond, 283, 338);
	Diamond001->SetPosition(283, 338);
	var Diamond002 = CreateObject(Diamond, 389, 271);
	Diamond002->SetPosition(389, 271);
	var Diamond003 = CreateObject(Diamond, 535, 379);
	Diamond003->SetPosition(535, 379);
	var Diamond004 = CreateObject(Diamond, 511, 421);
	Diamond004->SetPosition(511, 421);
	var Diamond005 = CreateObject(Diamond, 587, 401);
	Diamond005->SetPosition(587, 401);

	var WindBag001 = Chest001->CreateContents(WindBag);
	WindBag001->SetPosition(603, 140);

	var Coral001 = CreateObjectAbove(Coral, 501, 304);
	Coral001->SetCon(123);
	var Coral002 = CreateObjectAbove(Coral, 586, 312);
	Coral002->SetCon(152);

	CreateObjectAbove(Seaweed, 501, 303);
	CreateObjectAbove(Seaweed, 520, 303);
	CreateObjectAbove(Seaweed, 556, 311);
	CreateObjectAbove(Seaweed, 571, 311);
	CreateObjectAbove(Seaweed, 608, 311);
	CreateObjectAbove(Seaweed, 596, 311);
	CreateObjectAbove(Seaweed, 600, 311);

	CreateObjectAbove(Mushroom, 266, 256);
	CreateObjectAbove(Mushroom, 278, 255);
	CreateObjectAbove(Mushroom, 291, 255);
	CreateObjectAbove(Mushroom, 359, 312);
	CreateObjectAbove(Mushroom, 377, 326);
	CreateObjectAbove(Mushroom, 391, 336);
	CreateObjectAbove(Mushroom, 339, 445);
	CreateObjectAbove(Mushroom, 342, 447);
	CreateObjectAbove(Mushroom, 353, 447);
	CreateObjectAbove(Mushroom, 361, 447);
	CreateObjectAbove(Mushroom, 354, 311);

	var AncientTablet001 = Chest001->CreateContents(AncientTablet);
	AncientTablet001->SetPosition(603, 140);

	var GrenadeLauncher001 = Lorry001->CreateContents(GrenadeLauncher);
	GrenadeLauncher001->SetPosition(386, 319);

	var Dynamite001 = Lorry001->CreateContents(Dynamite);
	Dynamite001->SetPosition(386, 319);
	var Dynamite002 = Lorry001->CreateContents(Dynamite);
	Dynamite002->SetPosition(386, 319);
	var Dynamite003 = Lorry001->CreateContents(Dynamite);
	Dynamite003->SetPosition(386, 319);
	var Dynamite004 = Lorry001->CreateContents(Dynamite);
	Dynamite004->SetPosition(386, 319);
	var Dynamite005 = ChemicalLab001->CreateContents(Dynamite);
	Dynamite005->SetPosition(150, 103);

	var Boompack001 = CreateObject(Boompack, 99, 120);
	Boompack001->SetR(-176);
	Boompack001->SetPosition(99, 120);
	Boompack001->Unstick(7);

	var Blunderbuss001 = Armory001->CreateContents(Blunderbuss);
	Blunderbuss001->SetPosition(45, 103);

	var LeadBullet001 = Blunderbuss001->CreateContents(LeadBullet);
	LeadBullet001->SetPosition(45, 103);

	var Stalactite001 = CreateObject(Stalactite, 23, 167);
	Stalactite001->SetCon(54);
	Stalactite001->SetPosition(23, 167);

	var Zaphive001 = CreateObject(Zaphive, 332, 240);
	Zaphive001->SetPosition(332, 240);

	var FishRoe001 = CreateObjectAbove(FishRoe, 572, 271);
	FishRoe001->SetComDir(COMD_None);
	FishRoe001->SetCategory(C4D_None);
	var Firestone001 = CreateObject(Firestone, 428, 307);
	Firestone001->SetPosition(428, 307);
	var Firestone002 = CreateObject(Firestone, 294, 301);
	Firestone002->SetPosition(294, 301);
	var Firestone003 = CreateObject(Firestone, 474, 402);
	Firestone003->SetPosition(474, 402);
	var Firestone004 = CreateObject(Firestone, 568, 375);
	Firestone004->SetPosition(568, 375);
	var Firestone005 = CreateObject(Firestone, 300, 427);
	Firestone005->SetPosition(300, 427);
	var Firestone006 = CreateObject(Firestone, 398, 416);
	Firestone006->SetPosition(398, 416);
	return true;
}
