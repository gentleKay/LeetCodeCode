/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:

	std::vector<int> totalVec;

	FindElements(TreeNode* root) {
		if (!root)
		{
			return;
		}

		root->val = 0;

		totalVec.emplace_back(root->val);

		dfs(root->left, root->val, 0);
		dfs(root->right, root->val, 1);
	}

	void dfs(TreeNode* root, int val, int nNum)
	{
		if (!root)
		{
			return;
		}

		if (nNum == 0)
		{
			root->val = 2 * val + 1;
		}
		else
		{
			root->val = 2 * val + 2;
		}

		totalVec.emplace_back(root->val);

		dfs(root->left, root->val, 0);
		dfs(root->right, root->val, 1);
	}

	bool find(int target)
	{
		for (int i = 0; i < totalVec.size(); i++)
		{
			if (target == totalVec[i])
			{
				return true;
			}
		}

		return false;
	}
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */