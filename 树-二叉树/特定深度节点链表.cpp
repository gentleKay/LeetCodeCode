/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        		std::vector<ListNode*> vec;
		
		if (!tree)
		{
			return vec;
		}

		std::queue<TreeNode*> que;
		que.push(tree);

		while (!que.empty())
		{
			int currentQueSize = que.size();
			ListNode* pHead = new ListNode(0);
			ListNode* pLiNode = pHead;

			for (int i = 1; i <= currentQueSize; i++)
			{
				TreeNode* tmp = que.front();
				que.pop();

				ListNode* pTmpLiNode = new ListNode(tmp->val);

				pLiNode->next = pTmpLiNode;
				pLiNode = pTmpLiNode;

				if (tmp->left)
				{
					que.push(tmp->left);
				}

				if (tmp->right)
				{
					que.push(tmp->right);
				}
			}

			vec.emplace_back(pHead->next);
		}

		return vec;
    }
};