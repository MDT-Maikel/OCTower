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

// Sets the graphics to a contest reward (place = "Gold", "Silver", or "Bronze").
public func SetReward(string place)
{
	SetGraphics(place, Icon_QuestionMark, GFX_Overlay, GFXOV_MODE_Picture);
	SetGraphics(place, Icon_QuestionMark, GFX_Overlay + 1, GFXOV_MODE_IngamePicture);
	var scale = 800;
	SetObjDrawTransform(scale, 0, 0, 0, scale, 0, GFX_Overlay);
	SetObjDrawTransform(scale, 0, 0, 0, scale, 0, GFX_Overlay + 1);
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