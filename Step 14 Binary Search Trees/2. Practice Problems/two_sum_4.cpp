#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator{
public:
    stack<TreeNode*> st;
    bool reverse;

    BSTIterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext(){
        return !st.empty();
    }

    int next(){
        TreeNode* node = st.top(); st.pop();
        if(!reverse) pushAll(node->right);
        else pushAll(node->left);
        return node->val;
    }

    void pushAll(TreeNode* node){
        while(node != NULL){
            st.push(node);
            if(reverse) node = node->right;
            else node = node->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        BSTIterator l(root, false); // smallest → largest
        BSTIterator r(root, true);  // largest → smallest

        int i = l.next();
        int j = r.next();

        while(i < j){
            if(i + j == k) return true;
            if(i + j < k){
                if(l.hasNext()) i = l.next();
                else break;
            }
            else{
                if(r.hasNext()) j = r.next();
                else break;
            }
        }
        return false;
    }
};

int main() {
    /*
        Constructing BST:
                5
               / \
              3   7
             / \   \
            2   4   8
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);

    Solution sol;

    int k1 = 9;
    int k2 = 14;

    cout << "Does BST have two nodes with sum " << k1 << "? "
         << (sol.findTarget(root, k1) ? "Yes" : "No") << endl;

    cout << "Does BST have two nodes with sum " << k2 << "? "
         << (sol.findTarget(root, k2) ? "Yes" : "No") << endl;

    return 0;
}
