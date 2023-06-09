/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int ans = 0;
int find(TreeNode*root){
    if(root==nullptr) return 0;
    int left = find(root->left);
    int right = find(root->right);
    ans = max(left,right)+1;
    return max(left,right)+1;
}
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        find(root);
        return ans;
    }
};