#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    vector<int> ans;
    if(root==nullptr) return ans;
    map<int,int> mp;
    queue<pair<int,BinaryTreeNode<int>*>> q;
    q.push({0,root});
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        int vertical = front.first;
        BinaryTreeNode<int>*node = front.second;
        if(mp.find(vertical)==mp.end()) mp[vertical] = node->data;
        mp[vertical] = node->data;
        if(node->left) q.push({vertical-1,node->left});
        if(node->right) q.push({vertical+1,node->right});
    }
    for(auto it:mp) ans.push_back(it.second);
    return ans;
}
