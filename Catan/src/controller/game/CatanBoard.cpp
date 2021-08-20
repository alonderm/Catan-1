#include "CatanBoard.h"

void CatanBoard::init()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			this->hexMap[i][j] = new HexData(CatanData::HEX, i, j);

			this->vertexMap[i][j][VertexData::N] = new VertexData(CatanData::VERTEX, i, j, VertexData::N, VertexData::NONE);
			this->vertexMap[i][j][VertexData::S] = new VertexData(CatanData::VERTEX, i, j, VertexData::S, VertexData::NONE);

			this->edgeMap[i][j][EdgeData::NE] = new EdgeData(CatanData::EDGE, i, j, EdgeData::NE, EdgeData::DIRT);
			this->edgeMap[i][j][EdgeData::NW] = new EdgeData(CatanData::EDGE, i, j, EdgeData::NW, EdgeData::DIRT);
			this->edgeMap[i][j][EdgeData::W] = new EdgeData(CatanData::EDGE, i, j, EdgeData::W, EdgeData::DIRT);
		}
	}

	// TODO: delete unneccesary data from the maps and set it to NULL.
}