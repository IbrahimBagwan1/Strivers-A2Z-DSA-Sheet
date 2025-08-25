#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int data1) : val(data1), next(NULL) {}
    ListNode(int data1, ListNode *next1) : val(data1), next(next1) {}
};

class Solution {
public:
    int findLengthOfLoop(ListNode *head) {
        if(head == NULL) return 0;

        ListNode* fast = head;
        ListNode* slow = head;

        // Step 1: Detect cycle using Floyd’s algorithm
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) break;
        }

        // No cycle
        if(fast == NULL || fast->next == NULL) return 0;

        // Step 2: Find the start of the loop (not necessary if we just want length, but ok)
        ListNode* temp = head;
        while(temp != slow){
            temp = temp->next;
            slow = slow->next;
        }

        // Step 3: Count loop length
        ListNode* loop = temp;
        int count = 1;
        while(loop->next != temp){
            loop = loop->next;
            count++;
        }
        return count;
    }
};

int main() {
    // Example: 1 -> 2 -> 3 -> 4 -> 5 -> 3 (cycle starts at node 3)
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Creating cycle: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    Solution obj;
    cout << "Length of loop: " << obj.findLengthOfLoop(head) << endl;

    return 0;
}
