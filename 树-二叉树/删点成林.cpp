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
	std::vector<TreeNode*> vecTreeNode;
	std::unordered_set<int> todelete;

	std::vector<TreeNode*> delNodes(TreeNode* root, std::vector<int>& to_delete) 
	{
		todelete.insert(to_delete.begin(), to_delete.end());

		dfs(root);

		if (root)
		{
			vecTreeNode.push_back(root);
		}

		return vecTreeNode;
	}

	void dfs(TreeNode*& root)
	{
		if (!root)
		{
			return;
		}

		dfs(root->left);

		dfs(root->right);

		if (todelete.count(root->val))
		{
			if (root->left)
			{
				vecTreeNode.push_back(root->left);
			}

			if (root->right)
			{
				vecTreeNode.push_back(root->right);
			}

			root = nullptr;
		}
	}

};