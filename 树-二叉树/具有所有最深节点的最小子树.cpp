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
	TreeNode * subtreeWithAllDeepest(TreeNode* root)
	{
		return dfs(root).first;
	}

	std::pair<TreeNode*, int> dfs(TreeNode* root)
	{
		if (!root)
		{
			return {0, 0};
		}

		auto atLeft = dfs(root->left);

		auto atRight = dfs(root->right);

		if (atLeft.second == atRight.second)
		{
			return { root, atLeft.second + 1 };
		}
		else if (atLeft.second > atRight.second)
		{
			return { atLeft.first, atLeft.second + 1 };
		}
		else
		{
			return { atRight.first, atRight.second + 1 };
		}
	}
};