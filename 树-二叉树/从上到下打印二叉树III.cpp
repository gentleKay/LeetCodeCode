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
	std::vector<std::vector<int>> levelOrder(TreeNode* root) 
	{
		std::vector<std::vector<int>> resultVec;
		
		if (!root)
		{
			return resultVec;
		}

		bool bTag = false;
		
		std::vector<int> midVec;
		std::queue<TreeNode*> nodeQue;

		nodeQue.push(root);

		while (!nodeQue.empty())
		{
			midVec.clear();
			int nSize = nodeQue.size();

			for (int i = 0; i < nSize; i++)
			{
				TreeNode* pTemp = nodeQue.front();
				nodeQue.pop();

				midVec.emplace_back(pTemp->val);

				if (pTemp->left)
				{
					nodeQue.push(pTemp->left);
				}

				if (pTemp->right)
				{
					nodeQue.push(pTemp->right);
				}
			}

			if (bTag)
			{
				reverse(midVec.begin(), midVec.end());
			}

            bTag = !bTag;
			resultVec.emplace_back(midVec);
		}

		return resultVec;
	}
};