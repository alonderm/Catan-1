#include "CatanBoard.h"



bool CatanBoard::validate_hexes(int q, int r)
{
	if ((q + r) < 3 || (q + r) > 9)
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


	 //deleting all unnecessary vertexes & edges
	for (int q = 0, r = 3; q < 4 && r >= 0; q++, r--)
	{
		delete this->vertexMap[q][r][VertexData::N];
		this->vertexMap[q][r][VertexData::N] = NULL;

		delete this->edgeMap[q][r][EdgeData::NE];
		this->edgeMap[q][r][EdgeData::NE] = NULL;
		delete this->edgeMap[q][r][EdgeData::NW];
		this->edgeMap[q][r][EdgeData::NW] = NULL;
		delete this->edgeMap[q][r][EdgeData::W];
		this->edgeMap[q][r][EdgeData::W] = NULL;
	}

	for (int q = 4, r = 0; q <= 6 ; q++)
	{
		delete this->vertexMap[q][r][VertexData::N];
		this->vertexMap[q][r][VertexData::N] = NULL;

		delete this->edgeMap[q][r][EdgeData::NE];
		this->edgeMap[q][r][EdgeData::NE] = NULL;
		delete this->edgeMap[q][r][EdgeData::NW];
		this->edgeMap[q][r][EdgeData::NW] = NULL;
		delete this->edgeMap[q][r][EdgeData::W];
		this->edgeMap[q][r][EdgeData::W] = NULL;
	}

	for (int q = 6, r = 1; r <= 3; r++)
	{
		delete this->vertexMap[q][r][VertexData::N];
		this->vertexMap[q][r][VertexData::N] = NULL;

		delete this->edgeMap[q][r][EdgeData::NE];
		this->edgeMap[q][r][EdgeData::NE] = NULL;
		delete this->edgeMap[q][r][EdgeData::NW];
		this->edgeMap[q][r][EdgeData::NW] = NULL;

	}

	for (int q = 5, r = 4; q >= 3 && r <= 6; q--, r++)
	{
		delete this->vertexMap[q][r][VertexData::S];
		this->vertexMap[q][r][VertexData::S] = NULL;

		delete this->edgeMap[q][r][EdgeData::NE];
		this->edgeMap[q][r][EdgeData::NE] = NULL;
		if (q == 3 && r == 6)
		{
			delete this->edgeMap[q][r][EdgeData::W];
			this->edgeMap[q][r][EdgeData::W] = NULL;
		}
	}

	for (int q = 2, r = 6; q >= 0; q--)
	{
		delete this->vertexMap[q][r][VertexData::S];
		this->vertexMap[q][r][VertexData::S] = NULL;

		delete this->edgeMap[q][r][EdgeData::W];
		this->edgeMap[q][r][EdgeData::W] = NULL;

		if (q == 0)
		{
			delete this->edgeMap[q][r][EdgeData::NW];
			this->edgeMap[q][r][EdgeData::NW] = NULL;
		}
	}

	for (int q = 0, r = 5; r >= 4; r--)
	{
		delete this->vertexMap[q][r][VertexData::S];
		this->vertexMap[q][r][VertexData::S] = NULL;

		delete this->edgeMap[q][r][EdgeData::NW];
		this->edgeMap[q][r][EdgeData::NW] = NULL;
		delete this->edgeMap[q][r][EdgeData::W];
		this->edgeMap[q][r][EdgeData::W] = NULL;

	}

	
	

	// TODO: delete unneccesary data from the maps and set it to NULL.
}

//returns the pointer to a specific vertex on the game board
VertexData* CatanBoard::get_VertexData(int q, int r, VertexData::VertexDir dir)
{
	return this->vertexMap[q][r][dir];
}

//returns the pointer to a specific edge on the game board
EdgeData* CatanBoard::get_EdgeData(int q, int r, EdgeData::EdgeDir dir)
{
	return this->edgeMap[q][r][dir];
}


bool CatanBoard::build_settlement(PlayerId playerid, unsigned int q, unsigned int r, VertexData::VertexDir direction,PlayerId turn)
{
	VertexData* vertex_pointer;
	if (playerid == turn)
	{
		if ((q >= 0 && q <= 6) && (r >= 0 && r <= 6)) //checking if the q and r values are valid
		{
			if (this->validate_hexes(q, r)) //checking if the given hex(q,r) exists
			{
				vertex_pointer = this->get_VertexData(q, r, direction);
				if (!(vertex_pointer == NULL)) //checking if the given vertex(q,r,direction) exists
				{
					if (vertex_pointer->get_Building() == VertexData::Building::NONE) // if the vertex is clear of any settlement/city
					{
						vertex_pointer->setBuilding(playerid, VertexData::Building::SETTLEMENT); //build the settlement in the given coordinates
						return true;
					}

				}

			}

		}
	}

	return false;
}


bool CatanBoard::build_road(PlayerId playerid, unsigned int q, unsigned int r, EdgeData::EdgeDir direction,PlayerId turn)
{
	EdgeData* edge_pointer;
	if (playerid == turn)
	{
		if ((q >= 0 && q <= 6) && (r >= 0 && r <= 6)) //checking if the q and r values are valid
		{
			if (this->validate_hexes(q, r)) //checking if the given hex(q,r) exists
			{
				edge_pointer = this->get_EdgeData(q, r, direction);
				if (!(edge_pointer == NULL)) //checking if the given vertex(q,r,direction) exists
				{
					if (edge_pointer->get_path() == EdgeData::Path::DIRT) // if the edge is clear(no road is built on it)
					{
						edge_pointer->set_path(playerid, EdgeData::Path::ROAD); //build the road in the given coordinates
						return true;
					}

				}

			}

		}

	}

	return false;
}