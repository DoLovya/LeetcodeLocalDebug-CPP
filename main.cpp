#include "leetcode_lisst.h"
#include "leetcode_vector.h"
#include "leetcode_test.h"
#include "leetcode_headers.h"

Solution s;

int main()
{
	std::string str;
	std::cin >> str;

	auto result = s.longestPalindrome(str);
	std::cout << result << std::endl;
	return 0;
}