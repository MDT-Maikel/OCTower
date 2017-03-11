/**
	Statistics: Room Attempts
	Amount of successful and failed attempts per room.
	
	@author Maikel
*/


local stats;
local current_room;
local room_plr;

public func Initialize()
{
	stats = {};
	return;
}

public func OnRoomAttemptStarted(id room, int by_plr)
{
	current_room = room;
	room_plr = by_plr;
	return;
}

public func OnRoomAttemptFailed(id room, int by_plr)
{
	if (current_room == room && room_plr == by_plr)
	{
		var room_str = Format("%i", room);
		if (!stats[room_str])
			stats[room_str] = {};
		if (!stats[room_str].FailedCnt)
			stats[room_str].FailedCnt = 1;
		else
			stats[room_str].FailedCnt++;
		current_room = nil;
		room_plr = nil;
	}
	return;
}

public func OnRoomAttemptSucceeded(id room, int by_plr)
{
	if (current_room == room && room_plr == by_plr)
	{
		var room_str = Format("%i", room);
		if (!stats[room_str])
			stats[room_str] = {};
		if (!stats[room_str].SuccessCnt)
			stats[room_str].SuccessCnt = 1;
		else
			stats[room_str].SuccessCnt++;
		current_room = nil;
		room_plr = nil;
	}
	return;
}

public func CollectStats()
{
	var round_type = FindObject(Find_ID(Statistics_RoomAttempts));
	if (round_type)
		return round_type->GetStats();
	return nil;
}

public func GetStats() { return stats; }

public func IsStatistics() { return true; }