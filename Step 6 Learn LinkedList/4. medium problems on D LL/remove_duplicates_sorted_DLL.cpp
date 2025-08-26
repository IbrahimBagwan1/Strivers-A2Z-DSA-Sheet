#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode(int x) : val(x), next(NULL), prev(NULL) {}
};

class Solution {
public:
    ListNode * removeDuplicates(ListNode *head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;

        ListNode* i = head;
        ListNode* j = head;

        while(i){
            if(j->val != i->val){
                j->next = i;
                i->prev = j;
                j= j->next;
                i= i->next;
            }
            else{
                i= i->next;
            }
        }
        j->next = NULL; // important to terminate the DLL
        return head;
    }
};

// Utility to create DLL from vector
ListNode* createDLL(vector<int> arr) {
    if (arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        ListNode* temp = new ListNode(arr[i]);
        curr->next = temp;
        temp->prev = curr;
        curr = temp;
    }
    return head;
}

// Utility to print DLL
void printDLL(ListNode* head) {
    ListNode* temp = head;
    cout << "[";
    while (temp) {
        cout << temp->val;
        if (temp->next) cout << ",";
        temp = temp->next;
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test case 1
    vector<int> arr1 = {1,1,2,3,3,4,4,5};
    ListNode* head1 = createDLL(arr1);
    cout << "Test 1: ";
    printDLL(sol.removeDuplicates(head1));

    // Test case 2
    vector<int> arr2 = {1,1,1,1,1};
    ListNode* head2 = createDLL(arr2);
    cout << "Test 2: ";
    printDLL(sol.removeDuplicates(head2));

    // Test case 3
    vector<int> arr3 = {1,2,3,4,5};
    ListNode* head3 = createDLL(arr3);
    cout << "Test 3: ";
    printDLL(sol.removeDuplicates(head3));

    // Test case 4
    vector<int> arr4 = {2,2,3,3,3,4,5,5,6};
    ListNode* head4 = createDLL(arr4);
    cout << "Test 4: ";
    printDLL(sol.removeDuplicates(head4));

    // Test case 5
    vector<int> arr5 = {10,10,20,20,30,40,40,50};
    ListNode* head5 = createDLL(arr5);
    cout << "Test 5: ";
    printDLL(sol.removeDuplicates(head5));

    return 0;
}
