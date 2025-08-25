#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val1, ListNode* next1 = nullptr) {
        val = val1;
        next = next1;
    }
};

class Solution {
public:
    ListNode* insertAtHead(ListNode* &head, int X) {
        if (head == nullptr) {
            head = new ListNode(X, nullptr);
            return head;
        }
        ListNode* temp = new ListNode(X, head);
        head = temp;
        return head;
    }
};

// Helper function to print the linked list
void display(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    ListNode* head = nullptr;

    // Insert at head
    sol.insertAtHead(head, 10);
    sol.insertAtHead(head, 20);
    sol.insertAtHead(head, 30);

    // Display list
    cout << "Linked List after insertions at head: ";
    display(head);

    return 0;
}
