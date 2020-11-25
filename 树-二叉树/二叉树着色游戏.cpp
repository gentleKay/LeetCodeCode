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
    bool btreeGameWinningMove(TreeNode* root, int n, int x)
	{
		TreeNode* target = find(root, x);

		int nOther = count(root) - count(target);
		int nLCount = count(target->left);
		int nRCount = count(target->right);

		if ((nOther + nLCount < nRCount) || (nOther + nRCount < nLCount) || (nLCount + nRCount < nOther))
		{
			return true;
		}
		return false;
	}

	TreeNode* find(TreeNode* root, int x)
	{
		if (!root)
		{
			return nullptr;
		}

		if (root->val == x)
		{
			return root;
		}

		TreeNode* pLeft = find(root->left, x);
		TreeNode* pRight = find(root->right, x);

		return pLeft == nullptr ? pRight : pLeft;
	}

	int count(TreeNode* root)
	{
		if (!root)
		{
			return 0;
		}

		int nLeft = count(root->left);
		int nRight = count(root->right);

		return 1 + nLeft + nRight;
	}
};