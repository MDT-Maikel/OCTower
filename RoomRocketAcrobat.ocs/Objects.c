/* Automatically created objects file */

func InitializeObjects()
{
	var Torch001 = CreateObjectAbove(Torch, 530, 54);
	Torch001->AttachToWall(false);
	Torch001->SetMeshMaterial("Torch", 0);
	Torch001->SetState(2);

	var Trunk001 = CreateObject(Trunk, 600, 418);
	Trunk001->SetCon(114);
	Trunk001->SetR(-133);
	Trunk001->SetPosition(600, 418);

	var ItemSpawn001 = ItemSpawn->Create(Boompack,511,443);
	ItemSpawn001->SetPosition(511, 443);
	var ItemSpawn002 = ItemSpawn->Create(Boompack,536,443);
	ItemSpawn002->SetPosition(536, 443);
	var RoomEntrance001 = CreateObjectAbove(RoomEntrance, 564, 455);
	RoomEntrance001->SetColor(0xff32c832);

	var Chest001 = CreateObjectAbove(Chest, 77, 231);
	Chest001->MakeInvincible(false);

	var RoomExit001 = CreateObjectAbove(RoomExit, 567, 63);
	RoomExit001->SetColor(0xffc83232);

	var MovingBrick001 = CreateObject(MovingBrick, 20, 298);
	MovingBrick001->SetComDir(COMD_Down);
	MovingBrick001->SetYDir(10);
	MovingBrick001->MoveVertical(246, 466);
	MovingBrick001->SetPosition(20, 298);

	CreateObjectAbove(Column, 320, 320);

	var Lorry001 = CreateObject(Lorry, 325, 315);
	Lorry001->SetR(45);
	Lorry001->SetPosition(325, 315);

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
	Boompack001->SetPosition(77, 220);

	var AncientTablet001 = CreateObjectAbove(AncientTablet, 500, 246);
	AncientTablet001->SetXDir(-2);
	AncientTablet001->Unstick(7);

	var Shovel001 = CreateObject(Shovel, 599, 387);
	Shovel001->SetR(-53);
	Shovel001->SetPosition(599, 387);

	var WindBag001 = Chest001->CreateContents(WindBag);
	WindBag001->SetPosition(77, 220);

	var Balloon001 = Chest001->CreateContents(Balloon);
	Balloon001->SetPosition(77, 220);

	var Joker001 = CreateObjectAbove(Joker, 516, 343);
	Joker001->Unstick(7);

	var Dynamite001 = Lorry001->CreateContents(Dynamite);
	Dynamite001->SetPosition(325, 315);
	return true;
}
