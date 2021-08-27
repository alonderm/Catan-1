#pragma once

#include "Player.h"
#include "..\events\CatanEvent.h"
#include "states/CatanState.h"
#include <list>
#include <map>
#include <deque>
#include <iterator>
#include "CatanBoard.h"
#include "..\..\model\temp_data\VertexData.h"

class CatanGame
{
public:
	void handleEvent(CatanEvent event);
	PlayerId getPlayerCount();
	PlayerId getturn();
	void setup_board(CatanBoard& _board);
	bool build_settlement(PlayerId PlayerId, unsigned int q, unsigned int r, VertexData::VertexDir direction);


private:
	PlayerId playerCount;	// In example : for 4-players game, playerCount = PLAYER_FOUR
	PlayerId turn;
	std::list<Player> playerList;
	CatanState* state;
	CatanBoard& board;

};



