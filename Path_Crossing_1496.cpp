// Path_Crossing_1496.cpp : https://github.com/rahme007
//

#include <iostream>
#include<vector>
#include<map>

using namespace std;

// Note: To use pair or vector as key in Hash function, USE map; DO NOT USE unordered_map
class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int,int>, int> pmap;
        pmap[{0,0}] = 1; // declaring orign(0,0) as the starting point
        vector<int>north = { 0,1 };
        vector<int>south = { 0,-1 };
        vector<int>east = { 1,0 };
        vector<int>west = { -1,0 };

        int imap = 0, jmap = 0; // counter: imap= abscissa(x) and jmap = ordinate(y)

        for (int i = 0; i < path.length();i++) {
            if (path[i] == 'N') {
                imap += north[0];jmap += north[1];
                pmap[{imap,jmap }] += 1;
            }
            else if (path[i] == 'S') {
                imap += south[0];jmap += south[1];
                pmap[{imap, jmap }] += 1;
            }
            else if (path[i] == 'E') {
                imap += east[0];jmap += east[1];
                pmap[{imap, jmap }] += 1;
            }
            else if (path[i] == 'W') {
                imap += west[0];jmap += west[1];
                pmap[{imap, jmap }] += 1;
            }

            if (pmap[{imap, jmap}] > 1)
                return true;

        }

        return false;
    }
};

int main()
{
    string path = "NESW";
    Solution s;
    bool isPCross = s.isPathCrossing(path);
    cout << isPCross << endl;
}


