// Don't allow changing the game speed.

global func SetGameSpeed(int game_speed)
{
	Log("$MsgWarningNoGameSpeed$");
	return;
}