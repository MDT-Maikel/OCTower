/**
	Room Sign
	Is attached to a wall and can display a room.
	
	@author Maikel
*/

#include EnvPack_Guidepost


// Set the graphics to the given room.
public func SetRoom(id room)
{
	SetGraphics(nil, room, GFX_Overlay, GFXOV_MODE_Picture);
	SetGraphics(nil, room, GFX_Overlay + 1, GFXOV_MODE_IngamePicture);
	return;
}

// Color for messages.
public func GetColor() { return 0xffc0c0c0; }

public func Definition(proplist def)
{
	// Inscription editor props.
	if (!def.EditorProps)
		def.EditorProps = {};
	def.EditorProps.inscription = { Name="$Inscription$", Type="string", EditorHelp="$InscriptionHelp$", Set="SetInscription", Save="Inscription", Translatable=true };
}


/*-- Properties --*/

local Name = "$Name$";
local Description = "$Description$";