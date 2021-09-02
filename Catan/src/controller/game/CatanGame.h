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
	//Constructors:
	CatanGame(CatanBoard& _board, PlayerId _playerCount); // 'turn' will always start at PLAYER_ONE, 'playerList' is determined according to..
														  // 'PlayerCount' and 'state' always starts as a pointer to 'FirstTurnState' instance.

	void handleEvent(CatanEvent event);
	PlayerId getPlayerCount();
	PlayerId getturn();
	void setup_board(CatanBoard& _board);
	bool build_settlement(PlayerId PlayerId, unsigned int q, unsigned int r, VertexData::VertexDir direction);
	bool build_road(PlayerId PlayerId, unsigned int q, unsigned int r, EdgeData::EdgeDir direction);
	CatanBoard& get_board()
	{
		return this->board;
	}
	
	


private:
	PlayerId playerCount;	// In example : for 4-players game, playerCount = PLAYER_FOUR
	PlayerId turn;
	std::list<Player> playerList; //TODO:add initialization
	CatanState* state;
	CatanBoard& board;

};



