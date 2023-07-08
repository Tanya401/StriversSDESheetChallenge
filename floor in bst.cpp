void find(TreeNode<int>* root, int x, int& floor) {
    if (root == nullptr) return;

    if (root->val == x) {
        floor = root->val;
        return;
    }

    if (root->val > x) {
        find(root->left, x, floor);
    } else {
        floor = root->val;
        find(root->right, x, floor);
    }
}

int floorInBST(TreeNode<int>* root, int X) {
    int floor = INT_MIN;
    find(root, X, floor);
    return floor;
}