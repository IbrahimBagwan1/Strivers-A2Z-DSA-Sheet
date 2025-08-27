#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void myReverseFunc(stack<int> &st, int temp){
        if(st.empty()){
            st.push(temp);
        }
        else{
            int x = st.top(); st.pop();
            myReverseFunc(st,temp);
            st.push(x);
        }
    }

    void reverseStack(stack<int> &st) {
        if(!st.empty()){
            int temp = st.top(); st.pop();
            reverseStack(st);
            myReverseFunc(st, temp);
        }
    }
};

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    Solution s;
    s.reverseStack(st);

    cout << "Reversed stack (top to bottom): ";
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
