#include <iostream>
#include <cmath>

using namespace std;

double get_distance(double first_x, double first_y, double second_x, double second_y) {
    return sqrt(pow(second_x - first_x, 2) + 
	        pow(second_y - first_y, 2) * 1.0);
}

int main() {
    cout << "\n\t\tWelcome to the 2D Distance Program!!!\n";

    double first_x,
           first_y,
           second_x,
           second_y,
           distance;

    char symbol;

    cout << "\nEnter first point x and y coordinates (x, y): ";
    cin >> symbol >> first_x >> symbol >> first_y >> symbol;
    cout << "\nEnter second point x and y coordinates (x, y): ";
    cin >> symbol >> second_x >> symbol >> second_y >> symbol;

    cout << "\n\nThank you!!  Calculating...  ";
    distance = get_distance(first_x, first_y, second_x, second_y);
    cout << "Done." << "\n\n(" << first_x << ", " << first_y << ") is " <<
    distance << " units away from (" << second_x << ", " << second_y << ").";

    cout << "\n\nThank you for using the TDP!!\n";
    cout << "\nHave a wonderful day!\n";
    return 0;
}