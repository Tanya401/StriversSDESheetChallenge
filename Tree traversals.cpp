#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
void postorder(BinaryTreeNode<int>*root,vector<int>&ans){
    if(root==nullptr) return;
    postorder(root->left,ans);
    postorder(root->right,ans);
    ans.push_back(root->data);
}
void preorder(BinaryTreeNode<int>*root,vector<int>&ans){
    if(root==nullptr) return;
    ans.push_back(root->data);
    preorder(root->left,ans);
    preorder(root->right,ans);
}
void inorder(BinaryTreeNode<int>*root,vector<int>&ans){
    if(root==nullptr) return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> ans;
    if(root==nullptr) return ans;
    vector<int> temp;
    inorder(root,temp);
    ans.push_back(temp);
    temp.clear();
    preorder(root,temp);
    ans.push_back(temp);
    temp.clear();
    postorder(root,temp);
    ans.push_back(temp);
    temp.clear();
    return ans;
}