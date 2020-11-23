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
    
	std::vector<int> vecRoot;

	int getMinimumDifference(TreeNode* root)
	{
		dfs(root);

		int ans = INT16_MAX;

		for (int i = 0; i < vecRoot.size(); i++)
		{
			for (int j = i + 1; j < vecRoot.size(); j++)
			{
				 ans = std::min(ans, abs(vecRoot[i] - vecRoot[j]));
			}
		}

		return ans;
	}

	void dfs(TreeNode* root)
	{
		if (!root)
		{
			return;
		}

		vecRoot.emplace_back(root->val);

		dfs(root->left);
		dfs(root->right);
	}
};