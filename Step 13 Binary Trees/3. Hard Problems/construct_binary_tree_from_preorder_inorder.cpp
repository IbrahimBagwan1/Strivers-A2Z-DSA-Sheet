#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inMap;   // faster than map
        for(int i=0; i<inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        return buildTree(preorder, 0, preorder.size()-1,
                         inorder, 0, inorder.size()-1,
                         inMap);
    }

private:
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd,
                        vector<int>& inorder, int inStart, int inEnd,
                        unordered_map<int,int>& inMap) {
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(preorder, preStart+1, preStart+numsLeft,
                               inorder, inStart, inRoot-1, inMap);

        root->right = buildTree(preorder, preStart+numsLeft+1, preEnd,
                                inorder, inRoot+1, inEnd, inMap);

        return root;
    }
};

// Helper function: inorder traversal (to verify)
void printInorder(TreeNode* root) {
    if(!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Helper function: preorder traversal (to verify)
void printPreorder(TreeNode* root) {
    if(!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder  = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);

    cout << "Inorder of constructed tree: ";
    printInorder(root);   // should match original inorder
    cout << "\n";

    cout << "Preorder of constructed tree: ";
    printPreorder(root);  // should match original preorder
    cout << "\n";

    return 0;
}
