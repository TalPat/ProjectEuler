#include <iostream>
#include <string>

using namespace std;

unsigned long long binomCoefTable[64][64];

int depth = 0;

unsigned long long pascalCalculator(int n, int k)
{
    depth++;
    if (binomCoefTable[n][k] != 0)
    {
        return binomCoefTable[n][k];
    }
    if (n == k || k == 0)
    {
        binomCoefTable[n][k] = 1;
        return 1;
    }
    else
    {
        binomCoefTable[n][k] = pascalCalculator(n - 1, k - 1) + pascalCalculator(n - 1, k);
        return (binomCoefTable[n][k]);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        return 1;
    }

    int gridSize = stoi(argv[1]);

    // the problem can be considered a combinatorics problem where grid size is x and we need to choose x items from 2x. we can use the formula C(n,r)=n!/(r!*(n-r)!) C(2x,x)=(2x)!/(x!*x!)

    // issues arrive with large numbers due to overflow. Use Pascals theorem (n k)=(n-1 k-1) + (n-1 k) to calculate

    // depth is exponential, use memoization to spped up process

    cout << pascalCalculator(2 * gridSize, gridSize) << endl;

    cout << "Recursive function calls: " << depth << endl;

    return 0;
}