/* Automatically created objects file */

func InitializeObjects()
{
	var EnemySpawn001 = CreateObject(EnemySpawn, 578, 299);
	EnemySpawn001.attack_path = [{X=-529,Y=5}];
	EnemySpawn001->SetEnemy({AttackMode={Identifier="NukePowderKeg"},AttackSpeed=100,Backpack=false,Bounty=0,Color=16711680,Energy=1,ScaleX=100,ScaleY=100,Shield=false,Speed=150,Type="Clonk"});
	EnemySpawn001->SetSpawnCount(40);
	EnemySpawn001->SetSpawnInterval(5);
	EnemySpawn001->SetPosition(578, 299);

	var Rule_Gravestones001 = CreateObject(Rule_Gravestones, 621, 18);
	Rule_Gravestones001->SetPosition(621, 18);
	Rule_Gravestones001->SetFadeOut(100);

	var Fuse001 = CreateObject(Fuse, 81, 317);
	Fuse001.LineColors = [-10210816,-16711423];
	Fuse001->SetPosition(81, 317);
	Fuse->Create();
	var Fuse002 = CreateObject(Fuse, 63, 317);
	Fuse002.LineColors = [-10210816,-16711423];
	Fuse002->SetPosition(63, 317);
	Fuse->Create();
	var Fuse003 = CreateObject(Fuse, 32, 314);
	Fuse003.LineColors = [-10210816,-16711423];
	Fuse003->SetPosition(32, 314);
	Fuse->Create();

	var EnemySpawn002 = CreateObject(EnemySpawn, 76, 153);
	EnemySpawn002.attack_path = [{X=-2,Y=73}];
	EnemySpawn002->SetEnemy({Rider={Properties={AttackMode={Identifier="Blunderbuss"},AttackSpeed=5000,Backpack=false,Bounty=0,Color=16711680,Energy=50,ScaleX=100,ScaleY=100,Shield=false,Speed=100},Type="Clonk"},Type="Balloon"});
	EnemySpawn002->SetPosition(76, 153);

	var Sequence001 = CreateObject(Sequence, 76, 225);
	Sequence001->SetPosition(76, 225);
	Sequence001->SetTrigger({Rect=[-54,-137,74,162],Trigger="player_enter_region_rect"}, 6);
	Sequence001->SetAction({Actions=[{Function="enemy_spawn_set_active",Target={Function="object_constant",Value=EnemySpawn002}}],Function="sequence"}, nil);
	Sequence001->SetDeactivateAfterAction(true);

	var EnemySpawn003 = CreateObject(EnemySpawn, 599, 350);
	EnemySpawn003.attack_path = [{X=-327,Y=1}];
	EnemySpawn003->SetEnemy({FlySpeed=300,Rider=nil,Type="BoomAttack"});
	EnemySpawn003->SetPosition(599, 350);
	var EnemySpawn004 = CreateObject(EnemySpawn, 602, 443);
	EnemySpawn004.attack_path = [{X=-417,Y=1}];
	EnemySpawn004->SetEnemy({FlySpeed=300,Rider=nil,Type="BoomAttack"});
	EnemySpawn004->SetPosition(602, 443);
	var EnemySpawn005 = CreateObject(EnemySpawn, 599, 395);
	EnemySpawn005.attack_path = [{X=-321,Y=2}];
	EnemySpawn005->SetEnemy({FlySpeed=300,Rider=nil,Type="BoomAttack"});
	EnemySpawn005->SetPosition(599, 395);
	var EnemySpawn006 = CreateObject(EnemySpawn, 560, 119);
	EnemySpawn006.attack_path = [{X=-1,Y=1}];
	EnemySpawn006->SetEnemy({Gunner={Properties={AttackMode={Identifier="Lantern"},AttackSpeed=100,Backpack=false,Bounty=0,Color=16711680,Energy=50,GuardRange={hgt=276,wdt=765,x=95,y=-31},ScaleX=100,ScaleY=100,Shield=false,Speed=100},Type="Clonk"},Type="Catapult"});
	EnemySpawn006->SetMaxConcurrentEnemies(1);
	EnemySpawn006->SetPosition(560, 119);

	var Sequence002 = CreateObject(Sequence, 296, 403);
	Sequence002->SetCheckInterval(36);
	Sequence002->SetPosition(296, 403);
	Sequence002->SetTrigger({Rect=[-29,-82,363,147],Trigger="player_enter_region_rect"}, 18);
	Sequence002->SetAction({Actions=[{Function="enemy_spawn_set_active",Target={Function="object_constant",Value=EnemySpawn005}},{Function="enemy_spawn_set_active",Target={Function="object_constant",Value=EnemySpawn004}},{Function="enemy_spawn_set_active",Target={Function="object_constant",Value=EnemySpawn003}}],Function="sequence"}, nil);

	var JetStream001 = CreateObject(JetStream, 471, 183);
	JetStream001->SetClrModulation(0xff468dff);
	JetStream001->Create(0, 0, -204, -4, nil, 40, 100);
	JetStream001->SetPosition(471, 183);
	var JetStream002 = CreateObject(JetStream, 251, 223);
	JetStream002->SetClrModulation(0xff2aff83);
	JetStream002->Create(0, 0, 227, 2, nil, 40, 40);
	JetStream002->SetPosition(251, 223);

	var Deco_Tree_Deciduous2_Burned001 = CreateObjectAbove(Deco_Tree_Deciduous2_Burned, 444, 240);
	Deco_Tree_Deciduous2_Burned001->SetCon(96);
	Deco_Tree_Deciduous2_Burned001->MakeInvincible(false);
	var Deco_Tree_Deciduous2_Burned002 = CreateObjectAbove(Deco_Tree_Deciduous2_Burned, 304, 241);
	Deco_Tree_Deciduous2_Burned002->MakeInvincible(false);

	var EnemySpawn007 = CreateObject(EnemySpawn, 310, 136);
	EnemySpawn007.attack_path = [{X=-227,Y=-76}];
	EnemySpawn007->SetEnemy({AttackMode={Identifier="Firestone"},AttackSpeed=100,Backpack=false,Bounty=0,Color=16711680,Energy=50,ScaleX=100,ScaleY=100,Shield=false,Speed=100,Type="Clonk"});
	EnemySpawn007.spawn_action = {Amount={Function="int_constant",Value=8},BlitMode=0,CollisionFunc="bounce",Color={Function="color_constant",Value=-16777216},FadeOut=true,Function="cast_particles",Gravity={Function="int_constant",Value=0},Lifetime={Function="int_constant",Value=100},Name="Smoke",Size={Function="int_constant",Value=30},SizeEnd={Function="int_constant",Value=1},Speed={Function="int_constant",Value=20}};
	EnemySpawn007->SetSpawnCount(100);
	EnemySpawn007->SetSpawnInterval(1);
	EnemySpawn007->SetSpawnPosition({Area=[-289,-114,600,220],Mode="rectangle"});
	EnemySpawn007->SetPosition(310, 136);

	var StoneDoor001 = CreateObject(StoneDoor, 260, 436);
	StoneDoor001->MakeInvincible(false);
	StoneDoor001->SetPosition(260, 436);
	StoneDoor001->SetPlrViewOnSignalChange(true);

	var Keypad001 = CreateObjectAbove(Keypad, 598, 124);
	Keypad001->SetSwitchTarget(StoneDoor001);
	Keypad001->SetKeypadHashedCode("cw/ji02PlE9Ek]Ht$cg-.xTN$");
	Keypad001->SetCodeActions(nil, {Function="enemy_spawn_set_active",Target={Function="object_constant",Value=EnemySpawn007}});

	var ItemSpawn001 = ItemSpawn->Create(WindBag,128,65);
	ItemSpawn001->SetPosition(128, 65);

	var Diamond_Socket001 = CreateObject(Diamond_Socket, 291, 361);
	Diamond_Socket001->SetPosition(291, 361);
	var Diamond_Socket002 = CreateObject(Diamond_Socket, 308, 355);
	Diamond_Socket002->SetPosition(308, 355);
	var Diamond_Socket003 = CreateObject(Diamond_Socket, 337, 360);
	Diamond_Socket003->SetPosition(337, 360);

	var EnvPack_Guidepost2001 = CreateObjectAbove(EnvPack_Guidepost2, 108, 241);
	EnvPack_Guidepost2001->SetInscription({DE="Da bist du auf dem Holzweg, bleib meinen Schlüssel fern!",Function="Translate",US="You are heading the wrong way, stay away from my key!"});
	var StoneDoor002 = CreateObject(StoneDoor, 244, 436);
	StoneDoor002->SetComDir(COMD_Down);
	StoneDoor002->MakeInvincible(false);
	StoneDoor002->SetPosition(244, 436);
	StoneDoor002->SetPlrViewOnSignalChange(true);

	var RoomEntrance001 = CreateObjectAbove(RoomEntrance, 44, 456);
	RoomEntrance001->SetColor(0xff32c832);

	var RoomExit001 = CreateObjectAbove(RoomExit, 44, 71);
	RoomExit001->SetColor(0xffc83232);

	var RoomDoor002 = CreateObjectAbove(RoomDoor, 42, 312);
	var RoomDoor001 = CreateObjectAbove(RoomDoor, 42, 367);
	RoomDoor001->SetEntranceAction({Actions=[{Function="enemy_spawn_set_active",Target={Function="object_constant",Value=EnemySpawn001}},{Function="ambience_shader",ShaderName="Grayscale",Status={Function="bool_constant",Value=true}}],Function="sequence"});
	RoomDoor001->SetTargetDoor(RoomDoor002);
	RoomDoor002->SetEntranceAction({Function="ambience_shader",ShaderName="Grayscale",Status={Function="bool_constant",Value=false}});
	RoomDoor002->SetTargetDoor(RoomDoor001);
	var RoomDoor004 = CreateObjectAbove(RoomDoor, 598, 240);
	var RoomDoor003 = CreateObjectAbove(RoomDoor, 598, 312);
	RoomDoor003->SetEntranceAction({Actions=[{Function="ambience_shader",ShaderName="Grayscale",Status={Function="bool_constant",Value=false}},{Function="enemy_spawn_set_active",Target={Function="object_constant",Value=EnemySpawn006}}],Function="sequence"});
	RoomDoor003->SetTargetDoor(RoomDoor004);
	RoomDoor004->SetEntranceAction({Function="ambience_shader",ShaderName="Grayscale",Status={Function="bool_constant",Value=true}});
	RoomDoor004->SetTargetDoor(RoomDoor003);

	var Key001 = CreateObject(Key, 44, 223);
	Key001->SetR(-41);
	Key001->SetClrModulation(0xffff9513);
	Key001->SetPosition(44, 223);
	Key001->Unstick(7);

	var RoomDoor006 = CreateObjectAbove(RoomDoor, 139, 240);
	var RoomDoor005 = CreateObjectAbove(RoomDoor, 104, 71);
	RoomDoor005->SetEntranceAction({Function="ambience_shader",ShaderName="Grayscale",Status={Function="bool_constant",Value=false}});
	RoomDoor005->SetTargetDoor(RoomDoor006);
	RoomDoor006->SetKey(Key001);
	RoomDoor006->SetTargetDoor(RoomDoor005);

	var Ruin_WoodenCabin001 = CreateObjectAbove(Ruin_WoodenCabin, 379, 239);
	Ruin_WoodenCabin001->MakeInvincible(false);

	CreateObjectAbove(Column, 149, 440);
	CreateObjectAbove(Column, 437, 307);
	CreateObjectAbove(Column, 300, 306);
	var Switch001 = CreateObjectAbove(Switch, 83, 312);
	Switch001->SetSwitchTarget(StoneDoor002);
	Switch001->SetSwitchDir(1);

	CreateObjectAbove(Clonk_Grave, 72, 239);
	CreateObjectAbove(Clonk_Grave, 86, 239);

	var PlayerStart001 = CreateObject(PlayerStart, 77, 443);
	PlayerStart001->SetPosition(77, 443);
	PlayerStart001->SetStartingMaterial([Shovel]);
	PlayerStart001->SetViewLock(false);
	var Diamond001;
	var Diamond002;
	var Diamond003;
	var AncientTablet001 = CreateObject(AncientTablet, 281, 352);
	AncientTablet001->SetPosition(281, 352);

	var DynamiteBox001 = CreateObject(DynamiteBox, 223, 343);
	DynamiteBox001->SetPosition(223, 343);
	var Bread001 = CreateObjectAbove(Bread, 352, 455);
	Bread001->Unstick(7);

	var Trunk001 = CreateObject(Trunk, 210, 358);
	Trunk001->SetCon(145);
	Trunk001->SetR(-141);
	Trunk001.Plane = 500;
	Trunk001->MakeInvincible(false);
	Trunk001->SetPosition(210, 358);
	return true;
}
