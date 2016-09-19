/**
	Ancient Tablet
	Collect these tablets just in case they contain useful information.
	
	@author Maikel	
*/

public func IsAncientTablet() { return true; }

public func Hit(int x, int y)
{
	StonyObjectHit(x, y);
	return;
}


/*-- Properties --*/

local Name = "$Name$";
local Description = "$Description$";
local Collectible = true;