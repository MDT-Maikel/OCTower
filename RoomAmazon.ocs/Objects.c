/* Automatically created objects file */

func InitializeObjects()
{
	var Torch001 = CreateObjectAbove(Torch, 155, 428);
	Torch001->AttachToWall(true);
	Torch001->SetMeshMaterial("Torch", 0);
	Torch001->SetState(3);

	var ItemSpawn001 = ItemSpawn->Create(Boompack,253,423);
	ItemSpawn001->SetPosition(253, 423);

	CreateObjectAbove(LotsOfCoins, 57, 457);
	CreateObjectAbove(LotsOfCoins, 76, 456);

	var Sequence001 = CreateObject(Sequence, 126, 262);
	Sequence001->SetCheckInterval(30);
	Sequence001->SetPosition(126, 262);
	Sequence001->SetTrigger({Interval=30,Trigger="interval"}, 15);
	Sequence001->SetCondition({Function="object_exists",Object={Area={Area=[25,184,195,195],Function="InRect"},Function="find_object_in_area",ID={Function="def_constant",Value=Clonk}}});
	Sequence001->SetAction({Function="create_object",ID={Function="def_constant",Value=Firestone},Rotation={Function="int_constant",Value=0},SpeedR=nil,SpeedX={Function="int_random",Max={Function="int_constant",Value=99},Min={Function="int_constant",Value=-99}},SpeedY={Function="int_random",Max={Function="int_constant",Value=-3},Min={Function="int_constant",Value=-99}}}, nil);

	var Rule_NoPowerNeed001 = CreateObject(Rule_NoPowerNeed, 554, 31);
	Rule_NoPowerNeed001->SetPosition(554, 31);

	var Rule_FastPump001 = CreateObject(Rule_FastPump, 512, 27);
	Rule_FastPump001->SetPosition(512, 27);
	Rule_FastPump001->SetPumpSpeed(50);

	var Fuse001 = CreateObject(Fuse, 275, 912);
	Fuse001.LineColors = [-10210816,-16711423];
	Fuse001->SetPosition(275, 912);
	Fuse->Create();
	var Fuse002 = CreateObject(Fuse, 304, 534);
	Fuse002.LineColors = [-10210816,-16711423];
	Fuse002->SetPosition(304, 534);
	Fuse->Create();
	var Fuse003 = CreateObject(Fuse, 266, 746);
	Fuse003.LineColors = [-10210816,-16711423];
	Fuse003->SetPosition(266, 746);
	Fuse->Create();
	var Fuse004 = CreateObject(Fuse, 264, 744);
	Fuse004.LineColors = [-10210816,-16711423];
	Fuse004->SetPosition(264, 744);
	Fuse->Create();
	var Fuse005 = CreateObject(Fuse, 251, 742);
	Fuse005.LineColors = [-10210816,-16711423];
	Fuse005->SetPosition(251, 742);
	Fuse->Create();
	var Fuse006 = CreateObject(Fuse, 273, 490);
	Fuse006.LineColors = [-10210816,-16711423];
	Fuse006->SetPosition(273, 490);
	Fuse->Create();
	var Fuse007 = CreateObject(Fuse, 250, 261);
	Fuse007.LineColors = [-10210816,-16711423];
	Fuse007->SetPosition(250, 261);
	Fuse->Create();

	var Rule_Gravestones001 = CreateObject(Rule_Gravestones, 223, 423);
	Rule_Gravestones001->SetPosition(223, 423);
	Rule_Gravestones001->SetFadeOut(60);

	var Fuse008 = CreateObject(Fuse, 445, 716);
	Fuse008.LineColors = [-10210816,-16711423];
	Fuse008->SetPosition(445, 716);
	Fuse->Create();
	var Fuse009 = CreateObject(Fuse, 445, 716);
	Fuse009.LineColors = [-10210816,-16711423];
	Fuse009->SetPosition(445, 716);
	Fuse->Create();

	var Dynamite001 = CreateObjectAbove(Dynamite, 445, 359);
	var Dynamite002 = CreateObjectAbove(Dynamite, 435, 367);

	var Fuse010 = CreateObjectAbove(Fuse, 445, 708);
	Fuse010.LineColors = [-10210816,-16711423];
	Fuse->Create(Dynamite001, Dynamite002);
	var Fuse011 = CreateObject(Fuse, 421, 729);
	Fuse011.LineColors = [-10210816,-16711423];
	Fuse011->SetPosition(421, 729);
	Fuse->Create();
	var Fuse012 = CreateObject(Fuse, 435, 726);
	Fuse012.LineColors = [-10210816,-16711423];
	Fuse012->SetPosition(435, 726);
	Fuse->Create();

	var Dynamite003 = CreateObject(Dynamite, 435, 363);
	Dynamite003->SetR(64);
	Dynamite003->SetPosition(435, 363);

	var Fuse013 = CreateObjectAbove(Fuse, 435, 726);
	Fuse013.LineColors = [-10210816,-16711423];
	Fuse->Create(Dynamite003, Dynamite002);
	var Fuse014 = CreateObject(Fuse, 435, 723);
	Fuse014.LineColors = [-10210816,-16711423];
	Fuse014->SetPosition(435, 723);
	Fuse->Create();
	var Fuse015 = CreateObject(Fuse, 435, 726);
	Fuse015.LineColors = [-10210816,-16711423];
	Fuse015->SetPosition(435, 726);
	Fuse->Create();

	var Dynamite004 = CreateObjectAbove(Dynamite, 447, 359);

	var Fuse016 = CreateObjectAbove(Fuse, 435, 726);
	Fuse016.LineColors = [-10210816,-16711423];
	Fuse->Create(Dynamite003, Dynamite004);
	var Fuse017 = CreateObject(Fuse, 447, 721);
	Fuse017.LineColors = [-10210816,-16711423];
	Fuse017->SetPosition(447, 721);
	Fuse->Create();
	var Fuse018 = CreateObject(Fuse, 447, 721);
	Fuse018.LineColors = [-10210816,-16711423];
	Fuse018->SetPosition(447, 721);
	Fuse->Create();

	var Dynamite005 = CreateObject(Dynamite, 422, 367);
	Dynamite005->SetR(-34);
	Dynamite005->SetPosition(422, 367);

	var Fuse019 = CreateObjectAbove(Fuse, 447, 708);
	Fuse019.LineColors = [-10210816,-16711423];
	Fuse->Create(Dynamite004, Dynamite005);
	var Fuse020 = CreateObject(Fuse, 422, 367);
	Fuse020.LineColors = [-10210816,-16711423];
	Fuse020->SetPosition(422, 367);
	Fuse->Create();
	var Fuse021 = CreateObject(Fuse, 422, 367);
	Fuse021.LineColors = [-10210816,-16711423];
	Fuse021->SetPosition(422, 367);
	Fuse->Create();

	var DynamiteBox001 = CreateObjectAbove(DynamiteBox, 343, 334);
	DynamiteBox001->SetDynamiteCount(0);

	var Fuse022 = CreateObject(Fuse, 422, 367);
	Fuse022.LineColors = [-10210816,-16711423];
	Fuse022->SetPosition(422, 367);
	Fuse->Create(Dynamite005, DynamiteBox001);

	var MetalBarrel001 = CreateObjectAbove(MetalBarrel, 529, 382);
	MetalBarrel001->SetColor(0xfffe8a0e);
	MetalBarrel001->SetName("Metal Barrel with Magma");
	MetalBarrel001->Unstick(7);

	var DuroLava001 = MetalBarrel001->CreateContents(DuroLava);
	DuroLava001->SetStackCount(300);
	DuroLava001->SetPosition(529, 377);

	var LargeCaveMushroom001 = CreateObjectAbove(LargeCaveMushroom, 171, 377);
	LargeCaveMushroom001->SetClrModulation(0xffdddfed);
	LargeCaveMushroom001->MakeInvincible(false);
	LargeCaveMushroom001->SetSeedAmount(0);
	LargeCaveMushroom001->SetSeedChance(0);

	CreateObjectAbove(Fern, 204, 456);
	CreateObjectAbove(Fern, 469, 445);

	var LargeCaveMushroom002 = CreateObjectAbove(LargeCaveMushroom, 216, 378);
	LargeCaveMushroom002->SetClrModulation(0xffdddfed);
	LargeCaveMushroom002->MakeInvincible(false);
	LargeCaveMushroom002->SetSeedAmount(0);
	LargeCaveMushroom002->SetSeedChance(0);
	var LargeCaveMushroom003 = CreateObjectAbove(LargeCaveMushroom, 194, 376);
	LargeCaveMushroom003->SetClrModulation(0xffdddfed);
	LargeCaveMushroom003->MakeInvincible(false);
	LargeCaveMushroom003->SetSeedAmount(0);
	LargeCaveMushroom003->SetSeedChance(0);

	CreateObjectAbove(Fern, 463, 345);
	CreateObjectAbove(Fern, 252, 376);

	var MetalBarrel002 = CreateObjectAbove(MetalBarrel, 543, 382);
	MetalBarrel002->SetColor(0xfffe8a0e);
	MetalBarrel002->SetName("Metal Barrel with Magma");

	var DuroLava002 = MetalBarrel002->CreateContents(DuroLava);
	DuroLava002->SetStackCount(300);
	DuroLava002->SetPosition(543, 376);

	var MetalBarrel003 = CreateObjectAbove(MetalBarrel, 590, 385);
	MetalBarrel003->SetColor(0xfffe8a0e);
	MetalBarrel003->SetName("Metal Barrel with Magma");

	var DuroLava003 = MetalBarrel003->CreateContents(DuroLava);
	DuroLava003->SetStackCount(300);
	DuroLava003->SetPosition(590, 379);
	var Basement001 = CreateObject(Basement, 125, 307);
	Basement001->SetPosition(125, 307);
	Basement001->MakeInvincible(false);

	var RoomEntrance001 = CreateObjectAbove(RoomEntrance, 157, 455);
	RoomEntrance001->SetColor(0xff32c832);

	var RoomExit001 = CreateObjectAbove(RoomExit, 502, 231);
	RoomExit001->SetColor(0xffc83232);

	var Idol001 = CreateObjectAbove(Idol, 180, 455);
	Idol001->SetColor(0xff55aa00);
	Idol001->SetMeshMaterial("IdolGrayColor", 0);
	Idol001->SetName("Statue");
	Idol001->MakeInvincible(false);
	Idol001->SetAction("ItemRightLow");
	Idol001->EditorSetItemRight({Bone="Javelin",MeshTransformation=[-1500,0,0,0,0,-1500,0,0,0,0,1500,0],Type=Javelin});
	var Idol002 = CreateObjectAbove(Idol, 349, 382);
	Idol002->SetColor(0xff00557f);
	Idol002->SetMeshMaterial("IdolGrayColor", 0);
	Idol002->SetName("Statue");
	Idol002->MakeInvincible(false);
	Idol002->CustomInitialize("this.MeshTransformation = Trans_Scale(500)");
	Idol002->SetAction("ItemCentral");
	Idol002->EditorSetItemLeft({Bone="main",MeshTransformation=[0,0,1200,0,1200,0,0,0,0,1200,0,-1200],Type=Shield});
	var Idol003 = CreateObjectAbove(Idol, 134, 456);
	Idol003->SetColor(0xffff5500);
	Idol003->SetName("Statue");
	Idol003->MakeInvincible(false);
	Idol003->SetAction("ItemLeftLow");
	Idol003->EditorSetItemLeft({Bone="Javelin",MeshTransformation=[-1500,0,0,0,0,-1500,0,0,0,0,1500,0],Type=Javelin});
	Idol003->EditorSetItemRight({Bone="main",MeshTransformation=nil,Type=nil});
	var Idol004 = CreateObjectAbove(Idol, 112, 359);
	Idol004->SetColor(0xffff007f);
	Idol004->SetName("Statue");
	Idol004->MakeInvincible(false);
	Idol004->CustomInitialize("this.MeshTransformation = Trans_Scale(500)");
	Idol004->SetAction("ItemLeftHigh");
	Idol004->EditorSetItemLeft({Bone="main",MeshTransformation=[-1200,0,0,0,0,-1200,0,0,0,0,1200,0],Type=Axe});

	var StoneDoor001 = CreateObject(StoneDoor, 109, 436);
	StoneDoor001->SetComDir(COMD_Down);
	StoneDoor001->SetPosition(109, 436);
	StoneDoor001->SetPlrViewOnSignalChange(true);

	var FloorSwitch001 = CreateObject(FloorSwitch, 454, 452);
	FloorSwitch001->SetPosition(454, 452);
	FloorSwitch001->SetSwitchTarget(StoneDoor001);
	FloorSwitch001.SwitchMass = 10;

	var Foundry001 = CreateObjectAbove(Foundry, 383, 375);
	Foundry001->MakeInvincible(false);

	var InventorsLab001 = CreateObjectAbove(InventorsLab, 290, 376);
	InventorsLab001->SetClrModulation(0xff676b14);
	InventorsLab001->SetObjectBlitMode(GFX_BLIT_Mod2);
	InventorsLab001->MakeInvincible(false);

	var Dialogue001 = Idol002->SetDialogue("Statue",false);
	Dialogue001->SetUserDialogue({Actions=[{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Ich bin eine schüchterne Statue. Ich werde gar nicht mit dir reden!",Function="Translate",US="I am a shy statue. I will never talk to you."}}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="triggering_clonk"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Du hast gerade etwas zu mir gesagt.",Function="Translate",US="You just said something to me."}}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Ieh!",Function="Translate",US="Eek!"}}}],Function="sequence"}, nil);
	var Dialogue002 = Idol001->SetDialogue("Statue",false);
	Dialogue002->SetUserDialogue({Actions=[{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Ich bin keine ernsthafte Statue. Ich werde dich stets anlügen.",Function="Translate",US="I am not a serious statue. I will always lie to you."}}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="triggering_object"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Okay, dann sag mir bitte, wie ich diesen Raum auf keinen Fall lösen kann.",Function="Translate",US="Tell me then, how do I fail this room in the most horrible way?"}}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Ich weiß genau, was du meinst.",Function="Translate",US="I know exactly what you mean."}}}],Function="sequence"}, nil);
	var Dialogue003 = Idol003->SetDialogue("Statue",false);
	Dialogue003->SetUserDialogue({Actions=[{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Ich bin eine ernsthafte Statue. Ich werde dir immer die Wahrheit sagen.",Function="Translate",US="I am a serious statue. I will always tell you the truth."}}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="triggering_clonk"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Wie löse ich diesen Raum?",Function="Translate",US="How do I solve this room?"}}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Lass mich ehrlich zu dir sein. Das weiß ich nicht!",Function="Translate",US="I'll be honest with you. I don't know."}}}],Function="sequence"}, nil);
	var Dialogue004 = Idol004->SetDialogue("Statue",false);
	Dialogue004->SetUserDialogue({Actions=[{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Siehst du diese tolle Axt?",Function="Translate",US="See my nice axe?"}}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="triggering_clonk"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Ja. Die ist wirklich schön.",Function="Translate",US="Yes. It's really nice."}}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Ich hoffe nur, dass sie kein Feuer fängt.",Function="Translate",US="I just hope it doesn't catch fire."}}}],Function="sequence"}, nil);

	var PlayerStart001 = CreateObject(PlayerStart, 270, 220);
	PlayerStart001->SetPosition(270, 220);
	PlayerStart001->SetStartingMaterial([Shovel,Shovel,Shovel,Shovel,Shovel]);
	PlayerStart001->SetClonkMaxEnergy(5);
	PlayerStart001->SetViewLock(false);

	var Bat001 = CreateObjectAbove(Bat, 407, 415);
	Bat001->SetComDir(COMD_None);
	Bat001->DoEnergy(-15);
	Bat001->Unstick(7);
	var Bat002 = CreateObjectAbove(Bat, 432, 407);
	Bat002->SetComDir(COMD_None);
	Bat002->SetXDir(6);
	Bat002->Unstick(7);
	var Bat003 = CreateObjectAbove(Bat, 480, 455);
	Bat003->Kill(Bat003, true);
	Bat003->SetComDir(COMD_None);
	Bat003->SetCon(54);
	Bat003->DoEnergy(-20);
	var Bat004 = CreateObjectAbove(Bat, 403, 415);
	Bat004->SetComDir(COMD_None);
	Bat004->DoEnergy(-15);
	Bat004->Unstick(7);

	var Mosquito001 = CreateObjectAbove(Mosquito, 487, 416);
	Mosquito001->SetDir(DIR_Right);
	Mosquito001->SetComDir(COMD_UpRight);
	Mosquito001->Unstick(7);
	var Mosquito002 = CreateObjectAbove(Mosquito, 467, 431);
	Mosquito002->SetComDir(COMD_Up);
	Mosquito002->Unstick(7);
	var Mosquito003 = CreateObjectAbove(Mosquito, 485, 409);
	Mosquito003->SetComDir(COMD_Down);
	Mosquito003->Unstick(7);
	var Mosquito004 = CreateObjectAbove(Mosquito, 250, 415);
	Mosquito004->SetDir(DIR_Right);
	Mosquito004->SetComDir(COMD_None);
	Mosquito004->Unstick(7);
	var Mosquito005 = CreateObjectAbove(Mosquito, 365, 428);
	Mosquito005->SetComDir(COMD_Up);
	Mosquito005->Unstick(7);

	var Cloth001 = InventorsLab001->CreateContents(Cloth);
	Cloth001->SetPosition(290, 335);
	var Cloth002 = InventorsLab001->CreateContents(Cloth);
	Cloth002->SetPosition(290, 335);
	var Cloth003 = InventorsLab001->CreateContents(Cloth);
	Cloth003->SetPosition(290, 335);

	var Key001 = CreateObject(Key, 484, 454);
	Key001->SetR(-38);
	Key001->SetPosition(484, 454);
	Key001->Unstick(7);
	var Key002 = CreateObject(Key, 487, 455);
	Key002->SetR(-39);
	Key002->SetPosition(487, 455);
	var Key003 = CreateObject(Key, 481, 455);
	Key003->SetR(-42);
	Key003->SetPosition(481, 455);
	var Key004 = CreateObject(Key, 490, 455);
	Key004->SetR(-41);
	Key004->SetPosition(490, 455);
	var Key005 = CreateObject(Key, 487, 455);
	Key005->SetR(-39);
	Key005->SetPosition(487, 455);
	var Key006 = CreateObject(Key, 488, 454);
	Key006->SetR(-53);
	Key006->SetPosition(488, 454);
	var Key007 = CreateObject(Key, 488, 455);
	Key007->SetR(-39);
	Key007->SetPosition(488, 455);
	var Key008 = CreateObject(Key, 484, 455);
	Key008->SetR(-41);
	Key008->SetPosition(484, 455);
	Key008->Unstick(7);
	var Key009 = CreateObject(Key, 485, 455);
	Key009->SetR(-41);
	Key009->SetPosition(485, 455);
	var Key010 = CreateObject(Key, 490, 455);
	Key010->SetR(-41);
	Key010->SetPosition(490, 455);
	var Key011 = CreateObject(Key, 488, 454);
	Key011->SetR(-52);
	Key011->SetPosition(488, 454);
	var Key012 = CreateObject(Key, 484, 455);
	Key012->SetR(-39);
	Key012->SetPosition(484, 455);
	Key012->Unstick(7);
	var Key013 = CreateObject(Key, 480, 454);
	Key013->SetR(-41);
	Key013->SetPosition(480, 454);
	var Key014 = CreateObject(Key, 483, 450);
	Key014->SetR(-142);
	Key014->SetPosition(483, 450);
	var Key015 = CreateObject(Key, 490, 455);
	Key015->SetR(-41);
	Key015->SetPosition(490, 455);
	var Key016 = CreateObject(Key, 483, 455);
	Key016->SetR(-41);
	Key016->SetPosition(483, 455);
	Key016->Unstick(7);

	var DivingHelmet001 = CreateObject(DivingHelmet, 491, 451);
	DivingHelmet001->SetPosition(491, 451);

	var Axe001 = InventorsLab001->CreateContents(Axe);
	Axe001->SetPosition(290, 335);

	var WindBag001 = CreateObject(WindBag, 601, 227);
	WindBag001->SetR(-30);
	WindBag001->SetPosition(601, 227);
	var WindBag002 = CreateObject(WindBag, 577, 227);
	WindBag002->SetR(-29);
	WindBag002->SetPosition(577, 227);

	CreateObjectAbove(Seaweed, 496, 394);
	CreateObjectAbove(Seaweed, 510, 391);
	CreateObjectAbove(Seaweed, 539, 383);
	CreateObjectAbove(Seaweed, 568, 391);
	CreateObjectAbove(Seaweed, 593, 384);
	return true;
}
