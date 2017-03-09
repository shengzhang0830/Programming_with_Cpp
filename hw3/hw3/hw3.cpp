/**************************************************************************************************
** hw3.cpp
** Create A Tic-Tac-Toe Game
** Sheng Zhang
** SID 604029836
***************************************************************************************************/

/***
#include "ccc_win.h"
int ccc_win_main()
{
	// Define points, lines, and variables to be used
	Point P(-3, -9), Q(-3, 9), R(3, -9), S(3, 9), T(-9, 3), U(9, 3), V(-9, -3), W(9, -3), P1, P2;
	Line L(P, Q), M(S, R), N(T, U), O(V, W);
	string play_game = "Yes";
	double radius = 1;

	// Create a while loop to repeat the game if the players want to do so
	while (play_game == "Yes")
	{
		// Draw the grid
		cwin << L << M << N << O;

		// Create a for loop that runs 9 times
		for (int i = 1; i < 10; ++i)
		{
			// Create an if statement that distinguishes player 2's move (circle) and player 1's move (cross)
			if (i%2==0)
			{
				P2 = cwin.get_mouse("Player 2, choose your move by clicking within one previously unchosen box");
				Circle C2(P2, radius);
				cwin << C2;
			}
			else
			{
				P1 = cwin.get_mouse("Player 1, choose your move by clicking within one previously unchosen box");
				Point Q11(P1.get_x() + 1, P1.get_y() + 1), Q12(P1.get_x() - 1, P1.get_y() - 1), Q13(P1.get_x() + 1, P1.get_y() - 1), Q14(P1.get_x() - 1, P1.get_y() + 1);
				Line L11(Q11, Q12), L12(Q13, Q14);
				cwin << L11 << L12;
			}
		}

		// Announce the end of the game; Ask whether the players want to repeat the game
		play_game = cwin.get_string("Game Over!  Do you want to play the game again?    Yes or No?");
		
		// Clear the gameboard
		cwin.clear();
	}

	return 0;
}
***/



/***
#include "ccc_win.h"
int ccc_win_main()
{
	Point P = cwin.get_mouse("Please click somewhere.");
	Point Q = cwin.get_mouse("Please click somehwere.");
	if (P.get_x>1)
	{
		Circle C (Q, 1);
		cwin << C;
	}
}
***/



/**
// rectangle

#include "ccc_win.h"

void draw_rec(Point center, double scale)
{
	center.move(scale / 2, scale / 2);
	Point P_tr(center.get_x(), center.get_y());
	Point P_br(P_tr.get_x(), P_tr.get_y() - 1);
	Point P_tl(P_tr.get_x()-1, P_tr.get_y());
	Point P_bl(P_br.get_x()-1, P_br.get_y());
	Line L1(P_tr, P_br);
	Line L2(P_tr, P_tl);
	Line L3(P_bl, P_br);
	Line L4(P_tl, P_bl);
	cwin << L1 << L2 << L3 << L4;
}

int ccc_win_main()
{
	Point center;
	double scale;
	center = cwin.get_mouse("center? ");
	scale = cwin.get_double("scale? ");
	draw_rec(center, scale);
	return 0;
}
**/



/*****
// 2014 MDX2 Q1
#include "ccc_win.h"
#include <cstdlib>
#include <ctime>

int ccc_win_main()
{
	srand((int)time(0));
	for (int i = 0; i < 100; i++)
	{
		Point P((double)(rand() % 201 - 100) / 10, (double)(rand() % 201 - 100) / 10);
		cwin << P;
		//double x = (double)(rand() % 201) / 100 - 10;
		//double y = (double)(rand() % 201) / 100 - 10;
		//cwin << Point(x, y);
	}
	return 0;
}
****/






/*****
#include "ccc_win.h"

void draw_rectangle(Point center, double scale)
{

	Point p_bl = center;
	p_bl.move(-scale / 2, -scale / 2);  // Now p_bl is the bottom left corner 

	Point p_br = p_bl; // From the bottom left corner we will figure out the other points
	p_br.move(scale, 0);

	Point p_tl = p_bl;
	p_tl.move(0, scale);

	Point p_tr = p_bl;
	p_tr.move(scale, scale);

	Line l_bottom(p_bl, p_br);
	Line l_right(p_br, p_tr);
	Line l_top(p_tr, p_tl);
	Line l_left(p_tl, p_bl);

	cwin << l_bottom << l_right << l_top << l_left;

}

int ccc_win_main()
{
	double scale = 1.0;
	for (double i = 1.0; i <= 4; i = i + .5)
	{
		Point P = cwin.get_mouse("Click somewhere");
		draw_rectangle(P, i);
	}
	return 0;
}
*****/





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
