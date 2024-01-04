// https://github.com/rahme007
// Convert_an_Array_Into_a_2D_Array_With_Conditions_2610.cpp : The problem is approached with hash mapping.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> umap;
        vector<vector<int>> result;

        for (auto n : nums) {
            if (umap.find(n) == umap.end()) {
                umap[n] = 1;
                if (result.size() ==0) {
                    result.push_back({});
                }
                result[umap[n]-1].push_back(n);
            }
            else {
                umap[n] += 1;
                if (result.size() < umap[n])
                    result.push_back({});
                result[umap[n] - 1].push_back(n);
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = { 1,2,3,4 }; //{ 1,3,4,1,2,3,1 };
    Solution s;
    vector<vector<int>> matrix = s.findMatrix(nums);
    for (int i = 0; i < matrix.size();i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j]<<"\t";
        }
        cout << endl;
    }

    return 0;
}


