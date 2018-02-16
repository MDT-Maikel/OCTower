/* Automatically created objects file */

func InitializeObjects()
{
	CreateObjectAbove(Tree_Coniferous2_Burned, 306, 428);

	CreateObjectAbove(Tree_Coniferous3_Burned, 366, 429);
	CreateObjectAbove(Tree_Coniferous3_Burned, 502, 430);

	CreateObjectAbove(Tree_Coniferous4_Burned, 413, 425);
	CreateObjectAbove(Tree_Coniferous4_Burned, 488, 425);

	var Trunk001 = CreateObject(Trunk, 267, 335);
	Trunk001->SetCon(92);
	Trunk001->SetR(110);
	Trunk001->SetPosition(267, 335);
	var Trunk002 = CreateObject(Trunk, 559, 172);
	Trunk002->SetCon(127);
	Trunk002->SetR(-108);
	Trunk002->SetPosition(559, 172);

	var BoilingAcid001 = CreateObject(BoilingAcid, 51, 375);
	BoilingAcid001->SetPosition(51, 375);
	BoilingAcid001->SetIntensity(120);
	var RoomEntrance001 = CreateObjectAbove(RoomEntrance, 124, 392);
	RoomEntrance001->SetColor(0xff32c832);

	var StoneDoor001 = CreateObject(StoneDoor, 92, 372);
	StoneDoor001->SetComDir(COMD_Down);
	StoneDoor001->SetPosition(92, 372);
	StoneDoor001->SetPlrViewOnSignalChange(true);
	var StoneDoor002 = CreateObject(StoneDoor, 204, 372);
	StoneDoor002->SetComDir(COMD_Down);
	StoneDoor002->SetPosition(204, 372);
	StoneDoor002->SetPlrViewOnSignalChange(true);

	var RoomExit001 = CreateObjectAbove(RoomExit, 124, 120);
	RoomExit001->SetColor(0xffc83232);

	var Column001 = CreateObject(Column, 276, 425);
	Column001->SetPosition(276, 425);
	var Switch001 = CreateObjectAbove(Switch, 172, 392);
	Switch001->SetSwitchTarget(StoneDoor002);
	Switch001->SetSwitchDir(1);
	Switch001->SetActions({Actions=[{Door={Function="object_constant",Value=StoneDoor001},Function="open_door"},{Door={Function="object_constant",Value=StoneDoor002},Function="open_door"},{Function="Action_script",Script={Function="string_constant",Value={Function="Translate",US="\"ShakeFree(84, 440 - 64, 20)\""}}}],Function="sequence"}, {Actions=[{Door={Function="object_constant",Value=StoneDoor002},Function="close_door"},{Door={Function="object_constant",Value=StoneDoor001},Function="close_door"}],Function="sequence"});

	CreateObjectAbove(Clonk_Grave, 335, 423);
	CreateObjectAbove(Clonk_Grave, 347, 423);
	CreateObjectAbove(Clonk_Grave, 325, 423);

	var PlayerStart001 = CreateObject(PlayerStart, 144, 381);
	PlayerStart001->SetPosition(144, 381);
	PlayerStart001->SetStartingMaterial([]);
	PlayerStart001->SetClonkMaxEnergy(10);
	PlayerStart001->SetViewLock(false);
	PlayerStart001->SetZoomSet(500);
	var Boompack001 = CreateObjectAbove(Boompack, 460, 421);
	Boompack001->Unstick(7);

	var AncientTablet001 = CreateObject(AncientTablet, 74, 78);
	AncientTablet001->SetR(157);
	AncientTablet001->SetPosition(74, 78);
	AncientTablet001->Unstick(7);

	var TeleGlove001 = CreateObject(TeleGlove, 604, 418);
	TeleGlove001->SetPosition(604, 418);

	var Trunk003 = CreateObject(Trunk, 596, 400);
	Trunk003->SetCon(131);
	Trunk003->SetR(-30);
	Trunk003.Plane = 500;
	Trunk003->SetPosition(596, 400);
	var Firestone001 = CreateObject(Firestone, 75, 81);
	Firestone001->SetPosition(75, 81);
	Firestone001->Unstick(7);
	var Firestone002 = CreateObjectAbove(Firestone, 189, 223);
	Firestone002->Unstick(7);
	var Firestone003 = CreateObjectAbove(Firestone, 206, 222);
	Firestone003->Unstick(7);
	var Firestone004 = CreateObjectAbove(Firestone, 211, 223);
	Firestone004->Unstick(7);
	var Firestone005 = CreateObjectAbove(Firestone, 123, 263);
	Firestone005->Unstick(7);
	var Firestone006 = CreateObjectAbove(Firestone, 135, 262);
	Firestone006->Unstick(7);
	var Firestone007 = CreateObjectAbove(Firestone, 193, 223);
	Firestone007->Unstick(7);
	var Firestone008 = CreateObjectAbove(Firestone, 211, 223);
	Firestone008->Unstick(7);
	var Firestone009 = CreateObjectAbove(Firestone, 199, 222);
	Firestone009->Unstick(7);
	var Firestone010 = CreateObjectAbove(Firestone, 210, 303);
	Firestone010->Unstick(7);
	var Firestone011 = CreateObjectAbove(Firestone, 193, 303);
	Firestone011->Unstick(7);
	return true;
}
