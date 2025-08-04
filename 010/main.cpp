#include <iostream>
#include <cmath>
#include <string>

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
    if (argc < 2)
    {
        cout << "Invalid parametes" << endl;
        return 1;
    }

    int target = stoi(argv[1]);
    long long sum = 0;

    for (int i = 2; i < target; i++)
    {
        if (isPrime(i))
        {
            sum += i;
        }
    }

    cout << sum << endl;
    return 0;
}