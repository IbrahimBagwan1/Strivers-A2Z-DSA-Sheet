#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return -1;
}

bool isRightAssociative(char op) {
    return (op == '^'); // only exponentiation is right-associative
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
            if(!st.empty()) st.pop(); // remove '('
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

    // Pop remaining operators
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    string expr1 = "a+b*c";
    string expr2 = "(a+b)*c";
    string expr3 = "a+b*(c^d-e)^(f+g*h)-i";

    cout << "Infix: " << expr1 << "  →  Postfix: " << infixToPostfix(expr1) << endl;
    cout << "Infix: " << expr2 << "  →  Postfix: " << infixToPostfix(expr2) << endl;
    cout << "Infix: " << expr3 << "  →  Postfix: " << infixToPostfix(expr3) << endl;

    return 0;
}
