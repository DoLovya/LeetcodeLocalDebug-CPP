#pragma once	

#include "leetcode_headers.h"

using namespace std;

// Copy to this
class Solution {
	int dp[1001];
public:
	string longestPalindrome(string s) {
		dp[0] = 1;
		for (int i = 1; i < s.size(); i++) {
			dp[i] = 1;
			for (int j = 0; j < i; j++) {
				if (s[j] == s[i] && dp[i - 1] == i - j - 1) {
					dp[i] = std::max(dp[i], dp[i - 1] + 2);
				}
				if (s[j] == s[i] && i == j + 1) {
					dp[i] = std::max(dp[i], 2);
				}
				if (s[j] == s[i] && i == j + 2) {
					dp[i] = std::max(dp[i], 3);
				}
			}
		}

		int max = 0;
		for (int i = 0; i < s.size(); i++) {
			max = std::max(max, dp[i]);
		}
		for (int i = 0; i < s.size(); i++) {
			if (dp[i] == max) {
				return s.substr(i - max + 1, max);
			}
		}
		return "";
	}
};