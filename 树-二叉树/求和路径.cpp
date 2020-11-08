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
	int nCount = 0;

	int pathSum(TreeNode* root, int sum) 
	{
		if (!root)
		{
			return 0;
		}

		dfs(root, sum);
		
		pathSum(root->left, sum);
		pathSum(root->right, sum);

		return nCount;
	}

	void dfs(TreeNode* root, int sum)
	{
		if (!root)
		{
			return;
		}

		if (sum == root->val)
		{
			nCount++;
		}

		dfs(root->left, sum - root->val);

		dfs(root->right, sum - root->val);
	}
};