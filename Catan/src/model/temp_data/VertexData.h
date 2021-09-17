#pragma once

#include "CatanData.h"
#include "../../controller/game/Player.h"

class VertexData : CatanData
{
public:
	enum  VertexDir : unsigned int {N = 0, S = 1};

	enum  Building : unsigned int {NONE, SETTLEMENT, CITY};

	VertexData(Type _type,  int _q, int _r, VertexDir _vertexDir, Building _building) : CatanData(_type), vertexDir(_vertexDir), building(_building), q(_q), r(_r) {}

	void setBuilding(PlayerId _playerid, Building _building) 
	{
		this->building = _building;
		this->player_id = _playerid;
	}

	Building get_Building()
	{
		return this->building;
	}

	PlayerId get_Player()
	{
		return this->player_id;
	}

private:
	int q;
	int r;
	VertexDir vertexDir;
	Building building;
	PlayerId player_id;
};
