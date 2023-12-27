//  https://github.com/rahme007
//Minimum_Time_to_Make_Rope_Colorful_1578.cpp : The approach is based on two-pointers solution
//

#include <iostream>
#include<vector>


using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int minTime = 0; // total sum of balloon removal time
        int left = 0, right = 0; // initialize two pointers
        int total = 0; // total sum of time with same colors
        int maxVal = 0; // maximum time needed to remove balloon
                        //for repeated color
        int numOccur = 0; // find occurrence of same color

        while (right < neededTime.size()) {
            while (colors[left] == colors[right]) {
                if (numOccur > 0) {
                    total += neededTime[right];
                    maxVal = neededTime[right] > maxVal ? neededTime[right] : maxVal;
                    right++;
                }
                numOccur++;

            }

            left = right;
            minTime += total - maxVal;
            maxVal = 0;
            total = 0;
            numOccur = 0;


        }
        return minTime;
    }
};


int main()
{
    string colors = "aaabbbabbbb"; //"a";//"aabaa"; //"abc"; //"aaabbbabbbb";
    vector<int> neededTime = { 3,5,10,7,5,3,5,5,4,8,1 }; //{ 1 }; //{ 1,2,3,4,1 }; //{ 1,2,3 }; //{ 3,5,10,7,5,3,5,5,4,8,1 };
    Solution s;
    int minTime = s.minCost(colors, neededTime);
    cout << minTime << endl;

    return 0;
}


