#include <bits/stdc++.h>
using namespace std;

// Binary tree node structure
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    vector<vector<int>> treeTraversal(TreeNode* root) {
        vector<int> inorder, preorder, postorder;
        if (root == NULL) return {inorder, preorder, postorder};

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        while (!st.empty()) {
            auto it = st.top(); 
            st.pop();

            if (it.second == 1) {
                preorder.push_back(it.first->data);
                st.push({it.first, 2});

                if (it.first->left != NULL) {
                    st.push({it.first->left, 1});
                }
            } 
            else if (it.second == 2) {
                inorder.push_back(it.first->data);
                st.push({it.first, 3});

                if (it.first->right != NULL) {
                    st.push({it.first->right, 1});
                }
            } 
            else {
                postorder.push_back(it.first->data);
            }
        }

        vector<vector<int>> allTraversals;
        allTraversals.push_back(inorder);
        allTraversals.push_back(preorder);
        allTraversals.push_back(postorder);
        return allTraversals;
    }
};

// Helper function to build a sample tree
TreeNode* buildTree() {
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
    TreeNode* root = buildTree();

    vector<vector<int>> traversals = sol.treeTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : traversals[0]) cout << val << " ";
    cout << endl;

    cout << "Preorder Traversal: ";
    for (int val : traversals[1]) cout << val << " ";
    cout << endl;

    cout << "Postorder Traversal: ";
    for (int val : traversals[2]) cout << val << " ";
    cout << endl;

    return 0;
}
