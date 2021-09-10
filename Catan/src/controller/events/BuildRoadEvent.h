#pragma once

#include "..\game\Player.h"
#include "CatanEvent.h"
#include "..\..\model\temp_data\EdgeData.h"

class BuildRoadEvent : CatanEvent
{
public:
	//constructor of 'BuildSettlementEvent', also initializes the fields inherited from 'CatanEvent'
	BuildRoadEvent(int _q, int _r, EdgeData::EdgeDir _dir, PlayerId _playerId, Events _eventType) :q(_q), r(_r), dir(_dir), CatanEvent(_playerId, _eventType) {};
	int get_q();
	int get_r();
	EdgeData::EdgeDir get_dir();


private:
	int q;
	int r;
	EdgeData::EdgeDir dir;

};