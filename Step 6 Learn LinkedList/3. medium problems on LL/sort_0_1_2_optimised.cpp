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
        if(head ==NULL)return NULL;
        if(head->next == NULL)return head;
        ListNode* zeroHead= new ListNode(-1);
        ListNode* oneHead= new ListNode(-1);
        ListNode* twoHead= new ListNode(-1);

        ListNode* zero = zeroHead;
        ListNode* one = oneHead;
        ListNode* two = twoHead;
        
        ListNode* temp = head; 
        while(temp !=NULL){
          if(temp->val == 0){
            zero->next = temp;
            zero = zero->next;
          }
          else if(temp->val ==1){
            one->next = temp;
            one = one->next;
          }
          else{ 
            two->next = temp;
            two = two->next;
          }
          temp = temp->next;
        }
        zero->next = oneHead->next;
        one->next = twoHead->next;
        two->next = NULL;
        delete(oneHead);
        delete(twoHead);
        return zeroHead->next;
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
