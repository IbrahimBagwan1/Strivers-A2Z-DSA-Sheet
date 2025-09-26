#include <bits/stdc++.h>
using namespace std;

// Tree node structure
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> bottomView(TreeNode *root) {
        if(root == NULL) return {};

        map<int, int> mp;  // col -> last node at that column
        queue<pair<TreeNode*, int>> todo;  // {node, col}
        todo.push({root, 0});

        while(!todo.empty()) {
            auto p = todo.front(); 
            todo.pop();

            TreeNode* node = p.first;
            int col = p.second;

            // overwrite → bottom-most node remains at each column
            mp[col] = node->data;

            if(node->left) {
                todo.push({node->left, col-1});
            }
            if(node->right) {
                todo.push({node->right, col+1});
            }
        }

        vector<int> traversal;
        for(auto ele : mp) {
            traversal.push_back(ele.second);
        }
        return traversal;
    }
};

int main() {
    /*
            20
           /  \
          8    22
         / \     \
        5   3     25
           / \
          10 14

    Expected Bottom View: [5, 10, 3, 14, 25]
    */

    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);
    root->right->right = new TreeNode(25);

    Solution sol;
    vector<int> result = sol.bottomView(root);

    cout << "Bottom View of Tree: ";
    for(int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
