/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int ans;

	int longestZigZag(TreeNode* root) 
	{
		dfs(root->left, 0, 1);
		dfs(root->right, 1, 1);

		return ans;
	}

	void dfs(TreeNode* root, int dir, int dis)
	{
		if (!root)
		{
			return;
		}

		ans = std::max(ans, dis);

		if (dir)
		{
			dfs(root->left, 0, dis + 1);
			dfs(root->right, 1, 1);
		}
		else
		{
			dfs(root->left, 0, 1);
			dfs(root->right, 1, dis + 1);
		}
	}
};