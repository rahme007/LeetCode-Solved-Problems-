// Apply_Operations_to_an_Array_2460_C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> res(nums.size(),0);

        int resIdx = 0;
        int numsSize = nums.size();


        for (int i = 0; i < numsSize; i++) {

            if (i < numsSize-1 && nums[i+1] >0 && nums[i] == nums[i + 1]) {
                res[resIdx] = static_cast<long long>(nums[i]) * 2 ;
                nums[i + 1] = 0;
                resIdx++;
            }
            
            else if (nums[i] > 0) {
                res[resIdx] = nums[i];
                resIdx++;
            }

        }


        return res;

    }
};

int main()
{
    Solution s;

    //vector<int> nums = { 1,2,2,1,1,0 };
    vector<int> nums = { 847,847,0,0,0,399,416,416,879,879,206,206,206,272 }; //{0, 1};

    vector<int> res = s.applyOperations(nums);

    for (auto i : res)
        cout << i << "\t";

    return 0;
}


