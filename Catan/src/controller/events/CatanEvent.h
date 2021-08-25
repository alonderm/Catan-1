#pragma once

#include "..\game\Player.h"

enum class Events : int {BUILD_SETTLEMENT, BUILD_ROAD, MOVE_ROBBER};

enum class Source : int {GUI, SERVER};

class CatanEvent
{
public:
	PlayerId getPlayerId();
	void setPlayerId(PlayerId playerId);
	Events getEvent(); // No override methods allowed.

private:
	PlayerId playerId;
	Events eventType;

};