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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> ans;
    if(!root) return ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    int flag = 0;
    while(!q.empty()){
        int size = q.size();
        vector<int> temp;
        while(size--){
            BinaryTreeNode<int> *node=q.front();
            q.pop();
            temp.push_back(node->data);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
       if(flag!=0)
       reverse(temp.begin(),temp.end());
       for(auto it:temp) ans.push_back(it);
       flag = !flag;
    }
    return ans;
}
