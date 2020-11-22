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
	std::vector<int> rightSideView(TreeNode* root) 
	{
		std::vector<int> vecResult;
		std::queue<TreeNode*> queTreeNode;

		if (!root)
		{
			return vecResult;
		}

		queTreeNode.emplace(root);

		while (!queTreeNode.empty())
		{
			int nodeSize = queTreeNode.size();

			for (int i = 1; i <= nodeSize; i++)
			{
				TreeNode* node = queTreeNode.front();
				queTreeNode.pop();

				if (node->right)
				{
					queTreeNode.emplace(node->right);
				}

				if (node->left)
				{
					queTreeNode.emplace(node->left);
				}

				if (i == 1)
				{
					vecResult.emplace_back(node->val);
				}
			}
		}

		return vecResult;
	}
};