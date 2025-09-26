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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Nested map: column -> row -> multiset of values
        map<int, map<int, multiset<int>>> nodes;
        // Queue for BFS: stores node and its (x, y) coordinates
        queue<pair<TreeNode*, pair<int,int>>> todo;
        todo.push({root, {0,0}});

        while(!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first;   // column
            int y = p.second.second;  // row

            nodes[x][y].insert(node->val);

            if(node->left) todo.push({node->left, {x-1, y+1}});
            if(node->right) todo.push({node->right, {x+1, y+1}});
        }

        // Build the answer from the nodes map
        vector<vector<int>> ans;
        for(auto p : nodes) {
            vector<int> col;
            for(auto q : p.second) {
                // Append all values at (x,y) to the column
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

int main() {
    /*
            3
           / \
          9   20
             /  \
            15   7

    Expected vertical order traversal:
    [
      [9],
      [3, 15],
      [20],
      [7]
    ]
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.verticalTraversal(root);

    cout << "Vertical Order Traversal:\n";
    for(auto &col : result) {
        for(int val : col) cout << val << " ";
        cout << endl;
    }

    return 0;
}
