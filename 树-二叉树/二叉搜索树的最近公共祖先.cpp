//二叉搜索树的最近公共祖先
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

		TreeNode* pResult = root;

		while (true)
		{
			if (pResult->val > p->val && pResult->val > q->val)
			{
				pResult = pResult->left;
			}
			else if (pResult->val < p->val && pResult->val < q->val)
			{
				pResult = pResult->right;
			}
			else
			{
				break;
			}
		}
		
		return pResult;
	}
};