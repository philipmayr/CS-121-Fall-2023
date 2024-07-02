#include <iostream>
#include <string>
#include <cmath>
#include <ctype.h>

using namespace std;

constexpr streamsize INF_FLAG{numeric_limits<streamsize>::max()};

short get_numerical_input(string prompt)
{
    short input;
    while (true)
    {
        cin.clear();
        cout << prompt;

        while (!isdigit(cin.peek()) && cin.peek() != '\n')
        {
            cin.ignore(); 
        }

        if (isdigit(cin.peek()))
        {
            cin >> input;
        }

        cin.clear();
        cin.ignore(INF_FLAG, '\n');

        if (input < 1)
        {
            cout << "\nInput value must be greater than zero. "
                    "Please try again.\n";
            continue;
        }
        else
        {
            break;
        }
    }

    return input;
}

string set_modifier(double & occupancy_percent, 
                    double & rounded_occupancy_percent, 
                    string & modifier)
{
    if (rounded_occupancy_percent > occupancy_percent)
    {
        modifier = "just over ";
    }
    else if (rounded_occupancy_percent < occupancy_percent)
    {
        modifier = "nearly ";
    }

    return modifier;
}

double calculate_occupancy_percent(short & occupancy, short & capacity)
{
    return static_cast<double>(occupancy) / capacity * 100.0;
}

double calculate_rounded_occupancy_percent(double & occupancy_percent)
{
    return floor(occupancy_percent + 0.5);
}

int main(void)
{
    short capacity, occupancy;
    string prompt = "";
    bool yes = true;
    char yes_no;

    cout << "\n\t\tWelcome to the Room Capacity Program!!!\n";

    while(yes)
    {
        capacity = 0;
        occupancy = 0;
        
        prompt = "\nWhat is the room's maximum occupancy? ";
        capacity = get_numerical_input(prompt);
    
        prompt = "\nWhat is the room's current occupancy? ";
        occupancy = get_numerical_input(prompt);
        
        string modifier = "";

        double occupancy_percent, rounded_occupancy_percent;

        occupancy_percent = 
        calculate_occupancy_percent(occupancy, capacity);

        rounded_occupancy_percent = 
        calculate_rounded_occupancy_percent(occupancy_percent);

        modifier = 
        set_modifier(occupancy_percent, rounded_occupancy_percent, 
                     modifier);

        cout << "\n\nThe room is at " << modifier 
             << rounded_occupancy_percent << "% legal capacity!";

        if (occupancy < capacity)
        {
            cout << "\n\nThe room has not reached maximum capacity; "
                    "therefore, the meeting is legal.";
            cout << "\n\nThere is still room for " 
                 << (capacity - occupancy) << " more occupant(s).\n";
        }
        else if (occupancy == capacity)
        {
            cout << "\n\nThe room has not exceeded maximum capacity; "
                    "therefore, the meeting is legal.\n";
        }
        else
        {
            cout << "\n\nThe room has exceeded maximum capacity; "
                    "therefore, the meeting is illegal.";
            cout << "\n\nAt least " << occupancy - capacity 
                 << " occupant(s) must leave the room.\n";
        }

        cout << "\n\nWould you like to run the program again? "
                "Enter yes/no: ";

        cin >> yes_no;
        cin.ignore(INF_FLAG, '\n');
    
        yes = (tolower(yes_no) != 'y') ? false : true;
    }
    cout << "\n\nThank you for trying out the RCP!!";

    cout << "\n\nHave a bright day!\n\n";
}
