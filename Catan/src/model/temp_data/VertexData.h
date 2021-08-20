#pragma once

#include "CatanData.h"

class VertexData : CatanData
{
public:
	enum VertexDir : unsigned int {N = 0, S = 1};

	enum Building : unsigned int {NONE, SETTLEMENT, CITY};

	VertexData(Type _type,  int _q, int _r, VertexDir _vertexDir, Building _building) : CatanData(_type), vertexDir(_vertexDir), building(_building), q(_q), r(_r) {}

public:
	int q;
	int r;
	VertexDir vertexDir;
	Building building;
};