/**
	Statistics: Tower Ranking
	Monitors the progress of the different players.
	
	@author Maikel
*/


local stats;

public func Initialize()
{
	stats = {};
	return;
}

public func OnRoomAttemptStarted(id room, int by_plr)
{
	return;
}

public func OnRoomAttemptFailed(id room, int by_plr)
{
	return;
}

public func OnRoomAttemptSucceeded(id room, int by_plr)
{
	// Update ranking data for all players.
	for (var plr in GetPlayers(C4PT_User))
	{
		var plr_str = GetPlayerName(plr);
		stats[plr_str] = GetPlayerRankingInfo(plr);
	}
	return;
}

public func OnRoomAttemptJokerCollected(id room, int by_plr)
{
	return;
}

public func OnRoomAttemptTabletCollected(id room, int by_plr)
{
	return;
}

public func InitializePlayer(int plr)
{
	// Update ranking data to current progress, could have been made offline and this would be just an upload.
	var plr_str = GetPlayerName(plr);
	stats[plr_str] = GetPlayerRankingInfo(plr);
	return;
}

private func GetPlayerRankingInfo(int plr)
{
	var completed_rooms = GetPlayerCompletedRooms(plr);
	var ranking_info = {};
	for (var room in completed_rooms)
	{
		ranking_info[Format("%i", room)] = 
		{
			Difficulty = room->GetRoomDifficulty(),
			Completed = true,
			FoundTablet = HasPlayerFoundTablet(plr, room),
			FoundJoker = HasPlayerFoundJoker(plr, room)
		};
	}
	return ranking_info;
}

public func CollectStats()
{
	var round_type = FindObject(Find_ID(Statistics_TowerRanking));
	if (round_type)
		return round_type->GetStats();
	return nil;
}

public func GetStats() { return stats; }

public func IsStatistics() { return true; }