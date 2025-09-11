#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

string reverseString(const string &s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return rev;
}

string prefixToInfix(string expr) {
    // Step 1: reverse the prefix expression
    string revExpr = reverseString(expr);
    stack<string> st;

    // Step 2: process like postfix
    for(char c : revExpr) {
        if(isalnum(c)) {
            st.push(string(1, c));
        } else if(isOperator(c)) {
            if(st.size() < 2) return "Invalid Expression";
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string newExpr = "(" + op1 + c + op2 + ")";
            st.push(newExpr);
        }
    }

    // Step 3: result is at top of stack
    if(st.empty()) return "Invalid Expression";
    return st.top();
}

int main() {
    string expr1 = "+a*bc";       // prefix
    string expr2 = "*+ab-cd";     // prefix
    string expr3 = "-+a*b^-cde+fg"; // prefix

    cout << "Prefix: " << expr1 << "  →  Infix: " << prefixToInfix(expr1) << endl;
    cout << "Prefix: " << expr2 << "  →  Infix: " << prefixToInfix(expr2) << endl;
    cout << "Prefix: " << expr3 << "  →  Infix: " << prefixToInfix(expr3) << endl;

    return 0;
}
