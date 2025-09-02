#pragma once

#include <iostream>
#include <vector>
#include <sstream>

// Êä³öº¯Êý
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

std::vector<int> intput_int_vector()
{
	std::string str;
	std::cin >> str;
	return string_to_int_vector(str);
}
