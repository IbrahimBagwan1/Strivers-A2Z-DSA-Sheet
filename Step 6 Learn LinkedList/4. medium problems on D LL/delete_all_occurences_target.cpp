#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* prev;
    ListNode* next;
    ListNode(int x) : val(x), prev(NULL), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteAllOccurrences(ListNode* head, int target) {
      if(head == NULL) return NULL;
      ListNode* cur;
      while(head && head->val == target){
        cur = head->next;
        if(cur) cur->prev = NULL;
        head->next = NULL;
        head->prev = NULL;
        head = cur;
      }
      ListNode* temp = head;

      while(temp){
        if(temp->val == target){
            ListNode* cur = temp->next;
            ListNode* previous = temp->prev;
            if(cur) cur->prev = previous;
            temp->next = NULL;
            previous->next = cur;
            temp = cur;
        }
        else{
          temp = temp->next;
        }
      }
      return head;
    }
};

// helper function to create a doubly linked list from vector
ListNode* createList(vector<int> arr) {
    if(arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for(int i = 1; i < arr.size(); i++) {
        ListNode* node = new ListNode(arr[i]);
        temp->next = node;
        node->prev = temp;
        temp = temp->next;
    }
    return head;
}

// helper function to print doubly linked list (forward)
void printList(ListNode* head) {
    while(head) {
        cout << head->val;
        if(head->next) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution s;

    vector<pair<vector<int>, int>> tests = {
        {{1,2,3,2,4}, 2},
        {{5,5,5,5}, 5},
        {{1,2,3,4,5}, 10},
        {{7,8,9,7,10}, 7},
        {{0,1,0,2,0,3}, 0},
        {{}, 1},
        {{1}, 1},
        {{1}, 2},
        {{2,2,2,2,2}, 2},
        {{1,2,3,4,5,6}, 6},
        {{6,5,4,3,2,1}, 6},
        {{1,3,5,7,9}, 2},
        {{2,4,6,8,10}, 10},
        {{10,10,10,20}, 10},
        {{20,10,10,10}, 10},
        {{1,2,1,2,1,2}, 1},
        {{1,2,1,2,1,2}, 2},
        {{1,1,2,2,3,3}, 3},
        {{1,1,2,2,3,3}, 2},
        {{1,1,2,2,3,3}, 1},
        {{100}, 100},
        {{100}, 50},
        {{-1,-2,-3,-2,-1}, -2},
        {{-1,-1,-1,-1}, -1},
        {{-1,-2,-3,-4}, 0},
        {{1,2,3,4,5}, 1},
        {{1,2,3,4,5}, 5},
        {{9,8,7,6,5}, 4},
        {{9,9,8,8,7,7}, 9},
        {{9,9,8,8,7,7}, 8},
        {{9,9,8,8,7,7}, 7},
        {{1,2,3,4,1}, 1},
        {{2,3,4,5,2}, 2},
        {{3,4,5,6,3}, 3},
        {{4,5,6,7,4}, 4},
        {{5,6,7,8,5}, 5},
        {{6,7,8,9,6}, 6},
        {{7,8,9,10,7}, 7},
        {{8,9,10,11,8}, 8},
        {{9,10,11,12,9}, 9},
        {{1,2,3,4,5,6,7,8,9}, 10},
        {{1,1,1,2,2,2,3,3,3}, 2},
        {{1,1,1,2,2,2,3,3,3}, 1},
        {{1,1,1,2,2,2,3,3,3}, 3},
        {{1,2,3,1,2,3,1,2,3}, 2},
        {{1,2,3,1,2,3,1,2,3}, 1},
        {{1,2,3,1,2,3,1,2,3}, 3},
        {{1,2,1,2,1,2,1,2}, 1},
        {{1,2,1,2,1,2,1,2}, 2},
        {{10,20,30,40,50}, 25},
        {{10,20,30,40,50}, 40},
        {{10,20,30,40,50}, 10},
        {{10,20,30,40,50}, 50},
        {{5,4,3,2,1}, 3},
        {{5,4,3,2,1}, 1},
        {{5,4,3,2,1}, 5},
        {{11,22,33,44}, 22},
        {{11,22,33,44}, 33},
        {{11,22,33,44}, 11},
        {{11,22,33,44}, 44},
        {{1,1,1,1,2}, 1},
        {{1,1,1,1,2}, 2},
        {{2,2,2,2,1}, 2},
        {{2,2,2,2,1}, 1},
        {{0,0,0,0}, 0},
        {{0,0,0,0}, 1},
        {{-5,-4,-3,-2,-1}, -3},
        {{-5,-4,-3,-2,-1}, -5},
        {{-5,-4,-3,-2,-1}, -1},
        {{100,200,300,400}, 200},
        {{100,200,300,400}, 500},
        {{100,100,200,200,300,300}, 200},
        {{100,100,200,200,300,300}, 100},
        {{100,100,200,200,300,300}, 300},
        {{1,2,3,4,5,1,2,3,4,5}, 3},
        {{1,2,3,4,5,1,2,3,4,5}, 5},
        {{1,2,3,4,5,1,2,3,4,5}, 1},
        {{7,7,7,7,8,8,8}, 7},
        {{7,7,7,7,8,8,8}, 8},
        {{9,8,7,6,5,4,3,2,1}, 9},
        {{9,8,7,6,5,4,3,2,1}, 1},
        {{9,8,7,6,5,4,3,2,1}, 5},
        {{50,40,30,20,10}, 30},
        {{50,40,30,20,10}, 60},
        {{2,4,6,8}, 4},
        {{2,4,6,8}, 6},
        {{2,4,6,8}, 2},
        {{2,4,6,8}, 8},
        {{1000,2000,3000}, 1000},
        {{1000,2000,3000}, 2000},
        {{1000,2000,3000}, 4000},
        {{-10,-20,-30,-40}, -20},
        {{-10,-20,-30,-40}, -50},
        {{-10,-20,-30,-40}, -10},
        {{42}, 42},
        {{42}, 24},
        {{}, 0}
    };

    bool allPassed = true;

    auto toVector = [](ListNode* head) {
        vector<int> result;
        while(head) {
            result.push_back(head->val);
            head = head->next;
        }
        return result;
    };

    for(int i = 0; i < tests.size(); i++) {
        ListNode* head = createList(tests[i].first);
        head = s.deleteAllOccurrences(head, tests[i].second);

        vector<int> result = toVector(head);

        // expected output = original list without target
        vector<int> expected;
        for(int val : tests[i].first) {
            if(val != tests[i].second) expected.push_back(val);
        }

        if(result != expected) {
            allPassed = false;
            cout << " Test " << i+1 << " failed. Target = " << tests[i].second << endl;
        }
    }

    if(allPassed) cout << " All test cases passed!" << endl;
    else cout << " Some test cases failed." << endl;

    return 0;
}
