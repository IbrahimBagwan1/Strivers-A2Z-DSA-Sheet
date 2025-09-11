#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string prefixToPostfix(string prefix) {
    stack<string> st;
    for (int i = prefix.size() - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isalnum(c)) {
            st.push(string(1, c)); // operand
        } else if (isOperator(c)) {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string exp = op1 + op2 + c; // postfix style
            st.push(exp);
        }
    }
    return st.top();
}

int main() {
    string prefix1 = "+a*bc";
    string prefix2 = "*+abc";
    string prefix3 = "+a-*b^-^cde+f*ghi";

    cout << "Prefix: " << prefix1 << "  ->  Postfix: " << prefixToPostfix(prefix1) << endl;
    cout << "Prefix: " << prefix2 << "  ->  Postfix: " << prefixToPostfix(prefix2) << endl;
    cout << "Prefix: " << prefix3 << "  ->  Postfix: " << prefixToPostfix(prefix3) << endl;
}
