#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
 unordered_map<int,int> mp;
void find(BinaryTreeNode<int> *root, int k,bool &ans){
    if(root==nullptr) return;

    int val = root->data;
    if(mp.find(k-val)!=mp.end()){
        ans = true;
        return;
    }
    mp[val] = 1;

    find(root->left,k,ans);
    find(root->right,k,ans);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    mp.clear();
    bool ans = false;
    find(root,k,ans);
    return ans;
}