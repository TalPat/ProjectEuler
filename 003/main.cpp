#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        return 1;
    }

    unsigned long long input = stoull(argv[1]);
    int largestPrime = 1;

    // edgecase input is 1
    if (input == 1)
    {
        cout << largestPrime << endl;
        return 0;
    }

    while (!(input % 2))
    {
        largestPrime = 2;
        input /= 2;
        cout << largestPrime << endl;
    }

    for (int i = 3; i <= sqrt(input); i += 2)
    {
        while (!(input % i))
        {
            input /= i;
            largestPrime = i;
            cout << largestPrime << endl;
        }
        // cout << i << "  " << sqrt(input) << " " << input << endl;
    }

    if (input > 2)
    {
        largestPrime = input;
    }

    cout << largestPrime << endl;
    return 0;
}