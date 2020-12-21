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
    std::vector<int> vecNodeValue;

	int kthSmallest(TreeNode* root, int k)
	{
		dfs(root);

		return vecNodeValue[k - 1];
	}

	void dfs(TreeNode* root)
	{
		if (!root)
		{
			return;
		}

		dfs(root->left);

		vecNodeValue.emplace_back(root->val);

		dfs(root->right);
	}
};



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
    int nCount;
	int nResult;

	int kthSmallest(TreeNode* root, int k)
	{
		dfs(root, k);

		return nResult;
	}

	void dfs(TreeNode* root, int k)
	{
		if (!root)
		{
			return;
		}

		dfs(root->left, k);

		nCount++;
		if (nCount == k)
		{
			nResult = root->val;
			return;
		}

		dfs(root->right, k);
	}
};

