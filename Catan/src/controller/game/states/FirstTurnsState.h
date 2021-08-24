#pragma once

#include "CatanState.h"
#include "..\CatanGame.h"
#include "..\..\events\CatanEvent.h"

class FirstTurnsState : CatanState
{
public:
	virtual CatanState* handle(CatanGame& catanGame, CatanEvent catanEvent);
};