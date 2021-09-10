#pragma once

#include "CatanState.h"
#include "..\CatanGame.h"
#include "..\..\events\CatanEvent.h"

class FirstTurnsState : CatanState
{
public:
	virtual CatanState* handle(CatanGame& catanGame, CatanEvent catanEvent);

private:
	int buildings_hist[6] = { 0,0,0,0,0,0 }; // histogram thats holds the amount of buildings each player has built
	int roads_hist[6] = { 0,0,0,0,0,0 }; // histogram thats holds the amount of roads each player has built

};