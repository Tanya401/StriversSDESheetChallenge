#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
class nodevalue{
    public: int maxnode, minnode, maxsize;

    nodevalue(int minnode,int maxnode,int maxsize){
        this->maxnode = maxnode;
        this->minnode = minnode;
        this->maxsize = maxsize;
    }
};
nodevalue find(TreeNode<int>*root){
    if(!root) return nodevalue(INT_MAX,INT_MIN,0);

    auto left = find(root->left);
    auto right = find(root->right);

    if(left.maxnode < root->data && root->data <right.minnode){
        return nodevalue(min(left.minnode,root->data),max(root->data,right.maxnode),
        left.maxsize + right.maxsize +1);
    }
    return nodevalue(INT_MIN,INT_MAX,max(left.maxsize,right.maxsize));
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    return find(root).maxsize;

}
