/* Automatically created objects file */

func InitializeObjects()
{
	CreateObjectAbove(RoomEntrance, 609, 303);

	var StoneDoor001 = CreateObject(StoneDoor, 524, 258);
	StoneDoor001->SetComDir(COMD_Up);

	var SpinWheel001 = CreateObjectAbove(SpinWheel, 430, 320);
	SpinWheel001->SetStoneDoor(StoneDoor001);
	return true;
}
