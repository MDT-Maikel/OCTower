/* Automatically created objects file */

func InitializeObjects()
{
	var Torch001 = CreateObjectAbove(Torch, 539, 425);
	Torch001->AttachToWall(false);
	Torch001->SetMeshMaterial("Torch", 0);
	Torch001->SetState(2);

	CreateObjectAbove(Vine, 272, 300);
	var LargeCaveMushroom001 = CreateObjectAbove(LargeCaveMushroom, 572, 298);
	LargeCaveMushroom001->SetClrModulation(0xffd4e1dc);
	var LargeCaveMushroom002 = CreateObjectAbove(LargeCaveMushroom, 382, 319);
	LargeCaveMushroom002->SetClrModulation(0xffccced3);
	var LargeCaveMushroom003 = CreateObjectAbove(LargeCaveMushroom, 535, 312);
	LargeCaveMushroom003->SetClrModulation(0xffecd3e8);
	var LargeCaveMushroom004 = CreateObjectAbove(LargeCaveMushroom, 332, 304);
	LargeCaveMushroom004->SetCon(87);
	LargeCaveMushroom004->SetClrModulation(0xffede2e0);

	var Diamond_Socket001 = CreateObject(Diamond_Socket, 326, 418);
	Diamond_Socket001->SetPosition(326, 418);
	var Diamond_Socket002 = CreateObject(Diamond_Socket, 368, 453);
	Diamond_Socket002->SetPosition(368, 453);
	var Diamond_Socket003 = CreateObject(Diamond_Socket, 340, 435);
	Diamond_Socket003->SetPosition(340, 435);
	var Diamond_Socket004 = CreateObject(Diamond_Socket, 326, 405);
	Diamond_Socket004->SetPosition(326, 405);
	var Diamond_Socket005 = CreateObject(Diamond_Socket, 357, 417);
	Diamond_Socket005->SetPosition(357, 417);

	var LargeCaveMushroom005 = CreateObjectAbove(LargeCaveMushroom, 380, 320);
	LargeCaveMushroom005->SetClrModulation(0xfff8f6f4);
	var LargeCaveMushroom006 = CreateObjectAbove(LargeCaveMushroom, 325, 304);
	LargeCaveMushroom006->SetCon(87);
	LargeCaveMushroom006->SetClrModulation(0xfff8f2f3);

	var Sequence001 = CreateObject(Sequence, 498, 133);
	Sequence001->SetName("ResetNPC");
	Sequence001->SetPosition(498, 133);
	Sequence001->SetAction({Function="set_variable",VariableName={Function="string_constant",Value="paid"}}, nil);

	var LargeCaveMushroom007 = CreateObjectAbove(LargeCaveMushroom, 390, 319);
	LargeCaveMushroom007->SetClrModulation(0xffdfd9da);
	var LargeCaveMushroom008 = CreateObject(LargeCaveMushroom, 597, 528);
	LargeCaveMushroom008->SetCon(3);
	LargeCaveMushroom008->SetClrModulation(0xfff0e7e3);
	LargeCaveMushroom008->SetPosition(597, 528);
	var LargeCaveMushroom009 = CreateObjectAbove(LargeCaveMushroom, 521, 311);
	LargeCaveMushroom009->SetCon(45);
	LargeCaveMushroom009->SetClrModulation(0xffe3daef);
	var Basement001 = CreateObject(Basement, 424, 316);
	Basement001->SetPosition(424, 316);
	var Basement002 = CreateObject(Basement, 459, 316);
	Basement002->SetPosition(459, 316);
	var Basement003 = CreateObject(Basement, 500, 316);
	Basement003->SetPosition(500, 316);

	var RoomEntrance001 = CreateObjectAbove(RoomEntrance, 111, 455);
	RoomEntrance001->SetColor(0xff32c832);

	var RoomExit001 = CreateObjectAbove(RoomExit, 43, 48);
	RoomExit001->SetColor(0xffc83232);

	var StoneDoor001 = CreateObject(StoneDoor, 301, 212);
	StoneDoor001->SetComDir(COMD_Down);
	StoneDoor001->SetPosition(301, 212);
	StoneDoor001->SetPlrViewOnSignalChange(true);
	var StoneDoor002 = CreateObject(StoneDoor, 332, 212);
	StoneDoor002->SetComDir(COMD_Down);
	StoneDoor002->SetPosition(332, 212);
	StoneDoor002->SetPlrViewOnSignalChange(true);

	var SpinWheel001 = CreateObjectAbove(SpinWheel, 317, 231);
	SpinWheel001->SetActions({Actions=[{Door={Function="object_constant",Value=StoneDoor002},Function="open_door"},{Door={Function="object_constant",Value=StoneDoor001},Function="close_door"}],Function="sequence"}, {AfterMessage="stop",Function="message",Options=[],Speaker={Function="triggering_clonk"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value="Klemmt :("}});
	var SpinWheel002 = CreateObjectAbove(SpinWheel, 284, 231);
	SpinWheel002->SetSwitchTarget(StoneDoor001);
	var SpinWheel003 = CreateObjectAbove(SpinWheel, 350, 232);
	SpinWheel003->SetSwitchTarget(StoneDoor002);

	CreateObjectAbove(Pump, 498, 311);

	CreateObjectAbove(Foundry, 586, 151);

	var Chest001 = CreateObjectAbove(Chest, 552, 151);

	var SteamEngine001 = CreateObject(SteamEngine, 437, 288);
	SteamEngine001->SetPosition(437, 288);
	var PlayerStart001 = CreateObject(PlayerStart, 108, 437);
	PlayerStart001->SetPosition(108, 437);
	PlayerStart001->SetStartingMaterial([Lantern]);
	PlayerStart001->SetClonkMaxContentsCount(1);
	PlayerStart001->SetClonkMaxEnergy(10);
	PlayerStart001->SetViewLock(false);

	var Clonk001 = CreateObjectAbove(Clonk, 536, 151);
	Clonk001->SetColor(0xefef40);
	Clonk001->SetMeshMaterial("Clonk_Carpenter", 0);
	Clonk001->SetName("Davey");
	Clonk001->MakeInvincible(false);
	Clonk001->Unstick(7);
	Clonk001->SetDir(DIR_Left);
	Clonk001->SetAlternativeSkin("Carpenter");

	var Wipf001 = CreateObjectAbove(Wipf, 88, 455);
	Wipf001->SetDir(DIR_Right);
	Wipf001->SetComDir(COMD_Right);
	Wipf001->SetXDir(20);
	Wipf001->Unstick(7);

	var WindBag001 = Clonk001->CreateContents(WindBag);
	WindBag001->SetPosition(536, 142);

	var Dialogue001 = Clonk001->SetDialogue("Editor",true);
	Dialogue001->SetUserDialogue({Actions=[{Condition={Function="Boolean_variable",VariableName={Function="string_constant",Value="paid"}},Function="if",TrueEvaluator={Function="goto",Index={Function="int_constant",Value=10}}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value="Oh no, I am so poor. All I have is a massive pipe!"}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="triggering_clonk"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value="Cool, I also want a pipe."}},{Condition={Function="object_exists",Object={Container={Function="triggering_clonk"},Function="find_object_in_container",ID={Function="def_constant",Value=Diamond}}},Function="if",TrueEvaluator={Function="goto",Index={Function="int_constant",Value=15}}},{Condition={Function="object_exists",Object={Container={Function="triggering_clonk"},Function="find_object_in_container",ID={Function="def_constant",Value=GoldBar}}},Function="if",TrueEvaluator={Function="goto",Index={Function="int_constant",Value=15}}},{Condition={Function="object_exists",Object={Container={Function="triggering_clonk"},Function="find_object_in_container"}},FalseEvaluator={Function="goto",Index={Function="int_constant",Value=12}},Function="if"},{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_concat",Substrings=[{Function="string_constant",Value="You have "},{Context={Container={Function="triggering_clonk"},Function="find_object_in_container"},Function="String_script",Script={Function="string_constant",Value="GetName()"}},{Function="string_constant",Value=". But that is too cheap for me."}]}},{Function="stop_sequence"},nil,nil,{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value="I am so happy!"}},{Function="stop_sequence"},{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value="But you don't carry anything."}},{Function="stop_sequence"},nil,{Container={Function="npc"},Function="enter_object",Object={Container={Function="triggering_clonk"},Function="find_object_in_container"}},{Container={Function="triggering_clonk"},Function="create_object",ID={Function="def_constant",Value=Pipe},SpeedX={Function="int_constant",Value=0},SpeedY={Function="int_constant",Value=0}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value="Thanks! Here you go, take my pipe."}},{Function="set_variable",Value={Function="bool_constant",Value=true},VariableName={Function="string_constant",Value="paid"}},{Function="stop_sequence"}],Function="sequence"}, nil);

	var Rock001 = CreateObject(Rock, 538, 353);
	Rock001->SetR(74);
	Rock001->SetPosition(538, 353);

	var Nugget001 = Chest001->CreateContents(Nugget);
	Nugget001->SetPosition(552, 140);
	var Nugget002 = Chest001->CreateContents(Nugget);
	Nugget002->SetPosition(552, 140);

	var Diamond001;
	var Diamond002;
	var Diamond003;
	var Diamond004;
	var Diamond005;
	var Diamond006;
	var Diamond007;
	var Diamond008;
	var Diamond009;
	var Diamond010;
	var Diamond011;
	var Diamond012;
	var Diamond013;
	var Diamond014;
	var Diamond015;
	var Diamond016;
	var Diamond017;
	var Diamond018;
	var Diamond019;
	var Diamond020;
	var Diamond021;
	var Diamond022;
	var Diamond023;
	var Diamond024;
	var Diamond025;
	var Diamond026;
	var Diamond027;
	var Diamond028;
	var Diamond029;
	var Diamond030;
	var Diamond031;
	var Diamond032;
	var Diamond033;
	var Diamond034;
	var Diamond035;
	var Diamond036;
	var Diamond037;
	var Diamond038;
	var Diamond039;
	var Diamond040;
	var Diamond041;
	var Diamond042;
	var Diamond043;
	var Diamond044;
	var Diamond045;
	var WindBag002 = Wipf001->CreateContents(WindBag);
	WindBag002->SetPosition(88, 450);

	var Crate001 = CreateObjectAbove(Crate, 253, 365);
	Crate001->SetName("ZAUBERKISTE");
	Crate001.Plane = 550;
	Crate001->MakeInvincible(false);

	var TeleGlove001 = Crate001->CreateContents(TeleGlove);
	TeleGlove001->SetPosition(253, 360);

	var Axe001 = CreateObject(Axe, 255, 453);
	Axe001->SetR(-65);
	Axe001->MakeInvincible(false);
	Axe001->SetPosition(255, 453);

	var Shovel001 = CreateObject(Shovel, 27, 369);
	Shovel001->SetR(135);
	Shovel001->SetPosition(27, 369);

	var DivingHelmet001 = CreateObject(DivingHelmet, 422, 432);
	DivingHelmet001->SetR(-50);
	DivingHelmet001->SetPosition(422, 432);

	var Pickaxe001 = CreateObject(Pickaxe, 538, 340);
	Pickaxe001->SetPosition(538, 340);

	var DynamiteBox001 = CreateObject(DynamiteBox, 516, 439);
	DynamiteBox001->SetPosition(516, 439);
	DynamiteBox001->SetDynamiteCount(45);
	var DynamiteBox002 = CreateObject(DynamiteBox, 564, 445);
	DynamiteBox002->SetPosition(564, 445);
	DynamiteBox002->SetDynamiteCount(45);
	var DynamiteBox003 = CreateObject(DynamiteBox, 570, 438);
	DynamiteBox003->SetR(-12);
	DynamiteBox003->SetPosition(570, 438);
	DynamiteBox003->SetDynamiteCount(45);
	var Pipe001 = CreateObjectAbove(Pipe, 589, 47);
	Pipe001->Unstick(7);
	Pipe001->SetNeutralPipe();

	var GrappleBow001 = CreateObjectAbove(GrappleBow, 266, 360);
	GrappleBow001->MakeInvincible(false);

	var Ropeladder001 = CreateObject(Ropeladder, 247, 230);
	Ropeladder001->SetR(68);
	Ropeladder001->SetPosition(247, 230);
	Ropeladder001->Unroll(1);
	var Trunk001 = CreateObject(Trunk, 35, 377);
	Trunk001->SetCon(136);
	Trunk001->SetR(141);
	Trunk001.Plane = 550;
	Trunk001->SetPosition(35, 377);
	Trunk001->CustomInitialize("this.MeshTransformation= [946, 0, -326, 0, 0, 1000, 0, 0, 326, 0, 946, 0]");
	return true;
}
