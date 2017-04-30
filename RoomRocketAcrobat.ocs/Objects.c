/* Automatically created objects file */

func InitializeObjects()
{
	var Trunk001 = CreateObject(Trunk, 600, 418);
	Trunk001->SetCon(114);
	Trunk001->SetR(-133);
	Trunk001->SetPosition(600, 418);
	var RoomEntrance001 = CreateObjectAbove(RoomEntrance, 564, 455);
	RoomEntrance001->SetColor(0xff32c832);

	var Chest001 = CreateObjectAbove(Chest, 520, 455);
	var Chest002 = CreateObjectAbove(Chest, 77, 231);

	var RoomExit001 = CreateObjectAbove(RoomExit, 567, 63);
	RoomExit001->SetColor(0xffc83232);

	var MovingBrick001 = CreateObject(MovingBrick, 20, 378);
	MovingBrick001->SetComDir(COMD_Up);
	MovingBrick001->MoveVertical(246, 466);
	MovingBrick001->SetPosition(20, 378);

	var Column001 = CreateObject(Column, 320, 320);
	Column001->SetPosition(320, 320);

	var Clonk001 = CreateObjectAbove(Clonk, 269, 360);
	Clonk001->SetDir(DIR_Right);
	Clonk001->SetColor(0xa0a050);
	Clonk001->SetMeshMaterial("Clonk_Guard", 0);
	Clonk001->SetName("Luzi");
	Clonk001.MaxEnergy = 25000;
	Clonk001->DoEnergy(-40);
	AI->AddAI(Clonk001);
	AI->SetAttackMode(Clonk001, "Blunderbuss");
	AI->SetHome(Clonk001, 264, 352, DIR_Right);
	AI->SetGuardRange(Clonk001, 0, 0, 640, 480);
	AI->SetMaxAggroDistance(Clonk001, 511);
	Clonk001->Unstick(7);
	Clonk001->SetAlternativeSkin("Guard");
	var Boompack001 = Chest001->CreateContents(Boompack);
	Boompack001->SetPosition(520, 444);
	var Boompack002 = Chest001->CreateContents(Boompack);
	Boompack002->SetPosition(520, 444);
	var Boompack003 = Chest001->CreateContents(Boompack);
	Boompack003->SetPosition(520, 444);
	var Boompack004 = Chest001->CreateContents(Boompack);
	Boompack004->SetPosition(520, 444);
	var Boompack005 = Chest001->CreateContents(Boompack);
	Boompack005->SetPosition(520, 444);
	var Boompack006 = Chest001->CreateContents(Boompack);
	Boompack006->SetPosition(520, 444);
	var Boompack007 = Chest001->CreateContents(Boompack);
	Boompack007->SetPosition(520, 444);
	var Boompack008 = Chest001->CreateContents(Boompack);
	Boompack008->SetPosition(520, 444);
	var Boompack009 = Chest001->CreateContents(Boompack);
	Boompack009->SetPosition(520, 444);
	var Boompack010 = Chest001->CreateContents(Boompack);
	Boompack010->SetPosition(520, 444);
	var Boompack011 = Chest001->CreateContents(Boompack);
	Boompack011->SetPosition(520, 444);
	var Boompack012 = Chest001->CreateContents(Boompack);
	Boompack012->SetPosition(520, 444);
	var Boompack013 = Chest001->CreateContents(Boompack);
	Boompack013->SetPosition(520, 444);
	var Boompack014 = Chest001->CreateContents(Boompack);
	Boompack014->SetPosition(520, 444);
	var Boompack015 = Chest001->CreateContents(Boompack);
	Boompack015->SetPosition(520, 444);
	var Boompack016 = Chest001->CreateContents(Boompack);
	Boompack016->SetPosition(520, 444);
	var Boompack017 = Chest001->CreateContents(Boompack);
	Boompack017->SetPosition(520, 444);
	var Boompack018 = Chest001->CreateContents(Boompack);
	Boompack018->SetPosition(520, 444);
	var Boompack019 = Chest001->CreateContents(Boompack);
	Boompack019->SetPosition(520, 444);
	var Boompack020 = Chest001->CreateContents(Boompack);
	Boompack020->SetPosition(520, 444);
	var Boompack021 = Chest001->CreateContents(Boompack);
	Boompack021->SetPosition(520, 444);
	var Boompack022 = Chest001->CreateContents(Boompack);
	Boompack022->SetPosition(520, 444);
	var Boompack023 = Chest001->CreateContents(Boompack);
	Boompack023->SetPosition(520, 444);
	var Boompack024 = Chest001->CreateContents(Boompack);
	Boompack024->SetPosition(520, 444);
	var Boompack025 = Chest001->CreateContents(Boompack);
	Boompack025->SetPosition(520, 444);
	var Boompack026 = Chest002->CreateContents(Boompack);
	Boompack026->SetPosition(77, 220);

	CreateObjectAbove(AncientTablet, 499, 245);

	var Shovel001 = CreateObject(Shovel, 599, 387);
	Shovel001->SetR(-53);
	Shovel001->SetPosition(599, 387);

	var WindBag001 = Chest002->CreateContents(WindBag);
	WindBag001->SetPosition(77, 220);

	var Balloon001 = Chest002->CreateContents(Balloon);
	Balloon001->SetPosition(77, 220);

	CreateObjectAbove(Joker, 516, 342);
	return true;
}
