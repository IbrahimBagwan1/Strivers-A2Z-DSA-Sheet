#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution {	
public:
    vector<int> floorCeilOfBST(TreeNode* root, int key) {
        int floor = -1;
        int ceilVal = -1;
        TreeNode* cur = root;

        while (cur) {
            if (cur->data == key) {
                floor = cur->data;
                ceilVal = cur->data;
                break;
            } 
            else if (cur->data > key) {
                ceilVal = cur->data;   // possible ceil
                cur = cur->left;
            } 
            else {
                floor = cur->data;     // possible floor
                cur = cur->right;
            }
        }

        return {floor, ceilVal};
    }
};

int main() {
    // Example BST:
    //        8
    //       / \
    //      4   12
    //     / \   / \
    //    2   6 10  14

    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    Solution sol;

    vector<int> keys = {5, 1, 15, 10};  // test values
    for (int key : keys) {
        vector<int> ans = sol.floorCeilOfBST(root, key);
        cout << "Key: " << key 
             << " -> Floor = " << ans[0] 
             << ", Ceil = " << ans[1] << endl;
    }

    return 0;
}
