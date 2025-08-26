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
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        vector<vector<int>> ans;

        ListNode* left = head;
        ListNode* right = head;
        while(right ->next != NULL){
          right = right->next;
        }
        while(left!=right){
          vector<int> a ;
          if(left->val + right->val == target){
            a.push_back(left->val);
            a.push_back(right->val);
            right = right->prev;
            ans.push_back(a);
          }
          else if(left->val + right->val > target){
            right = right->prev;
          }
          else{
            left = left->next;
          }
        }
        return ans;
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

// Utility to print 2D vector
void printResult(vector<vector<int>> res) {
    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        cout << "[" << res[i][0] << "," << res[i][1] << "]";
        if (i != res.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test case 1
    vector<int> arr1 = {1, 2, 4, 5, 6, 8, 9};
    ListNode* head1 = createDLL(arr1);
    cout << "Test 1: ";
    printResult(sol.findPairsWithGivenSum(head1, 7));

    // Test case 2
    vector<int> arr2 = {1, 5, 6};
    ListNode* head2 = createDLL(arr2);
    cout << "Test 2: ";
    printResult(sol.findPairsWithGivenSum(head2, 6));

    // Test case 3
    vector<int> arr3 = {2, 3, 4, 8, 9, 11};
    ListNode* head3 = createDLL(arr3);
    cout << "Test 3: ";
    printResult(sol.findPairsWithGivenSum(head3, 13));

    // Test case 4
    vector<int> arr4 = {1, 2, 3, 4, 5};
    ListNode* head4 = createDLL(arr4);
    cout << "Test 4: ";
    printResult(sol.findPairsWithGivenSum(head4, 10));

    // Test case 5
    vector<int> arr5 = {1, 2, 3, 7, 11, 15};
    ListNode* head5 = createDLL(arr5);
    cout << "Test 5: ";
    printResult(sol.findPairsWithGivenSum(head5, 16));

    return 0;
}
