#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

std::vector<std::string> string_to_string_vector(const std::string& input);
std::vector<int> string_to_int_vector(const std::string& input);
std::vector<std::vector<int>> string_to_int_vector2(const std::string& input);

std::vector<std::string> input_string_vector()
{
	std::string str;
	std::cin >> str;
	return string_to_string_vector(str);
}
std::vector<int> input_int_vector()
{
	std::string str;
	std::cin >> str;
	return string_to_int_vector(str);
}
std::vector<std::vector<int>> input_int_vector2()
{
	std::string str;
	std::cin >> str;
	return string_to_int_vector2(str);
}

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

std::vector<std::vector<char>> string_to_2d_char_vector(const std::string& input) {
	std::vector<std::vector<char>> result;
	if (input == "[]") return result;
	
	std::string content = input.substr(1, input.length() - 2);
	int bracket_count = 0;
	std::string current_array = "";
	
	for (char c : content) {
		if (c == '[') {
			bracket_count++;
			current_array += c;
		} else if (c == ']') {
			bracket_count--;
			current_array += c;
			if (bracket_count == 0) {
				std::vector<std::string> str_vec = string_to_string_vector(current_array);
				std::vector<char> char_vec;
				for (const std::string& s : str_vec) {
					if (!s.empty()) {
						char_vec.push_back(s[0]);
					}
				}
				result.push_back(char_vec);
				current_array = "";
			}
		} else if (c == ',' && bracket_count == 0) {
			// Skip comma between arrays
		} else {
			current_array += c;
		}
	}
	return result;
}

void print_2d_char_vector(const std::vector<std::vector<char>>& vec2d) {
	for (const auto& vec1 : vec2d) {
		for (char c : vec1) {
			std::cout << c << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

std::vector<std::vector<char>> input_2d_char_vector()
{
	std::string str;
	std::cin >> str;
	return string_to_2d_char_vector(str);
}
std::vector<std::vector<int>> string_to_int_vector2(const std::string& input) {
	std::vector<std::vector<int>> result;
	if (input == "[]") return result;

	std::string content = input.substr(1, input.length() - 2);
	std::stringstream ss(content);
	std::string item;
	int bracket_count = 0;
	std::string current_array = "";

	for (char c : content) {
		if (c == '[') {
			bracket_count++;
			current_array += c;
		}
		else if (c == ']') {
			bracket_count--;
			current_array += c;
			if (bracket_count == 0) {
				result.push_back(string_to_int_vector(current_array));
				current_array = "";
			}
		}
		else if (c == ',' && bracket_count == 0) {
			// Skip comma between arrays
		}
		else {
			current_array += c;
		}
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
		size_t start = item.find_first_not_of(" \t");
		size_t end = item.find_last_not_of(" \t");
		if (start != std::string::npos && end != std::string::npos) {
			item = item.substr(start, end - start + 1);
		}

		if (item.length() >= 2 && item.front() == '"' && item.back() == '"') {
			item = item.substr(1, item.length() - 2);
		}

		result.push_back(item);
	}
	return result;
}
