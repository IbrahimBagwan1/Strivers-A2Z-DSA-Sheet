#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void insertInorder(stack<int>&st, int temp){
        if(st.empty() || temp > st.top()){
            st.push(temp);
        }
        else{
            int item = st.top(); 
            st.pop();
            insertInorder(st, temp);
            st.push(item);
        }
    }

    void sortStack(stack<int> &st) {
        if(!st.empty()){
            int temp = st.top();  
            st.pop();
            sortStack(st);
            insertInorder(st, temp);
        }        
    }
};

int main() {
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    Solution s;
    s.sortStack(st);

    cout << "Sorted stack (top to bottom): ";
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
