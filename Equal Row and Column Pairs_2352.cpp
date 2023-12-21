
// Product of Array Except Self_238.cpp : the solution is approached using sepearate maps for the rows and cols.
//                                          the approach is a bit expensive but easy to understand

#include <iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<int, vector<int>> rmap;
        unordered_map<int, vector<int>> cmap;

        for (int i = 0;i < grid.size();i++) {
            for (int j = 0; j < grid[i].size();j++) {
                rmap[i].push_back(grid[i][j]); // storing the row values
                cmap[j].push_back(grid[i][j]); // storing the col values
            }
        }
        int count = 0;

        for (int i = 0; i < rmap.size();i++) {
            for (int j = 0;j < cmap.size();j++) {
                if (rmap[i] == cmap[j]) // if row and column are equal
                    count++;
            }
        }
        return count;
    }
};

int main()
{
    vector<vector<int>> grid = { {3,2,1} ,{1,7,6},{2,7,7} };
    //vector<vector<int>> grid = { {3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2} };
    //vector<vector<int>> grid = { {13,13},{13,13} };
    Solution s;
    int r = s.equalPairs(grid);
    cout << r << endl;

    return 0;
}







