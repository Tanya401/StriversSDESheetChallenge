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
void find(TreeNode<int>*root,string &ans){
    if(root == nullptr){
        ans += 'a';
        return;
    }
    ans += to_string(root->data) + ',';
    find(root->left,ans);
    find(root->right,ans);
}
string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
 string ans = "";
 find(root,ans);
 return ans;
}

TreeNode<int>*maketree(string &serialized,int &idx){
    idx++;
    if(idx>=serialized.size()) return nullptr;
    if(serialized[idx] == 'a') return nullptr;
    string num = "";
    while(serialized[idx]!=','){
        num += serialized[idx++];
    }
    TreeNode<int>*root = new TreeNode<int>(stoi(num));
    root->left = maketree(serialized,idx);
    root->right = maketree(serialized,idx);
   return root;
}
TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
 int n = serialized.size();
 int idx = -1;
 return maketree(serialized,idx);

}



