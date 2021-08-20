#pragma once

#include "CatanData.h"

class EdgeData : CatanData
{
public:
	enum EdgeDir : unsigned int {NE = 0, NW = 1, W = 2};

	enum Path : unsigned int {DIRT, ROAD};

	EdgeData(Type _type, int _q, int _r, EdgeDir _edgeDir, Path _path) : CatanData(_type), q(_q), r(_r), edgeDir(_edgeDir), path(_path) {}

public:
	int q;
	int r;
	EdgeDir edgeDir;
	Path path;
};