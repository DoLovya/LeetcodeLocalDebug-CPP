#pragma once

#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


ListNode* input_list() {
	int n; std::cin >> n;

	ListNode* head1 = new ListNode();
	ListNode* head2 = head1;
	for (int i = 0; i < n; i++) {
		int val;
		std::cin >> val;

		ListNode* node = new ListNode(val);
		head2->next = node;
		head2 = head2->next;
	}
	return head1->next;
}

void output_list(ListNode* head)
{
	while (head != nullptr) {
		std::cout << head->val << " ";
		head = head->next;
	}
}