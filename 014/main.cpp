#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> chainLengths(1000000);

int countCollatz(unsigned long long num)
{
    int startingNum = num;
    int counter = 0;
    while (num != 1)
    {
        if (num < startingNum)
        {
            counter += chainLengths[num];
            break;
        }
        if (num % 2)
        {
            num = 3 * num + 1;
        }
        else
        {
            num /= 2;
        }
        counter++;
    }
    if (num == 1)
    {
        counter++;
    }
    chainLengths[startingNum] = counter;
    return counter;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        return 1;
    }

    int target = stoi(argv[1]);

    if (target < 1 || target > 1000000)
    {
        return 1;
    }
    int largest = 0;
    int largestStarter = 1;

    for (int i = 1; i < target; i++)
    {
        int count = countCollatz(i);

        if (count > largest)
        {
            largest = count;
            largestStarter = i;
        }
    }
    cout << largestStarter << ": " << largest << endl;
    return 0;
}