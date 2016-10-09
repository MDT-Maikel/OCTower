// Define certain properties for all objects via the editor base.

#appendto EditorBase

public func Definition(proplist def)
{
	var result = _inherited(def, ...);
	// Show the MakeRoomPlayerOwner property, which sets the owner of this object to the player attempting the room.
	def.EditorProps.MakeRoomPlayerOwner = { Type = "bool", Name = "$MakeRoomPlayerOwner$", EditorHelp = "$MakeRoomPlayerOwnerHelp$" }; 
	return result;
}