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
	TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
	{
		if (!root)
		{
			return nullptr;
		}

		if (root == p || root == q)
		{
			return root;
		}

		TreeNode* pLeft = lowestCommonAncestor(root->left, p, q);
		TreeNode* pRight = lowestCommonAncestor(root->right, p, q);

		if (pLeft && pRight)
		{
			return root;
		}

		return pLeft ? pLeft : pRight;
	}
};