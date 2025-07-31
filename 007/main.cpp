#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// check if prime
bool isPrime(int num)
{
    if (num < 2 || (num % 2 == 0 && num != 2))
    {
        return 0;
    }
    if (num == 2)
    {
        return 1;
    }

    for (int i = 3; i <= sqrt(num); i += 2)
    {
        if (!(num % i))
        {
            return (0);
        }
    }
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        return 1;
    }

    unsigned int target = stoi(argv[1]);
    unsigned int counter = 0;
    unsigned int i;

    for (i = 2; counter <= target-1; i++) {
        if (isPrime(i)) {
            counter++;
            // cout << i << endl;
        }
    }
    
            cout << i-1 << endl;
}