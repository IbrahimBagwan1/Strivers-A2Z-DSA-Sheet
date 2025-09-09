#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q;

    MyStack() {
    }
    
    void push(int x) {
        int s = q.size();
        q.push(x);

        for(int i=0; i<s; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int pop_elem = q.front();
        q.pop();
        return pop_elem;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.size()==0) return true;
        return false;
    }
};

int main() {
    MyStack* obj = new MyStack();
    obj->push(10);
    obj->push(20);
    obj->push(30);

    cout << "Top element: " << obj->top() << endl;   // should print 30
    cout << "Popped: " << obj->pop() << endl;       // should print 30
    cout << "Top element after pop: " << obj->top() << endl; // should print 20
    cout << "Is empty? " << (obj->empty() ? "Yes" : "No") << endl; // No

    obj->pop();
    obj->pop();
    cout << "Is empty after popping all? " << (obj->empty() ? "Yes" : "No") << endl; // Yes

    delete obj;
    return 0;
}
