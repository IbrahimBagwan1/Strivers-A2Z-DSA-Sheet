#include <bits/stdc++.h>
using namespace std;

// Tree node structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void preorderRightSideView(TreeNode* root, vector<int> &ans, int level) {
        if(root == NULL) return;

        // If visiting this level for the first time → add the node
        if(level == ans.size()) {
            ans.push_back(root->val);
        }

        // Prioritize right subtree first
        preorderRightSideView(root->right, ans, level+1);
        preorderRightSideView(root->left, ans, level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        preorderRightSideView(root, ans, 0);
        return ans;
    }
};

int main() {
    /*
            1
           / \
          2   3
           \   \
            5   4

    Expected Right Side View: [1, 3, 4]
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> result = sol.rightSideView(root);

    cout << "Right Side View of Tree: ";
    for(int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
