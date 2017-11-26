/* Automatically created objects file */

func InitializeObjects()
{
	var Branch001 = CreateObject(Branch, 469, 304);
	Branch001->SetCon(174);
	Branch001->SetR(-157);
	Branch001->SetPosition(469, 304);
	var Branch002 = CreateObject(Branch, 171, 266);
	Branch002->SetCon(135);
	Branch002->SetR(5);
	Branch002->SetPosition(171, 266);
	var Branch003 = CreateObject(Branch, 493, 149);
	Branch003->SetCon(174);
	Branch003->SetR(-157);
	Branch003->SetPosition(493, 149);
	var Branch004 = CreateObject(Branch, 194, 60);
	Branch004->SetCon(174);
	Branch004->SetR(-157);
	Branch004->SetPosition(194, 60);

	CreateObjectAbove(Vine, 308, 198);
	var Sequence001 = CreateObject(Sequence, 222, 147);
	Sequence001->SetCheckInterval(2);
	Sequence001->SetPosition(222, 147);
	Sequence001->SetTrigger({Interval=2,Trigger="interval"}, 0);
	Sequence001->SetCondition({Function="bool_constant",Value=true});
	Sequence001->SetAction({Amount={Function="int_constant",Value=1},AngleDeviation={Function="int_constant",Value=180},Function="cast_objects",ID={Function="def_constant",Value=BoilingLava_Bubble},Position={Function="position_constant",Value=[220,198]},Speed={Function="int_constant",Value=10}}, nil);
	var Sequence002 = CreateObject(Sequence, 427, 147);
	Sequence002->SetCheckInterval(2);
	Sequence002->SetPosition(427, 147);
	Sequence002->SetTrigger({Interval=2,Trigger="interval"}, 0);
	Sequence002->SetCondition({Function="bool_constant",Value=true});
	Sequence002->SetAction({Amount={Function="int_constant",Value=1},AngleDeviation={Function="int_constant",Value=180},Function="cast_objects",ID={Function="def_constant",Value=BoilingLava_Bubble},Position={Function="position_constant",Value=[428,197]},Speed={Function="int_constant",Value=10}}, nil);
	var Sequence003 = CreateObject(Sequence, 59, 10);
	Sequence003->SetCheckInterval(72);
	Sequence003->SetPosition(59, 10);
	Sequence003->SetTrigger({Interval=72,Trigger="interval"}, 0);
	Sequence003->SetCondition({Function="bool_constant",Value=true});
	Sequence003->SetAction({Function="create_object",ID={Function="def_constant",Value=Firestone},Position={Function="position_constant",Value=[31,7]},Rotation={Function="int_constant",Value=0},SpeedR={Function="int_constant",Value=0},SpeedX={Function="int_constant",Value=0},SpeedY={Function="int_constant",Value=0}}, nil);
	var Sequence004 = CreateObject(Sequence, 77, 10);
	Sequence004->SetCheckInterval(72);
	Sequence004->SetPosition(77, 10);
	Sequence004->SetTrigger({Interval=72,Trigger="interval"}, 36);
	Sequence004->SetCondition({Function="bool_constant",Value=true});
	Sequence004->SetAction({Function="create_object",ID={Function="def_constant",Value=Firestone},Position={Function="position_constant",Value=[43,9]},Rotation={Function="int_constant",Value=0},SpeedR={Function="int_constant",Value=0},SpeedX={Function="int_constant",Value=0},SpeedY={Function="int_constant",Value=0}}, nil);

	CreateObjectAbove(EnvPack_Guidepost2, 328, 66);

	var Sequence005 = CreateObject(Sequence, 11, 318);
	Sequence005->SetCheckInterval(8);
	Sequence005->SetPosition(11, 318);
	Sequence005->SetTrigger({Interval=8,Trigger="interval"}, 0);
	Sequence005->SetCondition({Function="bool_constant",Value=true});
	Sequence005->SetAction({Amount={Function="int_constant",Value=1},AngleDeviation={Function="int_constant",Value=90},Function="cast_objects",ID={Function="def_constant",Value=BoilingLava_Bubble},Position={Area=[29,318,43,10],Function="random_pos_rect_abs"},Speed={Function="int_constant",Value=4}}, nil);

	var LargeCaveMushroom001 = CreateObject(LargeCaveMushroom, 399, 297);
	LargeCaveMushroom001->SetCon(92);
	LargeCaveMushroom001->SetR(-166);
	LargeCaveMushroom001->SetClrModulation(0xffdbd6e7);
	LargeCaveMushroom001->SetSeedChance(0);
	LargeCaveMushroom001->SetPosition(399, 297);
	var LargeCaveMushroom002 = CreateObject(LargeCaveMushroom, 218, 380);
	LargeCaveMushroom002->SetCon(97);
	LargeCaveMushroom002->SetR(-112);
	LargeCaveMushroom002->SetClrModulation(0xffd4f0ed);
	LargeCaveMushroom002->SetSeedChance(0);
	LargeCaveMushroom002->SetPosition(218, 380);

	CreateObjectAbove(Fern, 454, 374);
	CreateObjectAbove(Fern, 236, 77);
	var Fern001 = CreateObject(Fern, 272, 74);
	Fern001->SetPosition(272, 74);

	var LargeCaveMushroom003 = CreateObject(LargeCaveMushroom, 264, 58);
	LargeCaveMushroom003->SetCon(68);
	LargeCaveMushroom003->SetR(-1);
	LargeCaveMushroom003->SetClrModulation(0xffdaf2d6);
	LargeCaveMushroom003->SetSeedChance(0);
	LargeCaveMushroom003->SetPosition(264, 58);
	var LargeCaveMushroom004 = CreateObject(LargeCaveMushroom, 358, 98);
	LargeCaveMushroom004->SetCon(77);
	LargeCaveMushroom004->SetR(-9);
	LargeCaveMushroom004->SetClrModulation(0xffe3f5ea);
	LargeCaveMushroom004->SetSeedOffset(0);
	LargeCaveMushroom004->SetPosition(358, 98);

	CreateObjectAbove(Fern, 367, 118);
	var Branch005 = CreateObject(Branch, 82, 123);
	Branch005->SetCon(140);
	Branch005->SetR(169);
	Branch005->SetPosition(82, 123);

	var RoomEntrance001 = CreateObjectAbove(RoomEntrance, 404, 64);
	RoomEntrance001->SetColor(0xff32c832);

	var RoomExit001 = CreateObjectAbove(RoomExit, 60, 400);
	RoomExit001->SetColor(0xffc83232);

	var StoneDoor001 = CreateObject(StoneDoor, 133, 61);
	StoneDoor001->SetComDir(COMD_Down);
	StoneDoor001->MakeInvincible(false);
	StoneDoor001->SetPosition(133, 61);

	var MovingBrick001 = CreateObject(MovingBrick, 123, 212);
	MovingBrick001->SetComDir(COMD_Left);
	MovingBrick001->MoveHorizontal(104, 272);
	MovingBrick001->SetPosition(123, 212);
	MovingBrick001->SetMoveSpeed(120);
	var MovingBrick002 = CreateObject(MovingBrick, 410, 212);
	MovingBrick002->SetComDir(COMD_Left);
	MovingBrick002->MoveHorizontal(361, 560);
	MovingBrick002->SetPosition(410, 212);
	MovingBrick002->SetMoveSpeed(120);
	var Switch001 = CreateObjectAbove(Switch, 286, 376);
	Switch001->SetSwitchTarget(StoneDoor001);
	Switch001->SetSwitchDir(1);

	var StrawMan001 = CreateObject(StrawMan, 44, 43);
	StrawMan001->SetR(-26);
	StrawMan001->SetPosition(44, 43);

	var Lorry001 = CreateObject(Lorry, 36, 389);
	Lorry001->SetR(41);
	Lorry001->SetPosition(36, 389);
	var PlayerStart001 = CreateObject(PlayerStart, 425, 52);
	PlayerStart001->SetPosition(425, 52);
	PlayerStart001->SetStartingKnowledge("allexcept", [Basement]);
	PlayerStart001->SetStartingMaterial([Shovel,Dynamite,Hammer]);
	PlayerStart001->SetViewLock(false);

	var LavaCore001 = CreateObjectAbove(LavaCore, 374, 395);
	LavaCore001->SetComDir(COMD_None);
	LavaCore001->SetCon(50);
	LavaCore001->SetXDir(1);
	LavaCore001->SetReproductionRate(0);
	LavaCore001->Unstick(7);
	var LavaCore002 = CreateObjectAbove(LavaCore, 385, 238);
	LavaCore002->SetComDir(COMD_None);
	LavaCore002->SetCon(47);
	LavaCore002->SetReproductionRate(0);
	LavaCore002->Unstick(7);
	var LavaCore003 = CreateObjectAbove(LavaCore, 132, 419);
	LavaCore003->SetComDir(COMD_None);
	LavaCore003->SetCon(50);
	LavaCore003->SetXDir(1);
	LavaCore003->SetReproductionRate(0);
	LavaCore003->Unstick(7);
	var LavaCore004 = CreateObjectAbove(LavaCore, 208, 444);
	LavaCore004->SetComDir(COMD_None);
	LavaCore004->SetCon(50);
	LavaCore004->SetXDir(1);
	LavaCore004->SetReproductionRate(0);
	LavaCore004->Unstick(7);
	var LavaCore005 = CreateObjectAbove(LavaCore, 534, 421);
	LavaCore005->SetComDir(COMD_None);
	LavaCore005->SetCon(49);
	LavaCore005->SetReproductionRate(0);
	LavaCore005->Unstick(7);
	var LavaCore006 = CreateObjectAbove(LavaCore, 469, 450);
	LavaCore006->SetComDir(COMD_None);
	LavaCore006->SetCon(49);
	LavaCore006->SetXDir(1);
	LavaCore006->SetReproductionRate(0);
	LavaCore006->Unstick(7);
	var Wood001 = Lorry001->CreateContents(Wood);
	Wood001->SetPosition(36, 389);
	var Wood002 = Lorry001->CreateContents(Wood);
	Wood002->SetPosition(36, 389);

	var Stalactite001 = CreateObject(Stalactite, 201, 252);
	Stalactite001->SetPosition(201, 252);

	var AncientTablet001 = CreateObjectAbove(AncientTablet, 599, 62);
	AncientTablet001->Unstick(7);

	var GrappleBow001 = CreateObject(GrappleBow, 331, 287);
	GrappleBow001->SetPosition(331, 287);

	var TeleGlove001 = CreateObject(TeleGlove, 86, 232);
	TeleGlove001->SetPosition(86, 232);

	CreateObjectAbove(Bread, 319, 284);

	CreateObjectAbove(Mushroom, 461, 376);
	var Mushroom001 = CreateObject(Mushroom, 255, 73);
	Mushroom001->SetPosition(255, 73);
	CreateObjectAbove(Mushroom, 242, 74);

	var Axe001 = Lorry001->CreateContents(Axe);
	Axe001->SetPosition(28, 392);

	var WindBag001 = CreateObject(WindBag, 591, 100);
	WindBag001->SetR(-45);
	WindBag001->SetPosition(591, 100);

	var Trunk001 = CreateObject(Trunk, 33, -24);
	Trunk001->SetCon(206);
	Trunk001->SetR(-4);
	Trunk001.Plane = 550;
	Trunk001->MakeInvincible(false);
	Trunk001->SetPosition(33, -24);
	return true;
}
