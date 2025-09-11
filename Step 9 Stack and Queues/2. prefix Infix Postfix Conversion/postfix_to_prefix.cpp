#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string postfixToPrefix(string postfix) {
    stack<string> st;
    for (char c : postfix) {
        if (isalnum(c)) {
            st.push(string(1, c)); // operand
        } else if (isOperator(c)) {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string exp = string(1, c) + op1 + op2;
            st.push(exp);
        }
    }
    return st.top();
}

int main() {
    string postfix1 = "abc*+";
    string postfix2 = "ab+c*";
    string postfix3 = "abcd^e-fgh*+^*+i-";

    cout << "Postfix: " << postfix1 << "  ->  Prefix: " << postfixToPrefix(postfix1) << endl;
    cout << "Postfix: " << postfix2 << "  ->  Prefix: " << postfixToPrefix(postfix2) << endl;
    cout << "Postfix: " << postfix3 << "  ->  Prefix: " << postfixToPrefix(postfix3) << endl;
}
