#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int recursive(ListNode* &head) {
        if(head == NULL) return 1; // start adding 1 at the end
        
        int carry = recursive(head->next);
        head->val += carry;
        if(head->val == 10) {
            head->val = 0;
            return 1;
        }
        return 0;
    }

    ListNode* addOne(ListNode* head) {
        if(head == NULL) return NULL;
        int carry = recursive(head);
        if(carry == 1) {
            ListNode* temp = new ListNode(1);
            temp->next = head;
            return temp;
        }
        return head;
    }
};

void printList(ListNode* head) {
    while(head) {
        cout << head->val;
        head = head->next;
    }
    cout << endl;
}

ListNode* createList(vector<int> arr) {
    if(arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for(int i=1;i<arr.size();i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    Solution s;

    vector<vector<int>> tests = {
        {1,2,3},       // 123 + 1 = 124
        {9,9,9},       // 999 + 1 = 1000
        {4,5,9},       // 459 + 1 = 460
        {0},           // 0 + 1 = 1
        {2,9,9,9}      // 2999 + 1 = 3000
    };

    for(auto &t : tests) {
        ListNode* head = createList(t);
        cout << "Input: ";
        printList(head);
        head = s.addOne(head);
        cout << "Output: ";
        printList(head);
        cout << "--------" << endl;
    }

    return 0;
}
