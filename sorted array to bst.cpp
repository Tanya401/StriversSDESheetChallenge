#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int idx = 0;
TreeNode<int>*find(vector<int>&arr,int start,int end){
    if(start>end) return nullptr;

    int mid = (start+end)/2;
    TreeNode<int>*root = new TreeNode<int>(arr[mid]);
    root->left = find(arr,start,mid-1);
    root->right = find(arr,mid+1,end);
    return root;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
   int start = 0, end = n-1;
   return find(arr,start,end);
}