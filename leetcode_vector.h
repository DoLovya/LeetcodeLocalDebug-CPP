#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

// �������
template<typename T> void print_vector(const std::vector<T>& vec) {
	for (auto num : vec) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
}

template<typename T> void print_vector2(const std::vector<std::vector<T>>& vec2) {
	for (auto vec1 : vec2) {
		for (auto num : vec1) {
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

std::vector<int> string_to_int_vector(const std::string& input) {
	std::vector<int> result;
	std::stringstream ss(input);
	char ch;
	int num;

	ss >> ch;

	while (ss >> num) {
		result.push_back(num);
		ss >> ch;
	}
	return result;
}

std::vector<std::string> string_to_string_vector(const std::string& input) {
	std::vector<std::string> result;
	if (input == "[]") return result;
	
	std::string content = input.substr(1, input.length() - 2);
	std::stringstream ss(content);
	std::string item;
	
	while (std::getline(ss, item, ',')) {
		// 去除前后空格
		size_t start = item.find_first_not_of(" \t");
		size_t end = item.find_last_not_of(" \t");
		if (start != std::string::npos && end != std::string::npos) {
			item = item.substr(start, end - start + 1);
		}
		
		// 去除引号
		if (item.length() >= 2 && item.front() == '"' && item.back() == '"') {
			item = item.substr(1, item.length() - 2);
		}
		
		result.push_back(item);
	}
	return result;
}

std::vector<int> intput_int_vector()
{
	std::string str;
	std::cin >> str;
	return string_to_int_vector(str);
}

std::vector<std::string> input_string_vector()
{
	std::string str;
	std::cin >> str;
	return string_to_string_vector(str);
}
