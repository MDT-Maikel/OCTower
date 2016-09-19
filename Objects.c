/* Automatically created objects file */

func InitializeObjects()
{
	var Grass001 = CreateObject(Grass, 118, 358);
	var Grass002 = CreateObjectAbove(Grass, 127, 358);
	var Grass003 = CreateObjectAbove(Grass, 143, 358);
	var Grass004 = CreateObjectAbove(Grass, 149, 358);
	var Grass005 = CreateObjectAbove(Grass, 163, 358);
	var Grass006 = CreateObject(Grass, 158, 358);
	var Grass007 = CreateObjectAbove(Grass, 173, 358);
	var Grass008 = CreateObject(Grass, 179, 357);
	var Grass009 = CreateObjectAbove(Grass, 186, 357);
	var Grass010 = CreateObjectAbove(Grass, 193, 358);
	var Grass011 = CreateObjectAbove(Grass, 200, 358);
	var Grass012 = CreateObjectAbove(Grass, 207, 359);
	var Grass013 = CreateObjectAbove(Grass, 215, 358);
	var Grass014 = CreateObjectAbove(Grass, 224, 358);
	var Grass015 = CreateObjectAbove(Grass, 228, 358);
	var Grass016 = CreateObjectAbove(Grass, 248, 359);
	var Grass017 = CreateObjectAbove(Grass, 256, 358);
	var Grass018 = CreateObjectAbove(Grass, 260, 353);
	var Grass019 = CreateObject(Grass, 264, 350);
	var Grass020 = CreateObject(Grass, 268, 346);
	var Grass021 = CreateObject(Grass, 273, 343);
	var Grass022 = CreateObject(Grass, 280, 342);
	var Grass023 = CreateObjectAbove(Grass, 283, 338);
	var Grass024 = CreateObject(Grass, 288, 334);
	var Grass025 = CreateObjectAbove(Grass, 297, 335);
	var Grass026 = CreateObjectAbove(Grass, 302, 335);
	var Grass027 = CreateObjectAbove(Grass, 138, 357);
	var Grass028 = CreateObjectAbove(Grass, 248, 358);
	var Grass029 = CreateObjectAbove(Grass, 229, 358);
	var Grass030 = CreateObjectAbove(Grass, 208, 358);

	CreateObjectAbove(Deco_Tree_Deciduous4, 225, 361);

	CreateObjectAbove(Deco_Tree_Deciduous3, 141, 356);

	var Tree_Deciduous001 = CreateObjectAbove(Tree_Deciduous, 124, 363);
	Tree_Deciduous001->SetCon(102);

	CreateObjectAbove(Tree_Coniferous2, 251, 364);
	var Tree_Coniferous2001 = CreateObjectAbove(Tree_Coniferous2, 245, 364);
	Tree_Coniferous2001->SetCon(101);

	CreateObjectAbove(Tree_Coniferous4, 278, 344);

	var Tree_Deciduous002 = CreateObjectAbove(Tree_Deciduous, 236, 363);
	Tree_Deciduous002->SetCon(101);
	var Tree_Deciduous003 = CreateObjectAbove(Tree_Deciduous, 271, 349);
	Tree_Deciduous003->SetCon(101);
	CreateObjectAbove(Tree_Deciduous, 183, 364);
	CreateObjectAbove(Tree_Deciduous, 192, 363);

	CreateObjectAbove(EnvPack_Guidepost2, 90, 360);

	var Flower001 = CreateObjectAbove(Flower, 160, 365);
	var Flower002 = CreateObjectAbove(Flower, 169, 366);
	var Flower003 = CreateObjectAbove(Flower, 197, 366);
	var Flower004 = CreateObjectAbove(Flower, 251, 366);
	var Flower005 = CreateObjectAbove(Flower, 208, 367);

	var Wheat001 = CreateObjectAbove(Wheat, 188, 360);
	Wheat001->SetMeshMaterial("wheat_material_ripe", 0);
	var Wheat002 = CreateObjectAbove(Wheat, 179, 358);
	Wheat002->SetMeshMaterial("wheat_material_ripe", 0);
	var Flower006 = CreateObjectAbove(Flower, 127, 368);
	CreateObjectAbove(Flower, 229, 367);

	var Tree_Coniferous2002 = CreateObjectAbove(Tree_Coniferous2, 280, 345);
	Tree_Coniferous2002->SetCon(99);
	var Tree_Coniferous2003 = CreateObjectAbove(Tree_Coniferous2, 136, 365);
	Tree_Coniferous2003->SetCon(104);
	var Tree_Coniferous2004 = CreateObjectAbove(Tree_Coniferous2, 257, 357);
	Tree_Coniferous2004->SetCon(96);
	CreateObjectAbove(Tree_Coniferous2, 163, 364);

	var Flower007 = CreateObjectAbove(Flower, 288, 342);
	Flower007->SetCon(90);

	var Tree_Deciduous004 = CreateObjectAbove(Tree_Deciduous, 207, 361);
	Tree_Deciduous004->SetCon(99);

	var Tree_Coniferous4001 = CreateObjectAbove(Tree_Coniferous4, 199, 361);
	Tree_Coniferous4001->SetCon(95);

	var Flower008 = CreateObject(Flower, 271, 350);
	Flower008->SetCon(5);

	var Tree_Coniferous4002 = CreateObject(Tree_Coniferous4, 127, 366);
	Tree_Coniferous4002->SetCon(5);
	var Tree_Coniferous4003 = CreateObject(Tree_Coniferous4, 251, 366);
	Tree_Coniferous4003->SetCon(1);

	CreateObjectAbove(RoomEntrance, 609, 303);

	var StoneDoor001 = CreateObject(StoneDoor, 524, 283);
	StoneDoor001->SetComDir(COMD_Down);

	var SpinWheel001 = CreateObjectAbove(SpinWheel, 430, 320);
	SpinWheel001->SetStoneDoor(StoneDoor001);

	CreateObjectAbove(Ruin_WoodenCabin, 343, 335);
	var Clonk001 = CreateObjectAbove(Clonk, 342, 335);
	Clonk001->SetColor(0x813100);
	Clonk001->SetMeshMaterial("Clonk_Sage", 0);
	Clonk001->Unstick(7);
	Clonk001->SetDir(DIR_Left);
	Clonk001->SetAlternativeSkin("Sage");

	var Pickaxe001 = Clonk001->CreateContents(Pickaxe);

	var Dialogue001 = Clonk001->SetDialogue("Editor",true);
	Dialogue001->SetUserDialogue({Actions=[{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value="Good day stranger."}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="triggering_clonk"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value="Hi there, what happened to your cabin?"}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value="There are some evil guys who took over the tower ahead and destroyed my little cabin."}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="triggering_clonk"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value="What is so special about the tower that they would destroy your tower?"}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value="I still have to find out. I am an archaeologist and was studing this ancient tower, it has several rooms with riddles and artefacts."}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="triggering_clonk"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value="Oh that's interesting! I like riddles, how can I enter the tower?"}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value="Well you just turn the lever ahead and go into the first room. The further you get the harder the riddles! I did not make it to the top before those evil guys came."}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="triggering_clonk"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value="Okay, I am going to give it a try!"}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value="Take care!"}}],Function="sequence"}, nil);
	return true;
}
