#include <iostream>

using namespace std;

struct Range {
        short min, max;
    } range;

auto get_range()
{
    char bracket, dot;
    short min, max;

    Range range;

    cin >> bracket >> range.min >> dot >> dot >> range.max >> bracket;

    return range;
}

void find_roll(Range range)
{
    short quotient;
    quotient = range.max % range.min;
    if (quotient == 0 )
    {
        
    }
}

int main()
{
	cout << "\n\t\tWelcome to the Developer's Dice Program!!!\n\n";

    cout << "Enter desired range: ";

    auto range = get_range();

    find_roll(range);

    cout << "Thank you!! Calculating... Done.";

    cout << "A range of [" << "..] results from rolling " << "";

    cout << "\nThank you for using the DDP!!\n";

    cout << "\nHave a good day.\n\n";
}
