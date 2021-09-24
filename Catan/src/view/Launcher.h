#pragma once
#include "game_window/GenericInterface.h"

class Launcher
{
public:
	static Launcher* launcher = NULL;
	Launcher(GenericInterface& _genericInterface) : genericInterface(_genericInterface) {};
	static Launcher getInstance() {
		if (launcher)
			return launcher;
		else {
			launcher = new Launcher();
			return launcher
		}
	};
private:
	GenericInterface& genericInterface;

};