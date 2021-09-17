#pragma once

#include "..\..\model\temp_data\CatanData.h"
#include "..\..\model\temp_data\EdgeData.h"
#include "..\..\model\temp_data\VertexData.h"
#include "..\..\model\temp_data\HexData.h"
#include "Player.h"

class CatanBoard
{
public:
	void init();
	bool validate_hexes(int q, int r);
	VertexData* get_VertexData(int q, int r, VertexData::VertexDir dir);
	EdgeData* get_EdgeData(int q, int r, EdgeData::EdgeDir dir);
	bool build_settlement(PlayerId playerid, unsigned int q, unsigned int r, VertexData::VertexDir direction,PlayerId turn);
	bool build_road(PlayerId playerid, unsigned int q, unsigned int r, EdgeData::EdgeDir direction,PlayerId turn);
	bool FindSettlement(PlayerId playerid, unsigned int q, unsigned int r, EdgeData::EdgeDir direction);
	bool CheckNeighbors(PlayerId playerid, unsigned int q, unsigned int r, VertexData::VertexDir direction);

private:
	HexData* hexMap[7][7];
	VertexData* vertexMap[7][7][2];
	EdgeData* edgeMap[7][7][3];
};