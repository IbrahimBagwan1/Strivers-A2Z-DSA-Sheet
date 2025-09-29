#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
  stack<TreeNode*> st;
  void fillLeft(TreeNode* root){
    while(root){
      st.push(root);
      root = root->left;
    }
  }

  BSTIterator(TreeNode* root) {
    fillLeft(root);
  }
  
  int next() {
    TreeNode* node = st.top(); st.pop();

    if(node->right) fillLeft(node->right);
    return node? node->val : -1;
  }
  
  bool hasNext() {
    return st.size()>0;   
  }
};

int main() {
  // Example usage:
  TreeNode* root = new TreeNode(7);
  root->left = new TreeNode(3);
  root->right = new TreeNode(15);
  root->right->left = new TreeNode(9);
  root->right->right = new TreeNode(20);

  BSTIterator* iterator = new BSTIterator(root);
  cout << iterator->next() << endl;    // Output: 3
  cout << iterator->next() << endl;    // Output: 7
  cout << iterator->hasNext() << endl; // Output: true
  cout << iterator->next() << endl;    // Output: 9
  cout << iterator->hasNext() << endl; // Output: true
  cout << iterator->next() << endl;    // Output: 15
  cout << iterator->hasNext() << endl; // Output: true
  cout << iterator->next() << endl;    // Output: 20
  cout << iterator->hasNext() << endl; // Output: false

  return 0;
}