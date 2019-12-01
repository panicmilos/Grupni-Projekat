#pragma once
#include <vector>

class MergeSort
{
public:
	template <typename T>
	static void merge_sort(std::vector<T>& vec, bool (*comparison_fcn)(T, T));
	template <typename T>
	static void merge_sort_loop(std::vector<T>& vec, std::vector<T>& pom, bool (*comparison_fcn)(T, T), int begin, int end);
	template <typename T>
	static void merge(std::vector<T>& vec, std::vector<T>& pom, bool (*comparison_fcn)(T, T), int begin, int middle, int end);
};