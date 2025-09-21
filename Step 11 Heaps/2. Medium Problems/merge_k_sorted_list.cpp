#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap with custom comparator
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        // Push only the head of each non-empty list
        for(auto node : lists) {
            if(node) pq.push(node);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(!pq.empty()) {
            ListNode* node = pq.top(); pq.pop();
            temp->next = node;
            temp = temp->next;

            if(node->next) pq.push(node->next);
        }

        return dummy->next;
    }
};

int main() {
    Solution sol;

    // Example test case: [[1->4->5],[1->3->4],[2->6]]
    ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* l3 = new ListNode(2, new ListNode(6));

    vector<ListNode*> lists = {l1, l2, l3};
    ListNode* merged = sol.mergeKLists(lists);

    cout << "Merged list: ";
    while(merged) {
        cout << merged->val << " ";
        merged = merged->next;
    }
    cout << endl;

    return 0;
}
