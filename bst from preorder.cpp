#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

TreeNode<int>* find(vector<int>&preOrder,int start,int end){
   if(start>end) return nullptr;
   int mid = (start+end)/2;
   TreeNode<int>*root = new TreeNode<int>(preOrder[mid]);
   root->left = find(preOrder,start,mid-1);
   root->right = find(preOrder,mid+1,end);
   return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    int idx = 0;
    sort(preOrder.begin(),preOrder.end());
    int start = 0 , end = preOrder.size()-1;
    return find(preOrder,start,end);
}