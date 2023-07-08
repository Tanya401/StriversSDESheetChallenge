#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
//ceil matlab usse ek bada
void find(BinaryTreeNode<int> *node, int x,int &ceil){
    if(node==nullptr) return;
    
    if(node->data==x){
        ceil=node->data;
        return;
    }

    if(node->data > x)
    {
        ceil = node->data;
        find(node->left,x,ceil);
    }
    else find(node->right,x,ceil);
}
int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ceil = INT_MAX;
    find(node,x,ceil);
    if(ceil==INT_MAX) return -1;
    return ceil;
}