#pragma once	

#include "leetcode_headers.h"

using namespace std;

// Copy to this
class Solution {
	int dp[2500];
public:
	int lengthOfLIS(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			dp[i] = 1;
			for (int j = 0; j < i; j++) {
				if (nums[j] < nums[i]) {
					dp[i] = std::max(dp[i], dp[j] + 1);
				}
			}
		}
		int max = *std::max_element(dp, dp + nums.size());
		return max;
	}
};

int main()
{
	Solution s;
	auto nums = input_int_vector();
	auto result = s.lengthOfLIS(nums);
	std::cout << result << std::endl;
	return 0;
}

