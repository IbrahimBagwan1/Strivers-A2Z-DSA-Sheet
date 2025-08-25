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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head; 
        ListNode* fast=head;
        while(fast!=NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        } 
        return slow;
    }
};

int main() {
    vector<int> v = {1,2,3,4,5,6};
    ListNode* head = new ListNode(v[0]);
    ListNode* temp = head;
    for(int i=1;i<v.size();i++){
        temp->next = new ListNode(v[i]);
        temp = temp->next;
    }

    Solution sol;
    ListNode* mid = sol.middleNode(head);
    cout << mid->val << endl;

    return 0;
}
