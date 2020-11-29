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
	int sumOfLeftLeaves(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}

		int nLeft = dfs(root->left, 0);
		int nRight = dfs(root->right, 1);

		return nLeft + nRight;
	}

	int dfs(TreeNode* root, int nNum)
	{
		if (!root)
		{
			return 0;
		}

		if (!root->left && !root->right && nNum == 0)
		{
			return root->val;
		}

		int nLeft = dfs(root->left, 0);
		int nRight = dfs(root->right, 1);

		return nLeft + nRight;
	}
};