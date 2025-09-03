#pragma once	

#include "leetcode_headers.h"

using namespace std;

// Copy to this
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
		vector<int> result;
		dfs(root, result);
		return result;
	}

private:
	void dfs(TreeNode* root, vector<int>& vec)
	{
		if (root == nullptr) return;

		dfs(root->left, vec);
		vec.push_back(root->val);
		dfs(root->right, vec);
	}
};

int main()
{
	Solution s;
	auto treeNode = input_tree();
	auto result = s.inorderTraversal(treeNode);
	print_vector(result);
	return 0;
}