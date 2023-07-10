void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    if(root==nullptr) return;
    BinaryTreeNode< int > *curr=root;
    while(curr->left!=nullptr){
        BinaryTreeNode< int > *temp=curr;
        while(curr!=nullptr){
            if(curr->left)
            curr->left->next = curr->right;
            if(curr->right)
            curr->right->next = (curr->next!=nullptr)?curr->next->left:nullptr;
            curr=curr->next;
        }
        curr=temp->left;
    }
}