// Store additional properties for objects in the tower rooms.

global func SaveScenarioObject(proplist props)
{
	// Store the MakeRoomPlayerOwner property, which sets the owner of this object to the player attempting the room.
	if (this.MakeRoomPlayerOwner)
		props->AddSet("MakeRoomPlayerOwner", this, "MakeRoomPlayerOwner", this.MakeRoomPlayerOwner);
	return _inherited(props, ...);
}