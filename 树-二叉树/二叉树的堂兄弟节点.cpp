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
	bool isCousins(TreeNode* root, int x, int y)
	{
		if (!root)
		{
			return false;
		}

		std::queue<TreeNode*> queNode;
		queNode.push(root);

		TreeNode* xNode = nullptr;
		TreeNode* yNode = nullptr;
		TreeNode* xpNode = nullptr;
		TreeNode* ypNode = nullptr;

		while (!queNode.empty())
		{
			int nSize = queNode.size();

			for (int i = 0; i < nSize; i++)
			{
				TreeNode* temp = queNode.front();
				queNode.pop();

				if (temp->left)
				{
					queNode.push(temp->left);

					if (temp->left->val == x)
					{
						xNode = temp->left;
						xpNode = temp;
					}

					if (temp->left->val == y)
					{
						yNode = temp->left;
						ypNode = temp;
					}
				}

				if (temp->right)
				{
					queNode.push(temp->right);

					if (temp->right->val == x)
					{
						xNode = temp->right;
						xpNode = temp;
					}

					if (temp->right->val == y)
					{
						yNode = temp->right;
						ypNode = temp;
					}
				}
			}

			if (!xNode && !yNode)
			{
				continue;
			}
			else if (xNode && yNode)
			{
				return xpNode != ypNode;
			}
			else
			{
				return false;
			}
		}

		return false;
	}
};