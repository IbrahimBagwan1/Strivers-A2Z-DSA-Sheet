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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL) return NULL;
        ListNode* temp = head;
        ListNode* slow = head;
        for(int i=0; i<n; i++){
            temp = temp->next;
        }
        while(temp!=NULL && temp->next!=NULL){
            temp = temp->next;
            slow= slow->next;
        }
        if(temp==NULL){
            head = head->next;
            return head;
        } 
        slow->next = slow->next->next;
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
    // Example: 1 -> 2 -> 3 -> 4 -> 5, remove 2nd from end -> 1 2 3 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution s;
    head = s.removeNthFromEnd(head, 2);

    displayList(head); // Expected output: 1 2 3 5

    return 0;
}
