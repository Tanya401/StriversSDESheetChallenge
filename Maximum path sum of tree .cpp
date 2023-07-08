#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;7
        }
    };

************************************************************/
long long int max(long long int a, long long int b){
    if(a > b) return a;
    return b;
}
long long int find(TreeNode<int>*root,long long int &ans){
    if(root == nullptr) return 0;

    long long int left = max(0LL,find(root->left,ans));
    long long int right = max(0LL,find(root->right,ans));

    long long int val = root->val;
    ans = max(ans,(left+right)+val);
    
    return max(left,right)+val;
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    long long int ans = LLONG_MIN;
    if(root==nullptr) return 0;
    find(root,ans);
    return ans;
}