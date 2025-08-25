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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(cur != NULL){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* temp = reverseList(slow);
        fast = head;
        while(temp!=NULL){
            if(fast->val!=temp->val) return false;
            fast = fast->next;
            temp = temp->next;
        }
        return true;
    }
};

int main(){
    // Example: 1 -> 2 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution s;
    if(s.isPalindrome(head))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";

    return 0;
}
