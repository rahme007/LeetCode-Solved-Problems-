// https://github.com/rahme007 
//Maximum_Twin_Sum_of_a_Linked_List_2130.cpp : The approach is to convert the list to an array and then
//                                              find the maximum twin sum; time complexity: O(n)
//                                              space complexity: O(n)

#include <iostream>
#include<vector>

using namespace std;

typedef struct ListNode {

	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}

}ListNode;

class Solution {
public:
	int pairSum(ListNode* head) {
		vector<int> list;
		while (head) { // travering the linked list and storing the values in a vector
			list.push_back(head->val);
			head = head->next;
		}

		int maxSum = 0;
		int n = list.size();
		int mid = (n / 2); // getting the mid since the length is even 

		for (int i = 0; i < mid;i++) {
			int sum = list[i] + list[n - i - 1];
			maxSum = max(sum, maxSum); // get the max of twin sum
		}

		return maxSum;
	}
};



int main()
{
	ListNode* n = new ListNode(4);
	n->next = new ListNode(2);
	n->next->next = new ListNode(2);
	n->next->next->next = new ListNode(3);
	Solution s;
	int maxSum = s.pairSum(n);
	cout << maxSum << endl;
}


