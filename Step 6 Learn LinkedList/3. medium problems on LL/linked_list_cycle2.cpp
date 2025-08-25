#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head;
        int count = 0;

        // Phase 1: Detect cycle using Floyd’s Tortoise and Hare
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                count = 1;
                break;
            }
        }

        // No cycle
        if(count == 0) return NULL;

        // Phase 2: Find start of cycle
        while(temp != slow) {
            temp = temp->next;
            slow = slow->next;
        }
        return temp;
    }
};

// Driver code
int main() {
    // Creating nodes
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Creating cycle: last node connects to 2nd node
    head->next->next->next->next = head->next;

    Solution s;
    ListNode* cycleNode = s.detectCycle(head);

    if(cycleNode != NULL)
        cout << "Cycle detected at node with value: " << cycleNode->val << endl;
    else
        cout << "No cycle detected." << endl;

    return 0;
}
