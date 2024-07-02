#include "findsuffix.h"
#include <string>

std::string find_suffix(short value)
{
    short last_digit, second_to_last_digit;
    std::string suffix = "th";

    last_digit = value % 10;

    second_to_last_digit = value / 10 % 10;

    if (second_to_last_digit != 1)
    {
        if (last_digit == 1)
        {
            suffix = "st";
        }
        else if (last_digit == 2)
        {
            suffix = "nd";
        }
        else if (last_digit == 3)
        {
            suffix = "rd";
        }
        else
        {
            suffix = "th";
        }
    }

    return suffix;
}