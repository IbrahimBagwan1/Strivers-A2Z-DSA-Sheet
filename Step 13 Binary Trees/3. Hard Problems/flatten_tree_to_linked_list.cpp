#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }

    // iterative solution .
    void flatten2(TreeNode* root) {
        TreeNode* cur = root;
        while(cur!=NULL){
            if(cur->left!=NULL){
                TreeNode* prev = cur->left;
                while(prev->right!=NULL){
                  prev = prev->right;
                }
                prev->right = cur->right;
                cur->right = cur->left;
            }
            cur = cur->right;
        }
    }    
};

// Function to print the flattened tree (like a linked list)
void printFlattened(TreeNode* root) {
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    // Build sample binary tree:
    //        1
    //       / \
    //      2   5
    //     / \   \
    //    3   4   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    Solution sol;
    sol.flatten2(root);

    cout << "Flattened tree: ";
    printFlattened(root);

    return 0;
}
