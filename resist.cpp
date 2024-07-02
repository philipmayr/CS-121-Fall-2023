#include <iostream>
#include <limits>

using namespace std;

constexpr streamsize INF_FLAG{numeric_limits<streamsize>::max()};

int main(void)
{
    cout << "\n\t\tWelcome to the Series and Parallel "
            "Circuit Resistance Calculator!\n";

    short value,
          first_value,
          second_value,
          series_resistance;

    bool yes = true;

    char yes_no;

    double parallel_resistance, parallel_resistance_denominator;

    cout << "\nPlease enter the first resistance value in ohms: ";
    cin >> first_value;

    cin.ignore(INF_FLAG, '\n');

    cout << "Please enter the second resistance value in ohms: ";
    cin >> second_value;

    cout << "\nYou entered " << first_value << " ohms and "
         << second_value << " ohms. Calculating...";

    series_resistance = first_value + second_value;

    parallel_resistance = 
    (first_value * second_value) / (static_cast<double>(first_value) +
    static_cast<double>(second_value));

    cout << "\n\nDone.\n";

    cout << "The total series circuit resistance adds up to " 
         << series_resistance << " ohms.\n";
    cout << "The total parallel circuit resistance adds up to " 
         << parallel_resistance << " ohms.\n";

    parallel_resistance_denominator = 
    (1 / static_cast<double>(first_value)) +
    (1 / static_cast<double>(second_value));

    while (yes)
    {
        cin.clear();
        cout << "\nWould you like to add on another resistor? "
                "Enter yes or no: ";
        cin >> yes_no;

        cin.ignore(INF_FLAG, '\n');
        cin.clear();

        if (tolower(yes_no) != 'n')
        {
            yes = true;
            cout << "\nPlease enter the next resistance value in ohms: ";
            cin >> value;
            series_resistance += value;
            parallel_resistance_denominator += 
            (1 / static_cast<double>(value));
            cin.ignore(INF_FLAG, '\n');
        } else
        {
            yes = false;
        }
    }

    parallel_resistance = (1 / parallel_resistance_denominator);

    cout << "\n\nWith the add'l. resistors, "
            "the total series circuit resistance is: " 
         << series_resistance;
    cout << "\nWith the add'l. resistors, "
            "the total parallel circuit resistance is: " 
         << parallel_resistance;

    cout << "\n\nThanks for using the Series and Parallel "
            "Circuit Resistance Calculator!\n";

    cout << "\nHave a wonderful day!\n\n";

    return 0;
}
