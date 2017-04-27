/**************************************************************************************************
** hw3.cpp
** Create A Tic-Tac-Toe Game
** Sheng Zhang
** SID 604029836
***************************************************************************************************/



#include "ccc_win.h"
#include <cmath>

int ccc_win_main()
{
	Point secret(3.3, 4.2);
	cwin << secret;
	Circle CS(secret, 2.0);
	cwin << CS;
	bool win = false;
	while (!win)
	{
		Point P = cwin.get_mouse("Click! ");
		cwin << P;
		if (sqrt((secret.get_x() - P.get_x()) * (secret.get_x() - P.get_x()) + (secret.get_y() - P.get_y()) * (secret.get_y() - P.get_y())) < 2 && sqrt((secret.get_x() - P.get_x()) * (secret.get_x() - P.get_x()) + (secret.get_y() - P.get_y()) * (secret.get_y() - P.get_y())) >= 1)
			cwin << Message(P, "You are close! ");
		else if (sqrt((secret.get_x() - P.get_x()) * (secret.get_x() - P.get_x()) + (secret.get_y() - P.get_y()) * (secret.get_y() - P.get_y()))  < 1)
		{
			cwin << Message(P, "You won!!! ");
			win = true;
			Circle C(P, 1.0);
			cwin << C;
		}
	}
	return 0;
}
