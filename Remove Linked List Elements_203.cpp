// Remove Linked List Elements_203.cpp : The solution can be solved using two pointer approach
//

#include <iostream>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode* next;
    //ListNode(int x) : val(x){}
    ListNode(int x,ListNode* next) : val(x), next(nullptr) {}

}ListNode;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) // if head is null
            return nullptr;

        ListNode* dummy = new ListNode(0,nullptr); // dummy node intialization
        dummy->next = head;
        if (head->val == val) {
            dummy->next = head->next;
            head = head->next;
        }
        ListNode* prev = dummy;
        while (head) {
            
            if (head->val == val) {
                prev->next = head->next; // removing the node from the list
                head = head->next;
            }
            else {
                prev = head;
                head = head->next;
            }
        }

        return dummy->next; // return the new head as dummy->next

    }
};

int main()
{
    ListNode* node = new ListNode(6, nullptr);
    node->next = new ListNode(6, nullptr);
    node->next->next = new ListNode(6, nullptr);
    node->next->next->next = new ListNode(6, nullptr);

    //ListNode* node = new ListNode(1, nullptr);
    //node->next = new ListNode(2, nullptr);
    //node->next->next = new ListNode(6, nullptr);
    //node->next->next->next = new ListNode(3, nullptr);
    //node->next->next->next->next = new ListNode(4, nullptr);
    //node->next->next->next->next->next = new ListNode(5, nullptr);
    //node->next->next->next->next->next->next = new ListNode(6, nullptr);

    Solution s;
    ListNode* head = s.removeElements(node,6);
    //cout << head->val << endl;

    while (head) {
        cout << head->val << "->";
        head = head->next;
    }

    return 0;
}


