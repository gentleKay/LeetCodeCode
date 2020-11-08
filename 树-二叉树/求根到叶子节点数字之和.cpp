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
	int sum = 0;

	int sumNumbers(TreeNode* root) 
	{
		dfs(root, 0);

		return sum;
	}


	void dfs(TreeNode* root, int num)
	{
		if (!root)
		{
			return;
		}

		if (!root->left && !root->right)
		{
			sum += num * 10 + root->val;
			return;
		}

		dfs(root->left, num * 10 + root->val);

		dfs(root->right, num * 10 + root->val);
	}
};