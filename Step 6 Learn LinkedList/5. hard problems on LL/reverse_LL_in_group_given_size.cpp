#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k==1) return head;
        if(head == NULL) return NULL;

        ListNode* counter = head;
        int n = 0;
        while(counter){
            counter = counter->next;
            n++;
        }

        int form = (n-(n%k))/k;
        int perm_form = form;
        ListNode* temp = NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* check = head;

        while(form>0){
            int count1=0;
            while(check->next != NULL){
                count1++;
                check = check->next;
                if(form == perm_form){
                    if(k+k-1 < n){
                        if(count1 == (k+k-1)) break;
                    }
                    else{
                        if(count1==k) break;
                    }
                }
                else{
                    if(form==1 && n%k!=0) break;
                    else if(count1 == (k)) break;
                }
            }
            int count2=0;
            while(count2<k){
                temp = curr;
                curr = curr->next;
                if(count2==0 && form!=1){
                    temp->next = check;
                }
                else if(count2==0 && form ==1){
                    if(n%k==0){
                        temp->next = NULL;
                    }
                    else{
                        temp->next = check;
                    }
                }
                else{
                    temp->next = prev;
                }
                prev = temp;
                count2++;
            }
            if(form == perm_form) head = temp;
            form--;
        }
        return head;
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
    head1 = sol.reverseKGroup(head1, 2);
    cout << "Reversed in K=2 Groups: ";
    printList(head1);

    // Input 2
    vector<int> arr2 = {1,2,3,4,5,6,7,8};
    ListNode* head2 = createList(arr2);
    cout << "\nOriginal List 2: ";
    printList(head2);
    head2 = sol.reverseKGroup(head2, 3);
    cout << "Reversed in K=3 Groups: ";
    printList(head2);

    return 0;
}
