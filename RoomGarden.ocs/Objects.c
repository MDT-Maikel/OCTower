/* Automatically created objects file */

func InitializeObjects()
{
	var Rule_NoPowerNeed001 = CreateObject(Rule_NoPowerNeed, 433, 66);
	Rule_NoPowerNeed001->SetPosition(433, 66);

	CreateObjectAbove(Trunk, 249, 160);

	var Branch001 = CreateObject(Branch, 561, 160);
	Branch001->SetR(30);
	Branch001->SetPosition(561, 160);

	var Cotton001 = CreateObjectAbove(Cotton, 386, 166);
	Cotton001->GrowBranch(true, 0);

	CreateObjectAbove(Vine, 233, 70);
	CreateObjectAbove(Vine, 233, 126);
	var SproutBerryBush001 = CreateObject(SproutBerryBush, 407, 165);
	SproutBerryBush001->SetPosition(407, 165);
	var SproutBerryBush002 = CreateObject(SproutBerryBush, 706, 183);
	SproutBerryBush002->SetPosition(706, 183);

	var Wheat001 = CreateObjectAbove(Wheat, 514, 175);
	Wheat001->SetMeshMaterial("wheat_material_ripe", 0);
	var Wheat002 = CreateObjectAbove(Wheat, 530, 176);
	Wheat002->SetMeshMaterial("wheat_material_ripe", 0);
	var Wheat003 = CreateObjectAbove(Wheat, 546, 174);
	Wheat003->SetMeshMaterial("wheat_material_ripe", 0);

	var Deco_Tree_Deciduous2001 = CreateObjectAbove(Deco_Tree_Deciduous2, 311, 152);
	Deco_Tree_Deciduous2001->SetCon(102);

	CreateObjectAbove(Deco_Tree_Deciduous4, 716, 169);

	var Deco_Tree_Deciduous3001 = CreateObjectAbove(Deco_Tree_Deciduous3, 569, 167);
	Deco_Tree_Deciduous3001->SetCon(102);

	var Wheat004 = CreateObjectAbove(Wheat, 493, 159);
	Wheat004->SetMeshMaterial("wheat_material_ripe", 0);

	CreateObjectAbove(Cotton, 331, 154);

	var Deco_Tree_Deciduous4001 = CreateObjectAbove(Deco_Tree_Deciduous4, 639, 195);
	Deco_Tree_Deciduous4001->SetCon(98);

	var Diamond_Socket001 = CreateObject(Diamond_Socket, 699, 198);
	Diamond_Socket001->SetPosition(699, 198);
	var Diamond_Socket002 = CreateObject(Diamond_Socket, 243, 215);
	Diamond_Socket002->SetPosition(243, 215);
	var Diamond_Socket003 = CreateObject(Diamond_Socket, 257, 242);
	Diamond_Socket003->SetPosition(257, 242);

	var Sequence001 = CreateObject(Sequence, 87, 186);
	Sequence001->SetName("DeathSpikes");
	Sequence001->SetCheckInterval(8);
	Sequence001->SetPosition(87, 186);
	Sequence001->SetTrigger({Rect=[-9,-24,15,17],Trigger="player_enter_region_rect"}, 5);
	Sequence001->SetAction({Actions=[{Function="do_energy",Object={Function="triggering_clonk"},Value={Function="int_constant",Value=-100}}],Function="sequence"}, nil);

	var Cotton002 = CreateObject(Cotton, 355, 177);
	Cotton002->SetCon(33);
	Cotton002->SetPosition(355, 177);
	var Cotton003 = CreateObject(Cotton, 294, 171);
	Cotton003->SetCon(23);
	Cotton003->SetPosition(294, 171);

	var Deco_Tree_Deciduous2002 = CreateObject(Deco_Tree_Deciduous2, 408, 161);
	Deco_Tree_Deciduous2002->SetCon(10);
	Deco_Tree_Deciduous2002->SetPosition(408, 161);

	var Fern001 = CreateObject(Fern, 267, 167);
	Fern001->SetPosition(267, 167);
	var Fern002 = CreateObject(Fern, 366, 174);
	Fern002->SetPosition(366, 174);
	var Fern003 = CreateObject(Fern, 390, 165);
	Fern003->SetPosition(390, 165);
	var Fern004 = CreateObject(Fern, 580, 170);
	Fern004->SetPosition(580, 170);
	var Fern005 = CreateObject(Fern, 396, 165);
	Fern005->SetPosition(396, 165);
	var Fern006 = CreateObject(Fern, 667, 197);
	Fern006->SetPosition(667, 197);
	var Fern007 = CreateObject(Fern, 320, 155);
	Fern007->SetPosition(320, 155);
	var Fern008 = CreateObject(Fern, 656, 196);
	Fern008->SetPosition(656, 196);
	var Fern009 = CreateObject(Fern, 664, 196);
	Fern009->SetPosition(664, 196);
	var Fern010 = CreateObject(Fern, 328, 157);
	Fern010->SetPosition(328, 157);
	var Fern011 = CreateObject(Fern, 235, 162);
	Fern011->SetPosition(235, 162);
	var Fern012 = CreateObject(Fern, 374, 171);
	Fern012->SetPosition(374, 171);
	var Fern013 = CreateObject(Fern, 308, 155);
	Fern013->SetPosition(308, 155);
	var Fern014 = CreateObject(Fern, 364, 174);
	Fern014->SetPosition(364, 174);
	var Fern015 = CreateObject(Fern, 406, 164);
	Fern015->SetPosition(406, 164);
	var Fern016 = CreateObject(Fern, 533, 180);
	Fern016->SetPosition(533, 180);
	var Fern017 = CreateObject(Fern, 558, 172);
	Fern017->SetPosition(558, 172);
	var Fern018 = CreateObject(Fern, 524, 181);
	Fern018->SetPosition(524, 181);
	var Fern019 = CreateObject(Fern, 574, 171);
	Fern019->SetPosition(574, 171);
	var Fern020 = CreateObject(Fern, 407, 165);
	Fern020->SetPosition(407, 165);

	var Flower001 = CreateObjectAbove(Flower, 661, 200);
	var Flower002 = CreateObjectAbove(Flower, 399, 166);
	CreateObjectAbove(Flower, 246, 168);
	var Flower003 = CreateObjectAbove(Flower, 711, 175);
	CreateObjectAbove(Flower, 357, 182);
	var Flower004 = CreateObjectAbove(Flower, 391, 167);
	CreateObjectAbove(Flower, 603, 184);
	var Flower005 = CreateObjectAbove(Flower, 378, 174);
	CreateObjectAbove(Flower, 363, 178);
	var Flower006 = CreateObjectAbove(Flower, 536, 183);
	var Flower007 = CreateObjectAbove(Flower, 629, 190);
	var Flower008 = CreateObjectAbove(Flower, 280, 175);
	var Flower009 = CreateObjectAbove(Flower, 567, 175);
	var Flower010 = CreateObjectAbove(Flower, 316, 159);
	var Flower011 = CreateObjectAbove(Flower, 388, 170);
	var Flower012 = CreateObjectAbove(Flower, 710, 174);
	var Flower013 = CreateObjectAbove(Flower, 407, 167);
	var Flower014 = CreateObjectAbove(Flower, 585, 173);
	var Flower015 = CreateObjectAbove(Flower, 357, 183);
	var Flower016 = CreateObjectAbove(Flower, 400, 167);
	var Flower017 = CreateObjectAbove(Flower, 316, 159);
	CreateObjectAbove(Flower, 312, 158);
	var Flower018 = CreateObjectAbove(Flower, 393, 167);
	var Flower019 = CreateObjectAbove(Flower, 647, 199);
	CreateObjectAbove(Flower, 411, 166);
	var Flower020 = CreateObjectAbove(Flower, 401, 167);
	var Flower021 = CreateObjectAbove(Flower, 368, 176);
	CreateObjectAbove(Flower, 537, 182);
	var Flower022 = CreateObjectAbove(Flower, 329, 160);
	var Flower023 = CreateObjectAbove(Flower, 535, 183);
	var Flower024 = CreateObjectAbove(Flower, 304, 160);
	CreateObjectAbove(Flower, 254, 167);
	CreateObjectAbove(Flower, 371, 174);
	CreateObjectAbove(Flower, 538, 182);
	var Flower025 = CreateObjectAbove(Flower, 526, 182);
	var Flower026 = CreateObjectAbove(Flower, 658, 199);
	CreateObjectAbove(Flower, 316, 159);
	var Flower027 = CreateObjectAbove(Flower, 578, 174);
	var Flower028 = CreateObjectAbove(Flower, 374, 175);
	var Flower029 = CreateObjectAbove(Flower, 524, 183);
	var Flower030 = CreateObjectAbove(Flower, 705, 175);
	var Flower031 = CreateObjectAbove(Flower, 646, 199);
	var Flower032 = CreateObjectAbove(Flower, 627, 189);
	var Flower033 = CreateObjectAbove(Flower, 321, 158);
	var Flower034 = CreateObjectAbove(Flower, 390, 169);
	var Flower035 = CreateObjectAbove(Flower, 250, 168);
	CreateObjectAbove(Flower, 622, 191);
	var Flower036 = CreateObjectAbove(Flower, 584, 175);
	var Flower037 = CreateObjectAbove(Flower, 709, 173);
	var Flower038 = CreateObjectAbove(Flower, 243, 168);

	var Rule_FastPump001 = CreateObject(Rule_FastPump, 462, 66);
	Rule_FastPump001->SetPosition(462, 66);
	Rule_FastPump001->SetPumpSpeed(50);

	var Fern021 = CreateObject(Fern, 584, 172);
	Fern021->SetPosition(584, 172);
	var Fern022 = CreateObject(Fern, 395, 163);
	Fern022->SetPosition(395, 163);
	var Fern023 = CreateObject(Fern, 241, 164);
	Fern023->SetPosition(241, 164);
	var Fern024 = CreateObject(Fern, 661, 196);
	Fern024->SetPosition(661, 196);
	var Fern025 = CreateObject(Fern, 364, 174);
	Fern025->SetPosition(364, 174);
	var Fern026 = CreateObject(Fern, 658, 195);
	Fern026->SetPosition(658, 195);
	var Fern027 = CreateObject(Fern, 633, 189);
	Fern027->SetPosition(633, 189);
	var Fern028 = CreateObject(Fern, 367, 173);
	Fern028->SetPosition(367, 173);
	var Fern029 = CreateObject(Fern, 238, 164);
	Fern029->SetPosition(238, 164);
	var Fern030 = CreateObject(Fern, 537, 178);
	Fern030->SetPosition(537, 178);
	var Fern031 = CreateObject(Fern, 665, 195);
	Fern031->SetPosition(665, 195);
	var Fern032 = CreateObject(Fern, 549, 173);
	Fern032->SetPosition(549, 173);
	var Fern033 = CreateObject(Fern, 634, 190);
	Fern033->SetPosition(634, 190);
	var Fern034 = CreateObject(Fern, 397, 163);
	Fern034->SetPosition(397, 163);
	var Fern035 = CreateObject(Fern, 329, 158);
	Fern035->SetPosition(329, 158);
	var Fern036 = CreateObject(Fern, 650, 195);
	Fern036->SetPosition(650, 195);
	var Fern037 = CreateObject(Fern, 268, 168);
	Fern037->SetPosition(268, 168);
	var Fern038 = CreateObject(Fern, 405, 163);
	Fern038->SetPosition(405, 163);
	var Fern039 = CreateObject(Fern, 553, 172);
	Fern039->SetPosition(553, 172);
	var Fern040 = CreateObject(Fern, 233, 164);
	Fern040->SetPosition(233, 164);

	var Flower039 = CreateObjectAbove(Flower, 375, 174);
	var Flower040 = CreateObjectAbove(Flower, 692, 189);
	CreateObjectAbove(Flower, 645, 198);
	var Flower041 = CreateObjectAbove(Flower, 409, 168);
	var Flower042 = CreateObjectAbove(Flower, 369, 175);
	var Flower043 = CreateObjectAbove(Flower, 551, 176);
	var Flower044 = CreateObjectAbove(Flower, 381, 174);
	CreateObjectAbove(Flower, 636, 195);
	var Flower045 = CreateObjectAbove(Flower, 660, 198);
	CreateObjectAbove(Flower, 239, 166);
	var Flower046 = CreateObjectAbove(Flower, 660, 198);
	CreateObjectAbove(Flower, 261, 166);
	var Flower047 = CreateObjectAbove(Flower, 237, 167);
	CreateObjectAbove(Flower, 585, 175);
	CreateObjectAbove(Flower, 553, 175);
	CreateObjectAbove(Flower, 523, 182);
	var Flower048 = CreateObjectAbove(Flower, 621, 191);
	CreateObjectAbove(Flower, 659, 198);
	var Flower049 = CreateObjectAbove(Flower, 359, 181);
	var Flower050 = CreateObjectAbove(Flower, 562, 173);
	var Flower051 = CreateObjectAbove(Flower, 332, 162);
	var Flower052 = CreateObjectAbove(Flower, 547, 178);
	var Flower053 = CreateObjectAbove(Flower, 548, 177);
	CreateObjectAbove(Flower, 280, 175);
	var Flower054 = CreateObjectAbove(Flower, 402, 165);
	var Flower055 = CreateObjectAbove(Flower, 275, 174);
	var Flower056 = CreateObjectAbove(Flower, 623, 190);
	var Flower057 = CreateObjectAbove(Flower, 330, 161);
	var Flower058 = CreateObjectAbove(Flower, 325, 158);
	var Flower059 = CreateObjectAbove(Flower, 356, 181);
	CreateObjectAbove(Flower, 631, 191);
	var Flower060 = CreateObjectAbove(Flower, 519, 184);
	CreateObjectAbove(Flower, 583, 175);
	var Flower061 = CreateObjectAbove(Flower, 659, 197);
	var Flower062 = CreateObjectAbove(Flower, 393, 166);
	var Flower063 = CreateObjectAbove(Flower, 568, 175);
	var Flower064 = CreateObjectAbove(Flower, 537, 182);
	CreateObjectAbove(Flower, 302, 163);
	CreateObjectAbove(Flower, 601, 182);
	var Flower065 = CreateObjectAbove(Flower, 372, 175);
	var Flower066 = CreateObjectAbove(Flower, 405, 167);
	var Flower067 = CreateObjectAbove(Flower, 393, 166);
	var Flower068 = CreateObjectAbove(Flower, 565, 175);
	var Flower069 = CreateObjectAbove(Flower, 705, 174);
	CreateObjectAbove(Flower, 268, 171);
	var Flower070 = CreateObjectAbove(Flower, 363, 178);
	var Flower071 = CreateObjectAbove(Flower, 552, 174);
	CreateObjectAbove(Flower, 494, 166);
	CreateObjectAbove(Flower, 392, 166);
	var Flower072 = CreateObjectAbove(Flower, 564, 174);

	var Rule_BuyAtFlagpole001 = CreateObject(Rule_BuyAtFlagpole, 404, 65);
	Rule_BuyAtFlagpole001->SetPosition(404, 65);

	var RoomSign001 = CreateObjectAbove(RoomSign, 134, 150);
	RoomSign001->SetInscription({DE="Dieser Raum hat den zweiten Platz im 2018er Turm-Wettbewerb erhalten!",Function="Translate",US="This room has been awarded second place in the 2018 tower design contest!"});
	RoomSign001->CustomInitialize("SetReward(\"Silver\")");
	var Fern041 = CreateObject(Fern, 372, 170);
	Fern041->SetPosition(372, 170);
	var Fern042 = CreateObject(Fern, 365, 173);
	Fern042->SetPosition(365, 173);
	var Fern043 = CreateObject(Fern, 315, 156);
	Fern043->SetPosition(315, 156);
	var Fern044 = CreateObject(Fern, 386, 169);
	Fern044->SetPosition(386, 169);
	var Fern045 = CreateObject(Fern, 549, 173);
	Fern045->SetPosition(549, 173);
	var Fern046 = CreateObject(Fern, 655, 195);
	Fern046->SetPosition(655, 195);
	var Fern047 = CreateObject(Fern, 580, 171);
	Fern047->SetPosition(580, 171);
	var Fern048 = CreateObject(Fern, 364, 174);
	Fern048->SetPosition(364, 174);
	var Fern049 = CreateObject(Fern, 578, 171);
	Fern049->SetPosition(578, 171);
	var Fern050 = CreateObject(Fern, 258, 163);
	Fern050->SetPosition(258, 163);
	var Fern051 = CreateObject(Fern, 239, 162);
	Fern051->SetPosition(239, 162);
	var Fern052 = CreateObject(Fern, 395, 164);
	Fern052->SetPosition(395, 164);
	var Fern053 = CreateObject(Fern, 527, 179);
	Fern053->SetPosition(527, 179);
	var Fern054 = CreateObject(Fern, 275, 169);
	Fern054->SetPosition(275, 169);
	var Fern055 = CreateObject(Fern, 389, 166);
	Fern055->SetPosition(389, 166);
	var Fern056 = CreateObject(Fern, 657, 196);
	Fern056->SetPosition(657, 196);
	var Fern057 = CreateObject(Fern, 368, 173);
	Fern057->SetPosition(368, 173);
	var Fern058 = CreateObject(Fern, 390, 166);
	Fern058->SetPosition(390, 166);
	var Fern059 = CreateObject(Fern, 637, 193);
	Fern059->SetPosition(637, 193);
	var Fern060 = CreateObject(Fern, 532, 180);
	Fern060->SetPosition(532, 180);

	var Flower073 = CreateObjectAbove(Flower, 497, 168);
	CreateObjectAbove(Flower, 625, 189);
	var Flower074 = CreateObjectAbove(Flower, 672, 199);
	var Flower075 = CreateObjectAbove(Flower, 663, 200);
	CreateObjectAbove(Flower, 253, 168);
	var Flower076 = CreateObjectAbove(Flower, 657, 200);
	var Flower077 = CreateObjectAbove(Flower, 626, 189);
	var Flower078 = CreateObjectAbove(Flower, 365, 176);
	var Flower079 = CreateObjectAbove(Flower, 534, 182);
	CreateObjectAbove(Flower, 321, 158);
	var Flower080 = CreateObjectAbove(Flower, 242, 168);
	var Flower081 = CreateObjectAbove(Flower, 606, 183);
	CreateObjectAbove(Flower, 333, 164);
	var Flower082 = CreateObjectAbove(Flower, 551, 176);
	var Flower083 = CreateObjectAbove(Flower, 367, 175);
	CreateObjectAbove(Flower, 274, 174);
	var Flower084 = CreateObjectAbove(Flower, 374, 175);
	var Flower085 = CreateObjectAbove(Flower, 310, 159);
	var Flower086 = CreateObjectAbove(Flower, 376, 174);
	var Flower087 = CreateObjectAbove(Flower, 547, 179);
	var Flower088 = CreateObjectAbove(Flower, 558, 174);
	var Flower089 = CreateObjectAbove(Flower, 526, 183);
	var Flower090 = CreateObjectAbove(Flower, 521, 184);
	var Flower091 = CreateObjectAbove(Flower, 319, 159);
	var Flower092 = CreateObjectAbove(Flower, 706, 174);
	var Flower093 = CreateObjectAbove(Flower, 400, 166);
	var Flower094 = CreateObjectAbove(Flower, 324, 159);
	var Flower095 = CreateObjectAbove(Flower, 591, 174);
	var Flower096 = CreateObjectAbove(Flower, 253, 167);
	var Flower097 = CreateObjectAbove(Flower, 555, 174);
	var Flower098 = CreateObjectAbove(Flower, 573, 175);
	var Flower099 = CreateObjectAbove(Flower, 575, 176);
	var Flower100 = CreateObjectAbove(Flower, 525, 183);
	CreateObjectAbove(Flower, 515, 183);
	CreateObjectAbove(Flower, 247, 167);
	var Flower101 = CreateObjectAbove(Flower, 517, 182);
	var Flower102 = CreateObjectAbove(Flower, 599, 184);
	CreateObjectAbove(Flower, 554, 174);
	var Flower103 = CreateObjectAbove(Flower, 321, 158);
	var Flower104 = CreateObjectAbove(Flower, 328, 159);
	var Flower105 = CreateObjectAbove(Flower, 308, 159);
	CreateObjectAbove(Flower, 282, 173);
	var Flower106 = CreateObjectAbove(Flower, 373, 174);
	var Flower107 = CreateObjectAbove(Flower, 683, 195);
	var Flower108 = CreateObjectAbove(Flower, 263, 167);
	var Flower109 = CreateObjectAbove(Flower, 273, 173);
	var Flower110 = CreateObjectAbove(Flower, 520, 184);
	var Flower111 = CreateObjectAbove(Flower, 288, 175);
	CreateObjectAbove(Flower, 533, 182);
	var Flower112 = CreateObjectAbove(Flower, 361, 181);
	var Basement001 = CreateObject(Basement, 473, 159);
	Basement001->SetPosition(473, 159);
	var Basement002 = CreateObject(Basement, 433, 160);
	Basement002->SetPosition(433, 160);

	var RoomEntrance001 = CreateObjectAbove(RoomEntrance, 109, 159);
	RoomEntrance001->SetColor(0xff32c832);

	var RoomExit001 = CreateObjectAbove(RoomExit, 205, 256);
	RoomExit001->SetColor(0xffc83232);

	var StoneDoor001 = CreateObject(StoneDoor, 180, 140);
	StoneDoor001->SetComDir(COMD_Down);
	StoneDoor001->SetPosition(180, 140);
	StoneDoor001->SetPlrViewOnSignalChange(true);

	var SpinWheel001 = CreateObjectAbove(SpinWheel, 84, 162);
	SpinWheel001->SetSwitchTarget(StoneDoor001);

	var ToolsWorkshop001 = CreateObjectAbove(ToolsWorkshop, 465, 155);

	var Flagpole001 = CreateObject(Flagpole, 434, 121);
	Flagpole001.MakeRoomPlayerOwner = true;
	Flagpole001->SetPosition(434, 121);

	var Hatch001 = CreateObject(Hatch, 159, 208);
	Hatch001->SetCategory(C4D_StaticBack);
	Hatch001->SetPosition(159, 208);

	var PlayerStart001 = CreateObject(PlayerStart, 108, 112);
	PlayerStart001->SetPosition(108, 112);
	PlayerStart001->SetStartingKnowledge("idlist", [Armory,Basement,Chest,Compensator,Flagpole,Foundry,Idol,Kitchen,Loom,Pump,Sawmill,SteamEngine,ToolsWorkshop,WindGenerator,WoodenCabin,Cannon,Catapult,Lorry,Bread,CookedMushroom,Flour,Cloth,Axe,Barrel,MetalBarrel,Crate,DivingHelmet,Hammer,Lantern,Pickaxe,Pipe,PowderKeg,Shovel,Sickle,Torch,Blunderbuss,Bow,Club,Helmet,Javelin,Shield,SmokeBomb,Sword]);
	PlayerStart001->SetStartingBaseMaterial([{count=5,id=Metal}]);
	PlayerStart001->SetViewLock(false);

	var Fish001 = CreateObjectAbove(Fish, 863, 179);
	Fish001->Unstick(7);
	var Fish002 = CreateObjectAbove(Fish, 868, 221);
	Fish002->Unstick(7);

	var Firefly001 = CreateObjectAbove(Firefly, 232, 71);
	Firefly001->SetComDir(COMD_UpLeft);
	Firefly001->DoEnergy(-11);
	Firefly001->SetCommand("Call", Firefly001, nil, 0, nil, "MissionComplete");
	Firefly001->Unstick(7);
	var Firefly002 = CreateObjectAbove(Firefly, 270, 102);
	Firefly002->SetComDir(COMD_DownLeft);
	Firefly002->SetXDir(-2);
	Firefly002->SetYDir(1);
	Firefly002->SetCommand("Call", Firefly002, nil, 0, nil, "MissionComplete");
	Firefly002->Unstick(7);
	var Firefly003 = CreateObjectAbove(Firefly, 274, 117);
	Firefly003->SetComDir(COMD_None);
	Firefly003->SetXDir(1);
	Firefly003->SetCommand("Call", Firefly003, nil, 0, nil, "MissionComplete");
	Firefly003->Unstick(7);
	var Firefly004 = CreateObjectAbove(Firefly, 294, 113);
	Firefly004->SetComDir(COMD_DownLeft);
	Firefly004->SetXDir(-2);
	Firefly004->SetCommand("Call", Firefly004, nil, 0, nil, "MissionComplete");
	Firefly004->Unstick(7);
	var Firefly005 = CreateObjectAbove(Firefly, 234, 51);
	Firefly005->SetComDir(COMD_DownRight);
	Firefly005->SetYDir(2);
	Firefly005->SetCommand("Call", Firefly005, nil, 0, nil, "MissionComplete");
	Firefly005->Unstick(7);
	var Firefly006 = CreateObjectAbove(Firefly, 590, 138);
	Firefly006->SetComDir(COMD_UpRight);
	Firefly006->SetXDir(1);
	Firefly006->SetYDir(-2);
	Firefly006->SetCommand("Call", Firefly006, nil, 0, nil, "MissionComplete");
	Firefly006->Unstick(7);
	var Firefly007 = CreateObjectAbove(Firefly, 645, 132);
	Firefly007->SetComDir(COMD_Right);
	Firefly007->SetXDir(1);
	Firefly007->SetCommand("Call", Firefly007, nil, 0, nil, "MissionComplete");
	Firefly007->Unstick(7);
	var Firefly008 = CreateObjectAbove(Firefly, 652, 110);
	Firefly008->SetComDir(COMD_DownLeft);
	Firefly008->SetXDir(-1);
	Firefly008->SetCommand("Call", Firefly008, nil, 0, nil, "MissionComplete");
	Firefly008->Unstick(7);
	var Firefly009 = CreateObjectAbove(Firefly, 705, 112);
	Firefly009->SetComDir(COMD_None);
	Firefly009->SetXDir(-2);
	Firefly009->SetCommand("Call", Firefly009, nil, 0, nil, "MissionComplete");
	Firefly009->Unstick(7);
	var Firefly010 = CreateObjectAbove(Firefly, 560, 101);
	Firefly010->SetComDir(COMD_UpRight);
	Firefly010->SetXDir(2);
	Firefly010->SetYDir(-2);
	Firefly010->SetCommand("Call", Firefly010, nil, 0, nil, "MissionComplete");
	Firefly010->Unstick(7);
	var Firefly011 = CreateObjectAbove(Firefly, 700, 133);
	Firefly011->SetComDir(COMD_None);
	Firefly011->SetYDir(2);
	Firefly011->SetCommand("Call", Firefly011, nil, 0, nil, "MissionComplete");
	Firefly011->Unstick(7);
	var Firefly012 = CreateObjectAbove(Firefly, 592, 138);
	Firefly012->SetComDir(COMD_None);
	Firefly012->SetXDir(1);
	Firefly012->SetCommand("Call", Firefly012, nil, 0, nil, "MissionComplete");
	Firefly012->Unstick(7);
	var Firefly013 = CreateObjectAbove(Firefly, 547, 120);
	Firefly013->SetComDir(COMD_UpLeft);
	Firefly013->SetXDir(-1);
	Firefly013->SetYDir(-2);
	Firefly013->SetCommand("Call", Firefly013, nil, 0, nil, "MissionComplete");
	Firefly013->Unstick(7);

	var Butterfly001 = CreateObjectAbove(Butterfly, 276, 111);
	Butterfly001->SetDir(DIR_Right);
	Butterfly001->SetComDir(COMD_Right);
	Butterfly001->SetXDir(10);
	Butterfly001->SetYDir(-2);
	Butterfly001->Unstick(7);
	Butterfly001->SetCommand("Call", Butterfly001, nil, 0, nil, "MissionComplete");
	Butterfly001->SetAction("Fly");
	var Butterfly002 = CreateObjectAbove(Butterfly, 652, 121);
	Butterfly002->SetDir(DIR_Right);
	Butterfly002->SetComDir(COMD_DownLeft);
	Butterfly002->SetXDir(-2);
	Butterfly002->SetYDir(1);
	Butterfly002->Unstick(7);
	Butterfly002->SetCommand("Call", Butterfly002, nil, 0, nil, "MissionComplete");
	Butterfly002->SetAction("SlowFly");
	var Butterfly003 = CreateObjectAbove(Butterfly, 739, 105);
	Butterfly003->SetDir(DIR_Right);
	Butterfly003->SetComDir(COMD_None);
	Butterfly003->Unstick(7);
	Butterfly003->SetCommand("Wait", nil, nil, 0, nil, 77);
	Butterfly003->SetAction("Fly");
	var Butterfly004 = CreateObjectAbove(Butterfly, 535, 170);
	Butterfly004->SetDir(DIR_Right);
	Butterfly004->SetComDir(COMD_UpLeft);
	Butterfly004->SetXDir(-2);
	Butterfly004->SetYDir(-1);
	Butterfly004->Unstick(7);
	Butterfly004->SetCommand("Call", Butterfly004, nil, 0, nil, "MissionComplete");
	Butterfly004->SetAction("SlowFly");
	var Butterfly005 = CreateObjectAbove(Butterfly, 745, 118);
	Butterfly005->SetDir(DIR_Right);
	Butterfly005->SetComDir(COMD_None);
	Butterfly005->Unstick(7);
	Butterfly005->SetCommand("Wait", nil, nil, 0, nil, 94);
	Butterfly005->SetAction("Fly");
	var Butterfly006 = CreateObjectAbove(Butterfly, 666, 149);
	Butterfly006->SetDir(DIR_Right);
	Butterfly006->SetComDir(COMD_None);
	Butterfly006->Unstick(7);
	Butterfly006->SetCommand("Wait", nil, nil, 0, nil, 84);
	Butterfly006->SetAction("Fly");
	var Butterfly007 = CreateObjectAbove(Butterfly, 311, 105);
	Butterfly007->SetDir(DIR_Right);
	Butterfly007->SetComDir(COMD_None);
	Butterfly007->SetXDir(-1);
	Butterfly007->SetYDir(-1);
	Butterfly007->Unstick(7);
	Butterfly007->SetCommand("Call", Butterfly007, nil, 0, nil, "MissionComplete");
	Butterfly007->SetAction("SlowFly");
	var Butterfly008 = CreateObjectAbove(Butterfly, 326, 95);
	Butterfly008->SetComDir(COMD_DownLeft);
	Butterfly008->SetXDir(-6);
	Butterfly008->SetYDir(6);
	Butterfly008->Unstick(7);
	Butterfly008->SetCommand("Call", Butterfly008, nil, 0, nil, "MissionComplete");
	Butterfly008->SetAction("Fly");
	var Butterfly009 = CreateObjectAbove(Butterfly, 631, 120);
	Butterfly009->SetDir(DIR_Right);
	Butterfly009->SetComDir(COMD_None);
	Butterfly009->Unstick(7);
	Butterfly009->SetCommand("Wait", nil, nil, 0, nil, 54);
	Butterfly009->SetAction("Fly");
	var Butterfly010 = CreateObjectAbove(Butterfly, 301, 91);
	Butterfly010->SetComDir(COMD_None);
	Butterfly010->Unstick(7);
	Butterfly010->SetCommand("Call", Butterfly010, nil, 0, nil, "MissionComplete");
	Butterfly010->SetAction("Fly");
	var Butterfly011 = CreateObjectAbove(Butterfly, 310, 120);
	Butterfly011->SetComDir(COMD_None);
	Butterfly011->SetXDir(-1);
	Butterfly011->Unstick(7);
	Butterfly011->SetCommand("Call", Butterfly011, nil, 0, nil, "MissionComplete");
	Butterfly011->SetAction("SlowFly");
	var Butterfly012 = CreateObjectAbove(Butterfly, 330, 131);
	Butterfly012->SetDir(DIR_Right);
	Butterfly012->SetComDir(COMD_None);
	Butterfly012->Unstick(7);
	Butterfly012->SetCommand("Wait", nil, nil, 0, nil, 53);
	Butterfly012->SetAction("Fly");
	var Butterfly013 = CreateObjectAbove(Butterfly, 259, 64);
	Butterfly013->SetDir(DIR_Right);
	Butterfly013->SetComDir(COMD_Down);
	Butterfly013->SetXDir(7);
	Butterfly013->SetYDir(6);
	Butterfly013->Unstick(7);
	Butterfly013->SetCommand("Call", Butterfly013, nil, 0, nil, "MissionComplete");
	Butterfly013->SetAction("Fly");
	var Butterfly014 = CreateObjectAbove(Butterfly, 529, 170);
	Butterfly014->SetDir(DIR_Right);
	Butterfly014->SetComDir(COMD_None);
	Butterfly014->Unstick(7);
	Butterfly014->SetCommand("Wait", nil, nil, 0, nil, 62);
	Butterfly014->SetAction("Fly");
	var Butterfly015 = CreateObjectAbove(Butterfly, 539, 158);
	Butterfly015->SetComDir(COMD_DownLeft);
	Butterfly015->SetXDir(-10);
	Butterfly015->SetYDir(6);
	Butterfly015->Unstick(7);
	Butterfly015->SetCommand("Call", Butterfly015, nil, 0, nil, "MissionComplete");
	Butterfly015->SetAction("Fly");
	var Butterfly016 = CreateObjectAbove(Butterfly, 301, 98);
	Butterfly016->SetComDir(COMD_None);
	Butterfly016->Unstick(7);
	Butterfly016->SetCommand("Wait", nil, nil, 0, nil, 55);
	Butterfly016->SetAction("Fly");
	var Butterfly017 = CreateObjectAbove(Butterfly, 382, 130);
	Butterfly017->SetComDir(COMD_None);
	Butterfly017->Unstick(7);
	Butterfly017->SetCommand("Wait", nil, nil, 0, nil, 41);
	Butterfly017->SetAction("Fly");
	var Butterfly018 = CreateObjectAbove(Butterfly, 754, 123);
	Butterfly018->SetDir(DIR_Right);
	Butterfly018->SetComDir(COMD_DownRight);
	Butterfly018->SetXDir(10);
	Butterfly018->SetYDir(2);
	Butterfly018->Unstick(7);
	Butterfly018->SetCommand("Call", Butterfly018, nil, 0, nil, "MissionComplete");
	Butterfly018->SetAction("Fly");
	var Butterfly019 = CreateObjectAbove(Butterfly, 315, 90);
	Butterfly019->SetComDir(COMD_DownLeft);
	Butterfly019->SetXDir(-6);
	Butterfly019->SetYDir(3);
	Butterfly019->Unstick(7);
	Butterfly019->SetCommand("Call", Butterfly019, nil, 0, nil, "MissionComplete");
	Butterfly019->SetAction("Fly");
	var Butterfly020 = CreateObjectAbove(Butterfly, 314, 78);
	Butterfly020->SetComDir(COMD_DownRight);
	Butterfly020->SetXDir(2);
	Butterfly020->SetYDir(2);
	Butterfly020->Unstick(7);
	Butterfly020->SetCommand("Call", Butterfly020, nil, 0, nil, "MissionComplete");
	Butterfly020->SetAction("SlowFly");
	var Butterfly021 = CreateObjectAbove(Butterfly, 662, 110);
	Butterfly021->SetComDir(COMD_DownLeft);
	Butterfly021->SetXDir(-10);
	Butterfly021->SetYDir(10);
	Butterfly021->Unstick(7);
	Butterfly021->SetCommand("Call", Butterfly021, nil, 0, nil, "MissionComplete");
	Butterfly021->SetAction("Fly");

	var Puka001 = CreateObjectAbove(Puka, 367, 161);
	Puka001->SetDir(DIR_Right);
	Puka001->SetMeshMaterial("Puka2", 0);
	Puka001->Unstick(7);

	var Rock001 = CreateObject(Rock, 448, 154);
	Rock001->SetR(-41);
	Rock001->SetRDir(3);
	Rock001->SetPosition(448, 154);
	Rock001->Unstick(7);
	var Rock002 = CreateObject(Rock, 550, 190);
	Rock002->SetPosition(550, 190);
	var Rock003 = CreateObject(Rock, 588, 192);
	Rock003->SetPosition(588, 192);
	var Rock004 = CreateObject(Rock, 682, 212);
	Rock004->SetPosition(682, 212);
	var Rock005 = CreateObject(Rock, 724, 197);
	Rock005->SetPosition(724, 197);
	var Rock006 = ToolsWorkshop001->CreateContents(Rock);
	Rock006->SetPosition(465, 136);
	var Rock007 = ToolsWorkshop001->CreateContents(Rock);
	Rock007->SetPosition(465, 136);
	var Rock008 = ToolsWorkshop001->CreateContents(Rock);
	Rock008->SetPosition(465, 136);
	var Rock009 = ToolsWorkshop001->CreateContents(Rock);
	Rock009->SetPosition(465, 136);
	var Rock010 = ToolsWorkshop001->CreateContents(Rock);
	Rock010->SetPosition(465, 136);
	var Rock011 = ToolsWorkshop001->CreateContents(Rock);
	Rock011->SetPosition(465, 136);
	var Rock012 = ToolsWorkshop001->CreateContents(Rock);
	Rock012->SetPosition(465, 136);
	var Rock013 = ToolsWorkshop001->CreateContents(Rock);
	Rock013->SetPosition(465, 136);

	var Ore001 = CreateObject(Ore, 268, 180);
	Ore001->SetPosition(268, 180);

	var Coal001 = CreateObject(Coal, 390, 204);
	Coal001->SetPosition(390, 204);
	var Coal002 = CreateObject(Coal, 406, 195);
	Coal002->SetPosition(406, 195);
	var Coal003 = CreateObject(Coal, 428, 198);
	Coal003->SetPosition(428, 198);
	var Coal004 = CreateObject(Coal, 442, 176);
	Coal004->SetPosition(442, 176);
	var Coal005 = CreateObject(Coal, 333, 191);
	Coal005->SetPosition(333, 191);
	var Coal006 = CreateObject(Coal, 350, 218);
	Coal006->SetPosition(350, 218);
	var Coal007 = CreateObject(Coal, 300, 176);
	Coal007->SetPosition(300, 176);
	var Coal008 = CreateObject(Coal, 434, 238);
	Coal008->SetPosition(434, 238);
	var Coal009 = CreateObject(Coal, 467, 221);
	Coal009->SetPosition(467, 221);

	var Wood001 = ToolsWorkshop001->CreateContents(Wood);
	Wood001->SetPosition(465, 136);
	var Wood002 = ToolsWorkshop001->CreateContents(Wood);
	Wood002->SetPosition(465, 136);
	var Wood003 = ToolsWorkshop001->CreateContents(Wood);
	Wood003->SetPosition(465, 136);
	var Wood004 = ToolsWorkshop001->CreateContents(Wood);
	Wood004->SetPosition(465, 136);
	var Wood005 = ToolsWorkshop001->CreateContents(Wood);
	Wood005->SetPosition(465, 136);
	var Wood006 = ToolsWorkshop001->CreateContents(Wood);
	Wood006->SetPosition(465, 136);

	var Metal001 = ToolsWorkshop001->CreateContents(Metal);
	Metal001->SetPosition(465, 136);
	var Metal002 = ToolsWorkshop001->CreateContents(Metal);
	Metal002->SetPosition(465, 136);
	var Metal003 = ToolsWorkshop001->CreateContents(Metal);
	Metal003->SetPosition(465, 136);
	var Metal004 = ToolsWorkshop001->CreateContents(Metal);
	Metal004->SetPosition(465, 136);
	var Metal005 = CreateObject(Metal, 384, 189);
	Metal005->SetPosition(384, 189);

	var Cloth001 = ToolsWorkshop001->CreateContents(Cloth);
	Cloth001->SetPosition(465, 136);

	var Ruby001 = CreateObject(Ruby, 874, 244);
	Ruby001->SetPosition(874, 244);

	var Diamond001;
	var Diamond002;
	var Diamond003;
	var Coral001 = CreateObjectAbove(Coral, 839, 223);
	Coral001->SetCon(184);
	var Coral002 = CreateObjectAbove(Coral, 866, 231);
	Coral002->SetCon(147);
	var Coral003 = CreateObjectAbove(Coral, 895, 239);
	Coral003->SetCon(154);
	var Coral004 = CreateObjectAbove(Coral, 912, 239);
	Coral004->SetCon(197);

	CreateObjectAbove(Seaweed, 796, 191);
	CreateObjectAbove(Seaweed, 815, 207);
	CreateObjectAbove(Seaweed, 831, 223);
	CreateObjectAbove(Seaweed, 857, 231);
	CreateObjectAbove(Seaweed, 896, 239);
	CreateObjectAbove(Seaweed, 913, 239);
	CreateObjectAbove(Seaweed, 893, 239);
	CreateObjectAbove(Seaweed, 885, 239);
	CreateObjectAbove(Seaweed, 866, 231);
	CreateObjectAbove(Seaweed, 918, 239);
	var Seaweed001 = CreateObject(Seaweed, 927, 232);
	Seaweed001->SetPosition(927, 232);
	CreateObjectAbove(Seaweed, 935, 231);

	var Joker001 = Diamond_Socket003->CreateContents(Joker);
	Joker001->SetPosition(257, 242);

	CreateObjectAbove(Mushroom, 573, 167);
	CreateObjectAbove(Mushroom, 310, 151);
	CreateObjectAbove(Mushroom, 281, 166);
	CreateObjectAbove(Mushroom, 350, 177);
	CreateObjectAbove(Mushroom, 232, 159);
	CreateObjectAbove(Mushroom, 612, 179);
	CreateObjectAbove(Mushroom, 332, 155);
	CreateObjectAbove(Mushroom, 330, 153);
	CreateObjectAbove(Mushroom, 362, 173);
	CreateObjectAbove(Mushroom, 350, 177);
	CreateObjectAbove(Mushroom, 707, 166);
	CreateObjectAbove(Mushroom, 576, 167);
	CreateObjectAbove(Mushroom, 250, 160);
	CreateObjectAbove(Mushroom, 573, 167);
	CreateObjectAbove(Mushroom, 575, 168);
	CreateObjectAbove(Mushroom, 371, 166);
	CreateObjectAbove(Mushroom, 706, 166);
	CreateObjectAbove(Mushroom, 381, 167);
	CreateObjectAbove(Mushroom, 586, 166);
	CreateObjectAbove(Mushroom, 556, 166);
	CreateObjectAbove(Mushroom, 690, 183);
	CreateObjectAbove(Mushroom, 690, 183);
	CreateObjectAbove(Mushroom, 407, 160);
	CreateObjectAbove(Mushroom, 385, 166);
	CreateObjectAbove(Mushroom, 259, 159);
	CreateObjectAbove(Mushroom, 593, 175);
	CreateObjectAbove(Mushroom, 600, 175);
	CreateObjectAbove(Mushroom, 333, 157);
	CreateObjectAbove(Mushroom, 512, 176);
	CreateObjectAbove(Mushroom, 574, 167);
	CreateObjectAbove(Mushroom, 690, 183);
	CreateObjectAbove(Mushroom, 239, 158);
	CreateObjectAbove(Mushroom, 245, 160);
	CreateObjectAbove(Mushroom, 404, 160);
	CreateObjectAbove(Mushroom, 680, 191);
	CreateObjectAbove(Mushroom, 294, 167);
	CreateObjectAbove(Mushroom, 676, 192);
	CreateObjectAbove(Mushroom, 296, 168);
	CreateObjectAbove(Mushroom, 525, 175);
	CreateObjectAbove(Mushroom, 280, 167);
	CreateObjectAbove(Mushroom, 617, 182);
	CreateObjectAbove(Mushroom, 383, 167);
	CreateObjectAbove(Mushroom, 660, 192);
	CreateObjectAbove(Mushroom, 634, 185);
	CreateObjectAbove(Mushroom, 498, 161);
	CreateObjectAbove(Mushroom, 682, 189);
	CreateObjectAbove(Mushroom, 376, 167);
	CreateObjectAbove(Mushroom, 698, 175);
	CreateObjectAbove(Mushroom, 675, 192);
	CreateObjectAbove(Mushroom, 242, 160);
	CreateObjectAbove(Mushroom, 504, 168);
	CreateObjectAbove(Mushroom, 280, 167);
	CreateObjectAbove(Mushroom, 272, 167);
	CreateObjectAbove(Mushroom, 641, 191);
	CreateObjectAbove(Mushroom, 689, 183);
	CreateObjectAbove(Mushroom, 317, 151);
	CreateObjectAbove(Mushroom, 661, 192);
	CreateObjectAbove(Mushroom, 314, 151);
	CreateObjectAbove(Mushroom, 627, 181);
	CreateObjectAbove(Mushroom, 241, 160);

	var Stalactite001 = CreateObject(Stalactite, 87, 163);
	Stalactite001->SetCon(20);
	Stalactite001->SetCategory(C4D_StaticBack);
	Stalactite001->SetClrModulation(0xffff0000);
	Stalactite001->MakeInvincible(false);
	Stalactite001->SetPosition(87, 163);
	var Stalactite002 = CreateObject(Stalactite, 79, 163);
	Stalactite002->SetCon(20);
	Stalactite002->SetCategory(C4D_StaticBack);
	Stalactite002->SetClrModulation(0xffff0000);
	Stalactite002->MakeInvincible(false);
	Stalactite002->SetPosition(79, 163);

	var Firestone001 = CreateObject(Firestone, 330, 182);
	Firestone001->SetPosition(330, 182);
	var Firestone002 = CreateObject(Firestone, 453, 238);
	Firestone002->SetPosition(453, 238);
	var Firestone003 = CreateObject(Firestone, 599, 203);
	Firestone003->SetPosition(599, 203);
	return true;
}
