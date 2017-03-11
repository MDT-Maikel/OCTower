// Let statistics objects survive section changes.

global func LoadScenarioSection(string sect)
{
	// Get all statistics objects.
	var statistics = FindObjects(Find_Func("IsStatistics"));
	// Disable all statistics objects.
	for (var obj in statistics)
		obj->SetObjectStatus(C4OS_INACTIVE);
	// Load scenario section.
	var res = inherited(sect, ...);
	// Enable all statistics objects.
	for (var obj in statistics)
		obj->SetObjectStatus(C4OS_NORMAL);
	return res;
}