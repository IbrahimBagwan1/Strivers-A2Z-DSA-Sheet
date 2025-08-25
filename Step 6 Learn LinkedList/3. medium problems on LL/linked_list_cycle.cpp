#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};

int main() {
    // Example 1: Linked list with cycle
    ListNode* head1 = new ListNode(3);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(-4);
    head1->next->next->next->next = head1->next; // cycle

    Solution s;
    cout << (s.hasCycle(head1) ? "Cycle detected" : "No cycle") << endl;

    // Example 2: Linked list without cycle
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);

    cout << (s.hasCycle(head2) ? "Cycle detected" : "No cycle") << endl;

    return 0;
}
