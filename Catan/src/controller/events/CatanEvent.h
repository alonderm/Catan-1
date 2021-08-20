#pragma once

#include "..\game\CatanGame.h"

enum Events : int {BUILD_SETTLEMENT, BUILD_ROAD, MOVE_ROBBER};

enum class Source : int {GUI, SERVER};

class CatanEvent
{
public:
	PlayerId getPlayerId();
	void setPlayerId(PlayerId playerId);
	Events getEvent();

private:
	PlayerId playerId;
	Events eventType;

};