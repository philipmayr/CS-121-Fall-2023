#include <iostream>
#include <cmath>

using namespace std;

constexpr streamsize INF_FLAG{numeric_limits<streamsize>::max()};

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

int main()
{
    short number, numerator, denominator, digit_count;
    char y_n, slash;
    bool has_fraction; 
    string roman;

    cout << "\n\t\tWelcome to the Roman Numeral Program!!!\n";

    while (tolower(y_n) != 'n')
    {
        roman = "";
        has_fraction = false;
        cout << "\nEnter a number: ";

        cin >> number;

        while (number < 1 || number > 3999 || !cin)
        {
            if (!cin)
            {
                cin.clear();
                cin.ignore(INF_FLAG, '\n');
                cout << "\nPlease enter a number "
                        "greater than 0 and less than 4000: ";
            }
            else if (number < 1)
            {
                cout << "\nPlease enter a number greater than 0: ";
            }
            else if (number > 3999)
            {
                cout << "\nPlease enter a number less than 4000: ";
            }
            cin >> number;
        }

        if (cin.peek() != '\n')
        {
            cin >> numerator >> slash >> denominator;
            has_fraction = true;
        }

        digit_count = count_digits(number);

        cout << "\n";

        for (short i = digit_count; i > 0; i--)
        {
            short digit, multiplier;
            multiplier = static_cast<short>(pow(10, i - 1));
            digit = static_cast<short>(number / multiplier % 10);

            string letters,
                   hundreds = "MDC",
                   tens = "CLX",
                   ones = "XVI";

            switch(i) 
            {
                case 4:
                    for (short j = 1; j <= digit; j++)
                    {
                        roman += 'M';
                    }
                    continue;
                case 3:
                    letters = hundreds;
                    break;
                case 2:
                    letters = tens;
                    break;
                case 1:
                    letters = ones;
                    break;
            }
            
            if (digit == 9)
            {
                roman += letters[2];
                roman += letters[0];
            }
            else if (digit == 4)
            {
                roman += letters[2];
                roman += letters[1];
            }
            else if (digit > 4 || digit < 4)
            {
                if (digit > 4)
                {
                    roman += letters[1];
                    digit -= 5;
                }
                for (short j = 1; j <= digit; j++)
                {
                    roman += letters[2];
                }
            }
        }

        if (has_fraction)
        {
            short multiplier;

            multiplier = 12 / denominator;

            numerator *= multiplier;

            if (12 % denominator != 0)
            {
                cout << "Invalid fraction entered.\n"
                        "Only duodecimal (base twelve) fractions "
                        "are supported.\n";
                continue;
            }

            if (numerator > 5)
            {
                roman += 'S';
                numerator -= 6;
            }

            for (short i = 0; i < numerator; i++)
            {
                roman += '.';
            }
        }

        cout << roman << "\n\n";

        cout << "Would you like to convert another number? Enter yes/no: ";

        cin >> y_n;
        cin.ignore(INF_FLAG, '\n');
    }

    cout << "\n";
}
