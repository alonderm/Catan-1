#include "FirstTurnsState.h"
#include "..\..\events\CatanEvent.h"

CatanState* FirstTurnsState::handle(CatanGame& catanGame, CatanEvent catanEvent)
{
	if (catanEvent.getEvent() == BUILD_SETTLEMENT || catanEvent.getEvent())
	{
		return new FirstTurnsState();
	}
}