#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL){
            if(root->val == val) return root;
            else if(root->val > val){
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return root;
    }
};

// Function to print subtree (for checking result)
void printSubtree(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printSubtree(root->left);
    printSubtree(root->right);
}

int main() {
    // Build sample BST:
    //        4
    //       / \
    //      2   7
    //     / \
    //    1   3

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;
    int val = 2; // value to search in BST
    TreeNode* result = sol.searchBST(root, val);

    if(result) {
        cout << "Subtree rooted at " << val << ": ";
        printSubtree(result);
    } else {
        cout << "Value not found in BST.";
    }

    return 0;
}
