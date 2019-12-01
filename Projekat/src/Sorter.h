#pragma once
#include <vector>

class MergeSort
{
public:
	template <typename T>
	void static merge_sort(std::vector<T>& vec, bool (*comparison_fcn)(T, T), int begin, int end);
};