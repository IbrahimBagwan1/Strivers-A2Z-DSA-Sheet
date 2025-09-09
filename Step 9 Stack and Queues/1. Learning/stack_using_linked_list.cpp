#include <iostream>
using namespace std;

// Node definition
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Stack class
class MyStack {
private:
    Node* topNode;   // pointer to the top of the stack

public:
    MyStack() {
        topNode = nullptr;
    }

    // Push element onto stack
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
    }

    // Pop element from stack
    int pop() {
        if (empty()) {
            cout << "Stack Underflow!" << endl;
            return -1; // error value
        }
        int popped = topNode->data;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        return popped;
    }

    // Return top element
    int top() {
        if (empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return topNode->data;
    }

    // Check if stack is empty
    bool empty() {
        return topNode == nullptr;
    }
};

// Driver code
int main() {
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;    // 30
    cout << "Popped: " << st.pop() << endl;        // 30
    cout << "Top element after pop: " << st.top() << endl; // 20

    st.pop();
    st.pop();
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl; // Yes

    return 0;
}
