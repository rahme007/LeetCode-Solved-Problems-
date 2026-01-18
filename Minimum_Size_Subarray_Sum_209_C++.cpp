// Minimum_Size_Subarray_Sum_209_C++.cpp
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int minVal = nums.size() +1;
        int sum = 0;

        while (left < nums.size() && right < nums.size()) {
 
            if (sum < target) {
                sum += nums[right];

            }

            if (sum >= target) {
                if (minVal > (right - left + 1))
                    minVal = (right - left + 1);
                sum -= nums[left];
                left++;
            }

            if (sum <target)
                right++;

        }

        if (left == 0)
            return 0;

        return minVal;
    }
};

int main()
{
    Solution s;

    vector<int> nums = { 2,3,1,2,4,3 };
    int target = 7;

    cout << s.minSubArrayLen(target, nums) << endl;

    return 0;
}


