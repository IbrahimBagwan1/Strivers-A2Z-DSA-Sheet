#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* temp = NULL;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            temp = slow;
            slow = slow->next;
        }
        temp->next = slow->next;
        return head;
    }
};

void displayList(ListNode* head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    // Example: 1 -> 2 -> 3 -> 4 -> 5, middle is 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution s;
    head = s.deleteMiddle(head);

    displayList(head); // Expected output: 1 2 4 5

    return 0;
}
