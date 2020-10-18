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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
				std::vector<std::vector<int>> vecResult;

		if (!root)
		{
			return vecResult;
		}
		
		std::deque<TreeNode*> deq;

		deq.push_back(root);

		bool bFlag = true;

		while (!deq.empty())
		{
			std::vector<int> vec;
			int nCurrentSize = deq.size();

			if (bFlag)
			{
				for (int i = 1; i <= nCurrentSize; i++)
				{
					TreeNode* pTmp = deq.front();
					vec.emplace_back(pTmp->val);
					deq.pop_front();

					if (pTmp->left)
					{
						deq.push_back(pTmp->left);
					}

					if (pTmp->right)
					{
						deq.push_back(pTmp->right);
					}
				}
			}
			else
			{
				for (int i = 1; i <= nCurrentSize; i++)
				{
					TreeNode* pTmp = deq.back();
					vec.emplace_back(pTmp->val);
					deq.pop_back();

					if (pTmp->right)
					{
						deq.push_front(pTmp->right);
					}

					if (pTmp->left)
					{
						deq.push_front(pTmp->left);
					}
				}
			}
			
			vecResult.emplace_back(vec);
			bFlag = !bFlag;
		}

		return vecResult;
	}
};