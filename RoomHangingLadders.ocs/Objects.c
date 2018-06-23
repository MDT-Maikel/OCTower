/* Automatically created objects file */

func InitializeObjects()
{
	var Sequence001 = CreateObject(Sequence, 206, 473);
	Sequence001->SetCheckInterval(60);
	Sequence001->SetPosition(206, 473);
	Sequence001->SetTrigger({Interval=60,Trigger="interval"}, 0);
	Sequence001->SetCondition({Function="bool_constant",Value=true});
	Sequence001->SetAction({Actions=[{Function="create_object",ID={Function="def_constant",Value=Firestone},Rotation={Function="int_constant",Value=0},SpeedR={Function="int_constant",Value=0},SpeedX={Function="int_constant",Value=0},SpeedY={Function="int_constant",Value=-74}}],Function="sequence"}, nil);
	var Sequence002 = CreateObject(Sequence, 252, 473);
	Sequence002->SetCheckInterval(60);
	Sequence002->SetPosition(252, 473);
	Sequence002->SetTrigger({Interval=60,Trigger="interval"}, 20);
	Sequence002->SetCondition({Function="bool_constant",Value=true});
	Sequence002->SetAction({Actions=[{Function="create_object",ID={Function="def_constant",Value=Firestone},Rotation={Function="int_constant",Value=0},SpeedR={Function="int_constant",Value=0},SpeedX={Function="int_constant",Value=0},SpeedY={Function="int_constant",Value=-74}}],Function="sequence"}, nil);
	var Sequence003 = CreateObject(Sequence, 296, 473);
	Sequence003->SetCheckInterval(60);
	Sequence003->SetPosition(296, 473);
	Sequence003->SetTrigger({Interval=60,Trigger="interval"}, 40);
	Sequence003->SetCondition({Function="bool_constant",Value=true});
	Sequence003->SetAction({Actions=[{Function="create_object",ID={Function="def_constant",Value=Firestone},Rotation={Function="int_constant",Value=0},SpeedR={Function="int_constant",Value=0},SpeedX={Function="int_constant",Value=0},SpeedY={Function="int_constant",Value=-74}}],Function="sequence"}, nil);

	var JetStream001 = CreateObject(JetStream, 505, -1);
	JetStream001->Create(0, 0, 16, 160, nil, 20, 92);
	JetStream001->SetPosition(505, -1);

	var BoilingLava001 = CreateObject(BoilingLava, 17, 370);
	BoilingLava001->SetPosition(17, 370);
	BoilingLava001->SetIntensity(5);
	BoilingLava001->SetArea(Shape->Rectangle(-2, 389, 643, 94));
	var RoomExit001 = CreateObjectAbove(RoomExit, 611, 67);
	RoomExit001->SetCategory(C4D_StaticBack);
	RoomExit001->SetColor(0xffc83232);

	var RoomEntrance001 = CreateObjectAbove(RoomEntrance, 22, 67);
	RoomEntrance001->SetCategory(C4D_StaticBack);
	RoomEntrance001->SetColor(0xff32c832);
	var MetalLadder001 = CreateObjectAbove(MetalLadder, 46, 164);
	MetalLadder001->SetLength(29);
	var MetalLadder002 = CreateObjectAbove(MetalLadder, 121, 317);
	MetalLadder002->SetLength(23);
	var MetalLadder003 = CreateObjectAbove(MetalLadder, 186, 387);
	MetalLadder003->SetLength(6);
	var MetalLadder004 = CreateObjectAbove(MetalLadder, 230, 387);
	MetalLadder004->SetLength(6);
	var MetalLadder005 = CreateObjectAbove(MetalLadder, 320, 387);
	MetalLadder005->SetLength(6);
	var MetalLadder006 = CreateObjectAbove(MetalLadder, 275, 387);
	MetalLadder006->SetLength(6);
	var MetalLadder007 = CreateObjectAbove(MetalLadder, 371, 231);
	MetalLadder007->SetLength(45);
	var MetalLadder008 = CreateObjectAbove(MetalLadder, 420, 130);
	MetalLadder008->SetLength(20);
	var MetalLadder009 = CreateObjectAbove(MetalLadder, 586, 107);
	MetalLadder009->SetLength(14);
	var MetalLadder010 = CreateObjectAbove(MetalLadder, 636, 106);
	MetalLadder010->SetLength(14);

	CreateObjectAbove(Airship_Burnt, 125, 76);

	var PlayerStart001 = CreateObject(PlayerStart, 66, 57);
	PlayerStart001->SetPosition(66, 57);
	PlayerStart001->SetStartingMaterial([]);
	PlayerStart001->SetStartingBaseMaterial([]);
	PlayerStart001->SetClonkMaxEnergy(10);
	PlayerStart001->SetViewLock(false);

	var Clonk001 = CreateObjectAbove(Clonk, 631, 120);
	Clonk001->SetDir(DIR_Right);
	Clonk001->SetColor(0xefef40);
	Clonk001->SetMeshMaterial("Clonk_Carpenter", 0);
	Clonk001->Unstick(7);
	Clonk001->SetAlternativeSkin("Carpenter");

	var Dialogue001 = Clonk001->SetDialogue("Editor",true);
	Dialogue001->SetUserDialogue({Actions=[{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Ich hange hier schon seit Tagen herum, wie komme aus diesen Raum heraus?",Function="Translate",US="I am hanging here for days, how do I get out of this room?"}}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="triggering_clonk"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Hab doch auch kein Ahnung, Halte durch!",Function="Translate",US="I am clueless as well, just hang on!"}}},{AfterMessage="next",Function="message",Options=[],Speaker={Function="npc"},TargetPlayers={Function="triggering_player_list"},Text={Function="string_constant",Value={DE="Ich bin fertig, ich werde gleich loslassen müssen.",Function="Translate",US="I am pumped, I'd need to let go any minute."}}}],Function="sequence"}, nil);

	var Wood001 = CreateObject(Wood, 330, 300);
	Wood001->SetR(47);
	Wood001->SetClrModulation(0xff5e4041);
	Wood001->MakeInvincible(false);
	Wood001->SetPosition(330, 300);
	var Wood002 = CreateObject(Wood, 325, 299);
	Wood002->SetCon(90);
	Wood002->SetR(138);
	Wood002->SetClrModulation(0xff5e4041);
	Wood002->MakeInvincible(false);
	Wood002->SetPosition(325, 299);
	Wood002->Unstick(7);
	var Wood003 = CreateObject(Wood, 328, 299);
	Wood003->SetR(85);
	Wood003->SetClrModulation(0xff5e4041);
	Wood003->MakeInvincible(false);
	Wood003->SetPosition(328, 299);

	var Crate001 = CreateObjectAbove(Crate, 151, 397);
	Crate001->SetClrModulation(0xff707070);

	var AncientTablet001 = Crate001->CreateContents(AncientTablet);
	AncientTablet001->SetPosition(151, 392);

	var WallKit001 = CreateObjectAbove(WallKit, 173, 303);
	WallKit001->SetStackCount(1);

	var WindBag001 = CreateObject(WindBag, 301, 171);
	WindBag001->SetR(-45);
	WindBag001->SetPosition(301, 171);

	var Flame001 = CreateObjectAbove(Flame, 328, 306);
	Flame001.NoBurnDecay = true;

	var Trunk001 = CreateObjectAbove(Trunk, 176, 305);
	Trunk001.Plane = 501;
	Trunk001->MakeInvincible(false);

	var Deco_TunnelSupport001 = CreateObjectAbove(Deco_TunnelSupport, 20, 53);
	Deco_TunnelSupport001->Extend(35);
	Deco_TunnelSupport001->SetObjDrawTransform(1000, 0, 0, 0, -1000, 0);
	var Deco_TunnelSupport002 = CreateObjectAbove(Deco_TunnelSupport, 610, 53);
	Deco_TunnelSupport002->Extend(35);
	Deco_TunnelSupport002->SetObjDrawTransform(1000, 0, 0, 0, -1000, 0);
	return true;
}
