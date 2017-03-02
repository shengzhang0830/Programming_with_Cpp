
/****
#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	int n;
	cout << "give me s";
	cin >> s;
	cout << "give me n";
	cin >> n;
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << s.substr(i, 1);
		}
		cout << endl;
	}
	return 0;
}
****/


/******
// Midterm 2014 Q5 // 
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string word;
	int match = 0;
	cout << "give me a word ";
	cin >> word;
	for (int i = 0; i < word.length() / 2; i++)
	{
		if (word.substr(i, 1) == word.substr(word.length() - i - 1, 1))
			match++;
	};
	if (match == word.length() / 2)
		cout << "it is a p";
	else
		cout << "it is not a p";
	return 0;
}
***/

/*****
#include <iostream>
using namespace std;

int main()
{
	int x = 0, y = x + 1;
	x = 1;
	cout << y; // The result is 1....
	return 0;
}
***/



/******
// Midterm
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string phrase, word;
	int index;
	cout << "Enter a phrase: ";
	getline(cin, phrase);
	cout << "Enter a word: ";
	cin >> word;
	for (int i = 0; i < phrase.length();i++)
	{
		/**
		index = phrase.find(word, i);
		cout << "Found " << word << " at index " << index << endl;
		**/
/**
		if (phrase.substr(i, word.length()) == word)
		{
			index = i;
			cout << "Found " << word << " at index " << index << endl;
		}
		
	}
	return 0;
}
*******/




/******
// 4.17
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	double x = 12345.12345;
	cout << setprecision(4);
	cout << x;
	return 0;
}
*****/

/*****
// 4.19 (use length + 5 to make it allign to the left instead of right
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	string first_name, last_name;
	cout << "first?" << endl;
	cin >> first_name;
	cout << "last?" << endl;
	cin >> last_name;
	cout << setw(first_name.length() + 5) << first_name << endl;
	cout << setw(last_name.length() + 5) << last_name << endl;
	return 0;
}
****/



/*******
//string example
#include <string>
#include <iostream>
using namespace std;

int main()
{

	string input;
	string simpsons = "The Simpsons";
	string futurama = "Futurama";
	cout << "input? ";
	getline(cin, input);

	for (int i = 0; i < input.length(); i++)
	{
		if (input.substr(i, simpsons.length()) == simpsons)
		{
			input.erase(i, simpsons.length());
			input.insert(i, futurama);
		}
	}

	cout << input << "\n";
	return 0;
}
******/



/*******
// 9.16/17
#include <iostream>
using namespace std;

int main()
{
	int number, sum = 0;
	cout << "number?\n";
	while (cin >> number)
	{
		sum += number;
		cout << "number?\n";
	}
	cout << sum;
	return 0;
}
*******/




/********
// 9.18

#include <iostream>
using namespace std;

int main()
{
	int x = 1, y = 1;
	while (x <= 10)
	{
		y = 1;
		while (y <= 10)
		{
			cout << x * y << " ";
			y++;
		}
		cout << endl;
		x++;
	}
	return 0;
}
********/



/*******
// game.cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand((int)time(0));
	int magic, guess;
	string response = "Y";

	while (response == "Y")
	{
		magic = rand() % 100 + 1;     // Randomization of magic has to be within the while loop. Otherwise every replay would have the same magic.
		cout << "magic? ";
		cin >> guess;
		while (guess != magic)
		{
			if (guess > magic)
				cout << "too high. ";
			else
				cout << "too low. ";
			cout << "magic? ";
			cin >> guess;
		}
		cout << "Woooo\n";
		cout << "play again? Y? ";   // Need to be placed inside the while loop.
		cin >> response;
	}
	
	return 0;
}
*******/



/******
// factorials - while
#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cout << "n? ";
	cin >> n;
	int i = 1, total = 1;
	while (i <= n)
	{
		total *= i;
		i++;
	}
	cout << total << endl;
	return 0;
}
*****/


/*****
// factorials - do
#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cout << "n? ";
	cin >> n;
	int i = 1, total = 1;
	do
	{
		total *= i;
		i++;
	} while (i<=n);
	cout << total << endl;
	return 0;
}
*****/

/******
// factorials - for
#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cout << "n? ";
	cin >> n;
	int total = 1;
	for (int i = 1; i <= n; i++)
	{
		total *= i;
	}
	cout << total << endl;
	return 0;
}
******/



/*******
// 10.25-27
#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cout << "height?";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - i; j > 0; j--)
		{
			cout << "[]";
		}
		cout << endl;
	}
	return 0;
}
*******/


/********
// 11.17
#include <iostream>
using namespace std;

int main()
{
	int n = 0, divisor = 2;
	cout << "number? ";
	cin >> n;
	while (divisor <= n)  // Must have = because (eg. you put in 24, it will just give 2 2 2).
	{
		while (n % divisor == 0)
		{
			n /= divisor;
			cout << divisor << " ";
		}
		divisor++;
	}
	return 0;
}
********/


/****
// 11.17
#include <iostream>
using namespace std;

int smallest_divisor(int n)
{
	int div = 2;
	while (div <= n && n%div != 0)
	{
		div++;
	}
	return div;
}
int main()
{
	int n;
	cout << "Yo, gimme a number. ";
	cin >> n;
	while (n != 1)
	{
		cout << smallest_divisor(n) << " ";
		n /= smallest_divisor(n);
	}
	return 0;
}
****/



/******
// 14.10 Ultimate Scope Example
#include <iostream>
using namespace std;
void f();
void g(int &x);
int x = 5;
void f()
{
	int x = 0;
	cout << ++x << endl;
}
void g(int &x)
{
	cout << x++ << endl;
	{
		cout << x << endl;
		int x = 9;
		cout << x << endl;
		{
			cout << x << endl;
			int x = 4;
			cout << x << endl;
		}
	}
}
int main()
{
	f();
	cout << x << endl;
	int x;
	x = 2;
	cout << x << endl;
	g(x);
	cout << x << endl;
	return 0;
}
*****/



/******
// 14.24/25
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand((int)time(0));
	int total = 0;
	for (int i = 0; i < 10000; i++)
	{
		int sum = 0, rolls = 0;      // Declare here rather than with total because declaring these var here helps with resetting after while loop is done.
		while (sum != 7)
		{
			int die1 = rand() % 6 + 1;
			int die2 = rand() % 6 + 1;
			rolls++;
			sum = die1 + die2;
			}
			total += rolls;
			}
			cout << double(total) / 10000 << " ";
			return 0;
			}
			******/



/******
// Point Class (no real graphics, so no need to do graphics files)
#include <iostream>
using namespace std;

class Point
{
public:
Point();
Point(double new_x, double new_y);
double get_x() const;
double get_y() const;
void move(double dx, double dy);
private:
double x;
double y;
};

Point::Point()
{
x = 0.0;
y = 0.0;
}

Point::Point(double new_x, double new_y)
{
x = new_x;
y = new_y;
}

double Point::get_x() const
{
return x;
}

double Point::get_y() const
{
return y;
}

void Point::move(double dx, double dy)
{
x += dx;
y += dy;
}

int main()
{
Point P1;
Point P2(1, 1);
cout << P1.get_x() << " " << P1.get_y() << endl;
P2.move(1, 1);
cout << P2.get_x() << " " << P2.get_y() << endl;
return 0;
}
*******/



/******
// Point Class II
#include <iostream>
using namespace std;

class Point
{
public:
	Point();
	Point(double new_x, double new_y);
	double get_x() const;
	double get_y() const;
	void move(double dx, double dy);
	bool operator > (Point Q) const;
private:
	double x;
	double y;
};


Point::Point()
{
	x = 1;
	y = 1;
}

Point::Point(double new_x, double new_y)
{
	x = new_x;
	y = new_y; 
}

double Point::get_x() const
{
	return x;
}

double Point::get_y() const
{
	return y;
}

void Point::move(double dx, double dy)
{
	x += dx;
	y += dy;
}

bool Point::operator> (Point Q) const
{
	if (x > Q.x && y > Q.y)
		return true;
	else
		return false;
}


int main()
{
	Point T;
	Point S(2, 2);
	S.move(-3, 1);
	cout << T.get_x() << " " << T.get_y() << endl;
	cout << S.get_x() << " " << S.get_y() << endl;
	if (S > T)
		cout << "S wins";
}
*******/





/********
// Insert (19.7/8)
#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int> &numbers, int slot, int newn)
{
	numbers.push_back(numbers[numbers.size() - 1]);
	for (int i = numbers[numbers.size() - 2]; i > slot; i--)
	{
		numbers[i] = numbers[i - 1];
	}
	numbers[slot] = newn;
}

int main()
{
	vector<int> v(6);
	int slot = 3, newn = 12;
	for (int i = 0; i < 6; i++)
	{
		cout << "a number? ";
		cin >> v[i];
	}
	insert(v, slot, newn);
	for (int i = 0; i < 7; i++)
	{
		cout << v[i] << " ";
	}
	return 0;
}
*******/




/****
// Increasing (20.21) m2.21
#include <iostream>
#include <vector>
using namespace std;

bool increasing(vector<int> numbers)
{
	bool inc = true;
	for (int i = 0; i < numbers.size()-1; i++)
	{
		if (numbers[i] >= numbers[i + 1])
			inc = false;
	}
	return inc;
}

int main()
{
	vector<int> v(6);
	for (int i = 0; i < 6; i++)
	{
		cout << "a number? ";
		cin >> v[i];
	}
	cout << increasing(v) << endl;
	return 0;
}
****/


/******
// Unique (20.25)
#include <iostream>
#include <vector>
using namespace std;

vector<int> unique (vector<int> &numbers)
{
	vector<int> final;
	for (int i = 0; i < numbers.size(); i++)
	{
		bool found = false;
		for (int j = 0; j < i; j++)
		{
			if (numbers[i] == numbers[j])
				found = true;
		}
		if (!found)
			final.push_back(numbers[i]);
	}
	return final;
}

int main()
{
	vector<int> v(6);
	for (int i = 0; i < 6; i++)
	{
		cout << "a number? ";
		cin >> v[i];
	}
	
	vector<int> u = unique(v);
	for (int j = 0; j < u.size(); j++)
	{
		cout << u[j] << " ";
	}

	return 0;
}
******/




/******
// MDX2 2012 Q2
#include <iostream>
#include <vector>
using namespace std;

bool same_elements(vector<int> v1, vector<int> v2)
{
	for (int i = 0; i < v1.size(); i++)
	{
		int n = 0;
		for (int j = 0; j < v2.size(); j++)
		{
			if (v1[i] == v2[j])
				n++;
		}
		if (n == 0)
			return false;
	}
	return true;
}

**** Solutions
bool same_elements(vector<int> v1, vector<int>v2)
{
	bool found = false;
	for (int i = 0; i < v1.size(); i++)
	{
		found = false;
		for (int j = 0; j < v2.size(); j++)
		{
			if
				(v1[i] == v2[j])
				found = true;
		} if (!found)
			return false;
	} return true;
}
******

int main()
{
	vector<int> v1(6);
	for (int i = 0; i < 6; i++)
	{
		cout << "a number for v1? ";
		cin >> v1[i];
	}
	vector<int> v2(6);
	for (int i = 0; i < 6; i++)
	{
		cout << "a number for v2? ";
		cin >> v2[i];
	}
	cout << same_elements(v2,v1) << endl;
	return 0;
}
******/




/*****
// MDX2 2012 3&4
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Athelete
{
public:
	Athelete();
	Athelete(string n, vector<double> r);
	string get_name() const;
	vector<double> get_run_times() const;
	bool operator<(Athelete b);
private:
	string name;
	vector<double> run_times;
};

Athelete::Athelete()
{
	name = "";
}

Athelete::Athelete(string n, vector<double> r)
{
	name = n;
	run_times = r;
}

string Athelete::get_name() const
{
	return name;
}

vector<double> Athelete:: get_run_times() const
{
	return run_times;
}


bool Athelete:: operator< (Athelete b)
{
	for (int i = 0; i < run_times.size(); i++)
	{
		int n = 0;
		for (int j = 0; j < b.run_times.size(); j++)
		{
			if (run_times[i] >= b.run_times[j])
				n++;
		}
		if (n == 0)
			return true;
	}
	return false;
}

//-----------
// Solutions
bool Athelete::operator < (Athelete b)
{
	double min_a;
	double min_b;
	min_a = run_times[0];
	min_b = b.run_times[0];
	for (int i = 0; i < run_times.size(); i++)
	{
		if (run_times[i] < min_a)
			min_a = run_times[i];
	}
	for (int i = 0; i < b.run_times.size(); i++)
	{
		if (b.run_times[i] < min_b)
			min_b = b.run_times[i];
	}
	return min_a < min_b;
}
//-----------

int main()
{
	vector<double> Av(2);
	Av[0] = 2.0;
	Av[1] = 3.0;
	Athelete A("john", Av);
	vector<double> R1(2);
	R1[0] = 1.8;
	R1[1] = 1.9;
	Athelete r1("sheng", R1);
	vector<double> R2(2);
	R2[0] = 2.2;
	R2[1] = 2.1;
	Athelete r2("zs", R2);
	vector<Athelete> Runners(2);
	Runners[0] = r1;
	Runners[1] = r2;
	
	for (int i = 0; i < Runners.size(); i++)
	{
		if (Runners[i] < A)
			cout << Runners[i].get_name() << endl;
	}
	
	return 0;
}
*****/



//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------



/****
#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	list<string> words;
	for (int j = 0; j < 10; j++)
	{
		string word;
		cout << "a word ? ";
		cin >> word;
		words.push_back(word);
	}

	list<string>::iterator i = find(words.begin(), words.end(), "ant");
	if (i != words.end())
	{
		list<string>::iterator end = find(i, words.end(), "bee");
		while (i != end)
		{
			cout << "word is " << *i << ". \n";
			++i;
		}
	}
	return 0;
}
***/



/*****
// Quene
#include <queue>
#include <iostream>
#include <string>
using namespace std;

int main()
{

	queue<string> simpsons;

	simpsons.push("Addis");
	simpsons.push("Bogus");
	simpsons.push("Cragis");

	while (simpsons.size() > 0)
	{
		cout << simpsons.front() << endl;
		simpsons.pop();
	}

	return 0;
}
****/



/*****
// Stack
#include <stack>
#include <iostream>
#include <string>
using namespace std;

int main()
{

	stack<string> simpsons;

	simpsons.push("Homer");
	simpsons.push("Marge");
	simpsons.push("Bart");
	simpsons.push("Lisa");
	simpsons.push("Maggie");


	while (simpsons.size() > 0)
	{
		cout << simpsons.top() << endl;
		simpsons.pop();
	}


	return 0;
}
*****/



/*****
// Set
#include <set>
#include <iostream>
#include <string>

using namespace std;

int main()
{

	set<string> simpsons;

	simpsons.insert("Homer");
	simpsons.insert("Marge");
	simpsons.insert("Marge"); // Marge will not occur twice

	simpsons.insert("Bart");
	simpsons.insert("Lisa");
	simpsons.insert("Maggie");

	int c = simpsons.count("Homer");

	cout << "Homer occurs: " << c << " times." << endl;

	simpsons.erase("Homer");

	c = simpsons.count("Homer");

	cout << "Homer occurs: " << c << " times." << endl;

	set<string>::iterator i = simpsons.begin();

	while (i != simpsons.end())
	{
		cout << *i << endl; // to access the element that the iterator points to we use *
		++i;
	}

	return 0;
}
*****/




/****
// 21.17
#include <iostream>
using namespace std;

int main()
{
	char c;
	for (int i = 'A'; i < 'Z'; i++)
	{
		c = i;
		cout << c << endl;
	}
	return 0;
}
****/



/*****
// M1.17
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	cout << "number? ";
	cin >> n;
	for (int i = 1; i <= n*n; i++)
	{
		cout << setw(5) << i;
		if (i%n == 0)
			cout << endl;
	}
	return 0;
}
*****/




/*****
//  M1.21
#include <iostream>
#include <string>
using namespace std;

int fib (int n);

int fib (int n)
{
	int prev = 0, cur = 1;
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	for (int i = 3; i <= n; i++)
	{
		int newn = prev + cur;
		prev = cur;
		cur = newn;
	}
	return cur;
}

int main()
{
	int n;
	cout << "n? ";
	cin >> n;
	cout << "The fib is " + to_string(fib(n)) + ". " << endl;
	return 0;
}
*****/



/*****
// M2.15
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
public:
	Student();
	Student(string s, vector<double> g);
	string get_name() const;
	bool operator>(Student b) const;
private:
	string name;
	vector <double> grades;
};

Student::Student()
{
	name = "";
}

Student::Student(string s, vector<double> g)
{
	name = s;
	grades = g;
}

string Student::get_name() const
{
	return name;
}

bool Student::operator> (Student b) const
{
	int total_a = 0, total_b = 0;
	for (int i = 0; i < grades.size(); i++)
	{
		total_a += grades[i];
	}
	for (int j = 0; j < b.grades.size(); j++)
	{
		total_b += b.grades[j];
	}
	if (double(total_a) / grades.size() > double(total_b) / b.grades.size())
		return true;
	else
		return false;
}

int main()
{
	string n1, n2;
	vector<double> g1, g2;
	double d1, d2;
	cout << "n1? ";
	cin >> n1;
	cout << "n2? ";
	cin >> n2;
	cout << "g1? ";
	while (cin >> d1)
	{
		g1.push_back(d1);
		cout << "more? ";
	}
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "g2? ";
	while (cin >> d2)
	{
		g2.push_back(d2);
		cout << "more? ";
	}

	Student A(n1, g1);
	Student B(n2, g2);
	cout << A.get_name() << endl;
	if (A > B)
	{
		cout << B.get_name() << " sucks. " << endl;
	}

	return 0;
}
*****/




/*****
// F.26
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool same_element(vector<string> v1, vector<string> v2)
{
	bool foundall = true;
	for (int i = 0; i < v2.size(); i++)
	{
		bool found = false;
		for (int j = 0; j < v1.size(); j++)
		{
			if (v2[i] == v1[j])
				found = true;
		}
		if (found == false)
			foundall = false;
	}
	return foundall;
}

int main()
{
	vector<string> vv1, vv2;
	string ss1, ss2;
	cout << "s1? ";
	for (int i = 0; i < 6; i++)
	{
		cin >> ss1;
		vv1.push_back(ss1);
		cout << "more? ";
	}
	cout << "s2? ";
	for (int j = 0; j < 3; j++)
	{
		cin >> ss2;
		vv2.push_back(ss2);
		cout << "more? ";
	}
	if (same_element(vv1, vv2))
	{
		cout << "same! " << endl;
	}
	return 0;
}
*****/




/*********
// F.27
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

void output_array(double a[10][10], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << fixed << setprecision(2);
			cout << setw(5) << a[i][j];
		}
		cout << endl;
	}
}

int main()
{
	srand((int)time(0));
	double array[10][10];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int r = rand() % 2;
			if (r == 0)
			{
				if (i == 0)
					array[i][j] = j;
				else
					array[i][j] = (double)j / i;
			}
			else
			{
				if (j == 0)
					array[i][j] = i;
				else
					array[i][j] = (double)i / j;
			}
		}
	}

	output_array(array, 10, 10);

	return 0;
}
**********/




/******
// Mdx2 Q4
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int frequency(vector <string> words, string word);
string most_frequent(vector<string> words, int &n);

int frequency(vector <string> words, string word)
{
	int n = 0;
	for (int i = 0; i < words.size(); i++)
	{
		if (words[i] == word)
			n++;
	}
	return n;
}

string most_frequent(vector<string> words, int &n)
{
	string max = words[0];
	for (int i = 0; i < words.size(); i++)
	{
		if (frequency(words, words[i]) > frequency(words, max))
			max = words[i];
	}
	n = frequency(words, max);
	return max;
}

int main()
{
	vector<string> w;
	string s;
	for (int i = 0; i < 10; i++)
	{
		cout << "Yo, string?! ";
		cin >> s;
		w.push_back(s);
	}
	int f;
	string m = most_frequent(w, f);
	cout << m << " " << f;
	return 0;
}
******/






//
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

class Person
{
public:
	Person();
	Person(string n, vector<Person> p);
	string get_name() const;
	vector<Person> get_friends() const;
private:
	string name;
	vector<Person> friends;
};

Person::Person()
{
	
}

Person::Person(string n, vector<Person> p)
{
	name = n;
	friends = p;
}

string Person::get_name() const
{
	return name;
}

vector<Person> Person::get_friends() const
{
	return friends;
}

int main()
{
	vector<Person> bob_friends, alan_friends, cha_friends;
	vector<Person> v;
	Person A ("zhu", v);
	Person B ("au", v);
	Person C ("fu", v);
	Person D ("hu", v);
	Person E ("zu", v);
	Person F ("dhu", v);
	Person G ("kdu", v);
	Person H ("su", v);
	Person I ("hsu", v);
	Person J ("chu", v);
	bob_friends[0] = A;	bob_friends[1] = B;	bob_friends[2] = C;
	alan_friends[0] = E; alan_friends[1] = F; alan_friends[2] = C; alan_friends[3] = D;
	cha_friends[0] = A;	cha_friends[1] = H;
	Person Bob("Bob", bob_friends);
	Person Alan("Alan", alan_friends);
	Person Cha("Cha", cha_friends);
	list<Person> people = { Bob, Alan, Cha };
	
	list<Person>::iterator i = people.begin();
	list<Person>::iterator m = people.begin();
	for (; i != people.end(); i++)
	{
		if ((*i).get_friends().size() > (*m).get_friends().size())
			m = i;
	}
	cout << (*m).get_name() << endl;
	for (int j = 0; j < (*m).get_friends().size(); j++)
	{
		cout << (*m).get_friends()[j].get_name();
	}

	return 0;
}