#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int maxVal = 0;
        sort(piles.begin(), piles.end());

        if (piles.size() == 3) {
            return piles[1];
        }

        int left = 0;
        int right = piles.size() - 1;

        while (right - left >= 2) {
            maxVal += piles[right - 1];
            right -= 2;
            left++;
        }
        return maxVal;
    }
};

int main()
{
    //vector<int> piles = { 2,4,1,2,7,8 };
    vector<int> piles = { 9,8,7,6,5,4,3,2,1};
    Solution s;
    int maxVal = s.maxCoins(piles);
    cout << maxVal << endl;
}
