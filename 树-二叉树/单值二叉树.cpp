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
	bool isUnivalTree(TreeNode* root) 
	{
		if (!root)
		{
			return true;
		}

		return isUnivalTree(root, root->val);
	}

	bool isUnivalTree(TreeNode* root, int value)
	{
		if (!root)
		{
			return true;
		}

		if (root->val != value)
		{
			return false;
		}

		return isUnivalTree(root->left, value) && isUnivalTree(root->right, value);
	}
};