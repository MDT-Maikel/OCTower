/**
	Statistics: Room Duration
	Collects the time it takes for players to complete rooms.
	
	@author Maikel
*/


local stats;
local current_room;
local room_time;
local room_plr;

public func Initialize()
{
	stats = [];
	return;
}

public func OnRoomAttemptStarted(id room, int by_plr)
{
	current_room = room;
	room_plr = by_plr;
	room_time = FrameCounter();
	return;
}

public func OnRoomAttemptFailed(id room, int by_plr)
{
	current_room = nil;
	room_plr = nil;
	return;
}

public func OnRoomAttemptSucceeded(id room, int by_plr)
{
	if (current_room == room && room_plr == by_plr)
	{
		var duration = FrameCounter() - room_time;
		PushBack(stats, {Room = Format("%i", current_room), Duration = duration});
		current_room = nil;
		room_plr = nil;
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

public func CollectStats()
{
	var round_type = FindObject(Find_ID(Statistics_RoomDuration));
	if (round_type)
		return round_type->GetStats();
	return nil;
}

public func GetStats() { return stats; }

public func IsStatistics() { return true; }