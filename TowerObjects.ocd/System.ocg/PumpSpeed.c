// Change the pump speed.

#appendto Pump

public func GetPumpSpeed()
{
	// Find the room control object.
	var room_control = FindObject(Find_Func("IsRoom")); 
	if (room_control)
	{
		var alt_speed = room_control->GetRoomPumpSpeed();
		if (alt_speed != nil)
			return alt_speed;	
	}
	// Pump at normal speed.
	return _inherited(...);
}