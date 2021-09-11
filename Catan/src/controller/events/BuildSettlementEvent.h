#pragma once

#include "..\game\Player.h"
#include "CatanEvent.h"
#include "..\..\model\temp_data\VertexData.h"

class BuildSettlementEvent : public CatanEvent
{


public:
	//constructor of 'BuildSettlementEvent', also initializes the fields inherited from 'CatanEvent'
	BuildSettlementEvent(int _q, int _r, VertexData::VertexDir _dir, PlayerId _playerId, Events _eventType) :q(_q), r(_r), dir(_dir), CatanEvent(_playerId, _eventType) {};
	int get_q();
	int get_r();
	VertexData::VertexDir get_dir();


private:
	int q;
	int r;
	VertexData::VertexDir dir;


};