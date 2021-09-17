#include "BuildSettlementEvent.h"


int BuildSettlementEvent::get_q()
{
	return this->q;
}


int BuildSettlementEvent::get_r()
{
	return this->r;
}


VertexData::VertexDir BuildSettlementEvent::get_dir()
{
	return this->dir;
}