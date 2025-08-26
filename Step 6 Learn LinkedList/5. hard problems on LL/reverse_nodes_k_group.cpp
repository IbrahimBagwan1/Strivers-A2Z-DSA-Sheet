#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Dummy node before head
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroup = &dummy;

        while (true) {
            // Find kth node from prevGroup
            ListNode* kth = prevGroup;
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }
            if (!kth) break; // not enough nodes

            ListNode* groupNext = kth->next;   // Node after kth
            ListNode* prev = groupNext;        // Start reversal
            ListNode* curr = prevGroup->next;

            // Reverse k nodes
            for (int i = 0; i < k; i++) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connect reversed group
            ListNode* temp = prevGroup->next;
            prevGroup->next = kth;
            prevGroup = temp;
        }
        return dummy.next;
    }
};

// Helper: Print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper: Create linked list from vector
ListNode* createList(vector<int> arr) {
    if (arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    Solution sol;

    // Input 1
    vector<int> arr1 = {1, 2, 3, 4, 5};
    ListNode* head1 = createList(arr1);
    cout << "Original List 1: ";
    printList(head1);
    head1 = sol.reverseKGroup(head1, 2);
    cout << "Reversed in K=2 Groups: ";
    printList(head1);

    // Input 2
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8};
    ListNode* head2 = createList(arr2);
    cout << "\nOriginal List 2: ";
    printList(head2);
    head2 = sol.reverseKGroup(head2, 3);
    cout << "Reversed in K=3 Groups: ";
    printList(head2);

    return 0;
}
