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
	VertexData* vertex_pointer;
	if (PlayerId == this->turn)
	{
		if ((q >= 0 && q <= 6) && (r >= 0 && r <= 6)) //checking if the q and r values are valid
		{
			if (board.validate_hexes(q, r)) //checking if the given hex(q,r) exists
			{
				vertex_pointer = board.get_VertexData(q, r, direction);
				if (!(vertex_pointer == NULL)) //checking if the given vertex(q,r,direction) exists
				{
					if (vertex_pointer->building == VertexData::Building::NONE) // if the vertex is clear of any settlement/city
					{
						vertex_pointer->setBuilding(PlayerId, VertexData::Building::SETTLEMENT); //build the settlement in the given coordinates
						return true;
					}

				}

			}

		}
	}
	
	return false;

}

CatanGame::CatanGame(CatanBoard& _board, PlayerId _playerCount):board(_board),playerCount(_playerCount)
{
	this->turn = PlayerId::PLAYER_ONE;

}