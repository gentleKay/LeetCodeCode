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
	std::vector<std::vector<int>> levelOrderBottom(TreeNode* root)
	{
		std::vector<std::vector<int>> levelVec;
        //std::vector<std::vector<int>> levelVecCopy;

		if (!root)
		{
			return levelVec;
		}

		std::queue<TreeNode*> queTreeNode;
		queTreeNode.push(root);

		std::vector<int> vecValue;

		while (!queTreeNode.empty())
		{
			vecValue.clear();

			int nodeSize = queTreeNode.size();

			for (int i = 1; i <= nodeSize; i++)
			{
				TreeNode* tmp = queTreeNode.front();
				queTreeNode.pop();
				vecValue.emplace_back(tmp->val);

				if (tmp->left)
				{
					queTreeNode.push(tmp->left);
				}

				if (tmp->right)
				{
					queTreeNode.push(tmp->right);
				}
			}

			levelVec.push_back(vecValue);
		}

        reverse(levelVec.begin(), levelVec.end());  // 利用翻转的函数
        
        /*for (int i = levelVec.size() - 1; i >= 0; i--)
        {
            levelVecCopy.push_back(levelVec[i]);
        }
        
        return levelVecCopy;
        */

        return levelVec;
	}
};