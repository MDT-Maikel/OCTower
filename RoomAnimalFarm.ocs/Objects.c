/* Automatically created objects file */

func InitializeObjects()
{
	var Grass001 = CreateObjectAbove(Grass, 122, 94);
	var Grass002 = CreateObjectAbove(Grass, 128, 94);

	var Flower001 = CreateObjectAbove(Flower, 163, 102);
	Flower001->SetSeedChance(0);
	Flower001->SetSeedAmount(0);
	var Flower002 = CreateObjectAbove(Flower, 205, 102);
	Flower002->SetSeedAmount(0);
	Flower002->SetSeedChance(0);
	var Flower003 = CreateObjectAbove(Flower, 231, 103);
	Flower003->SetSeedChance(0);
	Flower003->SetSeedAmount(0);

	var Fern001 = CreateObjectAbove(Fern, 130, 96);
	Fern001->SetSeedAmount(0);
	Fern001->SetSeedChance(0);
	var Fern002 = CreateObjectAbove(Fern, 177, 96);
	Fern002->SetSeedAmount(0);
	Fern002->SetSeedChance(0);
	var Fern003 = CreateObjectAbove(Fern, 248, 96);
	Fern003->SetSeedAmount(0);
	Fern003->SetSeedChance(0);

	var Vine001 = CreateObjectAbove(Vine, 478, 173);
	Vine001->CreateSegments();
	var Vine002 = CreateObjectAbove(Vine, 424, 172);
	Vine002->CreateSegments();
	var Vine003 = CreateObjectAbove(Vine, 367, 171);
	Vine003->CreateSegments();
	var Vine004 = CreateObjectAbove(Vine, 311, 172);
	Vine004->CreateSegments();
	var Tree_Deciduous001 = CreateObjectAbove(Tree_Deciduous, 191, 219);
	Tree_Deciduous001->SetCon(102);
	Tree_Deciduous001->SetSeedAmount(0);
	Tree_Deciduous001->SetSeedChance(0);
	var Tree_Deciduous002 = CreateObjectAbove(Tree_Deciduous, 137, 220);
	Tree_Deciduous002->SetCon(105);
	Tree_Deciduous002->SetSeedAmount(0);
	Tree_Deciduous002->SetSeedChance(0);
	var Branch001 = CreateObject(Branch, 68, 266);
	Branch001->SetCon(103);
	Branch001->SetR(124);
	var Branch002 = CreateObject(Branch, 39, 184);
	Branch002->SetCon(103);
	Branch002->SetR(139);

	var Trunk001 = CreateObject(Trunk, 598, 233);
	Trunk001->SetCon(101);
	Trunk001->SetR(-41);
	var Trunk002 = CreateObject(Trunk, 593, 271);
	Trunk002->SetCon(93);
	Trunk002->SetR(30);

	var Branch003 = CreateObject(Branch, 255, 40);
	Branch003->SetCon(95);
	Branch003->SetR(-145);

	var Fern004 = CreateObjectAbove(Fern, 130, 217);
	Fern004->SetSeedAmount(0);
	Fern004->SetSeedChance(0);
	var Fern005 = CreateObjectAbove(Fern, 116, 303);
	Fern005->SetSeedAmount(0);
	Fern005->SetSeedChance(0);
	var Fern006 = CreateObjectAbove(Fern, 179, 304);
	Fern006->SetSeedAmount(0);
	Fern006->SetSeedChance(0);

	var Flower004 = CreateObjectAbove(Flower, 210, 310);
	Flower004->SetSeedChance(0);
	Flower004->SetSeedAmount(0);
	var Flower005 = CreateObjectAbove(Flower, 134, 310);
	Flower005->SetSeedChance(0);
	Flower005->SetSeedAmount(0);

	var Cotton001 = CreateObjectAbove(Cotton, 153, 305);
	Cotton001->SetSeedAmount(0);
	Cotton001->SetSeedChance(0);

	CreateObjectAbove(RoomEntrance, 55, 80);

	CreateObjectAbove(RoomExit, 590, 456);

	var StoneDoor001 = CreateObject(StoneDoor, 308, 60);
	StoneDoor001->SetComDir(COMD_Down);
	var StoneDoor002 = CreateObject(StoneDoor, 556, 348);

	var SpinWheel001 = CreateObjectAbove(SpinWheel, 289, 80);
	SpinWheel001->SetStoneDoor(StoneDoor001);
	var SpinWheel002 = CreateObjectAbove(SpinWheel, 327, 80);
	SpinWheel002->SetStoneDoor(StoneDoor001);
	var SpinWheel003 = CreateObjectAbove(SpinWheel, 542, 368);
	SpinWheel003->SetStoneDoor(StoneDoor002);
	var SpinWheel004 = CreateObjectAbove(SpinWheel, 575, 368);
	SpinWheel004->SetStoneDoor(StoneDoor002);

	var Chest001 = CreateObjectAbove(Chest, 39, 215);
	var Seaweed001 = CreateObjectAbove(Seaweed, 404, 96);
	Seaweed001->SetSeedAmount(0);
	Seaweed001->SetSeedChance(0);
	var Seaweed002 = CreateObjectAbove(Seaweed, 462, 95);
	Seaweed002->SetSeedAmount(0);
	Seaweed002->SetSeedChance(0);
	var Seaweed003 = CreateObjectAbove(Seaweed, 515, 95);
	Seaweed003->SetSeedAmount(0);
	Seaweed003->SetSeedChance(0);
	var Seaweed004 = CreateObjectAbove(Seaweed, 445, 95);
	Seaweed004->SetSeedAmount(0);
	Seaweed004->SetSeedChance(0);
	var Seaweed005 = CreateObjectAbove(Seaweed, 306, 263);
	Seaweed005->SetSeedAmount(0);
	Seaweed005->SetSeedChance(0);
	var Seaweed006 = CreateObjectAbove(Seaweed, 332, 263);
	Seaweed006->SetSeedAmount(0);
	Seaweed006->SetSeedChance(0);
	var Seaweed007 = CreateObjectAbove(Seaweed, 342, 263);
	Seaweed007->SetSeedAmount(0);
	Seaweed007->SetSeedChance(0);
	var Seaweed008 = CreateObjectAbove(Seaweed, 409, 263);
	Seaweed008->SetSeedAmount(0);
	Seaweed008->SetSeedChance(0);
	var Seaweed009 = CreateObjectAbove(Seaweed, 459, 263);
	Seaweed009->SetSeedAmount(0);
	Seaweed009->SetSeedChance(0);
	var Seaweed010 = CreateObjectAbove(Seaweed, 474, 264);
	Seaweed010->SetSeedAmount(0);
	Seaweed010->SetSeedChance(0);
	var Seaweed011 = CreateObjectAbove(Seaweed, 491, 263);
	Seaweed011->SetSeedAmount(0);
	Seaweed011->SetSeedChance(0);

	Chest001->CreateContents(AncientTablet);

	var Mushroom001 = CreateObjectAbove(Mushroom, 198, 304);
	Mushroom001->SetSeedAmount(0);
	Mushroom001->SetSeedChance(0);
	var Mushroom002 = CreateObjectAbove(Mushroom, 140, 303);
	Mushroom002->SetSeedAmount(0);
	Mushroom002->SetSeedChance(0);
	var Mushroom003 = CreateObjectAbove(Mushroom, 178, 214);
	Mushroom003->SetSeedAmount(0);
	Mushroom003->SetSeedChance(0);
	var Mushroom004 = CreateObjectAbove(Mushroom, 202, 216);
	Mushroom004->SetSeedAmount(0);
	Mushroom004->SetSeedChance(0);
	return true;
}
