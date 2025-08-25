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
        if(!head) return NULL;
        if(head->next==NULL) return head;

        auto cmp = [](ListNode* a, ListNode* b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        ListNode* temp = head;
        while(temp != NULL){
            pq.push(temp);
            temp = temp->next;
        }

        temp = new ListNode(0, NULL);
        ListNode* finaltemp = temp;

        while(!pq.empty()){
            temp->next = pq.top(); pq.pop();
            temp = temp->next;
        }
        temp->next = NULL;

        return finaltemp->next;
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
    // Example: 4 -> 2 -> 1 -> 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    Solution s;
    head = s.sortList(head);

    displayList(head); // Expected output: 1 2 3 4

    return 0;
}
