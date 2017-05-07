// Store additional properties for objects.

global func SaveScenarioObject(proplist props)
{
	// Store the IsKeyContainer property.
	if (this.IsKeyContainer)
		props->AddSet("IsKeyContainer", this, "IsKeyContainer", this.IsKeyContainer);
	return _inherited(props, ...);
}