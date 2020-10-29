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
	bool isSymmetric(TreeNode* root) {
		if (!root)
		{
			return true;
		}

		return isSymmetric(root->left, root->right);

	}

	bool isSymmetric(TreeNode* pLeft, TreeNode* pRight)
	{
		if (pLeft == nullptr && pRight == nullptr)
		{
			return true;
		}

		if (pLeft == nullptr || pRight == nullptr)
		{
			return false;
		}

		if (pLeft->val != pRight->val)
		{
			return false;
		}

		return isSymmetric(pLeft->left, pRight->right) && isSymmetric(pLeft->right, pRight->left);
	}
};