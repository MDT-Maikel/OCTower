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
	var plr_str = GetPlayerName(by_plr);
	stats[room_str][plr_str] = rating;
	return;
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