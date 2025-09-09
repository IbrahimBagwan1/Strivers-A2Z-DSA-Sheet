#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> st_in, st_out;

    MyQueue() {}

    void push(int x) {
        st_in.push(x);   // just push into input stack
    }
    
    int pop() {
        if(st_out.empty()) {
            while(!st_in.empty()) {
                st_out.push(st_in.top());
                st_in.pop();
            }
        }
        int front_elem = st_out.top();
        st_out.pop();
        return front_elem;
    }
    
    int peek() {
        if(st_out.empty()) {
            while(!st_in.empty()) {
                st_out.push(st_in.top());
                st_in.pop();
            }
        }
        return st_out.top();
    }
    
    bool empty() {
        return st_in.empty() && st_out.empty();
    }
};

int main() {
    MyQueue* obj = new MyQueue();
    obj->push(10);
    obj->push(20);
    obj->push(30);

    cout << "Front element: " << obj->peek() << endl;   // should print 10
    cout << "Popped: " << obj->pop() << endl;          // should print 10
    cout << "Front element after pop: " << obj->peek() << endl; // should print 20
    cout << "Is empty? " << (obj->empty() ? "Yes" : "No") << endl; // No

    obj->pop();
    obj->pop();
    cout << "Is empty after popping all? " << (obj->empty() ? "Yes" : "No") << endl; // Yes

    delete obj;
    return 0;
}
