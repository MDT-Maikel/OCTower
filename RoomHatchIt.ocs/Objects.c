/* Automatically created objects file */

func InitializeObjects()
{
	var EnvPack_FenceRustic001 = CreateObjectAbove(EnvPack_FenceRustic, 471, 249);
	EnvPack_FenceRustic001.Plane = 50;

	CreateObjectAbove(EnvPack_Bag, 478, 248);
	CreateObjectAbove(EnvPack_Bag, 471, 249);
	CreateObjectAbove(EnvPack_Bag, 462, 248);
	CreateObjectAbove(EnvPack_Bag, 466, 249);
	var Hatch001 = CreateObject(Hatch, 316, 314);
	Hatch001->SetCategory(C4D_StaticBack);
	Hatch001->SetPosition(316, 314);

	var HatchBasement001 = CreateObjectAbove(HatchBasement, 316, 320);
	HatchBasement001->SetParent(Hatch001);

	var Hatch002 = CreateObject(Hatch, 509, 122);
	Hatch002->SetCategory(C4D_StaticBack);
	Hatch002->SetPosition(509, 122);

	var HatchBasement002 = CreateObjectAbove(HatchBasement, 509, 128);
	HatchBasement002->SetParent(Hatch002);

	var Hatch003 = CreateObject(Hatch, 508, 74);
	Hatch003->SetCategory(C4D_StaticBack);
	Hatch003->SetPosition(508, 74);

	var HatchBasement003 = CreateObjectAbove(HatchBasement, 508, 80);
	HatchBasement003->SetParent(Hatch003);

	var Hatch004 = CreateObject(Hatch, 509, 43);
	Hatch004->SetCategory(C4D_StaticBack);
	Hatch004->SetPosition(509, 43);

	var HatchBasement004 = CreateObjectAbove(HatchBasement, 509, 49);
	HatchBasement004->SetParent(Hatch004);

	var Hatch005 = CreateObject(Hatch, 125, 43);
	Hatch005->SetCategory(C4D_StaticBack);
	Hatch005->SetPosition(125, 43);

	var HatchBasement005 = CreateObjectAbove(HatchBasement, 125, 49);
	HatchBasement005->SetParent(Hatch005);

	var Hatch006 = CreateObject(Hatch, 85, 43);
	Hatch006->SetCategory(C4D_StaticBack);
	Hatch006->SetPosition(85, 43);

	var HatchBasement006 = CreateObjectAbove(HatchBasement, 85, 49);
	HatchBasement006->SetParent(Hatch006);

	var Hatch007 = CreateObject(Hatch, 45, 43);
	Hatch007->SetCategory(C4D_StaticBack);
	Hatch007->SetPosition(45, 43);

	var HatchBasement007 = CreateObjectAbove(HatchBasement, 45, 49);
	HatchBasement007->SetParent(Hatch007);
	var HatchBasement008 = CreateObjectAbove(HatchBasement, 389, 49);
	HatchBasement008->SetParent(Hatch007);

	var Hatch008 = CreateObject(Hatch, 508, 251);
	Hatch008->SetCategory(C4D_StaticBack);
	Hatch008->SetPosition(508, 251);

	var HatchBasement009 = CreateObjectAbove(HatchBasement, 508, 257);
	HatchBasement009->SetParent(Hatch008);

	var RoomEntrance001 = CreateObjectAbove(RoomEntrance, 153, 120);
	RoomEntrance001->SetColor(0xff32c832);

	var RoomExit001 = CreateObjectAbove(RoomExit, 121, 335);
	RoomExit001->SetColor(0xffc83232);

	var Hatch009 = CreateObject(Hatch, 389, 43);
	Hatch009->SetCategory(C4D_StaticBack);
	Hatch009->SetPosition(389, 43);

	var FloorSwitch001 = CreateObject(FloorSwitch, 596, 122);
	FloorSwitch001->SetPosition(596, 122);
	FloorSwitch001->SetActions(nil, {Actions=[{Context={Function="object_constant",Value=Hatch009},Function="Action_script",Script={Function="string_constant",Value="DoOpen()"}},{Context={Function="object_constant",Value=Hatch004},Function="Action_script",Script={Function="string_constant",Value="DoOpen()"}},{Context={Function="object_constant",Value=Hatch002},Function="Action_script",Script={Function="string_constant",Value="ScheduleCall(this, \"DoOpen\", 18, 0)"}},{Context={Function="object_constant",Value=Hatch008},Function="Action_script",Script={Function="string_constant",Value="ScheduleCall(this, \"DoOpen\", 40, 0)"}}],Function="sequence"});

	CreateObjectAbove(Ruin_ChemicalLab, 306, 120);

	CreateObjectAbove(Ruin_WoodenCabin, 570, 247);

	var Elevator001 = CreateObjectAbove(Elevator, 68, 336);
	Elevator001->SetDir(DIR_Right);
	Elevator001->CreateShaft(1);
	Elevator001->SetCasePosition(325);
	var Switch001 = CreateObjectAbove(Switch, 78, 120);
	Switch001->SetSwitchDir(1);
	Switch001->SetActions({Actions=[{Context={Function="object_constant",Value=Hatch006},Function="Action_script",Script={Function="string_constant",Value="DoOpen()"}},{Context={Function="object_constant",Value=Hatch007},Function="Action_script",Script={Function="string_constant",Value="DoOpen()"}},{Context={Function="object_constant",Value=Hatch005},Function="Action_script",Script={Function="string_constant",Value="DoOpen()"}},{Context={Function="action_object"},Function="Action_script",Script={Function="string_constant",Value="ScheduleCall(this, \"SetAction\", 14, 0, \"SwitchRight\")"}}],Function="sequence"});
	var Switch002 = CreateObjectAbove(Switch, 364, 120);
	Switch002->SetSwitchDir(1);
	Switch002->SetActions({Actions=[{Context={Function="object_constant",Value=Hatch003},Function="Action_script",Script={Function="string_constant",Value="DoOpen()"}},{Context={Function="action_object"},Function="Action_script",Script={Function="string_constant",Value="ScheduleCall(this, \"SetAction\", 14, 0, \"SwitchRight\")"}}],Function="sequence"});
	var Switch003 = CreateObjectAbove(Switch, 267, 456);
	Switch003->SetSwitchDir(1);
	Switch003->SetActions({Actions=[{Function="Action_script",Script={Function="string_constant",Value="ShakeFree(316, 316, 20)"}},{Context={Function="object_constant",Value=Hatch001},Function="Action_script",Script={Function="string_constant",Value="DoOpen()"}},{Context={Function="action_object"},Function="Action_script",Script={Function="string_constant",Value="ScheduleCall(this, \"SetAction\", 14, 0, \"SwitchRight\")"}}],Function="sequence"});

	var PlayerStart001 = CreateObject(PlayerStart, 132, 109);
	PlayerStart001->SetPosition(132, 109);
	PlayerStart001->SetStartingMaterial([]);
	PlayerStart001->SetViewLock(false);

	var Metal001 = CreateObject(Metal, 320, 243);
	Metal001->SetR(-9);
	Metal001->SetRDir(-2);
	Metal001->SetPosition(320, 243);
	CreateObjectAbove(Metal, 339, 245);
	var Metal002 = CreateObject(Metal, 600, 161);
	Metal002->SetPosition(600, 161);

	var TeleGlove001 = CreateObjectAbove(TeleGlove, 86, 40);
	TeleGlove001->Unstick(7);

	var Dynamite001 = CreateObject(Dynamite, 252, 98);
	Dynamite001->SetR(90);
	Dynamite001->SetPosition(252, 98);
	var Dynamite002 = CreateObject(Dynamite, 326, 211);
	Dynamite002->SetR(-178);
	Dynamite002->SetPosition(326, 211);
	var Dynamite003 = CreateObject(Dynamite, 590, 89);
	Dynamite003->SetR(172);
	Dynamite003->SetPosition(590, 89);
	var Dynamite004 = CreateObject(Dynamite, 605, 74);
	Dynamite004->SetR(-21);
	Dynamite004->SetPosition(605, 74);
	var Dynamite005 = CreateObject(Dynamite, 589, 59);
	Dynamite005->SetR(170);
	Dynamite005->SetPosition(589, 59);
	var Dynamite006 = CreateObject(Dynamite, 601, 54);
	Dynamite006->SetR(84);
	Dynamite006->SetPosition(601, 54);
	var Dynamite007 = CreateObject(Dynamite, 590, 37);
	Dynamite007->SetR(-58);
	Dynamite007->SetPosition(590, 37);
	var Dynamite008 = CreateObject(Dynamite, 604, 39);
	Dynamite008->SetR(-102);
	Dynamite008->SetPosition(604, 39);
	var Dynamite009 = CreateObject(Dynamite, 334, 205);
	Dynamite009->SetR(90);
	Dynamite009->SetPosition(334, 205);

	var Blunderbuss001 = CreateObject(Blunderbuss, 154, 36);
	Blunderbuss001->SetR(-14);
	Blunderbuss001->SetPosition(154, 36);

	var LeadBullet001 = Blunderbuss001->CreateContents(LeadBullet);
	LeadBullet001->SetPosition(155, 37);

	var MetalBarrel001 = CreateObjectAbove(MetalBarrel, 125, 40);
	MetalBarrel001->SetColor(0xff000000);
	MetalBarrel001->Unstick(7);

	var Hammer001 = CreateObject(Hammer, 330, 244);
	Hammer001->SetR(56);
	Hammer001->SetRDir(-8);
	Hammer001->MakeInvincible(false);
	Hammer001->SetPosition(330, 244);
	Hammer001->Unstick(7);

	var PowderKeg001 = CreateObjectAbove(PowderKeg, 596, 117);
	PowderKeg001->Unstick(7);
	var PowderKeg002 = CreateObject(PowderKeg, 610, 87);
	PowderKeg002->SetR(-87);
	PowderKeg002->SetPosition(610, 87);
	var PowderKeg003 = CreateObject(PowderKeg, 579, 78);
	PowderKeg003->SetR(-101);
	PowderKeg003->SetPosition(579, 78);
	var PowderKeg004 = CreateObject(PowderKeg, 613, 59);
	PowderKeg004->SetR(-82);
	PowderKeg004->SetPosition(613, 59);
	var PowderKeg005 = CreateObject(PowderKeg, 579, 56);
	PowderKeg005->SetR(-91);
	PowderKeg005->SetPosition(579, 56);

	var AncientTablet001 = CreateObject(AncientTablet, 509, 43);
	AncientTablet001->SetPosition(509, 43);
	AncientTablet001->Unstick(7);

	var Shield001 = CreateObject(Shield, 599, 78);
	Shield001->SetPosition(599, 78);
	var Shield002 = CreateObject(Shield, 587, 61);
	Shield002->SetR(46);
	Shield002->SetPosition(587, 61);
	var Shield003 = CreateObject(Shield, 603, 33);
	Shield003->SetPosition(603, 33);

	var Helmet001 = CreateObject(Helmet, 603, 54);
	Helmet001->SetPosition(603, 54);
	var Helmet002 = CreateObject(Helmet, 589, 77);
	Helmet002->SetR(55);
	Helmet002->SetPosition(589, 77);
	var Helmet003 = CreateObject(Helmet, 586, 42);
	Helmet003->SetPosition(586, 42);

	var DynamiteBox001 = CreateObject(DynamiteBox, 579, 67);
	DynamiteBox001->SetR(-23);
	DynamiteBox001->SetPosition(579, 67);
	var DynamiteBox002 = CreateObject(DynamiteBox, 613, 73);
	DynamiteBox002->SetR(35);
	DynamiteBox002->SetPosition(613, 73);
	var Firestone001 = CreateObjectAbove(Firestone, 46, 40);
	Firestone001->Unstick(7);
	var Firestone002 = CreateObjectAbove(Firestone, 389, 40);
	Firestone002->Unstick(7);
	CreateObjectAbove(Firestone, 384, 41);
	CreateObjectAbove(Firestone, 393, 41);
	var Firestone003 = CreateObject(Firestone, 388, 41);
	Firestone003->SetPosition(388, 41);
	var Firestone004 = CreateObjectAbove(Firestone, 388, 40);
	Firestone004->Unstick(7);
	CreateObjectAbove(Firestone, 390, 41);
	CreateObjectAbove(Firestone, 386, 41);

	var Trunk001 = CreateObject(Trunk, 458, 108);
	Trunk001->SetCon(126);
	Trunk001->SetR(95);
	Trunk001.Plane = 550;
	Trunk001->SetPosition(458, 108);
	var Trunk002 = CreateObject(Trunk, 590, 171);
	Trunk002->SetCon(89);
	Trunk002->SetR(-133);
	Trunk002.Plane = 550;
	Trunk002->SetPosition(590, 171);

	var Deco_TunnelSupport001 = CreateObjectAbove(Deco_TunnelSupport, 171, 121);
	Deco_TunnelSupport001->Extend(78);
	var Deco_TunnelSupport002 = CreateObjectAbove(Deco_TunnelSupport, 346, 456);
	Deco_TunnelSupport002->Extend(62);
	var Deco_TunnelSupport003 = CreateObjectAbove(Deco_TunnelSupport, 437, 249);
	Deco_TunnelSupport003->Extend(38);
	var Deco_TunnelSupport004 = CreateObjectAbove(Deco_TunnelSupport, 561, 121);
	Deco_TunnelSupport004->Extend(2);
	return true;
}
