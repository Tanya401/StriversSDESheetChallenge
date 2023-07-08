#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void find(TreeNode<int>* root,vector<int>&ans){
    if(root==nullptr){
        return;
    }

    find(root->left,ans);
    ans.push_back(root->data);
    find(root->right,ans);
}
int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
     vector<int> ans;
    find(root,ans);
    return ans[k-1];
}