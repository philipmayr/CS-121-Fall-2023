#include "ispalindrome.h"
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string input_str;

    cout << "\nA Palindrome is a word, phrase, or sequence that reads "
         << "alike backward as forward."

         << "\n\nThis program looks for palindromes. "
         << "Enter a word, phrase, or sequence below:\n\n";

    getline(cin, input_str);

    cout << "\n\"" << input_str << "\""
         << " is " << (is_palindrome(input_str) ? "" : "Not ") 
         << "a Palindrome.\n\n";
}
