#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char* arrgv[]) {
    for(int i = 1; i < 1000; i++) {
        for(int j = i; j <1000; j++) {
            long c = sqrt(i*i+j*j);
            if (sqrt(i*i+j*j) == c && i+j+c == 1000) {
                cout << i << " + " << j << " + " << long(sqrt(i*i+j*j)) << endl;
                cout << i * j * c << endl;
                return 0;
            }
        }
    }
}