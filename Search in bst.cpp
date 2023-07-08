#include <bits/stdc++.h> 
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
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
*/
void find(BinaryTreeNode<int> *root, int x,bool &ans){
    if(root==nullptr) return;
    if(root->data == x) {
        ans = true;
        return;
    }
    if(root->data < x) 
    return find(root->right,x,ans);
    return find(root->left,x,ans);
}
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(root==nullptr) return false;
    bool ans = false;
    find(root,x,ans);
    return ans;
}