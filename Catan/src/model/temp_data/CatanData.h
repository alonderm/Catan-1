#pragma once


class CatanData
{
public:
	enum Type : unsigned int {VERTEX, EDGE, HEX};

	CatanData(Type _type) : type(_type) {}

	Type getType(void) { return this->type; }
private:
	Type type;
};