#include "CatanGame.h"

void CatanGame::handleEvent(CatanEvent catanEvent)
{
	CatanState* _state = state->handle(*this ,catanEvent);

	if (_state)
	{
		delete state;
		state = _state;
	}

}

PlayerId CatanGame::getPlayerCount()
{
	return this->playerCount;
}

PlayerId CatanGame::getturn()
{
	return this->turn;
}

void CatanGame::setup_board(CatanBoard& _board)
{
	this->board = _board;
}

bool build_settlement(PlayerId _PlayerId, unsigned int _q, unsigned int _r, VertexData::VertexDir _direction)
{
	return false;
}

