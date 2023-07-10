#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

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
void find(TreeNode<int> *&root,TreeNode<int> *&prev){
    if(root==nullptr) return ;

    find(root->right,prev);
    find(root->left,prev);

    root->right=prev;
    root->left = nullptr;
    prev=root;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    TreeNode<int> *prev = nullptr;
    find(root,prev);
   return root;
}