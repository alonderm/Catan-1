#pragma once

#include "CatanData.h"

class HexData : CatanData
{
public:
	HexData(Type _type, int _q, int _r) : CatanData(_type), q(_q), r(_r){}


public:
	int q;
	int r;
};