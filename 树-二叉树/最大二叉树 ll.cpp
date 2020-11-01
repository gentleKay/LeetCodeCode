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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (!root || root->val < val)
        {
            TreeNode* pTemp = new TreeNode(val);

            pTemp->left = root;

            return pTemp;
        }

        TreeNode* pRight = insertIntoMaxTree(root->right, val);
        root->right = pRight;

        return root;
    }
};