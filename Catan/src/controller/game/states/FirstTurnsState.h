#pragma once

#include "CatanState.h"
#include "..\CatanGame.h"
#include "..\..\events\CatanEvent.h"

class FirstTurnsState : CatanState
{
public:
	virtual CatanEvent* handle(CatanGame& catanGame, CatanEvent catanEvent);
};