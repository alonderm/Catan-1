#include "ConsoleInterface.h"
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream.h>

using namespace std

void ConsoleInterface::run()
{
	bool flag = true;
	while (flag)
	{
		string str;
		cin << str << endl;
		handleInput(str);
	}
}

void ConsoleInterface::handleInput(string input)
{
}
