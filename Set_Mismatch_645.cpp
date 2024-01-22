//https://github.com/rahme007
// Runtime: 31 ms (better than 50% users)
// Set_Mismatch_645_C++.cpp : The approach is to sort the array and then find the duplicate 
// and then find the missing value from the sum of range
//

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        int sum = nums[0];
        int dupNum;
        for (int i = 1; i < nums.size();i++) {
            if (nums[i] == nums[i - 1])
                dupNum = nums[i];
            sum += nums[i];

        }
        int realSum = (nums.size() * (nums.size() + 1)) / 2;

        result.push_back(dupNum);
        result.push_back(realSum - (sum - dupNum));

        return result;
    }
};

int main()
{
    vector<int> nums = {1,2,2,4};
    Solution s;
    vector<int> r = s.findErrorNums(nums);

    cout << "[" << r[0] << "," << r[1] << "]" << endl;

    return 0;
}


