#include <bits/stdc++.h>
using namespace std;

// Binary tree node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// You will implement this function
vector<int> postorder(Node* root) {
    vector<int> traversal;
    if(root==NULL) return traversal;
    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node* node = st.top(); st.pop();

        traversal.push_back(node->data);
        if(node->left != NULL) st.push(node->left);
        if(node->right != NULL) st.push(node->right);
    }

    return traversal;
}

// Helper function to build a sample tree
Node* buildTree() {
    /*
           1
          / \
         2   3
        / \
       4   5
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    return root;
}

int main() {
    Node* root = buildTree();

    vector<int> traversal = postorder(root);

    cout << "PostOrder Traversal: ";
    for(int val : traversal) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
