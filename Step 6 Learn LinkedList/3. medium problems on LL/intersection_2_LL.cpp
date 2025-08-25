#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        while(t1 != t2){
            t1 = (t1 == NULL) ? headB : t1->next;
            t2 = (t2 == NULL) ? headA : t2->next;
        }
        return t1;
    }
};

int main() {
    // Example 1: Create intersection
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);

    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(7);
    headA->next->next = common;

    ListNode* headB = new ListNode(99);
    headB->next = new ListNode(1);
    headB->next->next = common;

    Solution sol;
    ListNode* ans = sol.getIntersectionNode(headA, headB);
    if(ans) cout << "Intersection Node Value: " << ans->val << endl;
    else cout << "No Intersection" << endl;

    // Example 2: No intersection
    ListNode* headC = new ListNode(1);
    headC->next = new ListNode(2);
    ListNode* headD = new ListNode(3);
    headD->next = new ListNode(4);

    ans = sol.getIntersectionNode(headC, headD);
    if(ans) cout << "Intersection Node Value: " << ans->val << endl;
    else cout << "No Intersection" << endl;

    return 0;
}
