#include <iostream>

using namespace std;

int main()
{
    short dice,
          sides,
          result;
          
    double average;
    
    char d;
          
    srand(static_cast<unsigned>(time(nullptr)));
          
    cout << "\n\t\tWelcome to the Dice Statistics Programs!!!\n";
   
    cout << "\nEnter your dice roll: ";
    cin >> dice >> d >> sides;
    
    cout << "\n\nThank you!! Calculating...  ";
    average = (dice + (dice * sides)) / 2.0;
    
    // result = rand() % ((sides * dice) - dice + 1) + dice;
    
    for (int i = 0; i < dice; i++)
        result += static_cast<short>(rand() % (sides + 1));
    
    cout << "Done.\n";
    
    cout << "\nWhen rolling " << dice << " dice of " << sides << " sides, " 
         << "your statistics will be:\n"
         << "\n\tMinimum: " << dice
         << "\n\tAverage: " << average
         << "\n\tMaximum: " << dice * sides
         << "\n\nA typical dice roll might result in " << result << ".";
    
    cout << "\n\nThank you for using the DSP!!"
         << "\n\nHave a wonderful day!\n\n";
    
    return 0;
}
