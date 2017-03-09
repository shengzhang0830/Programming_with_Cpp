/**************************************************************************************************
** hw1.cpp
** Calculate Time, Speed, and Distance
** Sheng Zhang
** SID 604029836
***************************************************************************************************/
#include <iostream>
using namespace std;
int main()
{
	int time, speed;
	double distance, time_hours_exact;
	int time_years, time_days, time_hours, time_minutes, time_seconds, time_remaining;

	// Input user information about time (in seconds) and speed (in miles per hour)
	cout << "Please give me the time of travel in seconds. ";
	cin >> time;
	cout << "Please give me your speed in miles per hour. ";
	cin >> speed;

	// Define constants to be used
	const int SECONDS_PER_YEAR = 31557600;
	const int SECONDS_PER_DAY = 86400;
	const int SECONDS_PER_HOUR = 3600;
	const int SECONDS_PER_MINUTE = 60;

	// Declare the unit conversion variables that convert the number of seconds into years, days, hours, minutes and seconds
	time_years = time / SECONDS_PER_YEAR;
	time_remaining = time % SECONDS_PER_YEAR;
	time_days = time_remaining / SECONDS_PER_DAY;
	time_remaining = time_remaining % SECONDS_PER_DAY;
	time_hours = time_remaining / SECONDS_PER_HOUR;
	time_remaining = time_remaining % SECONDS_PER_HOUR;
	time_minutes = time_remaining / SECONDS_PER_MINUTE;
	time_remaining = time_remaining % SECONDS_PER_MINUTE;
	time_seconds = time_remaining;

	// Display time in years, days, hours, minutes and seconds
	cout << "You have been traveling for: " << time_years << " years " << time_days << " days " << time_hours << " hours " << time_minutes << " minutes " << time_seconds << " seconds.\n";

	// Convert the number of seconds into hours; Calculate distance (in miles) based on time (in hours) and speed (miles per hour)
	time_hours_exact = (double)time / 3600;
	distance = time_hours_exact * speed;

	// Display distance (in miles)
	cout << "Your distance traveled is: " << distance << " miles.\n";

	system("pause");
	return 0;
}
