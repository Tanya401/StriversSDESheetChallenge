#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void left(TreeNode<int>*root,vector<int>&ans){
    if(root == nullptr || (!root->left && !root->right)) return;
       ans.push_back(root->data);
    if (root->left) {
      left(root->left, ans);
    } else if (root->right) {
      left(root->right, ans);
    }
}
void leaves(TreeNode<int>* root,vector<int>&ans){
    if(root==nullptr) return;

    leaves(root->left,ans);
    if(!root->left && !root->right) ans.push_back(root->data);
    leaves(root->right,ans);
}
void right(TreeNode<int>* root,vector<int>&ans){
    if(root==nullptr || (!root->left && !root->right)) return;

    if (root->right) {
      right(root->right, ans);
    } else if (root->left) {
      right(root->left, ans);
    }
      ans.push_back(root->data);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(!root) return ans;
     ans.push_back(root->data);
    left(root->left,ans);
    leaves(root->left, ans);
    leaves(root->right, ans);
    right(root->right,ans);
    return ans;
}

