#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void helper(TreeNode* root , vector<TreeNode*> &resolve, TreeNode* &prev){
        if(!root) return;

        helper(root->left, resolve, prev);

        if(prev != NULL){
            if(root->val < prev->val){
                if(resolve.size() == 0){
                    resolve.push_back(prev);
                    resolve.push_back(root);
                }
                else{
                    resolve[1] = root;
                }
            }
        }

        prev = root;

        helper(root->right, resolve, prev);
    }

    void recoverTree(TreeNode* root) {
        vector<TreeNode*> resolve;
        TreeNode* prev = NULL;
        helper(root, resolve, prev);

        int temp = resolve[0]->val;
        resolve[0]->val = resolve[1]->val;
        resolve[1]->val = temp;
    }
};

// Utility function: inorder traversal
void inorder(TreeNode* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    /*
        Constructing BST with swapped nodes:
                3
               / \
              1   4
                 /
                2

        Correct BST should be:
                2
               / \
              1   4
                 /
                3
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "Inorder before recover: ";
    inorder(root);
    cout << endl;

    Solution sol;
    sol.recoverTree(root);

    cout << "Inorder after recover: ";
    inorder(root);
    cout << endl;

    return 0;
}
