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
TreeNode<int>* find(TreeNode<int>*root,int x,int y){
    if(!root) return nullptr;

    if(root->data == x || root->data == y) return root;
    TreeNode<int>* left = find(root->left,x,y);
    TreeNode<int>* right = find(root->right,x,y);

    if(left && right) return root;
    if(!right) return left;
    return right;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    if(root == nullptr) return 0;
    TreeNode<int>*lca = find(root,x,y);
    return lca->data;
}