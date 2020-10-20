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
    TreeNode * pruneTree(TreeNode* root) {
		return judge(root) ? root : nullptr;
	}

	bool judge(TreeNode* root)
	{
		if (!root)
		{
			return false;
		}

		bool bLeft = judge(root->left);
		bool bRight = judge(root->right);

        if (!bLeft)
        {
            root->left = nullptr;
        }
        if (!bRight)
        {
            root->right = nullptr;
        }

		return root->val || bLeft || bRight;
	}
};