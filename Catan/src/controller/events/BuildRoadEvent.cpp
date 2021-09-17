#include "BuildRoadEvent.h"

int BuildRoadEvent::get_q()
{
	return this->q;
}


int BuildRoadEvent::get_r()
{
	return this->r;
}


EdgeData::EdgeDir BuildRoadEvent::get_dir()
{
	return this->dir;
}