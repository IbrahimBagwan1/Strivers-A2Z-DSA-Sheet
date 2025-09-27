#include <iostream>
#include <queue>

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

bool isLeaf(Node* root){
  return root->left==NULL && root->right==NULL;
}

void childrenSumProperty(Node* root) {
  if(root == NULL) return ;
  int total = 0;
  if(root->left) total += root->left->data;
  if(root->right) total += root->right->data;
  
  if(root->data >= total){
    if(root->left) root->left->data = root->data;
    if(root->right) root->right->data = root->data;
  }
  else if(root->data < total){
    root->data = total;
  }

  childrenSumProperty(root->left);
  childrenSumProperty(root->right);

  int afterSum = 0;
  if(root->left) afterSum+= root->left->data;
  if(root->right) afterSum+= root->right->data;
  if(root->left || root->right) root->data = afterSum;
}


// Function to print the tree (Level Order Traversal)
void printTree(Node* root) {
  if (!root) return;

  queue<Node*> q;
  q.push(root);
  q.push(nullptr);

  while (!q.empty()) {
    Node* node = q.front();
    q.pop();

    if (node == nullptr) {
      cout << endl;
      if (!q.empty()) {
        q.push(nullptr);
      }
    } else {
      cout << node->data << " ";

      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
  }
}

int main() {
  Node* root = new Node(50);
  root->left = new Node(7);
  root->right = new Node(2);
  root->left->left = new Node(3);
  root->left->right = new Node(5);
  root->right->left = new Node(1);

  cout << "Original Tree:" << endl;
  printTree(root);

  childrenSumProperty(root);
  
  cout << "\nTree after applying Children Sum Property:" << endl;
  printTree(root);

  return 0;
}