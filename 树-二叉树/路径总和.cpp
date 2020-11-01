// 递归
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
	bool hasPathSum(TreeNode* root, int sum) 
	{
		if (!root)
		{
			return false;
		}

		if (!root->left && !root->right)
		{
			return sum == root->val;
		}

		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};


// 迭代
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
	bool hasPathSum(TreeNode* root, int sum) 
	{
		if (!root)
		{
			return false;
		}

		std::stack<TreeNode*> stkNode;
		std::stack<int> stkVal;

		stkNode.push(root);
		stkVal.push(root->val);
		
		while (!stkNode.empty())
		{
			TreeNode* pRoot = stkNode.top();
			int nRootVal = stkVal.top();

			stkNode.pop();
			stkVal.pop();

			if (!pRoot->left && !pRoot->right && nRootVal == sum)
			{
				return true;
			}

			if (pRoot->left)
			{
				stkNode.push(pRoot->left);
				stkVal.push(pRoot->left->val + nRootVal);
			}

			if (pRoot->right)
			{
				stkNode.push(pRoot->right);
				stkVal.push(pRoot->right->val + nRootVal);
			}
		}
	
		return false;
	}
};