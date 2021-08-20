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

private:
	PlayerId playerCount;
	PlayerId turn;
	std::list<Player> playerList;
	CatanState* state;
};