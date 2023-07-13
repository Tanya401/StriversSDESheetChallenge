void solve(BinaryTreeNode<int>* root,BinaryTreeNode<int>* &head,BinaryTreeNode<int>*
&prev,int &flag){
    if(!root) return;
    solve(root->left,head,prev,flag);
    if(flag == 0){
        head=root;
        prev=root;
        flag=1;
    }else{
    prev->right = root;
    root->left = prev;
    prev = root;
    }
    solve(root->right,head,prev,flag);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    BinaryTreeNode<int>* head = nullptr;
    BinaryTreeNode<int>* prev = nullptr;
    int flag = 0;
    solve(root,head,prev,flag);
    return head;
}