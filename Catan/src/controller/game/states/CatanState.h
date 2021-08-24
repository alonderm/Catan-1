#pragma once

#include "..\..\events\CatanEvent.h"

class CatanGame;

class CatanState
{
public:
	virtual CatanState* handle(CatanGame& catanGame, CatanEvent catanEvent) = 0;
};