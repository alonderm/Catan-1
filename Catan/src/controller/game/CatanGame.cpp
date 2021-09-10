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

//builds a settlement on a given vertex: 'true' - a settlement was built , 'false' - the settlement was not built
bool CatanGame::build_settlement(PlayerId PlayerId, unsigned int q, unsigned int r, VertexData::VertexDir direction)
{
	
	return (this->board.build_settlement(PlayerId, q, r, direction, this->turn));
}

// CatanGame constructor
CatanGame::CatanGame(CatanBoard& _board, PlayerId _playerCount):board(_board),playerCount(_playerCount)
{
	this->turn = PlayerId::PLAYER_ONE;
}

//builds a road on a given edge: 'true' - the road was built, 'false' - the road was not built
bool CatanGame::build_road(PlayerId PlayerId, unsigned int q, unsigned int r, EdgeData::EdgeDir direction)
{

	return (this->board.build_road(PlayerId, q, r, direction, this->turn));
}

void CatanGame::increment_turn()
{
	if (this->turn != PlayerId::PLAYER_EIGHT)
	{
		this->turn = static_cast<PlayerId>(int(this->turn) + 1);
	}

}

void CatanGame::decrement_turn()
{
	if (this->turn != PlayerId::PLAYER_ONE)
	{
		this->turn = static_cast<PlayerId>(int(this->turn) - 1);
	}

}