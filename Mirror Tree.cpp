class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void find(Node*node){
      if(node==nullptr) return;
     
      Node*left = node->left;
      Node*right = node->right;
      node->left = right;
      node->right = left;

      find(node->left);
      find(node->right);
    }
    void mirror(Node* node) {
        // code here
        if(node == nullptr) return;
        find(node);
    }
};