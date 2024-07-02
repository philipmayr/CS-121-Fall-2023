#include "ispalindrome.h"
#include <cctype>
#include <string>

bool is_palindrome(std::string str)
{
    std::string::size_type len = str.length();
    bool is_palindrome = true;

    for (std::string::size_type i = 0, j = len - 1; 
         i <= j && is_palindrome; 
         i++, j--)
    {
        if ((ispunct(str[i]) || isspace(str[i])) && 
            (ispunct(str[j]) || isspace(str[j])))
        {
            continue;
        }
        else if (ispunct(str[i]) || isspace(str[i]))
        {
            j++;
        }
        else if (ispunct(str[j]) || isspace(str[j]))
        {
            i--;
        }
        else if (tolower(str[i]) != tolower(str[j]))
        {
            is_palindrome = false;
        }
    }
    
    return is_palindrome;
}
