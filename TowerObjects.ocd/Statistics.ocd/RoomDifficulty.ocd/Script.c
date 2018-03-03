/**
	Statistics: Room Difficulty
	Collects the difficulty each player has rated a room.
	
	@author Maikel
*/


local stats;

public func Initialize()
{
	stats = {};
	return;
}

public func OnRoomDifficultyChanged(id room, int by_plr, int difficulty)
{
	// Update the difficulty of this player for the given room.
	var room_str = Format("%i", room);
	if (!stats[room_str])
		stats[room_str] = {};
	var plr_str = GetPlayerRoomDifficultyID(by_plr);
	stats[room_str][plr_str] = difficulty;
	return;
}

public func GetPlayerRoomDifficultyID(int plr)
{
	// Get stored difficulty ID.
	var rating_id = GetPlrExtraData(plr, "OCTowerPlayerRoomDifficultyID");
	// Generate a difficulty ID if there is no one yet.
	if (!rating_id)
	{
		// Create a random ID with the methods available to us.
		rating_id = Format("%d%d%d%d", Random(2147483647), Random(2147483647), Random(2147483647), Random(2147483647));
		SetPlrExtraData(plr, "OCTowerPlayerRoomDifficultyID", rating_id);
	}
	return rating_id;
}

public func CollectStats()
{
	var round_type = FindObject(Find_ID(Statistics_RoomDifficulty));
	if (round_type)
		return round_type->GetStats();
	return nil;
}

public func GetStats() { return stats; }

public func IsStatistics() { return true; }

// Don't save in scenarios.
public func SaveScenarioObject() { return false; }
