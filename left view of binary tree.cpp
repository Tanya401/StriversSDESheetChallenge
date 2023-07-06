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

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> ans;
    if(root==nullptr) return ans;
    map<int,int> mp;
    queue<pair<int,TreeNode<int>*>> q;
    q.push({0,root});
    while(!q.empty()){
    auto front = q.front();
    q.pop();
    int level = front.first;
    TreeNode<int>*node = front.second;
    if(mp.find(level)==mp.end()) mp[level] = node->data;
    if(node->left) q.push({level+1,node->left});
    if(node->right) q.push({level+1,node->right});
    }
    for(auto it:mp){
        ans.push_back(it.second);
    }
    return ans;
}