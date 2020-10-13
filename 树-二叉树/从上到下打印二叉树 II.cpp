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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<vector<int>> vec;
		
		if (!root)
		{
			return vec;
		}

		std::queue<TreeNode*> que;
		que.push(root);

		while (!que.empty())
		{
			int currentQueSize = que.size();
			std::vector<int> vecList;

			for (int i = 1; i <= currentQueSize; i++)
			{
				TreeNode* tmp = que.front();
				que.pop();

				vecList.emplace_back(tmp->val);

				if (tmp->left)
				{
					que.push(tmp->left);
				}

				if (tmp->right)
				{
					que.push(tmp->right);
				}
			}

			vec.emplace_back(vecList);
		}

		return vec;
    }
};