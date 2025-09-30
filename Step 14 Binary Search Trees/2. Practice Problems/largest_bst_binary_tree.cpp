#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

class NodeValue {
public:
    int minNode, maxNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

class Solution {
public:
    NodeValue largestBSTHelper(TreeNode* root) {
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        auto left = largestBSTHelper(root->left);
        auto right = largestBSTHelper(root->right);

        if (left.maxNode < root->data && root->data < right.minNode) {
            return NodeValue(min(root->data, left.minNode),
                             max(root->data, right.maxNode),
                             1 + left.maxSize + right.maxSize);
        }

        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

    int largestBST(TreeNode* root) {
        return largestBSTHelper(root).maxSize;
    }
};

// ---------- MAIN FUNCTION ----------
int main() {
    /*
         Constructing this tree:
                 10
                /  \
               5   15
              / \    \
             1   8    7

        Largest BST is:
               5
              / \
             1   8
        Size = 3
    */

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Size of Largest BST is: " << sol.largestBST(root) << endl;

    return 0;
}
