//============================================================================
// File Name       : Ssorter.h
// Authors         : Dejan Todorovic
// Created         : 01.12.2019.
// Last Modified   : 02.12.2019. By Dejan Todorovic
// Version         : 1.0
// Description     : Klasa Sorter poseduje staticku metodu sort koja pomocu
// Merge Sort-a sortira vector elemenata po zadatom kriterijumu. Pored nje
// poseduje i metode merge koja spaja vektore u jedan nakon deljenja.
//============================================================================

#pragma once
#include <vector>

class MergeSort
{
private:
	template <typename T>
	static void merge_sort_loop(std::vector<T>& vec, std::vector<T>& temp, bool (*comparison_fcn)(const T&, const T&), const int begin, const int end);
	template <typename T>
	static void merge(std::vector<T>& vec, std::vector<T>& temp, bool (*comparison_fcn)(const T&, const T&), const int begin, const int middle, const int end);
public:
	template <typename T>
	static void merge_sort(std::vector<T>& vec, bool (*comparison_fcn)(const T&, const T&));
};