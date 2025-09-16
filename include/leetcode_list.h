#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


std::vector<int> parseArray(const std::string& input) {
	std::vector<int> result;
	if (input == "[]") return result;

	std::string content = input.substr(1, input.length() - 2);
	std::stringstream ss(content);
	std::string item;

	while (std::getline(ss, item, ',')) {
		result.push_back(std::stoi(item));
	}
	return result;
}

ListNode* buildList(const std::vector<int>& values) {
	if (values.empty()) return nullptr;

	ListNode* head = new ListNode(values[0]);
	ListNode* current = head;

	for (int i = 1; i < values.size(); i++) {
		current->next = new ListNode(values[i]);
		current = current->next;
	}
	return head;
}

ListNode* inputList() {
	std::string input;
	std::cin >> input;
	std::vector<int> values = parseArray(input);
	return buildList(values);
}

void printList(ListNode* head)
{
	while (head != nullptr) {
		std::cout << head->val << " ";
		head = head->next;
	}
}