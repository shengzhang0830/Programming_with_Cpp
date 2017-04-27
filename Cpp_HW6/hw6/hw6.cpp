/**************************************************************************************************
** hw6.cpp
** Create A Card Playing Game
** Sheng Zhang
** SID 604029836
***************************************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Define the class "Card"
class Card
{
public:
	Card();
	int get_rank() const;
	string get_rank_string() const;
	string get_suite_string() const;

private:
	int rank;
	int suite;
};

// Define the default constructor for the Card class
Card::Card()
{	
	rank = 1 + rand() % 13;
	suite = 1 + rand() % 4;
}

// Define the get_rank() member function of the Card class
int Card::get_rank() const
{
	return rank;
}

// Define the get_rank_string() member function of the Card class
string Card::get_rank_string() const
{
	if (rank == 1)
		return "Ace";
	else if (rank == 2)
		return "Two";
	else if (rank == 3)
		return "Three";
	else if (rank == 4)
		return "Four";
	else if (rank == 5)
		return "Five";
	else if (rank == 6)
		return "Six";
	else if (rank == 7)
		return "Seven";
	else if (rank == 8)
		return "Eight";
	else if (rank == 9)
		return "Nine";
	else if (rank == 10)
		return "Ten";
	else if (rank == 11)
		return "Jack";
	else if (rank == 12)
		return "Queen";
	else if (rank == 13)
		return "King";
	else
	{
		cout << "Illegal rank";
		exit(1);
	}
}

// Define the get_suite_string() member function of the Card class
string Card::get_suite_string() const
{
	if (suite == 1)
		return "Diamonds";
	else if (suite == 2)
		return "Hearts";
	else if (suite == 3)
		return "Spades";
	else if (suite == 4)
		return "Clubs";
	else
	{
		cout << "Illegal suite";
		exit(1);
	}
}


// Define the class "Player"
class Player
{
public:
	Player();
	void read();
	void update_current(int new_current_amt);
	int get_current_amt() const;
	int get_original_amt() const;
	string get_name() const;

private:
	string name;
	int current_amt;
	int original_amt;
};

// Define the default constructor for the Player class
Player::Player()
{
	name = "";
	current_amt = 100;
	original_amt = 100;
}

// Define the read() member function of the Player class
void Player::read()
{
	cout << "What is your name? ";
	getline (cin, name);
	cout << "How much money would you like to start with? ";
	cin >> original_amt;
	current_amt = original_amt;
	string remainder;
	getline (cin, remainder);
}

// Define the update_current() member function of the Player class
void Player::update_current(int new_current_amt)
{
	current_amt = new_current_amt;
}

// Define the get_current_amt() member function of the Player class
int Player::get_current_amt() const
{
	return current_amt;
}

// Define the get_original_amt() member function of the Player class
int Player::get_original_amt() const
{
	return original_amt;
}

// Define the get_name() member function of the Player class
string Player::get_name() const
{
	return name;
}


int main()
{
	// Declare variables to be used; Ask for the player's information
	Player A;
	int bet;
	A.read();
	srand((int)time(0));

	// Create a while loop that runs the game until the player wins or loses
	while (A.get_current_amt() < 10 * A.get_original_amt() && A.get_current_amt() > 0)
	{
		// Start the game; Draw 2 cards
		cout << A.get_name() << ", you have $" << A.get_current_amt() << "." << endl;
		Card a,b;
		cout << "You got a " << a.get_rank_string() << " of " << a.get_suite_string() << " and a " << b.get_rank_string() << " of " << b.get_suite_string() << "." << endl;
		
		// Ask the player to bet
		cout << "How much do you want to bet the next card is in between? ";
		cin >> bet;
		while (bet > A.get_current_amt() || bet < 0)
		{
			cout << "You only have $" << A.get_current_amt() << " to bet!" << endl <<  "Please enter a new bet: ";
			cin >> bet;
		}

		// Draw the 3rd card and check if its rank is within the ranks of the first 2 cards; Update the player's money accordingly
		Card c;
		cout << "You draw a " << c.get_rank_string() << " of " << c.get_suite_string() << "." << endl;
		if ((c.get_rank() < a.get_rank() && c.get_rank() > b.get_rank()) || (c.get_rank() > a.get_rank() && c.get_rank() < b.get_rank()))
		{
			cout << "Yes!! " << A.get_name() << " you win $" << bet << "!" << endl << endl;
			A.update_current(A.get_current_amt() + bet);
		}
		else
		{
			cout << "TOO BAD " << A.get_name() << "!! You lose $" << bet << "." << endl << endl;
			A.update_current(A.get_current_amt() - bet);
		}
	}

	// Tell the player the outcome once the game is over
	if (A.get_current_amt() == 0)
		cout << "You are out of money." << endl;
	else
		cout << "Congratualations, you broke the bank!!! " << endl;

	return 0;
	system("pause");
}
