// https://github.com/rahme007
// Longest_Increasing_Subsequence_300.cpp : The problem is approached by greedy binary search algorithm .
// Runtime: 27 ms (beats ~74%)
// Memory: 17.43 MB (beats ~27%)

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int smallestNumIdx(vector<int>subArr, int target) {
        int left = 0; // lowest number idx than target
        int right = subArr.size() - 1; // highest number idx than target
        sort(subArr.begin(), subArr.end());
        while (left <= right) {
            int mid = (left + right) / 2;
            if (subArr[mid] < target) {
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return left;
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub{nums[0]};
        for (int i = 1;i < nums.size(); i++) {
            if (sub[sub.size()-1]< nums[i]) {
                sub.push_back(nums[i]);
            }
            else {
                int idx = smallestNumIdx(sub, nums[i]);
                sub[idx] = nums[i];
            }
        }
        return sub.size();
    }
};


int main()
{
    vector<int> nums = { 10,9,2,5,3,7,101,18 };
    Solution s;
    int len = s.lengthOfLIS(nums);
    cout << len << endl;

    return 0;
}


