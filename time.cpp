#include <iostream>
#include <string>
#include <ctime>

using namespace std;

bool is_leap(short year);

int main() {
    const short seconds_per_minute = 60,
            minutes_per_hour = 60,
            seconds_per_hour = seconds_per_minute * minutes_per_hour,
            hours_per_day = 24,
            CDT_offset = -5;

    const long seconds_per_day =
            static_cast<long>(seconds_per_hour) * hours_per_day;

    long seconds_today = time(nullptr) % seconds_per_day;

    short current_hour = seconds_today / seconds_per_hour,
            current_minute =
            seconds_today % seconds_per_hour / seconds_per_minute,
            current_second =
            seconds_today % seconds_per_hour % seconds_per_minute;

    current_hour += CDT_offset;

    short twelve_hr_clock_hour = current_hour % 12;

    string am_pm = "AM";

    if (current_hour >= 12) {
        am_pm = "PM";
    }

    cout << "\nThe current time is " << current_hour << ':';
    cout.fill('0');
    cout.width(2);
    cout << current_minute << ":";
    cout.width(2);
    cout << current_second << " (";
    cout << twelve_hr_clock_hour << ":";
    cout.width(2);
    cout << current_minute << ":";
    cout.width(2);
    cout << current_second << " " <<
         am_pm << ").\n\n";
}