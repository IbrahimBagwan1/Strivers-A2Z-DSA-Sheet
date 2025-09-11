#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return -1;
}

bool isRightAssociative(char op) {
    return (op == '^');
}

string infixToPostfix(string expr) {
    stack<char> st;
    string result = "";

    for(char c : expr) {
        if(isalnum(c)) {
            result += c; // operand → output
        }
        else if(c == '(') {
            st.push(c);
        }
        else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        }
        else { // operator
            while(!st.empty() && st.top() != '(') {
                char topOp = st.top();
                if((precedence(topOp) > precedence(c)) || 
                   (precedence(topOp) == precedence(c) && !isRightAssociative(c))) {
                    result += topOp;
                    st.pop();
                } else break;
            }
            st.push(c);
        }
    }

    while(!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

string infixToPrefix(string expr) {
    // Step 1: reverse string and swap brackets
    reverse(expr.begin(), expr.end());
    for(char &c : expr) {
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }

    // Step 2: get postfix of modified expression
    string postfix = infixToPostfix(expr);

    // Step 3: reverse postfix → prefix
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main() {
    string expr1 = "a+b*c";
    string expr2 = "(a+b)*c";
    string expr3 = "a+b*(c^d-e)^(f+g*h)-i";

    cout << "Infix: " << expr1 << "  →  Prefix: " << infixToPrefix(expr1) << endl;
    cout << "Infix: " << expr2 << "  →  Prefix: " << infixToPrefix(expr2) << endl;
    cout << "Infix: " << expr3 << "  →  Prefix: " << infixToPrefix(expr3) << endl;

    return 0;
}
