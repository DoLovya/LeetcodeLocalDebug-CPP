# LeetCode 本地调试环境

这是一个用于本地方便调试 LeetCode 代码的 C++ 环境，提供了常用的数据结构和工具函数，让你可以在本地快速测试和调试 LeetCode 题目的解决方案。

## 数据结构工具使用说明

### 1. 链表工具 (leetcode_lisst.h)

#### 结构定义
```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
```

#### 使用方法
```cpp
#include "leetcode_lisst.h"

// 从控制台输入创建链表
// 输入格式：先输入节点数量，然后输入各节点值
// 例如：5 1 2 3 4 5
ListNode* head = input_list();

// 输出链表
output_list(head);
```

### 2. 二叉树工具 (leetcode_tree.h)

#### 结构定义
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
```

#### 使用方法
```cpp
#include "leetcode_tree.h"

// 从字符串构建二叉树（LeetCode格式）
// 输入格式：[1,2,3,null,null,4,5]
string input = "[1,2,3,null,null,4,5]";
TreeNode* root = build_tree(input);

// 从控制台输入构建二叉树
TreeNode* root = input_tree();

// 打印二叉树（前序遍历）
print_tree(root);
```

### 3. 向量工具 (leetcode_vector.h)

#### 使用方法
```cpp
#include "leetcode_vector.h"

// 打印一维向量
vector<int> nums = {1, 2, 3, 4, 5};
print_vector(nums);

// 打印二维向量
vector<vector<int>> matrix = {{1, 2}, {3, 4}, {5, 6}};
print_vector2(matrix);

// 从字符串创建整数向量
// 输入格式：[1,2,3,4,5]
string str = "[1,2,3,4,5]";
vector<int> vec = string_to_int_vector(str);

// 从控制台输入创建整数向量
vector<int> vec = intput_int_vector();
```

### 4. 常用头文件 (leetcode_headers.h)
包含了 LeetCode 题目中常用的头文件：
- `<math.h>`
- `<stack>`
- `<vector>`
- `<string>`
- `<unordered_map>`

### 5. Solution 模板 (leetcode_test.cpp)
提供了标准的 Solution 类模板，你可以直接在这里编写你的解决方案。

## 使用方法

### 环境要求
- CMake 3.10 或更高版本
- C++17 编译器

### 构建项目

1. 在项目根目录创建构建目录：
```bash
mkdir build
cd build
```

2. 生成构建文件：
```bash
cmake ..
```

3. 编译项目：
```bash
cmake --build .
```

### 使用步骤

1. **编写解决方案**：在 `leetcode_test.h` 文件中的 `Solution` 类里编写你的解决方案

2. **修改主函数**：根据题目要求，在 `main.cpp` 中修改输入输出逻辑

3. **编译运行**：使用上述构建步骤编译并运行程序

### 示例使用

当前项目包含了一个最长回文子串的示例实现：

```cpp
// 在 leetcode_test.cpp 中
#include "leetcode_headers.h"
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // 你的实现代码
    }
};

int main() {
    std::string str;
    std::cin >> str;
    
    Solution s;
    auto result = s.longestPalindrome(str);
    std::cout << result << std::endl;
    return 0;
}
```

## 自定义使用

你可以根据不同的题目需求：

1. **修改输入输出**：在 `main.cpp` 中根据题目要求修改输入输出格式
2. **使用工具函数**：利用提供的链表和向量工具函数简化数据处理
3. **添加新的工具函数**：根据需要在相应的头文件中添加新的工具函数

## 注意事项

- 确保在提交 LeetCode 时只复制 Solution 类中的核心代码
- 本地调试时可以使用所有提供的工具函数
- 项目使用 C++17 标准，确保你的编译器支持

## 贡献

欢迎提交 Issue 和 Pull Request 来改进这个调试环境！

## 许可证

本项目采用 MIT 许可证。