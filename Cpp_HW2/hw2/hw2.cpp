/**************************************************************************************************
** hw2.cpp
** Record Two Categories and Calculate Their Ratios
** Sheng Zhang 10/11/2015
** SID 604029836
***************************************************************************************************/
#include <iostream>;
#include <string>;
#include <iomanip>;

using namespace std;

int main()
{
	// Define variables to be used
	string first_category, second_category;
	int first_number, second_number;
	double first_over_second_ratio, second_over_first_ratio;

	// Display the questions; Record user defined categories and numbers
	cout << "How many in the first category? ";
	cin >> first_number >> first_category;
	cout << "How many in the second category? ";
	cin >> second_number >> second_category;
	cout << "\n";

	// Erase the "s" at the end of the category names
	first_category.erase(first_category.length() - 1, 1);
	second_category.erase(second_category.length() - 1, 1);

	// Set the decimal points to exactly 2; Calculate the ratios
	cout << fixed;
	cout << setprecision(2);
	first_over_second_ratio = double (first_number) / second_number;
	second_over_first_ratio = double (second_number) / first_number;

	// Display category names and ratios
	cout << setw(first_category.length() + second_category.length() + 10) << first_category + "s" << setw(10) << first_number << endl;
	cout << setw(first_category.length() + second_category.length() + 10) << second_category + "s" << setw(10) << second_number << endl;
	cout << setw(first_category.length() + second_category.length() + 10) << first_category + "-to-" + second_category + " ratio" << setw(10) << first_over_second_ratio << endl;
	cout << setw(first_category.length() + second_category.length() + 10) << second_category + "-to-" + first_category + " ratio" << setw(10) << second_over_first_ratio << endl << endl;


	system("pause");
	return 0;
}