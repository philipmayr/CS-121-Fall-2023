#include <iostream>
#include <string>
#include <cmath>
#include <limits>

using namespace std;

constexpr streamsize INF_FLAG{numeric_limits<streamsize>::max()};

int main()
{
    double budget_allotment, money_spent, money_spent_percentage;

    char leading_currency_unit, trailing_currency_unit, yes_no;

    bool invalid = true;

    cout << "\n\t\tWelcome to the Budget Projection Program!!!\n";

    while (tolower(yes_no) != 'n')
    {
        while (invalid)
        {
            budget_allotment = 0;
            leading_currency_unit = '\0';
            trailing_currency_unit = '\0';
            cout << "\nWhat was your budget allotment last year? ";

            cin.clear();

            cin >> ws;
            if (!isdigit(cin.peek()))
            {
                cin >> leading_currency_unit;
            }

            if (isdigit(cin.peek()))
            {
                cin >> budget_allotment;
            }

            while (cin.peek() != '\n' && isspace(cin.peek()))
            {
                cin.ignore();
            }

            if (!isdigit(cin.peek()) && cin.peek() != '\n')
            {
                cin >> trailing_currency_unit;
            }

            if (budget_allotment < 1)
            {
                cin.ignore(INF_FLAG, '\n');
                cout << "\n\nInvalid amount entered.\n\n";
            } 
            else
            {
                invalid = false;
            }
        }
        
        invalid = true;

        while (invalid)
        {
            money_spent = 0;
            leading_currency_unit = '\0';
            trailing_currency_unit = '\0';
                                
            cout << "How much did you spend last year? ";

            cin.clear();

            cin >> ws;
            if (!isdigit(cin.peek()))
            {
                cin >> leading_currency_unit;
            }

            if (isdigit(cin.peek()))
            {
                cin >> money_spent;
            }
            
            while (cin.peek() != '\n' && isspace(cin.peek()))
            {
                cin.ignore();
            }

            if (!isdigit(cin.peek()) && cin.peek() != '\n')
            {
                cin >> trailing_currency_unit;
            }

            if (money_spent < 1)
            {
                cin.ignore(INF_FLAG, '\n');
                cout << "\n\nInvalid amount entered.\n\n";
            } 
            else
            {
                invalid = false;
            }
        }

        invalid = true;

        cout << "\nThank you!!  Calculating...  ";

        money_spent_percentage = floor(((money_spent / budget_allotment) 
                                        * 100) + .5);

        cout << "Done.";

        cout << "\n\nLast year you used up approximately "
                << money_spent_percentage << "% of your budget.";

        cout.setf(ios_base::fixed);

        cout.precision(2);

        cout << "\n\nYour budget next year will be " 
                << leading_currency_unit << (floor(money_spent + 100) -
                                            (fmod(money_spent, 100))) 
                << trailing_currency_unit << ".";

        cout << "\n\nWould you like to repeat the program? Enter yes/no: ";

        cin >> yes_no;
        cin.ignore(INF_FLAG, '\n');
}
    cout << "\nThank you for using the BPP!!"
         << "\n\nEndeavour to have a prudential day!\n\n";
}
