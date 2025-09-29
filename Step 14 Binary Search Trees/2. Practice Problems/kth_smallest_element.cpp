#include <iostream>

using namespace std;

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
  void helperSmall(TreeNode* root, int &k, int &count, int &elem){
    if(root == NULL) return ;
    helperSmall(root->left, k, count, elem);
    count++;
    if(count==k){
      elem = root->val;
      return ;
    }
    helperSmall(root->right, k, count, elem);
    
  }

  int kthSmallest(TreeNode* root, int k) {
    int count=0;
    int elem=0;
    helperSmall(root, k, count,elem);
    return elem;
  }
};

int main() {
  // Example usage:
  // Create a sample BST
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(1);
  root->right = new TreeNode(4);
  root->left->right = new TreeNode(2);

  Solution sol;
  int k = 1;
  int kthSmallestElement = sol.kthSmallest(root, k);

  cout << "The " << k << "th smallest element is: " << kthSmallestElement << endl;

  // Clean up memory (important to avoid memory leaks)
  delete root->left->right;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}