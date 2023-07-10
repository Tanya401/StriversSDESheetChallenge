class BSTiterator
{
    stack<TreeNode<int> *> st;
    public:
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        pushall(root);
    }

    int next()
    {
        // write your code here
        if(hasNext()==false) return -1;
        TreeNode<int> *top = st.top();
        int ans = top->data;
        st.pop();
        pushall(top->right);
        return ans;
    }

    bool hasNext()
    {
        // write your code here
        if(st.empty()) return false;
        return true;
    }
    private:
      void pushall(TreeNode<int>* root) {
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/