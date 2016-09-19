// Define SaveScenarioObject for some definitions so that it can be overloaded to prevent saving in template rooms.
// Overload by writing obj.SaveScenarioObject = Global.NoSave;

#appendto Rule_Restart

public func SaveScenarioObject()
{
	return _inherited(...);
}