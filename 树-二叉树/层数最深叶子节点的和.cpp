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
 	int deepestLeavesSum(TreeNode* root) 
	{
		if (!root)
		{
			return 0;
		}

		int nResult = 0;
		std::queue<TreeNode*> queNode;
		queNode.emplace(root);

		while (!queNode.empty())
		{
			int nSize = queNode.size();
			int nTempNum = 0;

			for (int i = 0; i < nSize; i++)
			{
				TreeNode* pTempNode = queNode.front();
				queNode.pop();
				nTempNum += pTempNode->val;

				if (pTempNode->left)
				{
					queNode.emplace(pTempNode->left);
				}

				if (pTempNode->right)
				{
					queNode.emplace(pTempNode->right);
				}
			}

			nResult = nTempNum;
		}

		return nResult;
	}
};