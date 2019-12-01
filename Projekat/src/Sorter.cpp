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
void static MergeSort::merge_sort(std::vector<T>& vec, bool (*comparison_fcn)(T, T)) {
	// zauzmemo memoriju velicine vec.size() i u tom delu vrsimo spajanje nizova
	std::vector<T> pom;
	pom.reserve(vec.size());
	merge_sort_loop(vec, &pom, comparison_fcn, 0, vec.size() - 1);
}

template <typename T>
void MergeSort::merge_sort_loop(std::vector<T>& vec, std::vector<T>& pom, bool (*comparison_fcn)(T, T), int begin, int end) {
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
	merge_sort_loop(vec, comparison_fcn, begin, middle);
	merge_sort_loop(vec, comparison_fcn, middle + 1, end);
	merge(vec, pom, comparison_fcn, begin, middle, end);
}

template<typename T>
void MergeSort::merge(std::vector<T>& vec, std::vector<T>& pom, bool(*comparison_fcn)(T, T), int begin, int middle, int end) {
	int i = begin;
	int j = middle + 1;
	int k = begin;

	while (i <= middle and j <= end) {
		if (comparison_fcn(vec[i], vec[j])) {
			pom[k] = vec[i];
			i++;
		}
		else {
			pom[k] = vec[j];
			j++;
		}
		k++;
	}
	while (i <= middle) {
		pom[k] = vec[i];
		i++;
		k++;
	}
	while (j <= end) {
		pom[k] = vec[j];
		j++;
		k++;
	}
	for (k = begin; k <= end; ++k) {
		vec[k] = pom[k];
	}
}