#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(int i, int j,int rowSize) {
        if (i + 1 >= rowSize || j - 1 < 0)
            return false;
        else
            return true;
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int rowSize = nums.size();
        int colSize=0;
        vector<int> result;
        vector<vector<int>>isVisitedArr(rowSize, vector<int>(nums[0].size(), 0));

        for (int i = 0;i < nums.size();i++) {
            for (int j = 0;j < nums[i].size();j++) { 
                isVisitedArr[i].push_back(0);
            }
        }

        vector<int> stack;

        for (int i=0;i<nums.size();i++)
            for (int j = 0;j < nums[i].size();j++) {
                if (isVisitedArr[i][j])
                    continue;

                if (!isValid(i, j, rowSize)) {
                    result.push_back(nums[i][j]);
                    isVisitedArr[i][j] = 1;
                    continue;
                }

                vector<int> current = { i,j };
               stack.push_back(nums[i][j]);
               isVisitedArr[current[0]][current[1]] = 1;
                int p = current[0]; int q = current[1];
                while (isValid(p, q, rowSize)) {
                    if (q - 1 >= nums[p + 1].size()) {
                        p = p + 1;
                        q = q - 1;
                        continue;
                    }

                    if (nums[p + 1][q - 1]) {
                        stack.push_back(nums[p + 1][q - 1]);
                        isVisitedArr[p + 1][q - 1] = 1;
                    }

                    p = p + 1;
                    q = q - 1;

                }
                while (!stack.empty()) {
                    int currentVal = stack.back();
                    stack.pop_back();
                    result.push_back(currentVal);

                }




            }


        
        return result;
    }
};

int main()
{
    //vector<vector<int>> nums = { {1,2,3},{4,5,6},{7,8,9} };
    vector<vector<int>> nums = { {6},{8},{6,1,6,16} };
    //vector<vector<int>> nums = { {1, 2, 3, 4, 5},{6, 7},{8},{9, 10, 11},{12, 13, 14, 15, 16} };
    Solution s;
    vector<int> res = s.findDiagonalOrder(nums);
    for (auto v : res) {
        cout << v << "\t";
    }
    return 0;
}