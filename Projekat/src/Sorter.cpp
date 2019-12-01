//============================================================================
// File Name       : Ssorter.cpp
// Authors         : Dejan Todorovic
// Created         : 01.12.2019.
// Last Modified   : 01.12.2019. By Dejan Todorovic
// Version         : 1.0
// Description     : Klasa Sorter poseduje staticku metodu sort koja pomocu
// Merge Sort-a sortira vector elemenata po zadatom kriterijumu.
//============================================================================

#include "Sorter.h"

/*
Funckija koja sortira vector elemenata po zadatom kriterijmu

@param vec Vektor elemenata proizvoljnog tipa koji treba da se sortira
TODO: nisam siguran kako dokumentovati ovo
*/

template <typename T>
void static MergeSort::merge_sort(std::vector<T>& vec, bool (*comparison_fcn)(T, T), int begin = 0, int end = vec.size() - 1) {
	int middle = (end + begin) / 2;
	if (end - begin == 1) {
		if (comparison_fcn(vec[begin], vec[end])) {
			std::swap(vec[begin], vec[end]);
			return;
		}
	}
	else if (end == begin) {
		return;
	}
	merge_sort(vec, comparison_fcn, begin, middle);
	merge_sort(vec, comparison_fcn, middle + 1, end);
	merge(vec, comparison_fcn, begin, end);
}