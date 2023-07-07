#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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

*************************************************************/
int find(BinaryTreeNode<int>* root){
    if(!root) return 0;

    int left=0, right=0;
    if(root->left){
        left = find(root->left);
        if(left == -1) return -1;
    }

    if(root->right){
        right = find(root->right);
        if(right == -1) return -1;
    }
     if(abs(left-right)>1) return -1;
    return max(left,right)+1;
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    if(!root) return true;
    int ans = find(root);
    if(ans == -1) return false;
    return true;
}