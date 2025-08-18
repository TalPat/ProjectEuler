#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define FILE_NAME "0067_triangle.txt"

vector<vector<int>> loadTriFromFile(const string& filename) {
    vector<vector<int>> tri;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Could not open file " << filename << endl;
        return tri;
    }
    
    string line;
    while (getline(file, line)) {
        vector<int> row;
        istringstream iss(line);
        int num;
        
        while (iss >> num) {
            row.push_back(num);
        }
        
        if (!row.empty()) {  // Skip empty lines
            tri.push_back(row);
        }
    }
    file.close();
    return tri;
}

int main()
{

    cout << "a" << endl;
    vector<vector<int>> triangle = loadTriFromFile(FILE_NAME);
    cout << "b" << endl;
    
    for (int i = triangle.size() - 1; i > 0; i--)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            int valLeft = triangle[i - 1][j] + triangle[i][j];
            int valRight = triangle[i - 1][j] + triangle[i][j + 1];
            if (valLeft > valRight)
            {
                triangle[i - 1][j] = valLeft;
            }
            else
            {
                triangle[i - 1][j] = valRight;
            }
        }
    }
    cout << triangle[0][0] << endl;
    return 0;
}
