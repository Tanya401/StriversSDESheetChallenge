#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
       vector<int> ans;
    if(root==nullptr) return ans;
    map<int,int> mp;
    queue<pair<int,TreeNode<int>*>> q;
    q.push({0,root});
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        int vertical = front.first;
        TreeNode<int>*node = front.second;
        if(mp.find(vertical)==mp.end()) mp[vertical] = node->val;
        if(node->left) q.push({vertical-1,node->left});
        if(node->right) q.push({vertical+1,node->right});
    }
    for(auto it:mp) ans.push_back(it.second);
    return ans;
}