/* Automatically created objects file */

func InitializeObjects()
{
	CreateObjectAbove(EnvPack_WineBarrel, 124, 280);
	CreateObjectAbove(EnvPack_WineBarrel, 220, 281);
	CreateObjectAbove(EnvPack_WineBarrel, 298, 280);

	CreateObjectAbove(EnvPack_Candle, 136, 188);
	CreateObjectAbove(EnvPack_Candle, 217, 176);
	CreateObjectAbove(EnvPack_Candle, 292, 188);
	var WoodenSign001 = CreateObjectAbove(WoodenSign, 384, 274);
	WoodenSign001->SetInscription({DE="3xKlopfen = Tuer auf!",Function="Translate",US="3xKnock = Door opens!"});

	CreateObjectAbove(EnvPack_Candle, 491, 252);
	var StoneDoor001 = CreateObject(StoneDoor, 404, 260);
	StoneDoor001->SetComDir(COMD_Down);
	StoneDoor001->MakeInvincible(false);
	StoneDoor001->SetPosition(404, 260);
	StoneDoor001->SetPlrViewOnSignalChange(true);

	var FloorSwitch001 = CreateObject(FloorSwitch, 436, 283);
	FloorSwitch001->SetPosition(436, 283);
	FloorSwitch001->SetSwitchTarget(StoneDoor001);
	FloorSwitch001.SwitchMass = 20;

	var RoomExit001 = CreateObjectAbove(RoomExit, 491, 280);
	RoomExit001->SetColor(0xffc83232);

	var RoomEntrance001 = CreateObjectAbove(RoomEntrance, 327, 279);
	RoomEntrance001->SetColor(0xff32c832);

	CreateObjectAbove(ChemicalLab, 141, 280);

	CreateObjectAbove(InventorsLab, 244, 279);

	var Foundry001 = CreateObjectAbove(Foundry, 256, 279);

	CreateObjectAbove(ToolsWorkshop, 177, 279);

	var Chest001 = CreateObjectAbove(Chest, 307, 279);

	CreateObjectAbove(Armory, 235, 279);

	CreateObjectAbove(Kitchen, 261, 279);

	CreateObjectAbove(Windmill, 289, 279);

	var SteamEngine001 = CreateObject(SteamEngine, 191, 256);
	SteamEngine001.MakeRoomPlayerOwner = true;
	SteamEngine001->SetPosition(191, 256);

	var Cannon001 = CreateObjectAbove(Cannon, 377, 279);
	Cannon001->SetColor(0xfffcf41c);

	var Catapult001 = CreateObjectAbove(Catapult, 198, 279);
	Catapult001->SetRDir(6);
	CreateObjectAbove(Catapult, 254, 278);

	var Lorry004 = CreateObjectAbove(Lorry, 159, 279);
	var Lorry001 = CreateObject(Lorry, 217, 271);
	Lorry001->SetR(-17);
	Lorry001->SetMeshMaterial("RuinedLorry", 0);
	Lorry001->SetPosition(217, 271);
	var Lorry003 = CreateObjectAbove(Lorry, 271, 279);
	var Lorry002 = CreateObjectAbove(Lorry, 294, 279);
	Lorry002->SetRDir(-6);
	var PlayerStart001 = CreateObject(PlayerStart, 327, 296);
	PlayerStart001->SetPosition(327, 296);
	PlayerStart001->SetClonkMaxContentsCount(7);
	PlayerStart001->SetClonkMaxEnergy(69);
	PlayerStart001->SetViewLock(false);

	var Clonk001 = CreateObjectAbove(Clonk, 477, 279);
	Clonk001->SetColor(0x4040ff);
	Clonk001->SetMeshMaterial("Clonk_Beggar", 0);
	Clonk001->SetDir(DIR_Left);
	Clonk001->SetAlternativeSkin("Beggar");

	var Joker001 = Clonk001->CreateContents(Joker);
	Joker001->SetPosition(389, 150);

	var Dialogue001 = Clonk001->SetDialogue("Editor",true);
	Dialogue001->SetUserDialogue({Actions=[{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="WAS? SPRICH LAUTER! ICH KANN DICH NICHT HOEREN!",Function="Translate",US="WHAT? SPEAK LOUDER! I CANNOT HEAR YOU!"}}}],Function="sequence"}, nil);

	var Bone001 = Chest001->CreateContents(Bone);
	Bone001->SetPosition(226, 148);
	var Bone002 = Chest001->CreateContents(Bone);
	Bone002->SetPosition(226, 148);

	var Skull001 = Chest001->CreateContents(Skull);
	Skull001->SetPosition(226, 148);
	var Skull002 = Chest001->CreateContents(Skull);
	Skull002->SetPosition(226, 148);
	var Skull003 = Chest001->CreateContents(Skull);
	Skull003->SetPosition(226, 148);

	var Earth001 = Foundry001->CreateContents(Earth);
	Earth001->SetStackCount(2);
	Earth001->SetPosition(175, 134);

	var Rock001 = Foundry001->CreateContents(Rock);
	Rock001->SetPosition(175, 134);
	var Rock002 = Lorry003->CreateContents(Rock);
	Rock002->SetPosition(190, 152);
	var Rock003 = Lorry003->CreateContents(Rock);
	Rock003->SetPosition(190, 152);
	var Rock004 = Lorry003->CreateContents(Rock);
	Rock004->SetPosition(190, 152);
	var Rock005 = Lorry003->CreateContents(Rock);
	Rock005->SetPosition(190, 152);
	var Rock006 = Lorry003->CreateContents(Rock);
	Rock006->SetPosition(190, 152);
	var Rock007 = Lorry003->CreateContents(Rock);
	Rock007->SetPosition(190, 152);
	var Rock008 = Lorry003->CreateContents(Rock);
	Rock008->SetPosition(190, 152);
	var Rock009 = Lorry003->CreateContents(Rock);
	Rock009->SetPosition(190, 152);
	var Rock010 = Lorry003->CreateContents(Rock);
	Rock010->SetPosition(190, 152);
	var Rock011 = Lorry003->CreateContents(Rock);
	Rock011->SetPosition(190, 152);
	var Rock012 = Foundry001->CreateContents(Rock);
	Rock012->SetPosition(175, 134);
	var Rock013 = Foundry001->CreateContents(Rock);
	Rock013->SetPosition(175, 134);
	var Rock014 = Lorry003->CreateContents(Rock);
	Rock014->SetPosition(190, 152);
	var Rock015 = Foundry001->CreateContents(Rock);
	Rock015->SetPosition(175, 134);
	var Rock016 = Foundry001->CreateContents(Rock);
	Rock016->SetPosition(175, 134);
	var Rock017 = Foundry001->CreateContents(Rock);
	Rock017->SetPosition(175, 134);
	var Rock018 = Foundry001->CreateContents(Rock);
	Rock018->SetPosition(175, 134);
	var Rock019 = Foundry001->CreateContents(Rock);
	Rock019->SetPosition(175, 134);
	var Rock020 = Foundry001->CreateContents(Rock);
	Rock020->SetPosition(175, 134);
	var Rock021 = Foundry001->CreateContents(Rock);
	Rock021->SetPosition(175, 134);
	var Rock022 = Foundry001->CreateContents(Rock);
	Rock022->SetPosition(175, 134);
	var Rock023 = Lorry002->CreateContents(Rock);
	Rock023->SetPosition(213, 152);
	var Rock024 = Lorry002->CreateContents(Rock);
	Rock024->SetPosition(213, 152);
	var Rock025 = Lorry002->CreateContents(Rock);
	Rock025->SetPosition(213, 152);
	var Rock026 = Lorry002->CreateContents(Rock);
	Rock026->SetPosition(213, 152);
	var Rock027 = Lorry002->CreateContents(Rock);
	Rock027->SetPosition(213, 152);
	var Rock028 = Lorry002->CreateContents(Rock);
	Rock028->SetPosition(213, 152);
	var Rock029 = Lorry003->CreateContents(Rock);
	Rock029->SetPosition(190, 152);
	var Rock030 = Lorry003->CreateContents(Rock);
	Rock030->SetPosition(190, 152);
	var Rock031 = Lorry003->CreateContents(Rock);
	Rock031->SetPosition(190, 152);
	var Rock032 = Lorry003->CreateContents(Rock);
	Rock032->SetPosition(190, 152);
	var Rock033 = Lorry003->CreateContents(Rock);
	Rock033->SetPosition(190, 152);
	var Rock034 = Lorry003->CreateContents(Rock);
	Rock034->SetPosition(190, 152);
	var Rock035 = Lorry003->CreateContents(Rock);
	Rock035->SetPosition(190, 152);
	var Rock036 = Lorry003->CreateContents(Rock);
	Rock036->SetPosition(190, 152);
	var Rock037 = Lorry003->CreateContents(Rock);
	Rock037->SetPosition(190, 152);
	var Rock038 = Lorry003->CreateContents(Rock);
	Rock038->SetPosition(190, 152);

	var CottonSeed001 = Lorry004->CreateContents(CottonSeed);
	CottonSeed001->SetPosition(78, 152);
	var CottonSeed002 = Lorry004->CreateContents(CottonSeed);
	CottonSeed002->SetPosition(78, 152);
	var CottonSeed003 = Lorry004->CreateContents(CottonSeed);
	CottonSeed003->SetPosition(78, 152);
	var CottonSeed004 = Lorry001->CreateContents(CottonSeed);
	CottonSeed004->SetPosition(136, 151);
	var CottonSeed005 = Lorry001->CreateContents(CottonSeed);
	CottonSeed005->SetPosition(136, 151);
	var CottonSeed006 = Lorry001->CreateContents(CottonSeed);
	CottonSeed006->SetPosition(136, 151);
	var CottonSeed007 = Lorry003->CreateContents(CottonSeed);
	CottonSeed007->SetPosition(190, 152);
	var CottonSeed008 = Foundry001->CreateContents(CottonSeed);
	CottonSeed008->SetPosition(175, 134);

	var Ore001 = Lorry004->CreateContents(Ore);
	Ore001->SetPosition(78, 152);
	var Ore002 = Lorry004->CreateContents(Ore);
	Ore002->SetPosition(78, 152);
	var Ore003 = Lorry004->CreateContents(Ore);
	Ore003->SetPosition(78, 152);
	var Ore004 = Lorry004->CreateContents(Ore);
	Ore004->SetPosition(78, 152);
	var Ore005 = Lorry004->CreateContents(Ore);
	Ore005->SetPosition(78, 152);
	var Ore006 = Lorry004->CreateContents(Ore);
	Ore006->SetPosition(78, 152);
	var Ore007 = Lorry004->CreateContents(Ore);
	Ore007->SetPosition(78, 152);
	var Ore008 = Lorry004->CreateContents(Ore);
	Ore008->SetPosition(78, 152);
	var Ore009 = Lorry004->CreateContents(Ore);
	Ore009->SetPosition(78, 152);
	var Ore010 = Lorry004->CreateContents(Ore);
	Ore010->SetPosition(78, 152);

	var Coal001 = Lorry001->CreateContents(Coal);
	Coal001->SetPosition(136, 151);
	var Coal002 = Lorry001->CreateContents(Coal);
	Coal002->SetPosition(136, 151);
	var Coal003 = Lorry001->CreateContents(Coal);
	Coal003->SetPosition(136, 151);
	var Coal004 = Lorry001->CreateContents(Coal);
	Coal004->SetPosition(136, 151);
	var Coal005 = Lorry001->CreateContents(Coal);
	Coal005->SetPosition(136, 151);
	var Coal006 = SteamEngine001->CreateContents(Coal);
	Coal006->SetPosition(142, 135);
	var Coal007 = SteamEngine001->CreateContents(Coal);
	Coal007->SetPosition(142, 135);
	var Coal008 = SteamEngine001->CreateContents(Coal);
	Coal008->SetPosition(142, 135);
	var Coal009 = SteamEngine001->CreateContents(Coal);
	Coal009->SetPosition(142, 135);
	var Coal010 = Lorry001->CreateContents(Coal);
	Coal010->SetPosition(136, 151);
	var Coal011 = Lorry001->CreateContents(Coal);
	Coal011->SetPosition(136, 151);
	var Coal012 = Lorry001->CreateContents(Coal);
	Coal012->SetPosition(136, 151);
	var Coal013 = Lorry001->CreateContents(Coal);
	Coal013->SetPosition(136, 151);

	var Nugget001 = Lorry001->CreateContents(Nugget);
	Nugget001->SetPosition(136, 151);
	var Nugget002 = Lorry001->CreateContents(Nugget);
	Nugget002->SetPosition(136, 151);
	var Nugget003 = Lorry001->CreateContents(Nugget);
	Nugget003->SetPosition(136, 151);
	var Nugget004 = Lorry001->CreateContents(Nugget);
	Nugget004->SetPosition(136, 151);
	var Nugget005 = Lorry001->CreateContents(Nugget);
	Nugget005->SetPosition(136, 151);
	var Nugget006 = Lorry001->CreateContents(Nugget);
	Nugget006->SetPosition(136, 151);

	var Wood001 = Lorry004->CreateContents(Wood);
	Wood001->SetPosition(78, 152);
	var Wood002 = Lorry004->CreateContents(Wood);
	Wood002->SetPosition(78, 152);
	var Wood003 = Lorry004->CreateContents(Wood);
	Wood003->SetPosition(78, 152);
	var Wood004 = Lorry004->CreateContents(Wood);
	Wood004->SetPosition(78, 152);
	var Wood005 = Lorry004->CreateContents(Wood);
	Wood005->SetPosition(78, 152);
	var Wood006 = Lorry004->CreateContents(Wood);
	Wood006->SetPosition(78, 152);
	var Wood007 = Lorry004->CreateContents(Wood);
	Wood007->SetPosition(78, 152);
	var Wood008 = Lorry004->CreateContents(Wood);
	Wood008->SetPosition(78, 152);

	var Loam001 = Lorry003->CreateContents(Loam);
	Loam001->SetPosition(190, 152);
	var Loam002 = Foundry001->CreateContents(Loam);
	Loam002->SetPosition(175, 134);
	var Loam003 = Lorry003->CreateContents(Loam);
	Loam003->SetPosition(190, 152);
	var Loam004 = Lorry003->CreateContents(Loam);
	Loam004->SetPosition(190, 152);
	var Loam005 = Lorry003->CreateContents(Loam);
	Loam005->SetPosition(190, 152);
	var Loam006 = Lorry003->CreateContents(Loam);
	Loam006->SetPosition(190, 152);
	var Loam007 = Foundry001->CreateContents(Loam);
	Loam007->SetPosition(175, 134);
	var Loam008 = Foundry001->CreateContents(Loam);
	Loam008->SetPosition(175, 134);

	var Metal001 = Foundry001->CreateContents(Metal);
	Metal001->SetPosition(175, 134);
	var Metal002 = Foundry001->CreateContents(Metal);
	Metal002->SetPosition(175, 134);
	var Metal003 = Foundry001->CreateContents(Metal);
	Metal003->SetPosition(175, 134);
	var Metal004 = Foundry001->CreateContents(Metal);
	Metal004->SetPosition(175, 134);
	var Metal005 = Foundry001->CreateContents(Metal);
	Metal005->SetPosition(175, 134);
	var Metal006 = Foundry001->CreateContents(Metal);
	Metal006->SetPosition(175, 134);
	var Metal007 = Foundry001->CreateContents(Metal);
	Metal007->SetPosition(175, 134);
	var Metal008 = Foundry001->CreateContents(Metal);
	Metal008->SetPosition(175, 134);
	var Metal009 = Foundry001->CreateContents(Metal);
	Metal009->SetPosition(175, 134);

	var Moss001 = Lorry003->CreateContents(Moss);
	Moss001->SetPosition(190, 152);
	var Moss002 = Lorry003->CreateContents(Moss);
	Moss002->SetPosition(190, 152);
	var Moss003 = Lorry003->CreateContents(Moss);
	Moss003->SetPosition(190, 152);
	var Moss004 = Lorry003->CreateContents(Moss);
	Moss004->SetPosition(190, 152);
	var Moss005 = Lorry003->CreateContents(Moss);
	Moss005->SetPosition(190, 152);
	var Moss006 = Lorry003->CreateContents(Moss);
	Moss006->SetPosition(190, 152);

	var Cloth001 = Lorry002->CreateContents(Cloth);
	Cloth001->SetPosition(213, 152);
	var Cloth002 = Lorry002->CreateContents(Cloth);
	Cloth002->SetPosition(213, 152);
	var Cloth003 = Lorry002->CreateContents(Cloth);
	Cloth003->SetPosition(213, 152);
	var Cloth004 = Lorry002->CreateContents(Cloth);
	Cloth004->SetPosition(213, 152);

	var Amethyst001 = Lorry002->CreateContents(Amethyst);
	Amethyst001->SetPosition(213, 152);
	var Amethyst002 = Lorry002->CreateContents(Amethyst);
	Amethyst002->SetPosition(213, 152);
	var Amethyst003 = Lorry004->CreateContents(Amethyst);
	Amethyst003->SetPosition(78, 152);
	var Amethyst004 = Lorry001->CreateContents(Amethyst);
	Amethyst004->SetPosition(136, 151);
	var Amethyst005 = Lorry003->CreateContents(Amethyst);
	Amethyst005->SetPosition(190, 152);
	var Amethyst006 = Lorry003->CreateContents(Amethyst);
	Amethyst006->SetPosition(190, 152);

	var GoldBar001 = Lorry001->CreateContents(GoldBar);
	GoldBar001->SetPosition(136, 151);
	var GoldBar002 = Lorry001->CreateContents(GoldBar);
	GoldBar002->SetPosition(136, 151);
	var GoldBar003 = Lorry001->CreateContents(GoldBar);
	GoldBar003->SetPosition(136, 151);
	var GoldBar004 = Lorry001->CreateContents(GoldBar);
	GoldBar004->SetPosition(136, 151);

	var Ruby001 = Lorry004->CreateContents(Ruby);
	Ruby001->SetPosition(78, 152);
	var Ruby002 = Lorry004->CreateContents(Ruby);
	Ruby002->SetPosition(78, 152);
	var Ruby003 = Lorry004->CreateContents(Ruby);
	Ruby003->SetPosition(78, 152);
	var Ruby004 = Lorry004->CreateContents(Ruby);
	Ruby004->SetPosition(78, 152);
	var Ruby005 = Lorry004->CreateContents(Ruby);
	Ruby005->SetPosition(78, 152);

	var Shovel001 = Chest001->CreateContents(Shovel);
	Shovel001->SetPosition(226, 148);
	var Shovel002 = Lorry001->CreateContents(Shovel);
	Shovel002->SetPosition(136, 151);
	var Shovel003 = Lorry003->CreateContents(Shovel);
	Shovel003->SetPosition(190, 152);

	var Hammer001 = Chest001->CreateContents(Hammer);
	Hammer001->SetPosition(226, 148);
	var Hammer002 = Lorry002->CreateContents(Hammer);
	Hammer002->SetPosition(213, 152);
	var Hammer003 = Lorry002->CreateContents(Hammer);
	Hammer003->SetPosition(213, 152);

	var Axe001 = Chest001->CreateContents(Axe);
	Axe001->SetPosition(226, 148);
	var Axe002 = Lorry001->CreateContents(Axe);
	Axe002->SetPosition(136, 151);
	var Axe003 = Lorry001->CreateContents(Axe);
	Axe003->SetPosition(136, 151);

	var Bread001 = Lorry003->CreateContents(Bread);
	Bread001->SetPosition(190, 152);
	var Bread002 = Lorry003->CreateContents(Bread);
	Bread002->SetPosition(190, 152);
	var Bread003 = Lorry003->CreateContents(Bread);
	Bread003->SetPosition(190, 152);
	var Bread004 = Lorry003->CreateContents(Bread);
	Bread004->SetPosition(190, 152);
	var Bread005 = Lorry003->CreateContents(Bread);
	Bread005->SetPosition(190, 152);
	var Bread006 = Lorry003->CreateContents(Bread);
	Bread006->SetPosition(190, 152);
	var Bread007 = Lorry003->CreateContents(Bread);
	Bread007->SetPosition(190, 152);
	var Bread008 = Lorry003->CreateContents(Bread);
	Bread008->SetPosition(190, 152);

	var CookedMushroom001 = Lorry003->CreateContents(CookedMushroom);
	CookedMushroom001->SetPosition(190, 152);
	var CookedMushroom002 = Lorry003->CreateContents(CookedMushroom);
	CookedMushroom002->SetPosition(190, 152);
	var CookedMushroom003 = Lorry003->CreateContents(CookedMushroom);
	CookedMushroom003->SetPosition(190, 152);
	var CookedMushroom004 = Lorry003->CreateContents(CookedMushroom);
	CookedMushroom004->SetPosition(190, 152);
	var CookedMushroom005 = Lorry001->CreateContents(CookedMushroom);
	CookedMushroom005->SetPosition(136, 151);
	var CookedMushroom006 = Lorry001->CreateContents(CookedMushroom);
	CookedMushroom006->SetPosition(136, 151);
	var CookedMushroom007 = Lorry001->CreateContents(CookedMushroom);
	CookedMushroom007->SetPosition(136, 151);
	var CookedMushroom008 = Lorry004->CreateContents(CookedMushroom);
	CookedMushroom008->SetPosition(78, 152);

	var Flour001 = Lorry004->CreateContents(Flour);
	Flour001->SetPosition(78, 152);
	var Flour002 = Lorry004->CreateContents(Flour);
	Flour002->SetPosition(78, 152);
	var Flour003 = Lorry004->CreateContents(Flour);
	Flour003->SetPosition(78, 152);
	var Flour004 = Lorry002->CreateContents(Flour);
	Flour004->SetPosition(213, 152);
	var Flour005 = Lorry001->CreateContents(Flour);
	Flour005->SetPosition(136, 151);
	var Flour006 = Lorry003->CreateContents(Flour);
	Flour006->SetPosition(190, 152);

	var Sproutberry001 = Lorry003->CreateContents(Sproutberry);
	Sproutberry001->SetPosition(190, 152);
	var Sproutberry002 = Lorry003->CreateContents(Sproutberry);
	Sproutberry002->SetPosition(190, 152);
	var Sproutberry003 = Lorry001->CreateContents(Sproutberry);
	Sproutberry003->SetPosition(136, 151);
	var Sproutberry004 = Lorry001->CreateContents(Sproutberry);
	Sproutberry004->SetPosition(136, 151);
	var Sproutberry005 = Lorry001->CreateContents(Sproutberry);
	Sproutberry005->SetPosition(136, 151);
	var Sproutberry006 = Lorry004->CreateContents(Sproutberry);
	Sproutberry006->SetPosition(78, 152);

	var Diamond001 = Lorry004->CreateContents(Diamond);
	Diamond001->SetPosition(78, 152);
	var Diamond002 = Lorry004->CreateContents(Diamond);
	Diamond002->SetPosition(78, 152);
	var Diamond003 = Lorry001->CreateContents(Diamond);
	Diamond003->SetPosition(136, 151);
	var Diamond004 = Lorry003->CreateContents(Diamond);
	Diamond004->SetPosition(190, 152);
	var Diamond005 = Lorry003->CreateContents(Diamond);
	Diamond005->SetPosition(190, 152);

	var Seeds001 = Lorry004->CreateContents(Seeds);
	Seeds001->SetPosition(78, 152);
	var Seeds002 = Lorry004->CreateContents(Seeds);
	Seeds002->SetPosition(78, 152);
	var Seeds003 = Lorry004->CreateContents(Seeds);
	Seeds003->SetPosition(78, 152);
	var Seeds004 = Lorry004->CreateContents(Seeds);
	Seeds004->SetPosition(78, 152);
	var Seeds005 = Lorry004->CreateContents(Seeds);
	Seeds005->SetPosition(78, 152);

	var Balloon001 = Lorry004->CreateContents(Balloon);
	Balloon001->SetPosition(78, 152);
	var Balloon002 = Lorry004->CreateContents(Balloon);
	Balloon002->SetPosition(78, 152);

	var Boompack001 = Lorry001->CreateContents(Boompack);
	Boompack001->SetPosition(136, 151);
	var Boompack002 = Lorry001->CreateContents(Boompack);
	Boompack002->SetPosition(136, 151);
	var Boompack003 = Lorry001->CreateContents(Boompack);
	Boompack003->SetPosition(136, 151);
	var Boompack004 = Lorry001->CreateContents(Boompack);
	Boompack004->SetPosition(136, 151);

	var DynamiteBox001 = Lorry002->CreateContents(DynamiteBox);
	DynamiteBox001->SetPosition(213, 152);
	var DynamiteBox002 = Lorry002->CreateContents(DynamiteBox);
	DynamiteBox002->SetPosition(213, 152);
	var DynamiteBox003 = Lorry002->CreateContents(DynamiteBox);
	DynamiteBox003->SetPosition(213, 152);
	var DynamiteBox004 = Lorry002->CreateContents(DynamiteBox);
	DynamiteBox004->SetPosition(213, 152);
	var DynamiteBox005 = Lorry002->CreateContents(DynamiteBox);
	DynamiteBox005->SetPosition(213, 152);
	var DynamiteBox006 = Lorry002->CreateContents(DynamiteBox);
	DynamiteBox006->SetPosition(213, 152);
	var DynamiteBox007 = Lorry002->CreateContents(DynamiteBox);
	DynamiteBox007->SetPosition(213, 152);
	var DynamiteBox008 = Lorry002->CreateContents(DynamiteBox);
	DynamiteBox008->SetPosition(213, 152);
	var DynamiteBox009 = Lorry002->CreateContents(DynamiteBox);
	DynamiteBox009->SetPosition(213, 152);
	var Dynamite001 = Lorry002->CreateContents(Dynamite);
	Dynamite001->SetPosition(213, 152);
	var Dynamite002 = Lorry002->CreateContents(Dynamite);
	Dynamite002->SetPosition(213, 152);
	var Dynamite003 = Lorry002->CreateContents(Dynamite);
	Dynamite003->SetPosition(213, 152);
	var Dynamite004 = Lorry002->CreateContents(Dynamite);
	Dynamite004->SetPosition(213, 152);

	var Bucket001 = Lorry001->CreateContents(Bucket);
	Bucket001->SetPosition(136, 151);
	var Bucket002 = Lorry001->CreateContents(Bucket);
	Bucket002->SetPosition(136, 151);
	var Bucket003 = Lorry001->CreateContents(Bucket);
	Bucket003->SetPosition(136, 151);

	var GrappleBow001 = Lorry002->CreateContents(GrappleBow);
	GrappleBow001->SetPosition(213, 152);
	var GrappleBow002 = Lorry002->CreateContents(GrappleBow);
	GrappleBow002->SetPosition(213, 152);

	var Torch001 = Lorry002->CreateContents(Torch);
	Torch001->SetState(0);
	Torch001->SetPosition(213, 152);
	Torch001->SetMeshMaterial("Torch", 0);

	var Barrel001 = Lorry001->CreateContents(Barrel);
	Barrel001->SetPosition(136, 151);
	Barrel001->SetColor(0xff000000);

	var MetalBarrel001 = Lorry001->CreateContents(MetalBarrel);
	MetalBarrel001->SetPosition(136, 151);
	MetalBarrel001->SetColor(0xff000000);
	var MetalBarrel002 = Lorry001->CreateContents(MetalBarrel);
	MetalBarrel002->SetPosition(136, 151);
	MetalBarrel002->SetColor(0xff000000);

	var Ropebridge001 = Lorry003->CreateContents(Ropebridge);
	Ropebridge001->SetPosition(190, 152);

	var Crate001 = Lorry003->CreateContents(Crate);
	Crate001->SetPosition(190, 152);
	var Crate002 = Lorry003->CreateContents(Crate);
	Crate002->SetPosition(190, 152);

	var Lantern001 = Lorry003->CreateContents(Lantern);
	Lantern001->SetPosition(190, 152);
	var Lantern002 = Lorry003->CreateContents(Lantern);
	Lantern002->SetPosition(190, 152);
	var Lantern003 = Lorry003->CreateContents(Lantern);
	Lantern003->SetPosition(190, 152);

	var PowderKeg001 = CreateObject(PowderKeg, 384, 275);
	PowderKeg001->SetR(-99);
	PowderKeg001->SetPosition(384, 275);
	CreateObjectAbove(PowderKeg, 393, 279);

	var Pipe001 = Lorry002->CreateContents(Pipe);
	Pipe001->SetNeutralPipe();
	Pipe001->SetPosition(213, 152);
	var Pipe002 = Lorry002->CreateContents(Pipe);
	Pipe002->SetNeutralPipe();
	Pipe002->SetPosition(213, 152);
	var Pipe003 = Chest001->CreateContents(Pipe);
	Pipe003->SetNeutralPipe();
	Pipe003->SetPosition(226, 148);

	var Sickle001 = Lorry003->CreateContents(Sickle);
	Sickle001->SetPosition(190, 152);
	var Sickle002 = Lorry002->CreateContents(Sickle);
	Sickle002->SetPosition(213, 152);

	var Pickaxe001 = Lorry002->CreateContents(Pickaxe);
	Pickaxe001->SetPosition(213, 152);
	var Pickaxe002 = Lorry002->CreateContents(Pickaxe);
	Pickaxe002->SetPosition(213, 152);

	var Ropeladder001 = Chest001->CreateContents(Ropeladder);
	Ropeladder001->SetPosition(226, 148);
	var Ropeladder002 = Chest001->CreateContents(Ropeladder);
	Ropeladder002->SetPosition(226, 148);
	var Ropeladder003 = Chest001->CreateContents(Ropeladder);
	Ropeladder003->SetPosition(226, 148);

	var DivingHelmet001 = Chest001->CreateContents(DivingHelmet);
	DivingHelmet001->SetPosition(226, 148);

	var TeleGlove001 = Chest001->CreateContents(TeleGlove);
	TeleGlove001->SetPosition(226, 148);
	var TeleGlove002 = Chest001->CreateContents(TeleGlove);
	TeleGlove002->SetPosition(226, 148);
	var TeleGlove003 = Chest001->CreateContents(TeleGlove);
	TeleGlove003->SetPosition(226, 148);

	var WallKit001 = Lorry002->CreateContents(WallKit);
	WallKit001->SetPosition(213, 152);
	var WallKit002 = Lorry002->CreateContents(WallKit);
	WallKit002->SetPosition(213, 152);
	var WallKit003 = Lorry002->CreateContents(WallKit);
	WallKit003->SetPosition(213, 152);
	var WallKit004 = Lorry002->CreateContents(WallKit);
	WallKit004->SetPosition(213, 152);
	var WallKit005 = Lorry002->CreateContents(WallKit);
	WallKit005->SetPosition(213, 152);

	var WindBag001 = Chest001->CreateContents(WindBag);
	WindBag001->SetPosition(226, 148);
	var WindBag002 = Chest001->CreateContents(WindBag);
	WindBag002->SetPosition(226, 148);
	var WindBag003 = Chest001->CreateContents(WindBag);
	WindBag003->SetPosition(226, 148);
	var WindBag004 = Chest001->CreateContents(WindBag);
	WindBag004->SetPosition(226, 148);
	var WindBag005 = Chest001->CreateContents(WindBag);
	WindBag005->SetPosition(226, 148);

	var Bow001 = Chest001->CreateContents(Bow);
	Bow001->SetPosition(226, 148);

	var BombArrow001 = Chest001->CreateContents(BombArrow);
	BombArrow001->SetPosition(226, 148);
	var BombArrow002 = Chest001->CreateContents(BombArrow);
	BombArrow002->SetPosition(226, 148);
	var BombArrow003 = Chest001->CreateContents(BombArrow);
	BombArrow003->SetPosition(226, 148);
	var BombArrow004 = Chest001->CreateContents(BombArrow);
	BombArrow004->SetPosition(226, 148);
	var BombArrow005 = Chest001->CreateContents(BombArrow);
	BombArrow005->SetPosition(226, 148);
	var BombArrow006 = Chest001->CreateContents(BombArrow);
	BombArrow006->SetPosition(226, 148);

	var FireArrow001 = Chest001->CreateContents(FireArrow);
	FireArrow001->SetPosition(226, 148);
	var FireArrow002 = Chest001->CreateContents(FireArrow);
	FireArrow002->SetPosition(226, 148);
	var FireArrow003 = Chest001->CreateContents(FireArrow);
	FireArrow003->SetPosition(226, 148);

	var Arrow001 = Chest001->CreateContents(Arrow);
	Arrow001->SetPosition(226, 148);
	var Arrow002 = Chest001->CreateContents(Arrow);
	Arrow002->SetPosition(226, 148);

	var Blunderbuss001 = Chest001->CreateContents(Blunderbuss);
	Blunderbuss001->SetPosition(226, 148);

	var LeadBullet001 = Chest001->CreateContents(LeadBullet);
	LeadBullet001->SetPosition(226, 148);
	var LeadBullet002 = Chest001->CreateContents(LeadBullet);
	LeadBullet002->SetPosition(226, 148);
	var LeadBullet003 = Chest001->CreateContents(LeadBullet);
	LeadBullet003->SetPosition(226, 148);

	var IronBomb001 = Chest001->CreateContents(IronBomb);
	IronBomb001->SetPosition(226, 148);
	var IronBomb002 = Chest001->CreateContents(IronBomb);
	IronBomb002->SetPosition(226, 148);
	var IronBomb003 = Chest001->CreateContents(IronBomb);
	IronBomb003->SetPosition(226, 148);

	var GrenadeLauncher001 = Chest001->CreateContents(GrenadeLauncher);
	GrenadeLauncher001->SetPosition(226, 148);

	var Helmet001 = Chest001->CreateContents(Helmet);
	Helmet001->SetPosition(226, 148);
	var Helmet002 = Chest001->CreateContents(Helmet);
	Helmet002->SetPosition(226, 148);

	var Club001 = Chest001->CreateContents(Club);
	Club001->SetPosition(226, 148);

	var SmokeBomb001 = Chest001->CreateContents(SmokeBomb);
	SmokeBomb001->SetPosition(226, 148);

	var Shield001 = Chest001->CreateContents(Shield);
	Shield001->SetPosition(226, 148);

	var Sword001 = Chest001->CreateContents(Sword);
	Sword001->SetPosition(226, 148);

	var Javelin001 = Chest001->CreateContents(Javelin);
	Javelin001->SetPosition(226, 148);
	var Javelin002 = Chest001->CreateContents(Javelin);
	Javelin002->SetPosition(226, 148);
	var Javelin003 = Chest001->CreateContents(Javelin);
	Javelin003->SetPosition(226, 148);

	var AncientTablet001 = CreateObject(AncientTablet, 128, 293);
	AncientTablet001->SetR(45);
	AncientTablet001->SetPosition(128, 293);

	var Firestone001 = Lorry004->CreateContents(Firestone);
	Firestone001->SetPosition(78, 152);
	var Firestone002 = Lorry004->CreateContents(Firestone);
	Firestone002->SetPosition(78, 152);
	var Firestone003 = Lorry004->CreateContents(Firestone);
	Firestone003->SetPosition(78, 152);
	var Firestone004 = Lorry004->CreateContents(Firestone);
	Firestone004->SetPosition(78, 152);
	var Firestone005 = Lorry004->CreateContents(Firestone);
	Firestone005->SetPosition(78, 152);
	var Firestone006 = Lorry004->CreateContents(Firestone);
	Firestone006->SetPosition(78, 152);
	var Firestone007 = Lorry004->CreateContents(Firestone);
	Firestone007->SetPosition(78, 152);
	var Firestone008 = Lorry004->CreateContents(Firestone);
	Firestone008->SetPosition(78, 152);
	var Firestone009 = Lorry004->CreateContents(Firestone);
	Firestone009->SetPosition(78, 152);
	return true;
}
