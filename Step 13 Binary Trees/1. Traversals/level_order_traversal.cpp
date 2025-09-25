#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    // Level Order Traversal
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> allLevels;
        if(root == NULL) return allLevels;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> oneLevel;

            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                oneLevel.push_back(node->val);
            }
            allLevels.push_back(oneLevel);
        }

        return allLevels;
    }

    // ✅ You will write this
    void inorder(TreeNode* root) {
        // write inorder traversal logic here
    }
};

// Helper function to build a sample tree
TreeNode* buildSampleTree() {
    /*
           1
          / \
         2   3
        / \
       4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = buildSampleTree();

    // Test inorder traversal
    cout << "Inorder Traversal: ";
    sol.inorder(root);
    cout << endl;

    // Test level order traversal
    cout << "Level Order Traversal: " << endl;
    vector<vector<int>> levels = sol.levelOrder(root);
    for(auto &level : levels) {
        for(int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
