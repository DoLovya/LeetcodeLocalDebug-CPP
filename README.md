# LeetCode 本地调试环境

这是一个用于本地方便调试 LeetCode 代码的 C++ 环境，提供了常用的数据结构和工具函数，让你可以在本地快速测试和调试 LeetCode 题目的解决方案。

## 项目结构

```
LeetCode/
├── main.cpp              # 主程序入口
├── leetcode_headers.h     # 常用头文件集合
├── leetcode_lisst.h       # 链表相关工具函数
├── leetcode_vector.h      # 向量相关工具函数
├── leetcode_test.h        # Solution 类模板
├── CMakeLists.txt         # CMake 构建配置
├── .gitignore            # Git 忽略文件配置
└── README.md             # 项目说明文档
```

## 功能特性

### 1. 链表工具 (leetcode_lisst.h)
- **ListNode 结构体**: 标准的 LeetCode 链表节点定义
- **input_list()**: 从控制台输入创建链表
- **output_list()**: 输出链表内容

### 2. 向量工具 (leetcode_vector.h)
- **print_vector()**: 打印一维向量
- **print_vector2()**: 打印二维向量
- **string_to_int_vector()**: 将字符串转换为整数向量
- **intput_int_vector()**: 从控制台输入创建整数向量

### 3. 常用头文件 (leetcode_headers.h)
包含了 LeetCode 题目中常用的头文件：
- `<math.h>`
- `<stack>`
- `<vector>`
- `<string>`
- `<unordered_map>`

### 4. Solution 模板 (leetcode_test.h)
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
// 在 leetcode_test.h 中
class Solution {
public:
    string longestPalindrome(string s) {
        // 你的实现代码
    }
};

// 在 main.cpp 中
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