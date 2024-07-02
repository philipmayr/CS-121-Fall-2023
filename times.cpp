#include <iostream>
#include <ctype.h>

using namespace std;

int main ()
{
	cout << "\n\t\tWelcome to the Time Calculation Program!!!\n\n";

    string first_time, 
           second_time;

    short first_minutes, 
          first_hours,
          first_total_minutes, 
          second_minutes, 
          second_hours,
          second_total_minutes,
          difference_minutes,
          difference_hours;

    char colon;

    cout << "What is your first time of day? ";

    cin >> first_hours >> colon >> first_minutes;

    first_total_minutes = first_hours * 60 + first_minutes;

    cout << "What is your second time of day? ";
    
    cin >> second_hours >> colon >> second_minutes;

    second_total_minutes = second_hours * 60 + second_minutes;

    difference_minutes = (second_total_minutes - first_total_minutes); 
    difference_hours = difference_minutes / 60;

    cout << "\nThere are " 
         << difference_minutes << " minutes between the two times ("
         << difference_minutes + 2 << " inclusive).\n";

    cout.fill('0');

    cout << "\nThat's the same as " << difference_hours << " hours and " 
         << difference_minutes % 60 << " minutes (or "
         << difference_hours << ":";
    cout.width(2);
    cout
         << difference_minutes % 60 
         << " inclusive).\n";

    cout << "That's also " << " hours (or " << " inclusive).\n";

    cout << "\nThank you for using the TCP!!\n";

    cout << "\nHave a good day!\n\n";
}



