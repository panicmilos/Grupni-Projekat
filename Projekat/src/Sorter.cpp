//============================================================================
// File Name       : Ssorter.cpp
// Authors         : Dejan Todorovic, Milos Panic
// Created         : 01.12.2019.
// Last Modified   : 02.12.2019. By Milos Panic
// Version         : 1.0
// Description     : Klasa Sorter poseduje staticku metodu sort koja pomocu
// Merge Sort-a sortira vector elemenata po zadatom kriterijumu. Pored nje
// poseduje i metode merge koja spaja vektore u jedan nakon deljenja.
//============================================================================

#include "Sorter.h"

/**
 * Funckija koja sortira vector elemenata po zadatom kriterijmu. Algoritam je
 * Merge Sort.
 *
 * @param vec - vektor elemenata proizvoljnog tipa ciji se elementi sortiraju.
 * @param comparison_fcn - komparator funkcija koja poredi dva elementa
 * navedenog tipa po zeljenom kriterijumu.
 */
template <typename T>
void static MergeSort::merge_sort(std::vector<T>& vec, bool (*comparison_fcn)(const T&, const T&))
{
	std::vector<T> temp(vec.size());
	merge_sort_loop(vec, temp, comparison_fcn, 0, vec.size() - 1);
}

/**
 * Funkcija koja deli pocetni vektor na dva dela po sredini. Zatim ponavlja postupak
 * dokle god se ne svede na vektor velicine 1. A zatim poziva funkciju za spajanje
 * dva izdeljena vektora.
 *
 * @param vec - vektor koji se sortira i deli na dva dela.
 * @param temp - pomocni vektor koji se koristi za spajanje dva vektora.
 * @param comparison_fcn - komparator funkcija koja poredi dva elementa
 * navedenog tipa po zeljenom kriterijumu.
 * @param begin - pozicija prvog elementa u izdeljenom vektoru ili celom vektoru
 * @param end - pozicija poslednjeg elementa u izdeljenom vektoru ili celom vektoru
 *
 */
template <typename T>
void MergeSort::merge_sort_loop(std::vector<T>& vec, std::vector<T>& temp, bool (*comparison_fcn)(const T&, const T&), const int begin, const int end)
{
	if (begin < end)
	{
		const int middle = (end + begin) / 2;

		merge_sort_loop(vec, temp, comparison_fcn, begin, middle);
		merge_sort_loop(vec, temp, comparison_fcn, middle + 1, end);
		merge(vec, temp, comparison_fcn, begin, middle, end);
	}
}

/**
 * Funckija koja uzima dva dela izdeljenog vektora, i spaja ih tako da budu sortirana
 * dokle god se jedan od ta dva dela skroz ne isprazne. Zatim ostatak jednog od dva
 * vektora stavlja u temp i posle toga taj sortirani deo vraca u pocetan vektor.
 *
 * @param vec - vektor u koji se spajaju dva sortirana podvektora.
 * @param temp - pomocni vektor koji se koristi za spajanje dva vektora.
 * @param comparison_fcn - komparator funkcija koja poredi dva elementa
 * navedenog tipa po zeljenom kriterijumu.
 * @param begin - pozicija prvog elementa u izdeljenom vektoru ili celom vektoru
 * @param middle - pozicija sredisnjeg elementa u izdeljenom vektoru ili celom vektoru
 * @param end - pozicija poslednjeg elementa u izdeljenom vektoru ili celom vektoru
 *
 */
template<typename T>
void MergeSort::merge(std::vector<T>& vec, std::vector<T>& temp, bool(*comparison_fcn)(const T&, const T&), const int begin, const int middle, const int end)
{
	int i = begin;
	int j = middle + 1;
	int k = begin;

	while (i <= middle && j <= end)
	{
		temp[k++] = (comparison_fcn(vec[i], vec[j])) ? vec[j++] : vec[i++];
	}

	typename std::vector<T>::iterator it = temp.begin() + k;
	std::move(vec.begin() + i, vec.begin() + middle + 1, it);
	std::move(vec.begin() + j, vec.begin() + end + 1, it);
	std::move(temp.begin() + begin, temp.begin() + end + 1, vec.begin() + begin);
}

/*
template<typename T>
void MergeSort::merge(std::vector<T>& vec, std::vector<T>& temp, bool(*comparison_fcn)(T, T), int begin, int middle, int end)
{
	int i = begin;
	int j = middle + 1;
	int k = begin;

	while (i <= middle && j <= end) {
		temp[k++] = (comparison_fcn(vec[i], vec[j]))?vec[j++]:vec[i++];
	}
	while (i <= middle) {
		temp[k++] = vec[i++];
	}
	while (j <= end) {
		temp[k++] = vec[j++];
	}
	for (k = begin; k <= end; ++k) {
		vec[k] = temp[k];
	}
}
*/