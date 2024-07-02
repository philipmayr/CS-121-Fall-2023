#include "random.h"
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

void get_dice_roll(short & dice, 
    	   	       short & sides,
		           short & adjustment,  
		           char & plus_minus)
{
    cout << "\n\t\tWelcome to the Dice Statistics Programs!!!\n";

    cout << "\nEnter your dice roll: ";

    while (cin.peek() != '\n' && isspace(cin.peek()))
    {
        cin.ignore();
    }

    if (!isalpha(cin.peek()))
    {
        cin >> dice;
    } 
    else
    {
        dice = 1; 
    }
    
	char d;

    cin >> d >> sides;

    while (cin.peek() != '\n' && isspace(cin.peek()))
    {
        cin.ignore();
    }

    if (cin.peek() != '\n')
    {
        cin >> plus_minus >> adjustment;
    }
	
    if (plus_minus == '-')
    {
        adjustment = -adjustment;
    }

    cout << "\n\nThank you!!  Calculating...  ";
}

void calculate_results(short dice, 
		       short sides, 
		       short adjustment, 
		       short & min_roll, 
		       short & max_roll, 
		       short & random_roll,
		       double & average_roll) 
{
    min_roll = dice + adjustment;
    max_roll = static_cast<short>((dice * sides) + adjustment);
    average_roll = (min_roll + max_roll) / 2.0;
    random_roll = 0;
    
    for (short i = 0; i < dice; i++)
    {
        random_roll += get_random_num(1, sides);
    }
    random_roll += adjustment;
    
    cout << "Done.\n";
}

void print_results(short dice, 
 		   short sides, 
		   short adjustment, 
		   short min_roll, 
		   short max_roll, 
		   short random_roll, 
		   double average_roll, 
		   char plus_minus)
{
    string die_dice;

    die_dice = (dice > 1) ? "dice" : "die";

    if (adjustment < 0)
    {
        adjustment = -adjustment; // plus_minus takes cares of the sign
    }

    cout << "\nWhen rolling " << dice << " " << sides << "-sided "
         << die_dice << " adjusted by " << plus_minus << adjustment
         << ", your statistics will be:\n"
            "\n\tMinimum:  " << min_roll
         << "\n\tAverage:  " << average_roll
         << "\n\tMaximum:  " << max_roll
         << "\n\nA typical dice roll might result in " << random_roll 
         << ".";
    
    cout << "\n\nThank you for using the DSP!!"
            "\n\nHave a wonderful day!\n\n";
}

int main()
{
    short dice,
          sides,
          adjustment{0},
          min_roll,
          max_roll,
          random_roll;

    double average_roll; 

    char plus_minus;

    srand(static_cast<unsigned>(time(nullptr)));

    get_dice_roll(dice, sides, adjustment, plus_minus);
    calculate_results(dice, sides, adjustment, min_roll, max_roll, 
                      random_roll, average_roll);
    print_results(dice, sides, adjustment, min_roll, max_roll, 
                  random_roll, average_roll, plus_minus);
    
    return 0;
}
