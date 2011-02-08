
#include <exception>
#include <stdio.h>
#include "plat_windows.h"
#include <glload/gll.h>
#include <glload/gl_all.h>

void ShowCaps();

int main(int argc, char** argv)
{
	try
	{
		plat::Window theWnd;

		glload::LoadWinFunctions(theWnd.GetParamForLoad());
		glload::LoadFunctions();

		ShowCaps();
	}
	catch(std::exception e)
	{
		printf("Exception: %s\n", e.what());
		return -1;
	}


	return 0;
}
