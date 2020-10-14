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
    int kthLargest(TreeNode* root, int k) {
		std::vector<int> vec;

		if (!root)
		{
			return 0;
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

		return vec[vec.size() - k];
    }
};


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
int res=0,i=0;//res存储节点值，i计数
    int kthLargest(TreeNode* root, int k) {      
        myfun(root,k);   
        return res;
    }

    void myfun(TreeNode* root,int k)
    {
        if(root == NULL)
            return;
        myfun(root->right,k);//右

        ++i;//计数
        if(i == k)//相等，把节点值保存并推出循环
        {
            res = root->val;
            return;
        }

        myfun(root->left,k); //左
    }
};