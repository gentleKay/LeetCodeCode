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
	std::string tree2str(TreeNode* t) 
	{
        string szResult = "";

		if (!t)
		{
			return szResult;
		}

		if (!t->left && !t->right)
		{
			szResult.append(to_string(t->val));
            return szResult;
		}

        szResult.append(to_string(t->val));
        szResult += ("(" + tree2str(t->left) + ")");

		if (t->right)
		{
			szResult += ("(" + tree2str(t->right) + ")");
		}
        
        return szResult;
	}
};