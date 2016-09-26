/**
	Labyrinth of Light
	A labyrinth with moving lights.
	
	@author Maikel
*/

#include Library_Map


// Called be the engine: draw the complete map here.
public func InitializeMap(proplist map)
{
	// Set the map size, which is fitted for intersections.
	var map_size = 4;
	map->Resize(9 + 6 * 4 * map_size, 9 + 6 * 3 * map_size);
	map->Draw("Brick");
	
	var intersections = FindIntersections(map);
	var connections = FindConnections(intersections);
	for (var con in connections)
		map->Draw("Tunnel-brickback", con);

	// Return true to tell the engine a map has been successfully created.
	return true;
}

public func FindIntersections(proplist map)
{
	var intersections = [];	
	for (var x = 4; x <= map.Wdt - 4; x += 6)
		for (var y = 4; y <= map.Hgt - 4; y += 6)
			PushBack(intersections, {X = x, Y = y});
	ShuffleArray(intersections);	
	return intersections;
}

public func FindConnections(array intersections)
{
	var max_length = 10;
	var connections = [];
	for (var inter in intersections)
		inter.conn_count = 0;	
	for (var i = 0; i < GetLength(intersections) - 1; i++)
	{
		var max_connections = RandomX(2, 3);
		var from_inter = intersections[i];
		for (var j = i + 1; j < GetLength(intersections); j++)
		{
			var to_inter = intersections[j];
			// Check for the maximum connections per cave.
			if (from_inter.conn_count >= max_connections || to_inter.conn_count >= max_connections)
				continue;
			// Cave line parameters.
			var fx = from_inter.X;
			var fy = from_inter.Y;
			var tx = to_inter.X;
			var ty = to_inter.Y;
			// Check for the maximum line distance and for horizontal and vertical connections.
			if (Distance(fx, fy, tx, ty) > max_length)
				continue;
			if (!(Abs(fx - tx) == 0 || Abs(fy - ty) == 0))
				continue;
			// Check for overlap in existing connections.
			var has_overlap = false;
			for (var line in connections)
				if (IsLineOverlap(fx, fy, tx, ty, line.X[0], line.Y[0], line.X[1], line.Y[1]))	
				{
					has_overlap = true;
					break;
				}
			if (has_overlap)
				continue;
			var connection = {Algo = MAPALGO_Polygon, X = [fx, tx], Y = [fy, ty], Wdt = 2, Open = 1, Empty = 1};
			PushBack(connections, connection);
			intersections[i].conn_count++;
			intersections[j].conn_count++;
		}
	}
	return connections;
}
