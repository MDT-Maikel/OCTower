// Enables value overloads per room.

#appendto Library_Vendor

// Returns the value of the object if bought in this base.
public func GetBuyValue(id item)
{
	return GetRoomAlternativeValue(item) ?? _inherited(item, ...);
}

// Returns the value of the object if sold in this base.
public func GetSellValue(object item)
{
	return GetRoomAlternativeValue(item) ?? _inherited(item, ...);
}

private func GetRoomAlternativeValue(id item)
{
	var room_base = FindObject(Find_Func("IsRoom"));
	if (!room_base)
		return nil;
	var alt_values = room_base->GetValueOverloads();
	if (GetType(alt_values) != C4V_Array)
		return nil;
	for (var alt_value in alt_values)
		if (alt_value.type == item)
			return alt_value.value;
	return nil;
}