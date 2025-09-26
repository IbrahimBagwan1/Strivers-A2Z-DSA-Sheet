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
    vector<int> topView(TreeNode *root) {
        if(root == NULL) return {};

        map<int, int> mp;  // col -> node value
        queue<pair<TreeNode*, int>> todo; // {node, col}
        todo.push({root, 0});

        while(!todo.empty()){
            auto p = todo.front(); 
            todo.pop();

            TreeNode* node = p.first;
            int col = p.second;

            // store the first node we encounter at this column
            if(mp.find(col) == mp.end()){
                mp[col] = node->data;
            }

            if(node->left){
                todo.push({node->left, col-1});
            }
            if(node->right){
                todo.push({node->right, col+1});
            }
        }

        vector<int> traversal;
        for(auto ele : mp){
            traversal.push_back(ele.second);
        }
        return traversal;
    }
};

int main() {
    /*
            1
           / \
          2   3
           \   \
            4   5
             \   \
              6   7

    Expected Top View: [2, 1, 3, 5, 7]
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(5);
    root->right->right->right = new TreeNode(7);

    Solution sol;
    vector<int> result = sol.topView(root);

    cout << "Top View of Tree: ";
    for(int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
