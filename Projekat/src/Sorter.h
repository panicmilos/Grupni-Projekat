#pragma once
#include <vector>

class MergeSort
{
public:
	template <typename T>
	void static merge_sort(std::vector<T>& vec, bool (*comparison_fcn)(T, T));
	template <typename T>
	void merge_sort_loop(std::vector<T>& vec, std::vector<T>& pom, bool (*comparison_fcn)(T, T), int begin, int end);
	template <typename T>
	void merge(std::vector<T>& vec, std::vector<T>& pom, bool (*comparison_fcn)(T, T), int begin, int middle, int end);
};