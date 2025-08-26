#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode* child;
    ListNode(int x) : val(x), next(NULL), child(NULL) {}
};

class Solution {
public:
    ListNode* merge(ListNode* t1, ListNode* t2) {
        ListNode* dummy_const = new ListNode(-1);
        ListNode* dummy = dummy_const;
        while (t1 != NULL && t2 != NULL) {
            if (t1->val < t2->val) {
                dummy->child = t1;
                dummy = dummy->child;
                t1 = t1->child;
            } else {
                dummy->child = t2;
                dummy = dummy->child;
                t2 = t2->child;
            }
            dummy->next = nullptr;  // cut horizontal links
        }
        if (t1 != NULL) dummy->child = t1;
        else dummy->child = t2;
        return dummy_const->child;
    }

    ListNode* flattenLinkedList(ListNode*& head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* temp = flattenLinkedList(head->next);
        head = merge(head, temp);
        return head;
    }
};

void printFlattened(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->child;
    }
    cout << endl;
}

int main() {
    Solution s;

    // -------- Test case 1 --------
    // Create a 2D linked list
    ListNode* head1 = new ListNode(5);
    head1->child = new ListNode(7);
    head1->child->child = new ListNode(8);
    head1->child->child->child = new ListNode(30);

    head1->next = new ListNode(10);
    head1->next->child = new ListNode(20);

    head1->next->next = new ListNode(19);
    head1->next->next->child = new ListNode(22);
    head1->next->next->child->child = new ListNode(50);

    head1->next->next->next = new ListNode(28);
    head1->next->next->next->child = new ListNode(35);
    head1->next->next->next->child->child = new ListNode(40);
    head1->next->next->next->child->child->child = new ListNode(45);

    ListNode* flat1 = s.flattenLinkedList(head1);
    cout << "Flattened List 1: ";
    printFlattened(flat1);

    // -------- Test case 2 --------
    ListNode* head2 = new ListNode(3);
    head2->child = new ListNode(6);
    head2->child->child = new ListNode(9);

    head2->next = new ListNode(4);
    head2->next->child = new ListNode(8);

    head2->next->next = new ListNode(5);

    ListNode* flat2 = s.flattenLinkedList(head2);
    cout << "Flattened List 2: ";
    printFlattened(flat2);

    return 0;
}
