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
    TreeNode* increasingBST(TreeNode* root) {
        std::vector<int> vec;

		if (!root)
		{
			return nullptr;
		}

		std::stack<TreeNode*> stk;

		while (root || !stk.empty())
		{
			if (root)
			{
				stk.push(root);
				root = root->left;
			}
			else
			{
				root = stk.top();
				stk.pop();
				vec.emplace_back(root->val);

				root = root->right;
			}
		}

		TreeNode* pRoot = new TreeNode(0);
		TreeNode* pHead = pRoot;
		for (int i = 0; i < vec.size(); i++)
		{
			TreeNode* pNode = new TreeNode(vec[i]);

			pHead->right = pNode;
			pHead = pNode;
		}

		return pRoot->right;
    }
};