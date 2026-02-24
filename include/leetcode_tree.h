#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<string> splitString(const string& s, char delimiter) {
	vector<string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

TreeNode* buildTree(const string& data) {
	if (data == "[]") return nullptr;

	string content = data.substr(1, data.length() - 2);
	vector<string> nodes = splitString(content, ',');

	if (nodes.empty() || nodes[0] == "null") return nullptr;

	TreeNode* root = new TreeNode(stoi(nodes[0]));
	queue<TreeNode*> q;
	q.push(root);

	int index = 1;
	while (!q.empty() && index < nodes.size()) {
		TreeNode* current = q.front();
		q.pop();

		if (index < nodes.size() && nodes[index] != "null") {
			current->left = new TreeNode(stoi(nodes[index]));
			q.push(current->left);
		}
		index++;

		if (index < nodes.size() && nodes[index] != "null") {
			current->right = new TreeNode(stoi(nodes[index]));
			q.push(current->right);
		}
		index++;
	}

	return root;
}

void printTree(TreeNode* root) {
	if (!root) {
		cout << "null";
		return;
	}
	cout << root->val << " ";
	printTree(root->left);
	printTree(root->right);
}

TreeNode* inputTree()
{
	std::string input;
	std::cin >> input;
	return buildTree(input);
}
