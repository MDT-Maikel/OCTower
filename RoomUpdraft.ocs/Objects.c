/* Automatically created objects file */

func InitializeObjects()
{
	var Grass001 = CreateObjectAbove(Grass, 556, 333);
	var Grass002 = CreateObjectAbove(Grass, 551, 333);
	var Grass003 = CreateObjectAbove(Grass, 548, 330);
	var Grass004 = CreateObjectAbove(Grass, 544, 327);
	var Grass005 = CreateObjectAbove(Grass, 539, 327);
	var Grass006 = CreateObjectAbove(Grass, 534, 325);
	var Grass007 = CreateObjectAbove(Grass, 528, 325);
	var Grass008 = CreateObjectAbove(Grass, 524, 326);
	var Grass009 = CreateObjectAbove(Grass, 519, 326);
	var Grass010 = CreateObjectAbove(Grass, 516, 329);
	var Grass011 = CreateObjectAbove(Grass, 513, 331);
	var Grass012 = CreateObjectAbove(Grass, 510, 335);
	var Grass013 = CreateObjectAbove(Grass, 505, 339);
	var Grass014 = CreateObjectAbove(Grass, 503, 342);
	var Grass015 = CreateObjectAbove(Grass, 497, 342);
	var Grass016 = CreateObjectAbove(Grass, 494, 345);
	var Grass017 = CreateObjectAbove(Grass, 490, 347);
	var Grass018 = CreateObjectAbove(Grass, 487, 350);
	var Grass019 = CreateObjectAbove(Grass, 481, 350);
	var Grass020 = CreateObjectAbove(Grass, 473, 349);

	var ItemSpawn001 = ItemSpawn->Create(Boompack,424,1931);
	ItemSpawn001->SetPosition(424, 1931);
	ItemSpawn001->SetClrModulation(0xffff0000);

	var JetStream001 = CreateObject(JetStream, 457, 1826);
	JetStream001->Create(0, 0, -37, -105, nil, 40, 120);
	JetStream001->SetPosition(457, 1826);
	var JetStream002 = CreateObject(JetStream, 281, 1676);
	JetStream002->Create(0, 0, -143, -39, nil, 40, 120);
	JetStream002->SetPosition(281, 1676);
	var JetStream003 = CreateObject(JetStream, 41, 1716);
	JetStream003->Create(0, 0, 72, -57, nil, 40, 120);
	JetStream003->SetPosition(41, 1716);

	var ItemSpawn002 = ItemSpawn->Create(WindBag,36,1677);
	ItemSpawn002->SetPosition(36, 1677);
	ItemSpawn002->SetClrModulation(0xffffff00);

	var JetStream004 = CreateObject(JetStream, 339, 1604);
	JetStream004->Create(0, 0, -3, -80, nil, 10, 120);
	JetStream004->SetPosition(339, 1604);
	var JetStream005 = CreateObject(JetStream, 104, 1429);
	JetStream005->Create(0, 0, 62, 0, nil, 10, 120);
	JetStream005->SetPosition(104, 1429);

	var Sequence001 = CreateObject(Sequence, 18, 1297);
	Sequence001->SetCheckInterval(40);
	Sequence001->SetPosition(18, 1297);
	Sequence001->SetTrigger({Rect=[-20,-41,175,133],Trigger="player_enter_region_rect"}, 29);
	Sequence001->SetAction({Amount={Function="int_constant",Value=1},AngleDeviation={Function="int_constant",Value=1},Function="cast_objects",ID={Function="def_constant",Value=Firestone},MeanAngle={Function="int_constant",Value=40},Speed={Function="int_constant",Value=50}}, nil);

	var JetStream006 = CreateObject(JetStream, 435, 1109);
	JetStream006->Create(0, 0, -69, -57, nil, 20, 120);
	JetStream006->SetPosition(435, 1109);
	var JetStream007 = CreateObject(JetStream, 280, 1095);
	JetStream007->Create(0, 0, 1, -67, nil, 20, 120);
	JetStream007->SetPosition(280, 1095);
	var JetStream008 = CreateObject(JetStream, 122, 1091);
	JetStream008->Create(0, 0, 1, -67, nil, 20, 120);
	JetStream008->SetPosition(122, 1091);

	var EnemySpawn001 = CreateObject(EnemySpawn, 26, 1078);
	EnemySpawn001.attack_path = [{X=0,Y=1}];
	EnemySpawn001->SetEnemy({AttackMode={Identifier="BowArrow"},AttackSpeed=100,Backpack=false,Bounty=0,Color=-11162881,Energy=50,GuardRange={hgt=264,wdt=600,x=-274,y=859},ScaleX=100,ScaleY=100,Shield=false,Speed=100,Type="Clonk"});
	EnemySpawn001->SetMaxConcurrentEnemies(1);
	EnemySpawn001.spawn_action = {Amount={Function="int_constant",Value=8},BlitMode=0,CollisionFunc="bounce",Color={Function="color_constant",Value=-16711681},FadeOut=true,Function="cast_particles",Gravity={Function="int_constant",Value=20},Lifetime={Function="int_constant",Value=100},Name="Dust",Size={Function="int_constant",Value=10},SizeEnd={Function="int_constant",Value=1},Speed={Function="int_constant",Value=20}};
	EnemySpawn001->SetSpawnInterval(0);
	EnemySpawn001->SetPosition(26, 1078);

	var Sequence002 = CreateObject(Sequence, 123, 982);
	Sequence002->SetPosition(123, 982);
	Sequence002->SetTrigger({Rect=[-20,-20,40,88],Trigger="player_enter_region_rect"}, 10);
	Sequence002->SetAction({Function="enemy_spawn_set_active",Target={Function="object_constant",Value=EnemySpawn001}}, nil);

	var Fern001 = CreateObjectAbove(Fern, 534, 327);
	Fern001->SetCon(209);
	Fern001->SetSeedChance(0);

	CreateObjectAbove(Vine, 553, 406);
	CreateObjectAbove(Vine, 515, 414);
	var JetStream009 = CreateObject(JetStream, 265, 303);
	JetStream009->Create(0, 0, -47, -66, nil, 10, 100);
	JetStream009->SetPosition(265, 303);
	var JetStream010 = CreateObject(JetStream, 212, 108);
	JetStream010->Create(0, 0, -171, -7, nil, 10, 130);
	JetStream010->SetPosition(212, 108);
	var JetStream011 = CreateObject(JetStream, 215, 869);
	JetStream011->Create(0, 0, 72, -112, nil, 20, 120);
	JetStream011->SetPosition(215, 869);
	var JetStream012 = CreateObject(JetStream, 216, 886);
	JetStream012->Create(0, 0, 133, -1, nil, 10, 120);
	JetStream012->SetPosition(216, 886);
	var JetStream013 = CreateObject(JetStream, 491, 811);
	JetStream013->Create(0, 0, -96, -180, nil, 10, 120);
	JetStream013->SetPosition(491, 811);
	var JetStream014 = CreateObject(JetStream, 303, 619);
	JetStream014->Create(0, 0, -121, -68, nil, 10, 120);
	JetStream014->SetPosition(303, 619);

	CreateObjectAbove(Vine, 78, 526);
	var JetStream015 = CreateObject(JetStream, 128, 459);
	JetStream015->Create(0, 0, 120, -69, nil, 10, 120);
	JetStream015->SetPosition(128, 459);

	CreateObjectAbove(Vine, 555, 520);
	var EnvPack_Guidepost2001 = CreateObjectAbove(EnvPack_Guidepost2, 524, 1825);
	EnvPack_Guidepost2001->SetInscription({DE="Nächster Halt: Oben.",Function="Translate",US="Next stop: Up."});
	var Basement001 = CreateObject(Basement, 165, 140);
	Basement001->SetWidth(10);
	Basement001->SetPosition(165, 140);
	var Basement002 = CreateObject(Basement, 165, 132);
	Basement002->SetWidth(10);
	Basement002->SetPosition(165, 132);
	var Basement003 = CreateObject(Basement, 165, 225);
	Basement003->SetWidth(10);
	Basement003->SetPosition(165, 225);
	var Basement004 = CreateObject(Basement, 323, 305);
	Basement004->SetWidth(30);
	Basement004->SetPosition(323, 305);
	var Basement005 = CreateObject(Basement, 168, 889);
	Basement005->SetPosition(168, 889);
	var Basement006 = CreateObject(Basement, 25, 1092);
	Basement006->SetWidth(10);
	Basement006->SetPosition(25, 1092);
	var Basement007 = CreateObject(Basement, 305, 1443);
	Basement007->SetWidth(20);
	Basement007->SetPosition(305, 1443);

	var Hatch001 = CreateObject(Hatch, 36, 1646);
	Hatch001->SetCategory(C4D_StaticBack);
	Hatch001->SetPosition(36, 1646);

	var HatchBasement001 = CreateObjectAbove(HatchBasement, 36, 1652);
	HatchBasement001->SetParent(Hatch001);

	var Basement008 = CreateObject(Basement, 340, 1697);
	Basement008->SetWidth(60);
	Basement008->SetPosition(340, 1697);
	var Basement009 = CreateObject(Basement, 347, 344);
	Basement009->SetWidth(30);
	Basement009->SetPosition(347, 344);
	var Basement010 = CreateObject(Basement, 146, 305);
	Basement010->SetWidth(60);
	Basement010->SetPosition(146, 305);

	var RoomEntrance001 = CreateObjectAbove(RoomEntrance, 612, 1823);
	RoomEntrance001->SetColor(0xff32c832);

	var MovingBrick001 = CreateObject(MovingBrick, 75, 1381);
	MovingBrick001->SetComDir(COMD_Left);
	MovingBrick001->MoveHorizontal(9, 142);
	MovingBrick001->SetPosition(75, 1381);
	var MovingBrick002 = CreateObject(MovingBrick, 250, 1285);
	MovingBrick002->SetComDir(COMD_Left);
	MovingBrick002->MoveHorizontal(215, 325);
	MovingBrick002->SetPosition(250, 1285);
	var MovingBrick003 = CreateObject(MovingBrick, 461, 1286);
	MovingBrick003->SetComDir(COMD_Left);
	MovingBrick003->MoveHorizontal(408, 496);
	MovingBrick003->SetPosition(461, 1286);
	var MovingBrick004 = CreateObject(MovingBrick, 527, 1203);
	MovingBrick004->SetComDir(COMD_Up);
	MovingBrick004->MoveVertical(1161, 1246);
	MovingBrick004->SetPosition(527, 1203);

	var StoneDoor001 = CreateObject(StoneDoor, 150, 1363);
	StoneDoor001->SetComDir(COMD_Up);
	StoneDoor001->MakeInvincible(false);
	StoneDoor001->SetPosition(150, 1363);
	StoneDoor001->SetPlrViewOnSignalChange(true);

	var FloorSwitch001 = CreateObject(FloorSwitch, 275, 1442);
	FloorSwitch001->SetPosition(275, 1442);
	FloorSwitch001->SetSwitchTarget(StoneDoor001);
	FloorSwitch001->SetActions({Door={Function="object_constant",Value=StoneDoor001},Function="open_door"}, {Door={Function="object_constant",Value=StoneDoor001},Function="close_door"});
	FloorSwitch001.SwitchMass = 20;

	var RoomExit001 = CreateObjectAbove(RoomExit, 562, 262);
	RoomExit001->SetColor(0xffc83232);

	var Bone001 = CreateObject(Bone, 612, 1663);
	Bone001->SetR(-51);
	Bone001->SetPosition(612, 1663);

	var Skull001 = CreateObject(Skull, 616, 1384);
	Skull001->SetR(-156);
	Skull001->SetPosition(616, 1384);

	var Rock001 = CreateObjectAbove(Rock, 157, 884);
	Rock001->Unstick(7);
	var Rock002 = CreateObjectAbove(Rock, 169, 884);
	Rock002->Unstick(7);
	var Rock003 = CreateObjectAbove(Rock, 163, 884);
	Rock003->Unstick(7);
	var Rock004 = CreateObjectAbove(Rock, 174, 884);
	Rock004->Unstick(7);

	var Joker001 = CreateObjectAbove(Joker, 92, 1926);
	Joker001->Unstick(7);

	var AncientTablet001 = CreateObjectAbove(AncientTablet, 165, 127);
	AncientTablet001->Unstick(7);

	CreateObjectAbove(Mushroom, 620, 190);
	return true;
}
