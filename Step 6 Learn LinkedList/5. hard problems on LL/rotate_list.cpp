#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        ListNode* cur = head;
        int l = 1;
        while(cur->next != NULL){
            l++;
            cur = cur->next;
        }
        
        k = k % l;
        if(k==0) return head;

        cur->next = head;  // make it circular
        ListNode* temp = head;
        
        for(int i=1; i<= (l - k - 1); i++){
            temp = temp->next;
        }
        ListNode* first = temp->next;
        temp->next = NULL;
        return first;
    }
};

// Helper: Print list
void printList(ListNode* head) {
    while(head){
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper: Create linked list from vector
ListNode* createList(vector<int> arr) {
    if(arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for(int i=1; i<arr.size(); i++){
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    Solution sol;

    // Input 1
    vector<int> arr1 = {1,2,3,4,5};
    ListNode* head1 = createList(arr1);
    cout << "Original List 1: ";
    printList(head1);
    head1 = sol.rotateRight(head1, 2);
    cout << "Rotated Right by 2: ";
    printList(head1);

    // Input 2
    vector<int> arr2 = {0,1,2};
    ListNode* head2 = createList(arr2);
    cout << "\nOriginal List 2: ";
    printList(head2);
    head2 = sol.rotateRight(head2, 4);
    cout << "Rotated Right by 4: ";
    printList(head2);

    return 0;
}
