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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> vec;
        stack<TreeNode*> stk;

        if (root == nullptr)
        {
            return vec;
        }

        while (root != nullptr || !stk.empty())
        {
            if (root != nullptr)
            {
                stk.push(root);
                root = root->left;
            }
            else
            {
                root = stk.top();
                vec.emplace_back(root->val);
                stk.pop();
                root = root->right;
            }
        }

        return vec;
    }
};