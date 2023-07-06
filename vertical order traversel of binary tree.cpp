#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //Write your code here.
    //vertical level root
    vector<int> ans;
    if(root==nullptr) return ans;
    map<int,map<int,vector<int>>> mp;
    queue<pair<TreeNode<int>*,pair<int,int>>> q;
    q.push({root,{0,0}});
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        TreeNode<int>*node = front.first;
        int vertical = front.second.first;
        int level = front.second.second;
        mp[vertical][level].push_back(node->data);
        if(node->left) q.push({node->left,{vertical-1,level+1}});
        if(node->right) q.push({node->right,{vertical+1,level+1}});
    }
    for(auto it:mp){
        for(auto p:it.second){
             ans.insert(ans.end(),p.second.begin(),p.second.end());
        }
    }
    return ans;
}