#include <iostream>
#include <limits>

using namespace std;

constexpr streamsize INF_FLAG{numeric_limits<streamsize>::max()};

int main()
{
    const short OZ_IN_LB = 16;

    short ounces, pounds, ounces_remaining;

    cout << "\n\t\tWelcome to the Ounce-to-Pound Conversion Program!!!\n\n";
    cout << "Enter number of ounces: ";

    cin >> ounces;
    cin.ignore(INF_FLAG, '\n');

    pounds = ounces / OZ_IN_LB;
    ounces_remaining = ounces % OZ_IN_LB;

    cout << '\n' << ounces << " oz. is equal to " << pounds << " lb(s) and " 
         << ounces_remaining << " oz. (" 
         << static_cast<double>(ounces) / OZ_IN_LB << " lbs.).\n";

    cout << "\nThank you for using the OTP Conversion Program!!\n"
            "\nHave a wonderful day!\n\n";

    return 0;
}