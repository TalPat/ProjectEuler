#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    // find largest palindrommic number then check if multiple of 3 digit numbers
    // go down from 999x999 = 998001
    // 997799 is the largest candidate. Itterate from 997
    //  factorize from square root.
    // 100*100 = 100001
    int palindromicNum;
    for (int i = 997; i >= 100; i--)
    {
        palindromicNum = (i * 1000) + (i % 10 * 100) + (i / 10 % 10 * 10) + (i / 100);
        cout << palindromicNum << endl;

        for (int j = sqrt(palindromicNum); j > 100 && palindromicNum/j < 1000; j--)
        {
            if (palindromicNum % j == 0 && palindromicNum / j > 100)
            {
                cout << palindromicNum / j << " * " << j << endl;
                cout << palindromicNum << endl;
                return 0;
            }
        }
    }

    return 0;
}