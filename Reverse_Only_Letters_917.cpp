// Reverse_Only_Letters_917.cpp 
// the solution is straightforward i.e. two pointer approach

#include <iostream>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0; 
        int right = s.length() - 1;
        string result = s;
        while (left < right) {
            if (isalpha(result[left]) && isalpha(result[right])) {
                char temp = result[left];
                result[left] = result[right];
                result[right] = temp;
                left++;
                right--;
            }
            else if (!isalpha(result[left]) && !isalpha(result[right])) {
                left++;
                right--;
            }
            else if (!isalpha(result[left]) && isalpha(result[right]))
                left++;
            else
                right--;

        }

        return result;

    }
};




int main()
{
    string s1 = "a-bC-dEf-ghIj";//"ab-cd"; //"Test1ng-Leet=code-Q!";
    Solution s;
    string r = s.reverseOnlyLetters(s1);
    cout << r << endl;
}




