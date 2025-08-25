#include <bits/stdc++.h>
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
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;

        int count0 = 0, count1 = 0, count2 = 0;
        ListNode* temp = head;

        while(temp != NULL){
            if(temp->val == 0) count0++;
            else if(temp->val == 1) count1++;
            else count2++;
            temp = temp->next;
        }

        temp = head;
        while(temp != NULL){
            if(count0 != 0){
                temp->val = 0;
                count0--;
            }
            else if(count1 != 0){
                temp->val = 1;
                count1--;
            }
            else {
                temp->val = 2;
                count2--;
            }
            temp = temp->next;
        }
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
    // Example: 1 -> 2 -> 0 -> 1 -> 2 -> 0
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(0);

    Solution s;
    head = s.sortList(head);

    displayList(head); // Expected output: 0 0 0 1 1 2 2

    return 0;
}
