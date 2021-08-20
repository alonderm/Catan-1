#pragma once

#include <string>
#include <list>

enum class PlayerId : int {PLAYER_ONE, PLAYER_TWO, PLAYER_THREE, PLAYER_FOUR, PLAYER_FIVE, PLAYER_SIX, PLAYER_SEVEN, PLAYER_EIGHT};

class Player {
private:
	PlayerId player;
	std::string name;
	int vicPoints;
};