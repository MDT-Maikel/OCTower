/* Automatically created objects file */

func InitializeObjects()
{
	var Rule_NoPowerNeed001 = CreateObject(Rule_NoPowerNeed, 208, 60);
	Rule_NoPowerNeed001->SetPosition(208, 60);
	var RoomEntrance001 = CreateObjectAbove(RoomEntrance, 172, 111);
	RoomEntrance001->SetColor(0xff32c832);

	var RoomExit001 = CreateObjectAbove(RoomExit, 96, 111);
	RoomExit001->SetColor(0xffc83232);

	var MovingBrick001 = CreateObject(MovingBrick, 285, 117);
	MovingBrick001->SetMoveSpeed(20);
	MovingBrick001->SetPosition(285, 117);
	var MovingBrick002 = CreateObject(MovingBrick, 614, 117);
	MovingBrick002->SetPosition(614, 117);

	var Chest001 = CreateObjectAbove(Chest, 75, 111);
	Chest001->SetMeshMaterial("GoldenChest", 0);

	var StoneDoor001 = CreateObject(StoneDoor, 136, 92);
	StoneDoor001->SetComDir(COMD_Down);
	StoneDoor001->SetPosition(136, 92);
	StoneDoor001->SetPlrViewOnSignalChange(true);

	var SpinWheel001 = CreateObjectAbove(SpinWheel, 994, 111);
	SpinWheel001->SetSwitchTarget(StoneDoor001);

	var FloorSwitch001 = CreateObject(FloorSwitch, 246, 228);
	FloorSwitch001->SetPosition(246, 228);
	FloorSwitch001->SetActions(nil, {Actions=[{Context={Function="object_constant",Value=MovingBrick001},Function="Action_script",Script={Function="string_constant",Value="MoveHorizontal(257, 550)"}},{Function="wait",Time=1100},{Context={Function="object_constant",Value=MovingBrick001},Function="Action_script",Script={Function="string_constant",Value={DE="MoveVertical(117, 270)",Function="Translate",US="MoveVertical(117, 270)"}}},{Function="wait",Time=700},{Function="remove_object",Object={Function="object_constant",Value=MovingBrick001}}],Function="sequence"});
	FloorSwitch001.SwitchMass = 10;
	var FloorSwitch002 = CreateObject(FloorSwitch, 585, 228);
	FloorSwitch002->SetPosition(585, 228);
	FloorSwitch002->SetActions(nil, {Actions=[{Context={Function="object_constant",Value=MovingBrick002},Function="Action_script",Script={Function="string_constant",Value={DE="MoveHorizontal(580, 780)",Function="Translate",US="MoveHorizontal(580, 780)"}}},{Function="wait",Time=185},{Context={Function="object_constant",Value=MovingBrick002},Function="Action_script",Script={Function="string_constant",Value={DE="MoveVertical(117, 270)",Function="Translate",US="MoveVertical(117, 270)"}}},{Function="wait",Time=140},{Function="remove_object",Object={Function="object_constant",Value=MovingBrick002}}],Function="sequence"});
	FloorSwitch002.SwitchMass = 10;

	var PlayerStart001 = CreateObject(PlayerStart, 179, 59);
	PlayerStart001->SetPosition(179, 59);
	PlayerStart001->SetStartingMaterial([Shovel,Hammer,Pickaxe]);
	PlayerStart001->SetViewLock(false);

	var Fish001 = CreateObjectAbove(Fish, 220, 259);
	Fish001->SetClrModulation(0xffff0000);
	Fish001->Unstick(7);
	Fish001->MakeInvincible();
	var Fish002 = CreateObjectAbove(Fish, 239, 254);
	Fish002->SetClrModulation(0xffff0000);
	Fish002->Unstick(7);
	Fish002->MakeInvincible();
	var Fish003 = CreateObjectAbove(Fish, 228, 262);
	Fish003->SetClrModulation(0xffff0000);
	Fish003->Unstick(7);
	Fish003->MakeInvincible();
	var Fish004 = CreateObjectAbove(Fish, 264, 265);
	Fish004->SetClrModulation(0xffff0000);
	Fish004->Unstick(7);
	Fish004->MakeInvincible();
	var Fish005 = CreateObjectAbove(Fish, 447, 254);
	Fish005->SetClrModulation(0xffff0000);
	Fish005->Unstick(7);
	Fish005->MakeInvincible();
	var Fish006 = CreateObjectAbove(Fish, 236, 262);
	Fish006->SetClrModulation(0xffff0000);
	Fish006->Unstick(7);
	Fish006->MakeInvincible();
	var Fish007 = CreateObjectAbove(Fish, 253, 260);
	Fish007->SetClrModulation(0xffff0000);
	Fish007->Unstick(7);
	Fish007->MakeInvincible();
	var Fish008 = CreateObjectAbove(Fish, 449, 249);
	Fish008->SetClrModulation(0xffff0000);
	Fish008->Unstick(7);
	Fish008->MakeInvincible();
	var Fish009 = CreateObjectAbove(Fish, 232, 252);
	Fish009->SetClrModulation(0xffff0000);
	Fish009->Unstick(7);
	Fish009->MakeInvincible();
	var Fish010 = CreateObjectAbove(Fish, 434, 251);
	Fish010->SetClrModulation(0xffff0000);
	Fish010->Unstick(7);
	Fish010->MakeInvincible();
	var Fish011 = CreateObjectAbove(Fish, 701, 258);
	Fish011->SetClrModulation(0xffff0000);
	Fish011->Unstick(7);
	Fish011->MakeInvincible();
	var Fish012 = CreateObjectAbove(Fish, 703, 253);
	Fish012->SetClrModulation(0xffff0000);
	Fish012->Unstick(7);
	Fish012->MakeInvincible();
	var Fish013 = CreateObjectAbove(Fish, 709, 258);
	Fish013->SetClrModulation(0xffff0000);
	Fish013->Unstick(7);
	Fish013->MakeInvincible();
	var Fish014 = CreateObjectAbove(Fish, 721, 249);
	Fish014->SetClrModulation(0xffff0000);
	Fish014->Unstick(7);
	Fish014->MakeInvincible();
	var Fish015 = CreateObjectAbove(Fish, 859, 268);
	Fish015->SetClrModulation(0xffff0000);
	Fish015->Unstick(7);
	Fish015->MakeInvincible();
	var Fish016 = CreateObjectAbove(Fish, 844, 266);
	Fish016->SetClrModulation(0xffff0000);
	Fish016->Unstick(7);
	Fish016->MakeInvincible();
	var Fish017 = CreateObjectAbove(Fish, 886, 267);
	Fish017->SetClrModulation(0xffff0000);
	Fish017->Unstick(7);
	Fish017->MakeInvincible();
	var Fish018 = CreateObjectAbove(Fish, 885, 271);
	Fish018->SetClrModulation(0xffff0000);
	Fish018->Unstick(7);
	Fish018->MakeInvincible();

	var Wood001 = Chest001->CreateContents(Wood);
	Wood001->SetPosition(75, 99);
	var Wood002 = Chest001->CreateContents(Wood);
	Wood002->SetPosition(75, 99);
	var Wood003 = Chest001->CreateContents(Wood);
	Wood003->SetPosition(75, 99);
	var Wood004 = Chest001->CreateContents(Wood);
	Wood004->SetPosition(75, 99);

	var Metal001 = Chest001->CreateContents(Metal);
	Metal001->SetPosition(75, 99);
	var Metal002 = Chest001->CreateContents(Metal);
	Metal002->SetPosition(75, 99);
	var Metal003 = Chest001->CreateContents(Metal);
	Metal003->SetPosition(75, 99);

	var AncientTablet001 = CreateObject(AncientTablet, 61, 19);
	AncientTablet001->SetPosition(61, 19);

	var Joker001 = CreateObject(Joker, 1064, 237);
	Joker001->SetPosition(1064, 237);
	return true;
}
