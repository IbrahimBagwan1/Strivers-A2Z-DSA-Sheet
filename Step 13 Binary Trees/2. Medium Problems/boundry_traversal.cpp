#include <bits/stdc++.h>
using namespace std;

// Binary tree node structure
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isLeaf(TreeNode* root) {
        return (root->left == NULL && root->right == NULL);
    }

    void addLeftBoundary(TreeNode* root, vector<int>& boundaryTraversal) {
        TreeNode* cur = root->left;
        while (cur) {
            if (!isLeaf(cur)) boundaryTraversal.push_back(cur->data);
            if (cur->left) cur = cur->left;
            else cur = cur->right;
        }
    }

    void addLeafNodes(TreeNode* root, vector<int>& boundaryTraversal) {
        if (root == NULL) return;
        if (isLeaf(root)) {
            boundaryTraversal.push_back(root->data);
            return;
        }
        addLeafNodes(root->left, boundaryTraversal);
        addLeafNodes(root->right, boundaryTraversal);
    }

    void addRightBoundary(TreeNode* root, vector<int>& boundaryTraversal) {
        vector<int> temp;
        TreeNode* cur = root->right;
        while (cur) {
            if (!isLeaf(cur)) temp.push_back(cur->data);
            if (cur->right) cur = cur->right;
            else cur = cur->left;
        }
        for (int i = temp.size() - 1; i >= 0; i--) {
            boundaryTraversal.push_back(temp[i]);
        }
    }

    vector<int> boundary(TreeNode* root) {
        vector<int> boundaryTraversal;
        if (!root) return boundaryTraversal;
        if (!isLeaf(root)) boundaryTraversal.push_back(root->data);

        addLeftBoundary(root, boundaryTraversal);
        addLeafNodes(root, boundaryTraversal);
        addRightBoundary(root, boundaryTraversal);

        return boundaryTraversal;
    }
};

// Example usage
int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
           / \   \
          7   8   9

    Expected boundary traversal (anticlockwise):
    1 2 4 7 8 9 6 3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    root->right->right = new TreeNode(6);
    root->right->right->right = new TreeNode(9);

    Solution sol;
    vector<int> result = sol.boundary(root);

    cout << "Boundary Traversal: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
