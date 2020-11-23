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

	int distributeCoins(TreeNode* root) 
	{
		dfs(root);

		return ans;
	}

	int dfs(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}

		int nLeft = dfs(root->left);
		int nRight = dfs(root->right);

		ans += std::abs(nLeft) + std::abs(nRight);

		return root->val + nLeft + nRight - 1;
	}
};