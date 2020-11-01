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
	int countPairs(TreeNode* root, int distance)
	{
		int nCodeResult = 0;

		dfs(root, distance, nCodeResult);

		return nCodeResult;
	}

	std::vector<int> dfs(TreeNode* root, int distance, int& nAns)
	{
		if (!root)
		{
			return {};
		}

		if (!root->left && !root->right)
		{
			return { 0 };
		}

		std::vector<int> vecResult;

		std::vector<int> vecLeft = dfs(root->left, distance, nAns);
		for (int i = 0; i < vecLeft.size(); i++)
		{
			if (vecLeft[i]++ > distance)
			{
				continue;
			}
			
			vecResult.emplace_back(vecLeft[i]);
		}

		std::vector<int> vecRight = dfs(root->right, distance, nAns);
		for (int i = 0; i < vecRight.size(); i++)
		{
			if (vecRight[i]++ > distance)
			{
				continue;
			}

			vecResult.emplace_back(vecRight[i]);
		}

		for (int i = 0; i < vecLeft.size(); i++)
		{
			for (int j = 0; j < vecRight.size(); j++)
			{
				nAns = vecLeft[i] + vecRight[j] <= distance ? nAns+1 : nAns;
			}
		}

        return vecResult;
	}
};