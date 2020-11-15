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
	int nResult = 0;

	int minCameraCover(TreeNode* root) 
	{
		if (dfs(root) == 0)
		{
			nResult++;
		}

		return nResult;
	}

	int dfs(TreeNode* root)
	{
		if (!root)
		{
			return 2;
		}

		int nLeft = dfs(root->left);

		int nRight = dfs(root->right);

		if (nLeft == 2 && nRight == 2)
		{
			return 0;
		}
		else if (nLeft == 0 || nRight == 0)
		{
			nResult++;
			return 1;
		}
		else //if (nLeft == 1 || nRight == 1)
		{
			return 2;
		}
	}
};