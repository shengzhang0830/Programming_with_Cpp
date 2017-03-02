#include "ccc_win.h"
int ccc_win_main()
{
	Point P(4, 5), Q(6, 5), R(4, 2), S(6, 1), T(-2, 1), U(2, 3), V(6,-6), W(-2,-6);
	Line L(P, Q), M(P, R), N(Q, S), O(T,U), H(U,S), I(W,T), J(V,S),K(S,T), G(V,W);
	cwin << L << M << N << O << H << I << J << K << G;

	for (int i = 1; i < 20; i++)
	{
		double r = (double)rand() / RAND_MAX - 0.5;
		cwin << Circle(Point(5 + r, 5 + 0.2*i), 0.2);
	}

	cwin.get_mouse("Click Anywhere");
	cwin.clear();
	ccc_win_main();

	return 0;
}