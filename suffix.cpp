#include "findsuffix.h"
#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    short value;
    string suffix = "th";
    char yes_no;
	
    cout << "\n\t\tWelcome to the Suffix Testing Program!!!\n\n";

    cout << "Enter a value: ";

    cin >> value;

    suffix = find_suffix(value);

    cout << '\n' << value << suffix << '\n';

    cout << "\nTest another value? Enter y/n: ";

    cin >> yes_no;

    cout << "\nThank you for using the STP!!\n";

    cout << "\nHave a wonderful day!\n\n";
}
