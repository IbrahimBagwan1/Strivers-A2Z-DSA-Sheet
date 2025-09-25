#include <iostream>
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

// Function to create a new node
Node* createNode(int val) {
    return new Node(val);
}

// Example function to build a sample tree
Node* buildTree() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    return root;
}

//  You need to implement this function
void inorder(Node* root) {
    if(root!=nullptr){
      cout<< root->data<< " ";
      inorder(root->left);
      inorder(root->right);
    }
}

int main() {
    Node* root = buildTree();
    
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    return 0;
}
