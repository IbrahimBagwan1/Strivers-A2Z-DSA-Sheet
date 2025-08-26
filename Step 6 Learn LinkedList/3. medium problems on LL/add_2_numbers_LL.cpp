#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;

        while(temp1 != NULL || temp2 != NULL) {
            int sum = carry;
            if(temp1) sum += temp1->val;
            if(temp2) sum += temp2->val;

            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;

            curr->next = newNode;
            curr = curr->next;

            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
        }

        if(carry) {
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
        }

        return dummyHead->next;
    }
};

// helper function to create a linked list from vector
ListNode* createList(vector<int> arr) {
    if(arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for(int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// helper function to print linked list
void printList(ListNode* head) {
    while(head) {
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution s;

    // 5 hardcoded test cases
    vector<vector<int>> A = {
        {2,4,3},     // 342
        {9,9,9},     // 999
        {5},         // 5
        {1,8},       // 81
        {9,8,7}      // 789
    };

    vector<vector<int>> B = {
        {5,6,4},     // 465
        {1},         // 1
        {5},         // 5
        {0},         // 0
        {3,2}        // 23
    };

    for(int i = 0; i < A.size(); i++) {
        ListNode* l1 = createList(A[i]);
        ListNode* l2 = createList(B[i]);

        cout << "Input A: ";
        printList(l1);
        cout << "Input B: ";
        printList(l2);

        ListNode* result = s.addTwoNumbers(l1, l2);

        cout << "Output : ";
        printList(result);
        cout << "-------------------" << endl;
    }

    return 0;
}
