#include <iostream>
#include <vector>

using namespace std;

// Definition of a singly linked list node
typedef struct ListNode {
    int value;          // Value stored in the node
    ListNode* next;     // Pointer to the next node in the list

    // Constructor: initializes value and sets next to nullptr
    ListNode(int val) : value(val), next(nullptr) {}
} ListNode;


class Solution {
public:

    // Detects a cycle in a linked list and returns the node
    // where the cycle begins; returns nullptr if no cycle exists
    ListNode* detectCycle(ListNode* head) {

        // slow pointer moves one step at a time
        ListNode* slow = head;

        // fast pointer moves two steps at a time
        ListNode* fast = head;

        // slow2 starts from head to find cycle entry point
        ListNode* slow2 = head;

        // Traverse the list while fast pointer can safely move
        while (fast && fast->next) {

            // Move slow pointer by 1 step
            slow = slow->next;

            // Move fast pointer by 2 steps
            fast = fast->next->next;

            // If slow and fast meet, a cycle is detected
            if (slow == fast) {

                // Move slow and slow2 at the same speed
                // The point where they meet is the cycle entry
                while (slow != slow2) {
                    slow = slow->next;
                    slow2 = slow2->next;
                }

                // Return the starting node of the cycle
                return slow;
            }
        }

        // If no cycle is detected, return nullptr
        return nullptr;
    }
};


int main() {

    Solution s;    // Create Solution object

    // Create individual linked list nodes
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(-4);

    // Link nodes together: 3 -> 2 -> 0 -> -4
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    // Create a cycle by linking -4 back to node with value 2
    n4->next = n2;

    // Call detectCycle to find the start of the cycle
    ListNode* cycleNode = s.detectCycle(n1);

    // Print result
    if (cycleNode) {
        cout << "Cycle detected at node with value: "
             << cycleNode->value << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    return 0;
}
