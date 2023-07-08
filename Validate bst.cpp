bool find(BinaryTreeNode<int> *root,long long mini,long long maxi){
    if(root==nullptr) return true;
    if(root->data < mini || root->data > maxi) return false;

    return ( (find(root->left,mini,root->data)) 
    && (find(root->right,root->data,maxi)));
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==nullptr) return true;
    return find(root,LONG_MIN, LONG_MAX);
}