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
	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) 
	{
		if (pre.size() == 0)
		{
			return nullptr;
		}

		TreeNode* root = new TreeNode(pre[0]);

		if (pre.size() == 1)
		{
			return root;
		}

		int nPostLoc = 0;

		for (int i = 0; i < post.size(); i++)
		{
			if (post[i] == pre[1])
			{
				nPostLoc = i + 1;
			}
		}

		std::vector<int>::const_iterator first1 = pre.begin() + 1;
		std::vector<int>::const_iterator last1 = pre.begin() + 1 + nPostLoc;
		std::vector<int> frontLeftVec(first1, last1);

		std::vector<int>::const_iterator first2 = post.begin();
		std::vector<int>::const_iterator last2 = post.begin() + nPostLoc;
		std::vector<int> backLeftVec(first2, last2);

		root->left = constructFromPrePost(frontLeftVec, backLeftVec);

		std::vector<int>::const_iterator first3 = pre.begin() + 1 + nPostLoc;
		std::vector<int>::const_iterator last3 = pre.end();
		std::vector<int> frontRightVec(first3, last3);

		std::vector<int>::const_iterator first4 = post.begin() + nPostLoc;
		std::vector<int>::const_iterator last4 = post.end() - 1;
		std::vector<int> backRightVec(first4, last4);

		root->right = constructFromPrePost(frontRightVec, backRightVec);

		return root;
	}
};