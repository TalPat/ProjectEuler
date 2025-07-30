#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    // Is an argument provided
    if (argc < 2)
    {
        cerr << "Provide a positive integer" << endl;
        return 1;
    }

    int target = stoi(argv[1]);
    // vector<int> factors;
    int total = 0;

    for (int i = 0; i < target; i++)
    {
        if (!(i % 3) || !(i % 5))
        {
            // factors.push_back(i);
            total += i;
        }
    }

    cout << total << endl;
    return 0;
}