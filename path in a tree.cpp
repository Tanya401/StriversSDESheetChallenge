#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

void find(TreeNode<int>*root,vector<int>&ans,int x){
	if(root==nullptr) return;
	ans.push_back(root->data);
	if(root->data == x){
		return;
	}
	find(root->left,ans,x);
	find(root->right,ans,x);
	if(ans[ans.size()-1]!=x)
    ans.pop_back();
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> ans;
	if(root==nullptr) return ans;
	find(root,ans,x);
	return ans;
}
