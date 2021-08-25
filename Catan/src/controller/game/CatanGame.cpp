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