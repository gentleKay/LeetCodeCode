/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
 // 递归
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root)
        {
            return nullptr;
        }

        TreeNode* pTmp = root->right;
        root->right = root->left;
        root->left = pTmp;

        mirrorTree(root->left);
        mirrorTree(root->right);

        return root;
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
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root)
        {
            return nullptr;
        }

        std::queue<TreeNode*> que;
        que.push(root);

        while (!que.empty())
        {
            TreeNode* pRoot = que.front();
            que.pop();
            TreeNode* pTmp = pRoot->right;
            pRoot->right = pRoot->left;
            pRoot->left = pTmp;

            if (pRoot->left)
            {
                que.push(pRoot->left);
            }

            if (pRoot->right)
            {
                que.push(pRoot->right);
            }
        }

        return root;
    }
};