#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    // Is an argument provided
    if (argc < 2)
    {
        cerr << "Provide a positive integer" << endl;
    }

    int target = stoi(argv[1]);
    int prev = 1;
    int i = 1;
    int buffer = 0;
    int sum = 0;
    while (i <= target)
    {
        if (!(i % 2))
        {
            sum += i;
        }
        buffer = prev;
        prev = i;
        i += buffer;
        cout << i << ", ";
    }

    cout << endl << sum << endl;
    return(0);
}