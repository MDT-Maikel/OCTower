/* Automatically created objects file */

func InitializeObjects()
{
	var Torch001 = CreateObjectAbove(Torch, 579, 139);
	Torch001->AttachToWall(false);
	Torch001->SetMeshMaterial("Torch", 0);
	Torch001->SetState(2);

	var Rule_BuyAtFlagpole001 = CreateObject(Rule_BuyAtFlagpole, 320, 190);
	Rule_BuyAtFlagpole001->SetPosition(320, 190);

	var Rule_FastPump001 = CreateObject(Rule_FastPump, 349, 190);
	Rule_FastPump001->SetPosition(349, 190);
	Rule_FastPump001->SetPumpSpeed(50);

	var Rule_NoPowerNeed001 = CreateObject(Rule_NoPowerNeed, 378, 189);
	Rule_NoPowerNeed001->SetPosition(378, 189);

	var BoilingLava001 = CreateObject(BoilingLava, 268, 190);
	BoilingLava001->SetPosition(268, 190);
	BoilingLava001->SetIntensity(12);
	BoilingLava001->SetArea(Shape->Rectangle(-1, 239, 641, 240));

	var Trunk001 = CreateObject(Trunk, 263, 64);
	Trunk001->SetCon(119);
	Trunk001->SetR(-133);
	Trunk001->SetPosition(263, 64);
	var RoomExit001 = CreateObjectAbove(RoomExit, 601, 143);
	RoomExit001->SetColor(0xffc83232);

	var RoomEntrance001 = CreateObjectAbove(RoomEntrance, 101, 143);
	RoomEntrance001->SetColor(0xff32c832);

	CreateObjectAbove(Pump, 157, 143);

	var Column001 = CreateObject(Column, 101, 47);
	Column001->SetR(180);
	Column001->SetMeshMaterial("AncientColumn", 0);
	Column001->SetPosition(101, 47);

	var Flagpole001 = CreateObject(Flagpole, 123, 110);
	Flagpole001.MakeRoomPlayerOwner = true;
	Flagpole001->SetPosition(123, 110);

	var Idol001 = CreateObject(Idol, 222, 231);
	Idol001->SetCategory(C4D_StaticBack);
	Idol001->SetR(-1);
	Idol001->SetClrModulation(0xffff1313);
	Idol001->SetMeshMaterial("IdolGrayColor", 0);
	Idol001->SetPosition(222, 231);
	Idol001->SetAction("ItemLeftHigh");
	Idol001->EditorSetItemLeft({Bone="main",MeshTransformation=nil,Type=nil});

	var Elevator001 = CreateObjectAbove(Elevator, 64, 142);
	Elevator001->SetDir(DIR_Right);
	Elevator001->CreateShaft(4);
	Elevator001->SetCasePosition(134);
	var Lorry001 = CreateObjectAbove(Lorry, 85, 270);

	var PlayerStart001 = CreateObject(PlayerStart, 293, 189);
	PlayerStart001->SetPosition(293, 189);
	PlayerStart001->SetStartingMaterial([Shovel,Pipe,Firestone]);
	PlayerStart001->SetStartingBaseMaterial([{count=1,id=WindBag},{count=1,id=Pickaxe},{count=1,id=TeleGlove},{count=1,id=PowderKeg},{count=1,id=Blunderbuss},{count=1,id=LeadBullet},{count=1,id=DivingHelmet},{count=1,id=Bread},{count=250,id=Snow},{count=250,id=Ice}]);
	PlayerStart001->SetStartingWealth(25);
	PlayerStart001->SetViewLock(false);

	var Fish001 = CreateObjectAbove(Fish, 601, 201);
	Fish001->Unstick(7);
	var Rock001 = CreateObject(Rock, 53, 180);
	Rock001->SetPosition(53, 180);
	var Rock002 = CreateObject(Rock, 114, 227);
	Rock002->SetPosition(114, 227);
	var Rock003 = CreateObject(Rock, 39, 445);
	Rock003->SetPosition(39, 445);
	var Rock004 = CreateObject(Rock, 85, 383);
	Rock004->SetPosition(85, 383);
	var Rock005 = CreateObject(Rock, 64, 327);
	Rock005->SetPosition(64, 327);

	var Loam001 = CreateObject(Loam, 98, 311);
	Loam001->SetPosition(98, 311);

	var Metal001 = CreateObject(Metal, 97, 377);
	Metal001->SetR(-3);
	Metal001->SetPosition(97, 377);

	var Wood001 = CreateObject(Wood, 75, 173);
	Wood001->SetCon(92);
	Wood001->SetR(125);
	Wood001->SetPosition(75, 173);
	var Wood002 = CreateObject(Wood, 44, 279);
	Wood002->SetR(21);
	Wood002->SetPosition(44, 279);
	var Wood003 = CreateObject(Wood, 40, 415);
	Wood003->SetR(76);
	Wood003->SetPosition(40, 415);
	var Wood004 = CreateObject(Wood, 93, 324);
	Wood004->SetR(43);
	Wood004->SetPosition(93, 324);

	var AncientTablet001 = Fish001->CreateContents(AncientTablet);
	AncientTablet001->SetPosition(601, 198);

	var Pickaxe001 = Lorry001->CreateContents(Pickaxe);
	Pickaxe001->SetPosition(85, 263);

	var Stalactite001 = CreateObject(Stalactite, 456, 52);
	Stalactite001->SetClrModulation(0xffff2929);
	Stalactite001->MakeInvincible(false);
	Stalactite001->SetPosition(456, 52);
	var Flame001 = CreateObjectAbove(Flame, 233, 221);
	Flame001->SetCon(70);
	Flame001->SetCategory(C4D_StaticBack);
	Flame001.NoBurnDecay = true;
	var Firestone001 = CreateObject(Firestone, 30, 219);
	Firestone001->SetPosition(30, 219);
	var Firestone002 = CreateObject(Firestone, 39, 427);
	Firestone002->SetPosition(39, 427);
	var Firestone003 = CreateObject(Firestone, 31, 342);
	Firestone003->SetPosition(31, 342);
	var Firestone004 = CreateObject(Firestone, 105, 212);
	Firestone004->SetPosition(105, 212);

	var Deco_TunnelSupport001 = CreateObjectAbove(Deco_TunnelSupport, 187, 145);
	Deco_TunnelSupport001->Extend(91);
	return true;
}
