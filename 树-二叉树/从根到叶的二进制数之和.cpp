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
	int sum = 0;

	int sumRootToLeaf(TreeNode* root) 
	{
		dfs(root, 0);
		return sum;
	}

	void dfs(TreeNode* root, int ans)
	{
		if (!root)
		{
			return;
		}

		if (!root->left && !root->right)
		{
			sum += ans * 2 + root->val;
			return;
		}

		dfs(root->left, ans * 2 + root->val);

		dfs(root->right, ans * 2 + root->val);
	}
};