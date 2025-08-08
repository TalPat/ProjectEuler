#include <iostream>
#include <string>

using namespace std;

// zero, one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen.
const int unique0to19[] = {
    0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};

// zero, twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety.
const int uniqueTens[] = {
    0, 6, 6, 5, 5, 5, 7, 6, 6};

unsigned int numLetters(unsigned int number)
{
    // edge case
    if (number == 1000)
    {
        return 11;
    }

    unsigned int letterSum = 0;

    // one hundred+ value
    if (number > 99)
    {
        // letters in hundred + letters in hundred digit
        letterSum += unique0to19[number / 100] + 7;
        // add and if mod 100
        if (number % 100)
        {
            letterSum += 3;
        }
    }
    number %= 100;
    if (number > 19)
    {
        letterSum += uniqueTens[number / 10 - 1] + unique0to19[number % 10];
    }
    else
    {
        letterSum += unique0to19[number % 20];
    }
    return (letterSum);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        return 1;
    }

    int target = stoi(argv[1]);
    if (target < 1 || target > 1000)
    {
        return 1;
    }

    unsigned int letterSum = 0;

    for (int i = 1; i <= target; i++)
    {
        letterSum += numLetters(i);
    }

    cout << "number of letters in " << target << ": " << numLetters(target) << endl;
    cout <<"number of letters in all numbers up to "<< target << ": " << letterSum << endl;

    return 0;
}