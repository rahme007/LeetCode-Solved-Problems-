// https://github.com/rahme007
// Remove_Duplicates_from_Sorted_List_83.cpp : The approach is to apply single pointer.
//

#include <iostream>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}

}ListNode;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-200); // initializing a dummy node
        dummy->next = head; // putting the head to next node of dummy

        while (head && head->next) {
            if (head->val == head->next->val) {
                head->next = head->next->next; // deleting the duplicate node
            }
            else
                head = head->next;
        }

        return dummy->next;
    }
};

int main()
{
    ListNode* node = new ListNode(1);
    node->next = new ListNode(1);
    node->next->next = new ListNode(2);
    node->next->next->next = new ListNode(3);
    node->next->next->next->next = new ListNode(3);
    node->next->next->next->next->next = new ListNode(4);
    node->next->next->next->next->next->next = new ListNode(5);
    node->next->next->next->next->next->next->next = new ListNode(5);
    node->next->next->next->next->next->next->next->next = new ListNode(6);

    Solution s;
    ListNode* n2 = s.deleteDuplicates(node);

    // output tesing; comment it if you like to keep the node pointer
    // starting from head

    while (n2) {
        cout << n2->val;
        if (n2->next) cout << "->";
        n2 = n2->next;
    }
    cout << endl;

    return 0;
}


