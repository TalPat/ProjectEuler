#include <iostream>
#include <string>
#include <cmath>

using namespace std;

unsigned int countFactors(unsigned int num)
{
    if (num == 1)
    {
        return 1;
    }
    unsigned int counter = 1;
    for (int i = 1; i < sqrt(num); i++)
    {
        if (num % i == 0)
        {
            counter += 2;
        }
    }
    if (sqrt(num) == (int) sqrt(num)) {
        counter++;
    }
    return counter;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        return 1;
    }

    unsigned int triNum = 1;
    unsigned int counter = 1;

    unsigned int factorNum = stoi(argv[1]);

    while (countFactors(triNum) < factorNum)
    {
        int factorCount = countFactors(triNum);
        cout << "Tri-Number: " << triNum << ", Factors: " << factorCount << endl;
        counter++;
        triNum += counter;
    }
    cout << "Tri-Number: " << triNum << ", Factors: " << countFactors(triNum) << endl;
    return 0;
}