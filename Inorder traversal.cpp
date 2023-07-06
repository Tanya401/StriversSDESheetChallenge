#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void find(TreeNode*root,vector<int>&ans){
    if(root==nullptr) return;
    find(root->left,ans);
    ans.push_back(root->data);
    find(root->right,ans);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    if(root==nullptr) return {};
    vector<int> ans;
    find(root,ans);
    return ans;
}