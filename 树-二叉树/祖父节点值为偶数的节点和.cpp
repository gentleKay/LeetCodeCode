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
 	int nResult;

	int sumEvenGrandparent(TreeNode* root)
	{
		dfs(root);

		return nResult;
	}

	void dfs(TreeNode* root)
	{
		if (!root)
		{
			return;
		}

		if (root->val % 2 == 0)
		{
			if (root->left)
			{
				if (root->left->left)
				{
					nResult += root->left->left->val;
				}

				if (root->left->right)
				{
					nResult += root->left->right->val;
				}
			}

			if (root->right)
			{
				if (root->right->left)
				{
					nResult += root->right->left->val;
				}

				if (root->right->right)
				{
					nResult += root->right->right->val;
				}
			}
		}

		dfs(root->left);

		dfs(root->right);
	}
};