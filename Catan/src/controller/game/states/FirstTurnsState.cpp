#include "FirstTurnsState.h"
#include "..\..\events\CatanEvent.h"

CatanState* FirstTurnsState::handle(CatanGame& catanGame, CatanEvent catanEvent)
{
	
	if (catanGame.getturn() == catanGame.getPlayerCount())
	{
		return NULL;
	}

	
	return NULL;
}


// TODO: add observer actions according to the specified event
