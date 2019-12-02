//============================================================================
// File Name	   : strutils.cpp
// Authors		   : Milos Panic
// Created         : 01.12.2019.
// Last Modified   : 01.12.2019. By Milos Panic
// Version         : 1.0
// Description     : Ovaj moduo sadrzi sve dodatne funkcije nad stringovima.
//============================================================================
#include "strutils.h"
#include <sstream>

/*
 * Funkcija trazi poslednje pojavljivanje zadatog karaktera u zadatom stringu.
 *
 * @param str - string u kojem se trazi znak.
 * @param c - znak koji se trazi.
 * @return pozicija(index) na kojoj se poslednji put nalazi znak ili -1 ako
 * string ne sadrzi sadati znak.
 */
int find_last_char_in_string(std::string str, char c)
{
	for (int i = str.size() - 1; i >= 0; --i)
	{
		if (str[i] == c)
		{
			return i;
		}
	}

	return -1;
}

int count_words(std::string& str) {
	int count = 0;
	std::string word;
	std::istringstream s(str);
	while (s >> word) {
		count++;
	}
	return count;
}