#pragma once
#include "GenericInterface.h"
#include "../Launcher.h"

class ConsoleInterface : GenericInterface 
{
public:
	ConsoleInterface(Launcher& _launcher) : launcher(_launcher) {};
	void run();
	void handleInput(string input);

private:
	Launcher& launcher;
};