#include<bits/stdc++.h>
using namespace std;
// Tree node structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution{
	public:
        bool isLeaf(TreeNode* root){
            if(root->left ==NULL && root->right==NULL) return true;
            return false;
        }

        void helper(TreeNode* root, vector<vector<int>> &rootToNode, vector<int> &temp){
          if(root==NULL) return;  
          if(isLeaf(root)){
                temp.push_back(root->val);
                rootToNode.push_back(temp);
                temp.pop_back();
                return;
            }

            temp.push_back(root->val);
            helper(root->left, rootToNode, temp);
            helper(root->right, rootToNode, temp);
            temp.pop_back();
        }

		vector<vector<int>> allRootToLeaf(TreeNode* root) {
            vector<vector<int>> rootToNode;
            if(root==NULL)return rootToNode;
            vector<int> temp;
            helper(root, rootToNode, temp);
            return rootToNode;            
		}
};


int main() {
    /*
            20
           /  \
          8    22
         / \     \
        5   3     25
           / \
          10 14
    */

    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);
    root->right->right = new TreeNode(25);

    Solution sol;
    vector<vector<int>> result = sol.allRootToLeaf(root);

    cout << "All Paths of Tree to Leaf: ";
    for(auto val : result){
      cout << endl;
      for(auto nums : val){
        cout << nums << " ";
      }
    }

    return 0;
}