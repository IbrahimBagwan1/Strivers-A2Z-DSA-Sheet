#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Queue class
class MyQueue {
private:
    Node* frontNode;
    Node* rearNode;

public:
    MyQueue() {
        frontNode = rearNode = nullptr;
    }

    // Enqueue (push element to rear)
    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (rearNode == nullptr) {
            // Queue is empty
            frontNode = rearNode = newNode;
            return;
        }
        rearNode->next = newNode;
        rearNode = newNode;
    }

    // Dequeue (pop element from front)
    int dequeue() {
        if (empty()) {
            cout << "Queue Underflow!" << endl;
            return -1; // error value
        }
        int val = frontNode->data;
        Node* temp = frontNode;
        frontNode = frontNode->next;

        // If queue becomes empty
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }
        delete temp;
        return val;
    }

    // Get front element
    int front() {
        if (empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return frontNode->data;
    }

    // Check if queue is empty
    bool empty() {
        return frontNode == nullptr;
    }
};

// Driver code
int main() {
    MyQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl;  // 10
    cout << "Dequeued: " << q.dequeue() << endl;    // 10
    cout << "Front after dequeue: " << q.front() << endl; // 20

    q.dequeue();
    q.dequeue();
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // Yes

    return 0;
}
