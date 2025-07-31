#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        return 1;
    }

    unsigned int natNums = stoi(argv[1]);
    unsigned int sumOfSquares = 0;
    unsigned int squareOfSum = 0;
    int difference = 0;

    for (int i = 1; i <= natNums; i++)
    {
        sumOfSquares += i*i;
        squareOfSum += i;
    }
    squareOfSum *= squareOfSum;
    difference = squareOfSum - sumOfSquares;

    cout << difference << endl;
}