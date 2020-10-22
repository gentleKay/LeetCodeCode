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
	std::unordered_map<int, int> inorderMap;

	TreeNode * buildTree(std::vector<int>& preorder, std::vector<int>& inorder) 
	{
		int nPreLen = preorder.size();
		int nInLen = inorder.size();
		
		for (int i = 0; i < inorder.size(); i++)
		{
			inorderMap.emplace(inorder[i], i);
		}

		return buildTree(preorder, 0, nPreLen - 1, inorderMap, 0, nInLen - 1);
	}

	TreeNode* buildTree(std::vector<int>& preoder, int preLeft, int preRight, 
		std::unordered_map<int, int>& inorderMap, int inLeft, int inRight)
	{
		if (preLeft > preRight || inLeft > inRight)
		{
			return nullptr;
		}

		TreeNode* rootVal = new TreeNode(preoder[preLeft]);
		int pIndex = inorderMap[rootVal->val];

		rootVal->left = buildTree(preoder, preLeft + 1, pIndex + preLeft - inLeft, 
			inorderMap, inLeft, pIndex - 1);

		rootVal->right = buildTree(preoder, pIndex + preLeft - inLeft + 1, preRight, 
			inorderMap, pIndex + 1, inRight);

		return rootVal;
	}
};