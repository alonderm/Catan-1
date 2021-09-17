#pragma once

#include "..\game\Player.h"

enum class Events : int {BUILD_SETTLEMENT, BUILD_ROAD, MOVE_ROBBER};

enum class Source : int {GUI, SERVER};

class CatanEvent
{

// making sure that the constructor is called exclusively from derived classes of 'CatanEvent'
protected:
	CatanEvent(PlayerId _playerId, Events _eventType) :playerId(_playerId), eventType(_eventType) {};

public:
	PlayerId getPlayerId();
	Events getEvent(); // No override methods allowed.

private:
	PlayerId playerId;
	Events eventType;

};