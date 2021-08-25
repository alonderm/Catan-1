#pragma once

#include "Player.h"
#include "..\events\CatanEvent.h"
#include "states/CatanState.h"
#include <list>
#include <map>
#include <deque>
#include <iterator>

class CatanGame
{
public:
	void handleEvent(CatanEvent event);
	PlayerId getPlayerCount();
	PlayerId getturn();


private:
	PlayerId playerCount;	// In example : for 4-players game, playerCount = PLAYER_FOUR
	PlayerId turn;
	std::list<Player> playerList;
	CatanState* state;
};