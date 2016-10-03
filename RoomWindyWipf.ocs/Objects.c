/* Automatically created objects file */

func InitializeObjects()
{
	var Torch001 = CreateObjectAbove(Torch, 539, 425);
	Torch001->AttachToWall(false);

	var Vine001 = CreateObjectAbove(Vine, 272, 300);
	Vine001->CreateSegments();
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
	Diamond_Socket001->SetR(-77);
	Diamond_Socket001.Visibility = VIS_None;
	var Diamond_Socket002 = CreateObject(Diamond_Socket, 368, 453);
	Diamond_Socket002->SetR(-158);
	Diamond_Socket002.Visibility = VIS_None;
	var Diamond_Socket003 = CreateObject(Diamond_Socket, 340, 435);
	Diamond_Socket003->SetR(-55);
	Diamond_Socket003.Visibility = VIS_None;
	var Diamond_Socket004 = CreateObject(Diamond_Socket, 326, 405);
	Diamond_Socket004->SetR(-31);
	Diamond_Socket004.Visibility = VIS_None;
	var Diamond_Socket005 = CreateObject(Diamond_Socket, 357, 417);
	Diamond_Socket005->SetR(77);
	Diamond_Socket005.Visibility = VIS_None;

	var LargeCaveMushroom005 = CreateObjectAbove(LargeCaveMushroom, 380, 320);
	LargeCaveMushroom005->SetClrModulation(0xfff8f6f4);
	var LargeCaveMushroom006 = CreateObjectAbove(LargeCaveMushroom, 325, 304);
	LargeCaveMushroom006->SetCon(87);
	LargeCaveMushroom006->SetClrModulation(0xfff8f2f3);

	var Sequence001 = CreateObject(Sequence, 498, 133);
	Sequence001->SetName("ResetNPC");
	Sequence001->SetAction({Function="set_variable",VariableName={Function="string_constant",Value="paid"}}, nil);

	var LargeCaveMushroom007 = CreateObjectAbove(LargeCaveMushroom, 390, 319);
	LargeCaveMushroom007->SetClrModulation(0xffdfd9da);
	var LargeCaveMushroom008 = CreateObject(LargeCaveMushroom, 597, 498);
	LargeCaveMushroom008->SetCon(3);
	LargeCaveMushroom008->SetClrModulation(0xfff0e7e3);

	CreateObject(Rule_Restart);
	CreateObject(Rule_Restart);
	CreateObject(Rule_Restart);
	CreateObject(Rule_Restart);

	var LargeCaveMushroom009 = CreateObjectAbove(LargeCaveMushroom, 521, 311);
	LargeCaveMushroom009->SetCon(45);
	LargeCaveMushroom009->SetClrModulation(0xffe3daef);
	var Basement001 = CreateObject(Basement, 500, 316);
	var Basement002 = CreateObject(Basement, 459, 316);
	var Basement003 = CreateObject(Basement, 424, 316);

	CreateObjectAbove(RoomEntrance, 111, 455);

	CreateObjectAbove(RoomExit, 43, 48);

	var StoneDoor001 = CreateObject(StoneDoor, 301, 212);
	StoneDoor001->SetComDir(COMD_Down);
	var StoneDoor002 = CreateObject(StoneDoor, 332, 212);
	StoneDoor002->SetComDir(COMD_Down);

	var SpinWheel001 = CreateObjectAbove(SpinWheel, 317, 231);
	SpinWheel001->SetActions({Actions=[{Door={Function="object_constant",Value=StoneDoor002},Function="open_door"},{Door={Function="object_constant",Value=StoneDoor001},Function="close_door"}],Function="sequence"}, {AfterMessage="stop",Function="message",Options=[],Speaker={Function="triggering_clonk"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value="Klemmt :("}});
	var SpinWheel002 = CreateObjectAbove(SpinWheel, 284, 231);
	SpinWheel002->SetStoneDoor(StoneDoor001);
	var SpinWheel003 = CreateObjectAbove(SpinWheel, 350, 232);
	SpinWheel003->SetStoneDoor(StoneDoor002);

	CreateObjectAbove(Pump, 498, 311);

	CreateObjectAbove(Foundry, 586, 151);

	var Chest001 = CreateObjectAbove(Chest, 552, 151);

	var SteamEngine001 = CreateObject(SteamEngine, 437, 288);
	var PlayerStart001 = CreateObject(PlayerStart, 108, 437);
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
	var Clonk002;

	var Wipf001 = CreateObjectAbove(Wipf, 88, 455);
	Wipf001->SetDir(DIR_Right);
	Wipf001->SetComDir(COMD_Right);
	Wipf001->SetXDir(20);
	Wipf001->Unstick(7);

	var WindBag001 = Clonk001->CreateContents(WindBag);

	var Dialogue001 = Clonk001->SetDialogue("Editor",true);
	Dialogue001->SetUserDialogue({Actions=[{Condition={Function="Boolean_variable",VariableName={Function="string_constant",Value="paid"}},Function="if",TrueEvaluator={Function="goto",Index={Function="int_constant",Value=10}}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value="$DlgDaveyPoor$"}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="triggering_clonk"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value="$DlgDaveyPipe$"}},{Condition={Function="object_exists",Object={Container={Function="triggering_clonk"},Function="find_object_in_container",ID={Function="def_constant",Value=Diamond}}},Function="if",TrueEvaluator={Function="goto",Index={Function="int_constant",Value=15}}},{Condition={Function="object_exists",Object={Container={Function="triggering_clonk"},Function="find_object_in_container",ID={Function="def_constant",Value=GoldBar}}},Function="if",TrueEvaluator={Function="goto",Index={Function="int_constant",Value=15}}},{Condition={Function="object_exists",Object={Container={Function="triggering_clonk"},Function="find_object_in_container"}},FalseEvaluator={Function="goto",Index={Function="int_constant",Value=12}},Function="if"},{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_concat",Substrings=[{Function="string_constant",Value="$DlgDaveyHave$"},{Context={Container={Function="triggering_clonk"},Function="find_object_in_container"},Function="String_script",Script={Function="string_constant",Value="GetName()"}},{Function="string_constant",Value="$DlgDaveyCheap$"}]}},{Function="stop_sequence"},nil,nil,{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value="$DlgDaveyHappy$"}},{Function="stop_sequence"},{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value="$DlgDaveyNothing$"}},{Function="stop_sequence"},nil,{Container={Function="npc"},Function="enter_object",Object={Container={Function="triggering_clonk"},Function="find_object_in_container"}},{Container={Function="triggering_clonk"},Function="create_object",ID={Function="def_constant",Value=Pipe},SpeedX={Function="int_constant",Value=0},SpeedY={Function="int_constant",Value=0}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value="$DlgDaveyThanks$"}},{Function="set_variable",Value={Function="bool_constant",Value=true},VariableName={Function="string_constant",Value="paid"}},{Function="stop_sequence"}],Function="sequence"}, nil);

	var Rock001 = CreateObject(Rock, 538, 353);
	Rock001->SetR(74);

	Chest001->CreateContents(Nugget, 2);

	var Diamond001 = Diamond_Socket001->CreateContents(Diamond);
	Diamond001->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond001->SetClrModulation(0xff0fe4cc);
	var Diamond002 = Diamond_Socket002->CreateContents(Diamond);
	Diamond002->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond002->SetClrModulation(0xff61ecf8);
	var Diamond003 = Diamond_Socket003->CreateContents(Diamond);
	Diamond003->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond003->SetClrModulation(0xff27ac3e);
	var Diamond004 = Diamond_Socket004->CreateContents(Diamond);
	Diamond004->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond004->SetClrModulation(0xffe001b9);
	var Diamond005 = Diamond_Socket005->CreateContents(Diamond);
	Diamond005->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond005->SetClrModulation(0xffdf84b7);
	var Diamond006 = Diamond_Socket001->CreateContents(Diamond);
	Diamond006->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond006->SetClrModulation(0xfff46ab3);
	var Diamond007 = Diamond_Socket002->CreateContents(Diamond);
	Diamond007->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond007->SetClrModulation(0xffa5df0c);
	var Diamond008 = Diamond_Socket003->CreateContents(Diamond);
	Diamond008->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond008->SetClrModulation(0xff3f8fc4);
	var Diamond009 = Diamond_Socket004->CreateContents(Diamond);
	Diamond009->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond009->SetClrModulation(0xfff0982e);
	var Diamond010 = Diamond_Socket005->CreateContents(Diamond);
	Diamond010->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond010->SetClrModulation(0xffa7d6d1);
	var Diamond011 = Diamond_Socket001->CreateContents(Diamond);
	Diamond011->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond011->SetClrModulation(0xff4b76f3);
	var Diamond012 = Diamond_Socket002->CreateContents(Diamond);
	Diamond012->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond012->SetClrModulation(0xffd24e11);
	var Diamond013 = Diamond_Socket003->CreateContents(Diamond);
	Diamond013->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond013->SetClrModulation(0xff7f2ef1);
	var Diamond014 = Diamond_Socket004->CreateContents(Diamond);
	Diamond014->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond014->SetClrModulation(0xffb1efcb);
	var Diamond015 = Diamond_Socket005->CreateContents(Diamond);
	Diamond015->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond015->SetClrModulation(0xff58ef5d);
	var Diamond016 = Diamond_Socket001->CreateContents(Diamond);
	Diamond016->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond016->SetClrModulation(0xffe41da0);
	var Diamond017 = Diamond_Socket002->CreateContents(Diamond);
	Diamond017->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond017->SetClrModulation(0xff6f817d);
	var Diamond018 = Diamond_Socket003->CreateContents(Diamond);
	Diamond018->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond018->SetClrModulation(0xff3ef4d8);
	var Diamond019 = Diamond_Socket004->CreateContents(Diamond);
	Diamond019->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond019->SetClrModulation(0xff125c70);
	var Diamond020 = Diamond_Socket005->CreateContents(Diamond);
	Diamond020->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond020->SetClrModulation(0xffa4b409);
	var Diamond021 = Diamond_Socket001->CreateContents(Diamond);
	Diamond021->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond021->SetClrModulation(0xff655fd4);
	var Diamond022 = Diamond_Socket002->CreateContents(Diamond);
	Diamond022->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond022->SetClrModulation(0xfff157f7);
	var Diamond023 = Diamond_Socket003->CreateContents(Diamond);
	Diamond023->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond023->SetClrModulation(0xff0e5e73);
	var Diamond024 = Diamond_Socket004->CreateContents(Diamond);
	Diamond024->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond024->SetClrModulation(0xfffd8467);
	var Diamond025 = Diamond_Socket005->CreateContents(Diamond);
	Diamond025->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond025->SetClrModulation(0xff7cbb14);
	var Diamond026 = Diamond_Socket001->CreateContents(Diamond);
	Diamond026->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond026->SetClrModulation(0xff998cc4);
	var Diamond027 = Diamond_Socket002->CreateContents(Diamond);
	Diamond027->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond027->SetClrModulation(0xffc9cddf);
	var Diamond028 = Diamond_Socket003->CreateContents(Diamond);
	Diamond028->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond028->SetClrModulation(0xff73553c);
	var Diamond029 = Diamond_Socket004->CreateContents(Diamond);
	Diamond029->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond029->SetClrModulation(0xff15c0cf);
	var Diamond030 = Diamond_Socket005->CreateContents(Diamond);
	Diamond030->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond030->SetClrModulation(0xffed977b);
	var Diamond031 = Diamond_Socket001->CreateContents(Diamond);
	Diamond031->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond031->SetClrModulation(0xff4fce61);
	var Diamond032 = Diamond_Socket002->CreateContents(Diamond);
	Diamond032->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond032->SetClrModulation(0xff14a612);
	var Diamond033 = Diamond_Socket003->CreateContents(Diamond);
	Diamond033->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond033->SetClrModulation(0xff4f0112);
	var Diamond034 = Diamond_Socket004->CreateContents(Diamond);
	Diamond034->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond034->SetClrModulation(0xfff96744);
	var Diamond035 = Diamond_Socket005->CreateContents(Diamond);
	Diamond035->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond035->SetClrModulation(0xfff791c0);
	var Diamond036 = Diamond_Socket001->CreateContents(Diamond);
	Diamond036->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond036->SetClrModulation(0xff2af578);
	var Diamond037 = Diamond_Socket002->CreateContents(Diamond);
	Diamond037->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond037->SetClrModulation(0xffe8bc40);
	var Diamond038 = Diamond_Socket003->CreateContents(Diamond);
	Diamond038->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond038->SetClrModulation(0xff316aba);
	var Diamond039 = Diamond_Socket004->CreateContents(Diamond);
	Diamond039->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond039->SetClrModulation(0xff43050a);
	var Diamond040 = Diamond_Socket005->CreateContents(Diamond);
	Diamond040->SetObjectBlitMode(GFX_BLIT_Mod2);
	Diamond040->SetClrModulation(0xfffb8c10);

	Wipf001->CreateContents(WindBag);

	var Crate001 = CreateObjectAbove(Crate, 253, 365);
	Crate001->SetName("ZAUBERKISTE");
	Crate001.Plane = 550;
	Crate001->MakeInvincible(false);

	Crate001->CreateContents(TeleGlove);

	var Axe001 = CreateObject(Axe, 254, 456);
	Axe001->SetR(-65);

	var Shovel001 = CreateObject(Shovel, 27, 369);
	Shovel001->SetR(135);

	var DivingHelmet001 = CreateObject(DivingHelmet, 422, 432);
	DivingHelmet001->SetR(-50);

	CreateObject(Pickaxe, 538, 340);

	var DynamiteBox002 = CreateObject(DynamiteBox, 516, 439);
	var DynamiteBox003 = CreateObject(DynamiteBox, 564, 445);
	var DynamiteBox001 = CreateObject(DynamiteBox, 570, 438);
	DynamiteBox001->SetR(-12);

	DynamiteBox002->CreateContents(Dynamite, 40);
	DynamiteBox003->CreateContents(Dynamite, 40);
	DynamiteBox001->CreateContents(Dynamite, 40);

	var Pipe001 = CreateObjectAbove(Pipe, 589, 47);
	Pipe001->Unstick(7);

	CreateObjectAbove(GrappleBow, 266, 360);

	var Ropeladder001 = CreateObject(Ropeladder, 247, 231);
	Ropeladder001->SetR(68);
	Ropeladder001->Unroll(1);

	var Trunk001 = CreateObject(Trunk, 30, 340);
	Trunk001->SetCon(136);
	Trunk001->SetR(141);
	Trunk001.Plane = 550;
	Trunk001->CustomInitialize("this.MeshTransformation= [946, 0, -326, 0, 0, 1000, 0, 0, 326, 0, 946, 0]");
	return true;
}
