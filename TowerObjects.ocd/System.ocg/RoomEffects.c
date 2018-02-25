// Several effects that are shared between some of the rooms and are thus defined for all rooms.

// Creates falling clonks for rooms on the outside of the tower.
global func RoomEffectAddFallingClonks(int xmin, int xmax, int xdir, int xdir_dev)
{
	CreateEffect(FxRoomFallingClonks, 100, 20, xmin, xmax, xdir, xdir_dev);
	return;
}

static const FxRoomFallingClonks = new Effect
{
	Construction = func(int xmin, int xmax, int xdir, int xdir_dev)
	{
		this.xmin = xmin ?? 0;
		this.xmax = xmax ?? LandscapeWidth();
		this.xdir = xdir ?? 0;
		this.xdir_dev = xdir_dev ?? 10;
		return FX_OK;
	},
	
	Timer = func()
	{
		if (Random(4))
			return FX_OK;
		var clonk = CreateObject(Clonk, RandomX(this.xmin, this.xmax), -30);
		clonk->SetAction("Tumble");
		clonk->SetXDir(RandomX(this.xdir - this.xdir_dev, this.xdir + this.xdir_dev));
		clonk->SetYDir(6 + Random(8));
		clonk.Plane = -1000;
		clonk->SetCon(RandomX(60, 80));
		while(clonk->RemoveVertex()) {};
		clonk.Death = this.None;
		clonk->SetCategory(C4D_Vehicle);
		clonk->SetAlternativeSkin(RandomElement(["Carpenter", "MaleBlackHair", "MaleBrownHair", "MaleDarkHair", "Youngster", "YoungsterBlond"]));
		clonk->SetColor(HSL(Random(255), 180, 200));
		clonk->SetObjectLayer(clonk);
		clonk.BorderBound = nil;
		return FX_OK;
	},
	
	None = func() { return;	}
};