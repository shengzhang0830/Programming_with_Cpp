/**************************************************************************************************
** hw5.cpp
** Create A Program to Implement the Flesch Reading Ease Test 
** Sheng Zhang
** SID 604029836
***************************************************************************************************/

#include <iostream>
#include <string>

using namespace std;

// Declare function prototypes
bool is_punctuation(string character);
int number_sentences(string phrase);
int number_words(string phrase);
bool is_vowel(string letter);
int number_syllables(string word);
double index(int number_syllables, int number_words, int number_sentences);

int main()
{
	// Define the variables to be used
	string phrase;
	int total_sentences, total_words, total_syllables = 0;

	// Ask for the phrase from the user
	cout << "Please type in a phrase: ";
	getline(cin, phrase);

	// Return the number of sentences and the number of words in the phrase
	total_sentences = number_sentences(phrase);
	cout << "The number of sentences in this phrase: " << total_sentences << endl;
	total_words = number_words(phrase);
	cout << "The number of words in this phrase: " << total_words << endl;

	// Create a nested loop that extracts each word and calculates the number of syllables in each word
	// Then add the numbers up to get the total number of syllables of the whole phrase
	for (int i = 0; i < phrase.length(); i++)
	{
		int start_word = 0, end_word = 0;
		string word;
		if (!is_punctuation(phrase.substr(i, 1)) && phrase.substr(i, 1) != " ")
			start_word = i;
		while (!is_punctuation(phrase.substr(i, 1)) && phrase.substr(i, 1) != " " && i < phrase.length())
		{
				i++;
		}
		if (!is_punctuation(phrase.substr(i - 1, 1)) && phrase.substr(i - 1, 1) != " ")
		{
			end_word = i - 1;
			word = phrase.substr(start_word, end_word - start_word + 1);
			total_syllables += number_syllables(word);
		}
	}

	// Return the number of syllables in the phrase
	cout << "The number of syllables in this phrase: " << total_syllables << endl;

	// Return the index of the phrase
	cout << "The Readability Index: " << index(total_syllables, total_words, total_sentences) << endl;

	return 0;
	system("pause");
}


// Delare function definitions

/************************************************
** is_punctuation: determines whether a character is a punctuation.
** Parameters:
** character -- the character we are testing
** Returns true if it is a punctuation and false if it is not a punctuation.
************************************************/
bool is_punctuation(string character)
{
	if (character.length() > 1)
		return false;
	else if (character == "." || character == ":" || character == ";" || character == "?" || character == "!")
		return true;
	else
		return false;
}

/************************************************
** number_sentences: calculates the number of sentences in a phrase.
** Parameters:
** phrase -- the phrase we entered
** Returns an integer that represents the number of sentences in a phrase.
************************************************/
int number_sentences(string phrase)
{
	int sentence_breakers = 0;
	for (int i = 0; i < phrase.length(); i++)
	{
		if (is_punctuation(phrase.substr(i, 1)))
			sentence_breakers++;
	}
	return sentence_breakers;
}

/************************************************
** number_words: calculates the number of words in a phrase.
** Parameters:
** phrase -- the phrase we entered
** Returns an integer that represents the number of words in a phrase.
************************************************/
int number_words(string phrase)
{
	int i = 0, number_words = 0, len = phrase.length();
	while (i < len)
	{
		if (!is_punctuation(phrase.substr(i, 1)) && phrase.substr(i, 1) != " ")
			number_words++;
		while (!is_punctuation(phrase.substr(i, 1)) && phrase.substr(i, 1) != " " && i < len)
		{
				i++;
		}
		i++;
	}
	return number_words;
}

/************************************************
** is_vowel: determines whether a letter is a vowel.
** Parameters:
** letter -- the letter we are testing
** Returns true if it is a vowel and false if it is not a vowel.
************************************************/
bool is_vowel(string letter)
{
	if (letter.length() > 1)
		return false;
	else if (letter == "a" || letter == "e" || letter == "i" || letter == "o" || letter == "u" || letter == "y")
		return true;
	else if (letter == "A" || letter == "E" || letter == "I" || letter == "O" || letter == "U" || letter == "Y")
		return true;
	else
		return false;
}

/************************************************
** number_syllables: calculates the number of syllables in a word.
** Parameters:
** word -- the word we entered
** Returns an integer that represents the number of syllables in a word.
************************************************/
int number_syllables(string word)
{
	int i = 0, syllables = 0, len = word.length();
	while (i < len)
	{
		if (is_vowel(word.substr(i, 1)))
			syllables++;
		while (is_vowel(word.substr(i, 1)) && i<len)
		{
				i++;
		}
		i++;
	}

	// Make sure a standalone e at the end of a word does not count as a syllable
	if (word.substr(word.length() - 1, 1) == "e" && !is_vowel(word.substr(word.length() - 2, 1)))
		syllables--;

	// Make sure the number of syllables is at least 1
	if (syllables > 1)
		return syllables;
	else
		return 1;
}

/************************************************
** index: calculates the index of the phrase we entered based on a formula.
** Parameters:
** number_syllables -- the number of syllables of the whole phrase
** number_words -- the number of words of the whole phrase
** number_sentences -- the number of sentences of the whole phrase
** Returns a double that represents the index of the phrase we entered.
************************************************/
double index(int number_syllables, int number_words, int number_sentences)
{
	double i = 206.835 - 84.6*(double(number_syllables) / number_words) - 1.015*(double(number_words) / number_sentences);
	return i;
}

