#include <iostream>

using namespace std;

int main()
{
    char symbol;

    double x1,
           y1,
           x2,
           y2;

    double midpoint_x,
           midpoint_y;

    cout << "\n\t\tWelcome to the 2D Midpoint Program!\n\n";

    cout << "What is the first endpoint? ";

    cin >> symbol >> x1 >> symbol >> y1 >> symbol;

    cout << "What is the second endpoint? ";

    cin >> symbol >> x2 >> symbol >> y2 >> symbol;

    cout << "\nCalculating... ";

    midpoint_x = ((x1 + x2) / 2);
    midpoint_y = ((y1 + y2) / 2);

    cout << "Done.\n";

    cout << "\nThe midpoint of the line segment between points "
	    "(" << x1 << ", " << y1 << ") and (" << x2 << ", " << y2 << ")"
	    " is (" << midpoint_x << ", " << midpoint_y << ").\n";

    cout << "\nThank you for using the 2D Midpoint Program!\n";

    cout << "\nHave a bright day!\n\n";

    return 0;
}