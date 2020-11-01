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
	TreeNode* constructMaximumBinaryTree(std::vector<int>& nums)
	{
		return dfs(nums, 0, nums.size());
	}

	TreeNode* dfs(std::vector<int>& nums, int nLeft, int nRight)
	{
		if (nLeft == nRight)
		{
			return nullptr;
		}

		int nMaxIndex = GetMaxIndex(nums, nLeft, nRight);

		TreeNode* pRoot = new TreeNode(nums[nMaxIndex]);

		pRoot->left = dfs(nums, nLeft, nMaxIndex);
		pRoot->right = dfs(nums, nMaxIndex + 1, nRight);

		return pRoot;
	}

	int GetMaxIndex(std::vector<int>& nums, int nLeft, int nRight)
	{
		int nMaxIndex = nLeft;
		for (int i = nLeft; i < nRight; i++)
		{
			if (nums[i] > nums[nMaxIndex])
			{
				nMaxIndex = i;
			}
		}

		return nMaxIndex;
	}
};