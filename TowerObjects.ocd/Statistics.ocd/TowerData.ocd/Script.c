/**
	Statistics: Tower Data
	Some general data for the tower.
	
	@author Maikel
*/


local stats;

public func Initialize()
{
	stats = {};
	// Store the version of the tower.
	stats["TowerVersion"] = GetTowerVersion();
	return;
}

public func CollectStats()
{
	var round_type = FindObject(Find_ID(Statistics_TowerData));
	if (round_type)
		return round_type->GetStats();
	return nil;
}

public func GetStats() { return stats; }

public func IsStatistics() { return true; }

// Don't save in scenarios.
public func SaveScenarioObject() { return false; }
