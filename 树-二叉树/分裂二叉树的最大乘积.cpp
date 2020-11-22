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
		std::vector<long> vecNum;

	int maxProduct(TreeNode* root) 
	{
		dfs(root);

		long maxNum = -1;

		for (int i = 0; i < vecNum.size(); i++)
		{
			maxNum = std::max(maxNum, vecNum[i] * (vecNum.back() - vecNum[i]));
		}

		return (int)(maxNum % 1000000007);
	}

	long dfs(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}

		long result = root->val + dfs(root->left) + dfs(root->right);

		vecNum.push_back(result);

		return result;
	}
};