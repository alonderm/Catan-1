#pragma once

#include "..\..\model\temp_data\CatanData.h"
#include "..\..\model\temp_data\EdgeData.h"
#include "..\..\model\temp_data\VertexData.h"
#include "..\..\model\temp_data\HexData.h"

class CatanBoard
{
public:
	void init();

private:
	HexData* hexMap[7][7];
	VertexData* vertexMap[7][7][2];
	EdgeData* edgeMap[7][7][3];
};