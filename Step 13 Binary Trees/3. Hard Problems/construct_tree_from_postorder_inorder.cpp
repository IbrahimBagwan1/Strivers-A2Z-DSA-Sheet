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
    TreeNode* buildTree(vector<int> &postorder, int postStart, int postEnd,
                        vector<int> &inorder, int inStart, int inEnd,
                        map<int,int>& inMap) {
        if(postStart > postEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(postorder, postStart, postStart + numsLeft - 1,
                               inorder, inStart, inRoot - 1, inMap);

        root->right = buildTree(postorder, postStart + numsLeft, postEnd - 1,
                                inorder, inRoot + 1, inEnd, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> inMap;
        for(int i=0; i<inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        return buildTree(postorder, 0, postorder.size()-1,
                         inorder, 0, inorder.size()-1, inMap);
    }
};

// Helper function to print preorder traversal (root -> left -> right)
void printPreorder(TreeNode* root) {
    if(!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    Solution sol;

    // Example tree
    // Inorder   = [9,3,15,20,7]
    // Postorder = [9,15,7,20,3]
    vector<int> inorder   = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    TreeNode* root = sol.buildTree(inorder, postorder);

    cout << "Preorder traversal of constructed tree: ";
    printPreorder(root);
    cout << endl;

    return 0;
}
