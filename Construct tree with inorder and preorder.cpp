#include <bits/stdc++.h> 
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

TreeNode<int>* find(int start, int end, const vector<int>& inorder, const vector<int>& preorder,
                    const unordered_map<int, int>& mp, int& idx) {
    if (start > end) return nullptr;
    if (idx >= preorder.size()) return nullptr;

    TreeNode<int>* root = new TreeNode<int>(preorder[idx++]);
    int mid = mp.at(root->data);
    if (start == end) return root;
    root->left = find(start, mid - 1, inorder, preorder, mp, idx);
    root->right = find(mid + 1, end, inorder, preorder, mp, idx);
    return root;
}

TreeNode<int>* buildBinaryTree(vector<int>& inorder, vector<int>& preorder) {
    int n = inorder.size();
    if (n != preorder.size()) return nullptr;

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) mp[inorder[i]] = i;

    int idx = 0;
    int start = 0, end = n - 1;
    return find(start, end, inorder, preorder, mp, idx);
}
