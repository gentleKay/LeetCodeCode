// 层次遍历
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
    int countNodes(TreeNode* root)	
    {
		if (!root)
		{
			return 0;
		}

		std::queue<TreeNode*> que;
		que.push(root);

		int nLevel = 0;

		while (!que.empty())
		{
			nLevel++;
			int nCurrentQueSzie = que.size();
			
			for (int i = 1; i <= nCurrentQueSzie; i++)
			{
				TreeNode* tmp = que.front();
                que.pop();
				if (tmp->left)
				{
					que.push(tmp->left);
				}
				else
				{
					return pow(2, nLevel) + 2 * (i - 1) - 1;
				}

				if (tmp->right)
				{
					que.push(tmp->right);
				}
				else
				{
					return pow(2, nLevel) + 2 * i - 2;
				}
			}
		}
        return 0;
    }
};


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
    int countNodes(TreeNode* root)	
    {
		if (!root)
		{
			return 0;
		}
		
		return countNodes(root->left) + countNodes(root->right) + 1;
	}
};

// 二分查找
// ... 