#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string postfixToInfix(string postfix) {
    stack<string> st;
    for (char c : postfix) {
        if (isalnum(c)) {
            st.push(string(1, c)); // operand
        } else if (isOperator(c)) {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string exp = "(" + op1 + c + op2 + ")";
            st.push(exp);
        }
    }
    return st.top();
}

int main() {
    string postfix1 = "abc*+";
    string postfix2 = "ab+c*";
    string postfix3 = "abcd^e-fgh*+^*+i-";

    cout << "Postfix: " << postfix1 << "  ->  Infix: " << postfixToInfix(postfix1) << endl;
    cout << "Postfix: " << postfix2 << "  ->  Infix: " << postfixToInfix(postfix2) << endl;
    cout << "Postfix: " << postfix3 << "  ->  Infix: " << postfixToInfix(postfix3) << endl;
}
