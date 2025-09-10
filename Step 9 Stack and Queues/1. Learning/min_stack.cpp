#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<long long> st;   // use long long for safe storage
    long long mini;        // also long long to avoid overflow

    MinStack() {
        mini = LLONG_MAX;  // initialize with max long long
    }
    
    void push(int val) {
        long long value = val;
        if(st.empty()) {
            st.push(value);
            mini = value;
            return;
        }
        if(value > mini) {
            st.push(value);
        } else {
            st.push(2*value - mini); // encoded value
            mini = value;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long x = st.top();
        st.pop();
        if(x < mini) {
            mini = 2*mini - x; // restore old min
        }
        if(st.empty()) {
            mini = LLONG_MAX; // reset if stack empty
        }
    }
    
    int top() {
        if(st.empty()) return 0; // ideally throw exception
        long long x = st.top();
        if(x >= mini) return (int)x;
        return (int)mini;
    }
    
    int getMin() {
        return (int)mini;
    }
};

int main() {
    MinStack* obj = new MinStack();

    // Test sequence from your failing case
    obj->push(2147483646);
    obj->push(2147483646);
    obj->push(2147483647);
    cout << "Top: " << obj->top() << endl;     // expect 2147483647
    obj->pop();
    cout << "GetMin: " << obj->getMin() << endl; // expect 2147483646
    obj->pop();
    cout << "GetMin: " << obj->getMin() << endl; // expect 2147483646
    obj->pop();
    obj->push(2147483647);
    cout << "Top: " << obj->top() << endl;     // expect 2147483647
    cout << "GetMin: " << obj->getMin() << endl; // expect 2147483647
    obj->push(-2147483648);
    cout << "Top: " << obj->top() << endl;     // expect -2147483648
    cout << "GetMin: " << obj->getMin() << endl; // expect -2147483648
    obj->pop();
    cout << "GetMin: " << obj->getMin() << endl; // expect 2147483647

    return 0;
}
