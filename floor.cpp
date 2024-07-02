#include "findsuffix.h"
#include <iostream>
#include <cmath>

using namespace std;

pair<char, short> get_input();

short find_floor_number(short room_number);
short count_digits(short number);

constexpr streamsize INF_FLAG{numeric_limits<streamsize>::max()};

int main()
{
    char y_n;

    cout << "\n\t\tWelcome to the Floor Determining Program.\n";

    while (tolower(y_n) != 'n')
    {
        cout << "\nWhich room are you looking for? ";

        auto [building_letter, room_number] = get_input();

        short floor_number;
        string suffix;

        floor_number = find_floor_number(room_number);
        suffix = find_suffix(floor_number);

        cout << "\nThank you!! Calculating... ";

        cout << "Done.\n";

        cout << "\nYour room is on the " 
             << floor_number << suffix << " floor of building " 
             << building_letter << ".\n";

        cout << "\nWould you like to find another room? Enter y/n: ";

        cin >> y_n;
        cin.ignore(INF_FLAG, '\n');
    }

    cout << "\nThanks for using the FDP.\n\n";
}

pair<char, short> get_input()
{
    char building_letter;
    short room_number;

    cin >> building_letter >> room_number;
    building_letter = static_cast<char>(toupper(building_letter));

    return {building_letter, room_number};
}

short find_floor_number(short room_number)
{
    short digit_count, floor_number, multiplier;
    
    digit_count = count_digits(room_number);
    multiplier = static_cast<short>(pow(10, digit_count - 1));
    floor_number = static_cast<short>(room_number / multiplier % 10);

    return floor_number;
}   

short count_digits(short number)
{
    short digit_count = 0;

    while (number > 0)
    {
        number /= 10;
        digit_count++;
    }

    return digit_count;
}

