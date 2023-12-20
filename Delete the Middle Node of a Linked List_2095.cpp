// Delete the Middle Node of a Linked List_2095.cpp : This problem is approached by first finding the median of the list and then compared with
//                                                      the nodes until it finds the expected middle node of that list and then delete the middle
//                                                      node.
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
    ListNode* findMedian(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next)
            return nullptr;
        ListNode* current = head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* mid = this->findMedian(head);

        while (current != mid) {
            prev = current;
            current = current->next;

        }

        prev->next = current->next;


        return dummy->next;
    }

};

int main()
{
    ListNode* n = new ListNode(1);
    n->next = new ListNode(2);
    n->next->next = new ListNode(3);
    n->next->next->next = new ListNode(4);

    Solution s;
    ListNode* r = s.deleteMiddle(n);
    while (r) {
        cout << r->val << "->";
        r = r->next;
    }


    return 0;
}