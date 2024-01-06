// https://github.com/rahme007
// Minimum_Index_Sum_of_Two_Lists_599.cpp : The approach is to use hash map for the first
//                                          list and then find the minimum index while
//                                          traversing through list2;
//
// Leet Code Run time: 65 ms (beats 83.94% of users)

#include <iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int>umap;
        int minIdx = 2000;
        vector<string> commonIdx{};
        for (int i = 0;i < list1.size();i++) {
            umap[list1[i]] = i;
        }
        for (int j = 0;j < list2.size();j++) {
            if (umap.find(list2[j]) != umap.end()) {
                int sumIdx = j + umap.at(list2[j]);
                if (sumIdx < minIdx) {
                    commonIdx = {};
                    minIdx = sumIdx;
                    commonIdx.push_back(list2[j]);
                }
                else if (sumIdx == minIdx) {
                    commonIdx.push_back(list2[j]);
                }


            }
        }

        return commonIdx;
    }
};


int main()
{
    vector<string> list1 = { "happy","sad","good" }; //{ "Shogun", "Tapioca Express", "Burger King", "KFC" };
    vector<string> list2 = { "sad","happy","good" }; //{ "Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun" };
    Solution s;
    vector<string> commonStr = s.findRestaurant(list1, list2);

    bool isEnd = true;
    for (auto n : commonStr) {
        if (!isEnd) cout << ",";
        cout << n;
        isEnd = false;
    }
    cout << endl;

    return 0;
}


