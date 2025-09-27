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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        int maxWidth = 0;
        q.push({root, 0});

        while (!q.empty()) {
            unsigned long long minId = q.front().second;
            int size = q.size();
            unsigned long long last = 0, first = 0;

            for (int i = 0; i < size; i++) {
                unsigned long long currId = q.front().second - minId;
                TreeNode* node = q.front().first; 
                q.pop();

                if (i == 0) first = currId;
                if (i == size - 1) last = currId;

                if (node->left) q.push({node->left, 2 * currId + 1});
                if (node->right) q.push({node->right, 2 * currId + 2});
            }
            maxWidth = max(maxWidth, int(last - first + 1));
        }

        return maxWidth;
    }
};

int main() {
    /*
        Build example tree:
                1
               / \
              3   2
             /     \
            5       9
           /         \
          6           7

        Expected maximum width = 8 (between nodes 6 and 7)
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    Solution sol;
    cout << "Maximum width of the binary tree: " << sol.widthOfBinaryTree(root) << endl;

    return 0;
}
