// Keeps track of players voting to abort the current attempt.

static g_abort_attempt_votes;

global func InitAbortAttemptVotes()
{
	g_abort_attempt_votes = [];
	return;
}

global func RegisterAbortAttemptVote(int from_plr)
{
	if (g_abort_attempt_votes == nil)
		InitAbortAttemptVotes();
	var from_plr_id = GetPlayerID(from_plr);
	if (IsValueInArray(g_abort_attempt_votes, from_plr_id))
		return;
	// Add player ID from the new vote to the list.
	PushBack(g_abort_attempt_votes, from_plr_id);
	// Update room menus.
	UpdateRoomMenus("rooms");
	// Log vote and play a sound to warn the player.
	Log("$MsgVoteAbortAttempt$", GetTaggedPlayerName(from_plr));
	Sound("Animals::Monster::Growl*", {global = true, volume = 80});
	// Check if the vote count to abort the attempt has been reached.
	if (ReachedAbortAttemptVoteCount())
	{
		// Log the abortion of the attempt.
		var active_plr = GetActivePlayer();
		Log("MsgVotingCompleted", GetTaggedPlayerName(active_plr));
		Rule_Relaunch->Activate(active_plr);
		return;
	}
	return;
}

global func UnregisterAbortAttemptVote(int from_plr)
{
	if (g_abort_attempt_votes == nil)
		return InitAbortAttemptVotes();
	var from_plr_id = GetPlayerID(from_plr);
	// Remove player ID from the new vote to the list.
	RemoveArrayValue(g_abort_attempt_votes, from_plr_id);
	// Update room menus.
	UpdateRoomMenus("rooms");
	// Log vote take back.
	Log("$MsgVoteNotAbortAttempt$", GetTaggedPlayerName(from_plr));
	return;
}

global func ReachedAbortAttemptVoteCount()
{
	var vote_cnt = 0;
	for (var plr in GetPlayers(C4PT_User))
	{
		var plr_id = GetPlayerID(plr);
		if (IsValueInArray(g_abort_attempt_votes, plr_id))
			vote_cnt++;
	}
	// Vote is successful if more than half of the players vote for attempt abortion.
	return vote_cnt >= RequiredAbortAttemptVoteCount();
}

global func RequiredAbortAttemptVoteCount()
{
	var total_plr_cnt = GetPlayerCount(C4PT_User);
	return total_plr_cnt / 2 + 1;
}

global func HasVotedForAttemptAbortion(int plr)
{
	var plr_id = GetPlayerID(plr);
	return IsValueInArray(g_abort_attempt_votes, plr_id);
}

global func GetAbortVotesTaggedString()
{
	if (g_abort_attempt_votes == nil)
		return;
	var first =  GetPlayerByID(g_abort_attempt_votes[0]);
	var queue = GetTaggedPlayerName(first);
	for (var index = 1; index < GetLength(g_abort_attempt_votes); index++)
	{
		var plr = GetPlayerByID(g_abort_attempt_votes[index]);
		queue = Format("%s, %s", queue, GetTaggedPlayerName(plr));
	}
	return queue;
}