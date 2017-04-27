#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;


void fill_list(list<int> &n)
{
	for (int i = 0; i < 10; i++)
	{
		n.push_back(rand() % 21 - 10);
	}
}

/*bool list::operator<(list<int> l)
{

}
*/

void output_list(list<list<int>> &results)
{
	list<list<int>>::iterator i;
	for ( i = results.begin(); i != results.end(); ++i)
	{
		list<int> temp = *i;
		list<int>::iterator j;
		for (j = temp.begin(); j != temp.end(); ++j)
		{
			cout << *j << ", ";
		}
		cout << endl;
	}
}


int main()
{
	srand((int)time(0));
	list<int> nlist, zerosum;
	list<list<int>> nlists;
	
	/*
	fill_list(nlist);

	
	list<int>::iterator i;
	for (i = nlist.begin(); i != nlist.end(); ++i)
	{
		list<int>::iterator j;
		for (j = i; j != nlist.end(); ++j)
		{
			list<int>::iterator k;
			list<int>::iterator p;
			p = i;
			p--;
			for (k = j; k != p; --k)
			{
				list<int>::iterator n;
				int sum = 0;
				list<int>::iterator q;
				q = k;
				q--;
				for (n = j; n != q; --n)
				{
					sum += *n;
				}
				sum += *i;
				if (sum == 0)
				{
					list<int>::iterator m;
					for (m = j; m != q; --m)
					{
						zerosum.push_back(*m);
					}
					zerosum.push_back(*i);
					nlists.push_back(zerosum);
				}
			}
		}
	}
	*/

		
	fill_list(nlist);
	cout << "The 10 integers you got are: ";
	list<int>::iterator s;
	for (s = nlist.begin(); s != nlist.end(); ++s)
	{
		cout << *s << " ";
	}

	vector<int> vlist, zerosumv;
	list <int>::iterator t;
	for (t = nlist.begin(); t != nlist.end(); ++t)
	{
		vlist.push_back(*t);
	}

	for (int i = 0; i <10 ; i++)
	{
		for (int j = i; j <10 ; j++)
		{
			for (int k = j; k > i-1; --k)
			{
				int sum = 0;
				for (int n = j; n > k-1; --n)
				{
					sum += vlist[n];
				}
				//if (k != i)
					sum += vlist[i];

				if (sum == 0)
				{
					for (int m = j; m > k-1; --m)
					{
						zerosum.push_back(vlist[m]);
					}
					//if (k!=i)
					zerosum.push_back(vlist[i]);
					nlists.push_back(zerosum);
				}
			}
		}
	}
	





	output_list(nlists);

	return 0;
}
