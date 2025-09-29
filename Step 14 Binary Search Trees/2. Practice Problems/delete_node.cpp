#include<bits/stdc++.h>
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
    TreeNode* inordersuccessor(TreeNode* root){
     TreeNode* cur = root;
     while(cur->left != NULL){
      cur = cur->left;
     }
     return cur;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
     TreeNode* temp = root;
     if(root == NULL) return root;
     if(key > root->val){
      root->right = deleteNode(root->right, key);
     }
     else if(key < root->val){
      root->left = deleteNode(root->left, key);
     }
     else{
      if(root->left == NULL){
       temp = root->right;
       delete(root);
       return temp;
      }
      else if(root->right == NULL){
       temp = root->left;
       delete(root);
       return temp;
      }

      temp = inordersuccessor(root->right);
      root->val = temp->val;
      root->right = deleteNode(root->right, temp->val);
      
     }
     return root;
    }
};

// Function to create a sample BST for testing
TreeNode* createSampleBST() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    return root;
}

// Function to print the BST (inorder traversal)
void inorderPrint(TreeNode* root) {
    if (root != NULL) {
     inorderPrint(root->left);
     cout << root->val << " ";
     inorderPrint(root->right);
    }
}

int main() {
    Solution sol;
    TreeNode* root = createSampleBST();

    cout << "Original BST (inorder): ";
    inorderPrint(root);
    cout << endl;

    int keyToDelete = 3;
    root = sol.deleteNode(root, keyToDelete);

    cout << "BST after deleting " << keyToDelete << " (inorder): ";
    inorderPrint(root);
    cout << endl;

    return 0;
}