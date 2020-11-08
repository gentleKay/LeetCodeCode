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
	bool isSymmetric(TreeNode* root) 
	{
		if (!root)
		{
			return true;
		}

		return dfs(root->left, root->right);
	}

	bool dfs(TreeNode* pLeft, TreeNode* pRight)
	{
		if (!pLeft && !pRight)
		{
			return true;
		}

		if (!pLeft || !pRight)
		{
			return false;
		}

		if (pLeft->val != pRight->val)
		{
			return false;
		}

		return dfs(pLeft->left, pRight->right) && dfs(pLeft->right, pRight->left);
	}
};