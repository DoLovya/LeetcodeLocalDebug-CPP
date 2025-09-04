
cmake_minimum_required(VERSION 3.10)
project(LeetCodeTest)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加可执行文件
add_executable(LeetCodeTest 
	"leetcode_list.h"
	"leetcode_vector.h"
	"leetcode_headers.h"
	"leetcode_tree.h"
	"leetcode_test.cpp"
)

# 可选：添加头文件搜索路径
target_include_directories(LeetCodeTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
