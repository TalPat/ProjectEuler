#include <iostream>
#include <string>

using namespace std;
// Monday: 0 ... Sunday: 6
// January: 0 ... December: 11

int day = 1;
int month = 0;
int year = 1900;
int weekDay = 0;

const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int daysInMonthLY[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear()
{
    return (!(year % 400) || (!(year % 4) && (year % 100)));
}

void incrementDay()
{
    day++;
    weekDay++;
    if (weekDay > 6)
    {
        weekDay = 0;
    }
    if (isLeapYear())
    {
        if (day > daysInMonthLY[month])
        {
            day = 1;
            month++;
            if (month > 11)
            {
                month = 0;
                year++;
            }
        }
    }
    else
    {
        if (day > daysInMonth[month])
        {
            day = 1;
            month++;
            if (month > 11)
            {
                month = 0;
                year++;
            }
        }
    }
}

int main()
{
    int counter = 0;

    while (year < 2001)
    {
        if (year > 1900)
        {
            if (day == 1 && weekDay == 6)
            {
                counter++;
            }
        }
        incrementDay();
    }

    cout << counter << endl;

    return 0;
}