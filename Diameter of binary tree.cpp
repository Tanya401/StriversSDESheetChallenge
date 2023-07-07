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
int find(TreeNode<int>*root,int &ans){
  if(root==nullptr) return 0;
  int left = find(root->left,ans);
  int right = find(root->right,ans);
  ans = max(ans,left+right);
  return 1 + max(left,right);
  }
int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    if(!root) return 0;
    int ans = 0;
    find(root,ans);
    return ans;
}
