#include <iostream>
#include <string>

const int digits = 1000;
using namespace std;

void doubleNumber(char *num)
{
    int index = digits - 1;
    int carry = 0;

    while (index > 0)
    {
        int val = 2 * (num[index] - '0') + carry;
        num[index] = (val % 10) + '0';
        carry = val / 10;
        index--;
    }
}

unsigned long sumDigits(char *num)
{
    unsigned long sum;
    int index = 0;

    while (num[index])
    {
        sum += num[index] - '0';
        index++;
    }
    return sum;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        return 1;
    }

    int power = stoi(argv[1]);
    char number[digits + 1];

    // format string to 1 with leading zeroes and terminate
    for (int i = 0; i < digits; i++)
    {
        number[i] = '0';
    }
    number[digits - 1] = '1';
    number[digits] = 0;

    for (int i = 0; i < power; i++)
    {
        doubleNumber(number);
    }

    cout << sumDigits(number);
    return 0;
}