#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        
        // Step 1: Insert new nodes after each original node
        Node* temp = head;
        while(temp){
            Node* t = new Node(temp->val);
            t->next = temp->next;
            temp->next = t;
            temp = t->next; // move two steps
        }
        
        // Step 2: Assign random pointers
        temp = head;
        while(temp){
            Node* a = temp->next;
            if(temp->random) a->random = temp->random->next;
            else a->random = NULL;
            temp = temp->next->next;
        }    

        // Step 3: Separate original and copied lists
        Node* temp_even = head;
        Node* temp_odd = head->next;
        Node* final_return = head->next;
        while(temp_even){
            temp_even->next = temp_even->next ? temp_even->next->next : NULL;
            temp_odd->next = temp_odd->next ? temp_odd->next->next : NULL;
            temp_even = temp_even->next;
            temp_odd = temp_odd->next;
        }    
        return final_return;
    }   
};

void printList(Node* head) {
    while(head){
        cout << "Val: " << head->val;
        if(head->random) cout << ", Random: " << head->random->val;
        else cout << ", Random: NULL";
        cout << "\n";
        head = head->next;
    }
    cout << "----\n";
}

int main() {
    Solution s;

    // -------- Test case 1 --------
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    // random pointers
    head1->random = head1->next->next; // 1->random = 3
    head1->next->random = head1;       // 2->random = 1
    head1->next->next->random = head1->next; // 3->random = 2

    cout << "Original List 1:\n";
    printList(head1);

    Node* copy1 = s.copyRandomList(head1);
    cout << "Copied List 1:\n";
    printList(copy1);

    // -------- Test case 2 --------
    Node* head2 = new Node(10);
    head2->next = new Node(20);
    head2->next->next = new Node(30);

    // random pointers
    head2->random = NULL;             // 10->random = NULL
    head2->next->random = head2;      // 20->random = 10
    head2->next->next->random = head2; // 30->random = 10

    cout << "Original List 2:\n";
    printList(head2);

    Node* copy2 = s.copyRandomList(head2);
    cout << "Copied List 2:\n";
    printList(copy2);

    return 0;
}
