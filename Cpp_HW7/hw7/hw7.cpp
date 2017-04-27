/**************************************************************************************************
** hw7.cpp
** Write the source file that contains the definitions of the member and non-member functions
declared in phonebook.h and used in phone_book_main.cpp
** Sheng Zhang
** SID 604029836
***************************************************************************************************/

#include <iostream>
#include "phonebook.h"
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// Define the member functions
// Define the default constructor of the Person class
Person::Person()
{
	name = "";
	phone = 0;
}

// Define the regular constructor of the Person class
Person::Person(string new_name, int new_phone)
{
	name = new_name;
	phone = new_phone;
}

// Define the get_name() accessor of the Person class
string Person::get_name() const
{
	return name;
}

// Define the get_phone() accessor of the Person class
int Person::get_phone() const
{
	return phone;
}

// Define the operator< of the Person class
bool Person::operator < (Person p) const
{
	return name < p.name;
}

// Define the print() member function of the Person class
void Person::print() const
{
	cout << name << " " << phone << endl;
}


// Define the non-member functions
// Define the add_people function
void add_people(vector<Person> &phone_book)
{
	string input;
	int number;
	cout << "Please enter a name or enter Q to quit. ";
	getline(cin, input);
	while (input != "Q")
	{
		cout << "Please enter this person's phone number. ";
		cin >> number;
		Person P(input, number);
		phone_book.push_back(P);
		string clear;
		getline(cin, clear);
		cout << "Please enter a name or enter Q to quit. ";
		getline(cin, input);
	}
}

// Define the erase function
void erase(vector<Person> &phone_book, string name)
{
	int pos = -1; // Make sure the second for loop and the pop back never gets run if the name is not in the phone book.
	for (int i = 0; i < phone_book.size(); i++)
	{
		if (phone_book[i].get_name() == name)
			pos = i;
	}
	if (pos != -1)
	{
		for (int j = pos; j < phone_book.size() - 1; j++)
		{
			phone_book[j] = phone_book[j + 1];
		}
		phone_book.pop_back();
	}
}

// Define the sort function
void sort(vector<Person> &phone_book)
{
	sort(phone_book.begin(), phone_book.end());
}

// Define the swap helper function to be used in the shuffle function
void swap(int &a, int &b)
{
	int temp;
	temp = a;
	b = temp;
	a = b;
}

// Define the shuffle function
void shuffle(vector<Person> &phone_book)
{
	for (int i = 0; i < phone_book.size()*phone_book.size(); i++)
	{
		int slot_1 = rand() % phone_book.size ();
		int slot_2 = rand() % phone_book.size ();
		swap(phone_book[slot_1], phone_book[slot_2]);
	}
}

// Define the reverse function
void reverse(vector<Person> &phone_book)
{
	vector <Person> temp(phone_book.size());
	for (int i = 0; i < phone_book.size(); i++)
	{
		temp[phone_book.size() - 1 - i] = phone_book[i];
	}
	phone_book = temp;
}

// Define the print function
void print(vector<Person> &phone_book)
{
	for (int i = 0; i < phone_book.size(); i++)
	{
		phone_book[i].print();
	}
}

// Define the lookup function
int lookup(const vector<Person> &phone_book, string name)
{
	int output = -1;
	for (int i = 0; i < phone_book.size(); i++)
	{
		if (phone_book[i].get_name() == name)
			output = phone_book[i].get_phone();
	}
	return output;
}



