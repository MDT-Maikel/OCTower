/**
	Statistics: Room Rating
	Collects the rating each player has given a room.
	
	@author Maikel
*/


local stats;

public func Initialize()
{
	stats = {};
	return;
}

public func OnRoomRatingChanged(id room, int by_plr, int rating)
{
	// Update the rating of this player for the given room.
	var room_str = Format("%i", room);
	if (!stats[room_str])
		stats[room_str] = {};
	var plr_str = GetPlayerRoomRatingID(by_plr);
	stats[room_str][plr_str] = rating;
	return;
}

public func GetPlayerRoomRatingID(int plr)
{
	// Get stored rating ID.
	var rating_id = GetPlrExtraData(plr, "OCTowerPlayerRoomRatingID");
	// Generate a rating ID if there is no one yet.
	if (!rating_id)
	{
		// Create a random ID with the methods available to us.
		rating_id = Format("%d%d%d%d", Random(2147483647), Random(2147483647), Random(2147483647), Random(2147483647));
		SetPlrExtraData(plr, "OCTowerPlayerRoomRatingID", rating_id);
	}
	return rating_id;
}

public func CollectStats()
{
	var round_type = FindObject(Find_ID(Statistics_RoomRating));
	if (round_type)
		return round_type->GetStats();
	return nil;
}

public func GetStats() { return stats; }

public func IsStatistics() { return true; }