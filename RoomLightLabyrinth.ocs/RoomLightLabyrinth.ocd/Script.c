/**
	Room Control
	This object's script contains the properties and the functions of the room.

	@author See contents of GetRoomAuthor().
*/

#include RoomBase


/*-- Room Properties --*/
// Overload these properties if needed.

// The name of the room, appears in menus and the room start.
// Add both an English and German version.
public func GetRoomName() { return "$RoomName$"; }

// The description of the room, appears in menus and the room start.
// Add both an English and German version.
public func GetRoomDescription() { return "$RoomDescription$"; }

// The name of the author of the room, separate multiple authors with comma's or & (like "John, Jane & Wipf").
// Names may not contain comma's or &.
public func GetRoomAuthor() { return "Maikel"; }

// The map section that needs to be loaded for this room, usually equal to the name of the room.
public func GetRoomSection() { return "LightLabyrinth"; }

// A unique ID for the room which is used for saving player progress. It must be two characters
// long which can be chosen from the set [A-Za-z].
public func GetRoomID() { return "LL"; }

// The difficulty of this room, ranges from 0 to 999.
public func GetRoomDifficulty() { return 40; }

// Whether or not the room has an ancient tablet which can be found.
public func HasTablet() { return true; }

// Whether or not the room has a joker which can be found.
public func HasJoker() { return false; }

// Hints and tricks shown in the help menu when currently playing this room.
// Pass a list of strings which represent the hints, each is shown separately.
public func GetRoomHints() { return nil; }


/*-- Room Scripts --*/

// The labyrinth map has step size 24.
static const LabyrinthMap = new AStarMap { step = 24 };

// Called when the room is initialized.
// Here you can create effects and extra objects that are needed for the room.
public func OnRoomInit()
{	
	// Get room size.
	var wdt = LandscapeWidth();
	var hgt = LandscapeHeight();
	
	// Create room entrance, exit and tablet.
	var attempts = 0;
	var entrance_x, entrance_y, exit_x, exit_y, tablet_x, tablet_y;
	while (attempts <= Sqrt(wdt**2 + hgt**2))
	{
		attempts++;
		entrance_x = GetRandomPosition();
		entrance_y = GetRandomPosition(true);
		exit_x = GetRandomPosition();
		exit_y = GetRandomPosition(true);
		tablet_x = GetRandomPosition();
		tablet_y = GetRandomPosition(true);
		if (!GBackSolid(AbsX(entrance_x), AbsY(entrance_y) + 24) || !GBackSolid(AbsX(exit_x), AbsY(exit_y) + 24))
			continue;
		// Check distance and a free path.
		if (Distance(entrance_x, entrance_y, exit_x, exit_y) < Sqrt(wdt**2 + hgt**2) - attempts)
			continue;
		if (Distance(tablet_x, tablet_y, exit_x, exit_y) * 2 < Sqrt(wdt**2 + hgt**2) - attempts)
			continue;
		if (Distance(tablet_x, tablet_y, entrance_x, entrance_y) * 2 < Sqrt(wdt**2 + hgt**2) - attempts)
			continue;
		if (!LabyrinthMap->FindPath({x = entrance_x, y = entrance_y}, {x = exit_x, y = exit_y}) || !LabyrinthMap->FindPath({x = tablet_x, y = tablet_y}, {x = exit_x, y = exit_y}))
			continue;
		// Success!
		break;
	}
	var entrance = CreateObjectAbove(RoomEntrance, entrance_x, entrance_y + 12);
	entrance->SetLightRange(20, 20);
	CreateObjectAbove(RoomExit, exit_x, exit_y + 12);
	CreateObject(AncientTablet, tablet_x, tablet_y);
	
	// Create moving lights.
	var lights_count = 50;
	for (var count = 0; count < lights_count;)
	{
		var light_x = GetRandomPosition();
		var light_y = GetRandomPosition(true);
		if (GBackSolid(AbsX(light_x), AbsY(light_y)))
			continue;
		CreateMovingLight(light_x, light_y);
		count++;
	}
	// Draw slabs of rocks which block the way.
	CreateBlockingRocks(entrance_x, entrance_y, exit_x, exit_y, tablet_x, tablet_y);
	
	// Add some vegetation.
	Branch->Place(60, nil, {in_mat = "Brick"});
	return;
}

// Called when the player starts its room attempt.
// Here you can create effects and extra objects that are needed for the player and its crew.
public func OnPlayerInit(int plr)
{	
	// The clonk has no light range.
	var clonk = GetCrew(plr);
	clonk->SetLightRange(0, 0);
	// Set the player zoom.
	SetPlayerViewLock(plr, true);
	SetPlayerZoomByViewRange(plr, 100, PLRZOOM_Direct | PLRZOOM_LimitMin);
	SetPlayerZoomByViewRange(plr, 600, PLRZOOM_Direct | PLRZOOM_LimitMax);
	SetPlayerZoomByViewRange(plr, 300, PLRZOOM_Direct | PLRZOOM_Set);
	return;
}


/*-- Labyrinth Positions --*/

// Returns a free random position in the labyrinth.
private func GetRandomPosition(bool for_y)
{
	var map_size = LandscapeWidth();
	if (for_y)
		map_size = LandscapeHeight();
	// Return a position on the grid of paths at every possible intersection.
	return 36 + 24 * Random((map_size - 2 * 36) / 24 + 1);
}

global func DrawPath(int x1, int y1, int x2, int y2, int n)
{
	var path = LabyrinthMap->FindPath({x = x1, y = y1}, {x = x2, y = y2});
	if (!path) return;
	for (var p in path)
	{
		var loam = CreateObject(Loam, p.x, p.y);
		loam->SetCategory(C4D_StaticBack);
		loam->Message("@%d", n);
	}	
}


/*-- Blocking Rock --*/

private func CreateBlockingRocks(int entrance_x, int entrance_y, int exit_x, int exit_y, int tablet_x, int tablet_y)
{
	// Create 5 random blocks as long as the path between entrance and exit is not blocked.
	var block_cnt = 0;
	for (var attempts = 0; attempts < 500 && block_cnt < 5; attempts++)
	{
		var rock_x = GetRandomPosition();
		var rock_y = GetRandomPosition(true);
		// Only positions in the free.
		if (GBackSolid(AbsX(rock_x), AbsY(rock_y)))
			continue;
		// Ensure blocking rock is not too close to the exit, entrance and tablet.
		if (Distance(entrance_x, entrance_y, rock_x, rock_y) < 200)
			continue;
		if (Distance(exit_x, exit_y, rock_x, rock_y) < 200)
			continue;
		if (Distance(tablet_x, tablet_y, rock_x, rock_y) < 120)
			continue;
		// Try horizontal or vertical blocking rock.
		var left = GetMaterial(AbsX(rock_x - 24), AbsY(rock_y)) == Material("Brick");
		var right = GetMaterial(AbsX(rock_x + 24), AbsY(rock_y)) == Material("Brick");
		var top = GetMaterial(AbsX(rock_x), AbsY(rock_y - 24)) == Material("Brick");
		var bottom = GetMaterial(AbsX(rock_x), AbsY(rock_y + 24)) == Material("Brick");
		if (left && right && !top && !bottom)
		{
			DrawRockSlab(rock_x - 12, rock_y, rock_x + 12, rock_y);
			block_cnt++;
		}
		else if (!left && !right && top && bottom)
		{
			DrawRockSlab(rock_x, rock_y - 12, rock_x, rock_y + 12);
			block_cnt++;
		}
		// Determine whether this has blocked the path from entrance to exit.
		if (!LabyrinthMap->FindPath({x = entrance_x, y = entrance_y}, {x = exit_x, y = exit_y}))
			break;	
	}
	
	// Block the path between entrance, exit and tablet.
	BlockPath(entrance_x, entrance_y, exit_x, exit_y);
	BlockPath(entrance_x, entrance_y, tablet_x, tablet_y);
	BlockPath(exit_x, exit_y, tablet_x, tablet_y);

	// Place a dynamite stick with a path free to the entrance and one with its path not free (as a possible backup).
	var attempts = 0;
	var found_free = false, found_blocked = false;
	while (!(found_free && found_blocked) && attempts < 1000)
	{
		attempts++;
		var dynamite_x = GetRandomPosition();
		var dynamite_y = GetRandomPosition(true);
		// Only positions in the free.
		if (GBackSolid(AbsX(dynamite_x), AbsY(dynamite_y)))
			continue;
		if (!GBackSolid(AbsX(dynamite_x), AbsY(dynamite_y) + 24))
			continue;
		if (Distance(entrance_x, entrance_y, dynamite_x, dynamite_y) < (1000 - attempts) / 10)
			continue;
		if (!LabyrinthMap->FindPath({x = entrance_x, y = entrance_y}, {x = dynamite_x, y = dynamite_y}))
		{
			if (!found_blocked)
			{
				CreateObjectAbove(Dynamite, dynamite_x, dynamite_y + 12);
				found_blocked = true;
			}
			continue;
		}
		if (!found_free)
		{
			CreateObjectAbove(Dynamite, dynamite_x, dynamite_y + 12);
			found_free = true;
		}
	}
	return;
}

// Block the path between 1 and 2, with potentially two rock slabs.
private func BlockPath(int x1, int y1, int x2, int y2, int x_ex, int y_ex)
{
	var path, attempts = 0;
	while ((path = LabyrinthMap->FindPath({x = x1, y = y1}, {x = x2, y = y2})) && attempts < 1000)
	{
		attempts++;
		var length = GetLength(path);
		var placed = 0;
		for (var dev = 1; dev <= length / 2; dev++)
		{
			var rock_slabs = path[length / 2 - dev:length / 2 + dev];
			var rock = RandomElement(rock_slabs);
			// Not at already solid position or excluded position.
			if (GBackSolid(AbsX(rock.x), AbsY(rock.y)) || (rock.x == x_ex && rock.y == y_ex))
				continue;			
			// Try horizontal or vertical blocking rock.
			var left = GetMaterial(AbsX(rock.x - 24), AbsY(rock.y)) == Material("Brick");
			var right = GetMaterial(AbsX(rock.x + 24), AbsY(rock.y)) == Material("Brick");
			var top = GetMaterial(AbsX(rock.x), AbsY(rock.y - 24)) == Material("Brick");
			var bottom = GetMaterial(AbsX(rock.x), AbsY(rock.y + 24)) == Material("Brick");
			if (left && right && !top && !bottom)
			{
				DrawRockSlab(rock.x - 12, rock.y, rock.x + 12, rock.y);
				dev = Min(dev + 4, length / 2 - 1);
				placed++;
			}
			else if (!left && !right && top && bottom)
			{
				DrawRockSlab(rock.x, rock.y - 12, rock.x, rock.y + 12);
				dev = Min(dev + 4, length / 2 - 1);
				placed++;
			}
			// Stop if two slabs have been placed.
			if (placed >= 2)
				break;
			// Also stop if one has been placed and this blocks the path.
			if (placed >= 1 && !LabyrinthMap->FindPath({x = x1, y = y1}, {x = x2, y = y2}))
				break;
		}
	}
	return;
}

private func DrawRockSlab(int x1, int y1, int x2, int y2)
{
	var x = (x1 + x2) / 2;
	var y = (y1 + y2) / 2;
	if (y1 == y2)
	{
		var yu = y + 8;
		var yd = y - 8;
		for (var x = Min(x1, x2); x < Max(x1, x2); x++)
		{
			yu = yu + RandomX(-1, 1);
			yd = yd + RandomX(-1, 1);
			yu = BoundBy(yu, y + 6, y + 12);
			yd = BoundBy(yd, y - 12, y - 6);
			DrawMaterialQuad("Rock", x, yu, x, yd, x + 1, yd, x + 1, yu, "Tunnel-brickback");
		}
	}
	if (x1 == x2)
	{
		var xu = x + 8;
		var xd = x - 8;
		for (var y = Min(y1, y2); y < Max(y1, y2); y++)
		{
			xu = xu + RandomX(-1, 1);
			xd = xd + RandomX(-1, 1);
			xu = BoundBy(xu, x + 6, x + 12);
			xd = BoundBy(xd, x - 12, x - 6);
			DrawMaterialQuad("Rock", xu, y, xd, y, xd, y + 1, xu, y + 1, "Tunnel-brickback");
		}
	}
	return;
}


/*-- Moving Lights --*/

private func CreateMovingLight(int x, int y)
{
	// Create a dummy object and give it light.
	var light_colors = [0xff0000, 0x00ff00, 0x0000ff, 0xffff00, 0xff00ff, 0x00ffff];
	var light = CreateObject(Dummy, AbsX(x), AbsY(y));
	light.Plane = 400;
	light->SetCategory(C4D_None);
	light->SetLightRange(20, 20);
	light->SetLightColor(RandomElement(light_colors));
	
	// Make the light source float.
	light.ActMap = {
		Float = {
			Prototype = Action,
			Name = "Float",
			Procedure = DFA_FLOAT,
			Directions = 1,
			Length = 20,
			Delay = 1,
			Speed = 80,
			Accel = 80,
			Decel = 80,
			NextAction = "Float",
		}
	};
	light->SetAction("Float");
	// Add an effect to make it move.
	AddEffect("IntMoveLight", light, 100, 1, this);
	return light;
}

public func FxIntMoveLightStart(object light, effect fx, int temp)
{
	if (temp)
		return FX_OK;
	fx.has_changed_dir = 0;
	// Give light an initial direction to move towards.
	var x = light->GetX();
	var y = light->GetY();
	var dirs = [COMD_Up, COMD_Down, COMD_Left, COMD_Right];
	// Remove a direction if not open.
	if (GetMaterial(AbsX(x + 24), AbsY(y)) == Material("Brick"))
		RemoveArrayValue(dirs, COMD_Right);
	if (GetMaterial(AbsX(x - 24), AbsY(y)) == Material("Brick"))
		RemoveArrayValue(dirs, COMD_Left);
	if (GetMaterial(AbsX(x), AbsY(y + 24)) == Material("Brick"))
		RemoveArrayValue(dirs, COMD_Down);
	if (GetMaterial(AbsX(x), AbsY(y - 24)) == Material("Brick"))
		RemoveArrayValue(dirs, COMD_Up);
	light->SetComDir(RandomElement(dirs));
	return FX_OK;
}

public func FxIntMoveLightTimer(object light, effect fx)
{
	var x = light->GetX();
	var y = light->GetY();
	fx.has_changed_dir--;
	// Change the light direction if at a crossing.
	if (fx.has_changed_dir < 0 && Inside(Mod(AbsX(x) - 36, 48), -2, 2) && Inside(Mod(AbsY(y) - 36, 48), -2, 2))
	{
		var dirs = [COMD_Up, COMD_Down, COMD_Left, COMD_Right];
		// Remove a direction if not open.
		if (GetMaterial(AbsX(x + 24), AbsY(y)) == Material("Brick"))
			RemoveArrayValue(dirs, COMD_Right);
		if (GetMaterial(AbsX(x - 24), AbsY(y)) == Material("Brick"))
			RemoveArrayValue(dirs, COMD_Left);
		if (GetMaterial(AbsX(x), AbsY(y + 24)) == Material("Brick"))
			RemoveArrayValue(dirs, COMD_Down);
		if (GetMaterial(AbsX(x), AbsY(y - 24)) == Material("Brick"))
			RemoveArrayValue(dirs, COMD_Up);
		// Remove direction opposite to movement if still open directions are remaining.
		if (GetLength(dirs) >= 2)
		{
			var opposite_dir = (light->GetComDir() + 4) % 8;
			RemoveArrayValue(dirs, opposite_dir);
		}
		light->SetComDir(RandomElement(dirs));
		fx.has_changed_dir = 4;
	}
	return FX_OK;
}
