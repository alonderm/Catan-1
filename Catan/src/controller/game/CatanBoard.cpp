#include "CatanBoard.h"



bool CatanBoard::validate_hexes(int q, int r)
{
	if (q + r < 3 || q + r > 9)
	{
		return false;
	}

	return true;
}


void CatanBoard::init()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (validate_hexes(i, j))
			{
				this->hexMap[i][j] = new HexData(CatanData::HEX, i, j);

				this->vertexMap[i][j][VertexData::N] = new VertexData(CatanData::VERTEX, i, j, VertexData::N, VertexData::NONE);
				this->vertexMap[i][j][VertexData::S] = new VertexData(CatanData::VERTEX, i, j, VertexData::S, VertexData::NONE);

				this->edgeMap[i][j][EdgeData::NE] = new EdgeData(CatanData::EDGE, i, j, EdgeData::NE, EdgeData::DIRT);
				this->edgeMap[i][j][EdgeData::NW] = new EdgeData(CatanData::EDGE, i, j, EdgeData::NW, EdgeData::DIRT);
				this->edgeMap[i][j][EdgeData::W] = new EdgeData(CatanData::EDGE, i, j, EdgeData::W, EdgeData::DIRT);
			}

			else
			{
				this->hexMap[i][j] = NULL;

				this->vertexMap[i][j][VertexData::N] = NULL;
				this->vertexMap[i][j][VertexData::S] = NULL;

				this->edgeMap[i][j][EdgeData::NE] = NULL;
				this->edgeMap[i][j][EdgeData::NW] = NULL;
				this->edgeMap[i][j][EdgeData::W] = NULL;
			}
			
		}
	}


	// deleting all unnecessary vertexes
	for (int q = 0, r = 3; q < 4 && r <= 0; q++, r--)
	{
		delete this->vertexMap[q][r][VertexData::N];
		this->vertexMap[q][r][VertexData::N] = NULL;
	}

	for (int q = 3, r = 0; q <= 6 ; q++)
	{
		delete this->vertexMap[q][r][VertexData::N];
		this->vertexMap[q][r][VertexData::N] = NULL;
	}

	for (int q = 6, r = 0; r <= 3; r++)
	{
		delete this->vertexMap[q][r][VertexData::N];
		this->vertexMap[q][r][VertexData::N] = NULL;
	}

	for (int q = 6, r = 3; q >= 3 && r <= 6; q--, r++)
	{
		delete this->vertexMap[q][r][VertexData::S];
		this->vertexMap[q][r][VertexData::S] = NULL;
	}

	for (int q = 3, r = 6; q >= 0; q--)
	{
		delete this->vertexMap[q][r][VertexData::S];
		this->vertexMap[q][r][VertexData::S] = NULL;
	}

	for (int q = 0, r = 6; r >= 3; r--)
	{
		delete this->vertexMap[q][r][VertexData::S];
		this->vertexMap[q][r][VertexData::S] = NULL;
	}




	// TODO: delete unneccesary data from the maps and set it to NULL.
}

