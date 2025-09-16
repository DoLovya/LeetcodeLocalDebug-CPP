#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

std::vector<std::string> stringToStringVector(const std::string& input);
std::vector<int> stringToIntVector(const std::string& input);
std::vector<std::vector<int>> stringTo2dIntVector(const std::string& input);

std::vector<std::string> inputStringVector()
{
	std::string str;
	std::cin >> str;
	return stringToStringVector(str);
}
std::vector<int> inputIntVector()
{
	std::string str;
	std::cin >> str;
	return stringToIntVector(str);
}
std::vector<std::vector<int>> input2dIntVector()
{
	std::string str;
	std::cin >> str;
	return stringTo2dIntVector(str);
}

template<typename T> void printVector(const std::vector<T>& vec) {
	for (auto num : vec) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
}

template<typename T> void print2dVector(const std::vector<std::vector<T>>& vec2) {
	for (auto vec1 : vec2) {
		for (auto num : vec1) {
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

std::vector<int> stringToIntVector(const std::string& input) {
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

std::vector<std::vector<char>> stringTo2dCharVector(const std::string& input) {
	std::vector<std::vector<char>> result;
	if (input == "[]") return result;

	std::string content = input.substr(1, input.length() - 2);
	int bracketCount = 0;
	std::string currentArray = "";

	for (char c : content) {
		if (c == '[') {
			bracketCount++;
			currentArray += c;
		}
		else if (c == ']') {
			bracketCount--;
			currentArray += c;
			if (bracketCount == 0) {
				std::vector<std::string> strVec = stringToStringVector(currentArray);
				std::vector<char> charVec;
				for (const std::string& s : strVec) {
					if (!s.empty()) {
						charVec.push_back(s[0]);
					}
				}
				result.push_back(charVec);
				currentArray = "";
			}
		}
		else if (c == ',' && bracketCount == 0) {
			// Skip comma between arrays
		}
		else {
			currentArray += c;
		}
	}
	return result;
}

void print2dCharVector(const std::vector<std::vector<char>>& vec2d) {
	for (const auto& vec1 : vec2d) {
		for (char c : vec1) {
			std::cout << c << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

std::vector<std::vector<char>> input2dCharVector()
{
	std::string str;
	std::cin >> str;
	return stringTo2dCharVector(str);
}
std::vector<std::vector<int>> stringTo2dIntVector(const std::string& input) {
	std::vector<std::vector<int>> result;
	if (input == "[]") return result;

	std::string content = input.substr(1, input.length() - 2);
	std::stringstream ss(content);
	std::string item;
	int bracketCount = 0;
	std::string currentArray = "";

	for (char c : content) {
		if (c == '[') {
			bracketCount++;
			currentArray += c;
		}
		else if (c == ']') {
			bracketCount--;
			currentArray += c;
			if (bracketCount == 0) {
				result.push_back(stringToIntVector(currentArray));
				currentArray = "";
			}
		}
		else if (c == ',' && bracketCount == 0) {
			// Skip comma between arrays
		}
		else {
			currentArray += c;
		}
	}
	return result;
}
std::vector<std::string> stringToStringVector(const std::string& input) {
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
