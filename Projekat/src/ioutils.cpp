//============================================================================
// File Name	   : ioutils.cpp
// Authors		   : Milos Panic
// Created         : 01.12.2019.
// Last Modified   : 01.12.2019. By Milos Panic
// Version         : 1.0
// Description     : Ovaj moduo sadrzi sve dodatne funkcije nad ulazno/izlaznim
// tokom kao sto su otvaranje toka i pronalazenje izlazne putanje.
//============================================================================

#include <sstream>
#include "ioutils.h"
#include "Validations.h"

/*
 * Funkcija odredjuje izlaznu putanju na osnovu ulaznih parametara. Ukoliko
 * se izlazna putanja nalazi u parametrima onda vraca nju a ako ne onda
 * odredjuje izlaznu putanju na osnovu ulazne.
 *
 * @param argc - broj argumenata komandne linije.
 * @param argv - vrednost argumenata komandne linije.
 * @return izlazna putanja.
 */
std::string find_output_path(int argc, char* argv[])
{
	if (argc == 4)
	{
		return argv[3];
	}

	const int index = find_last_char_in_string(argv[1], '/');

	if (index != -1)
	{
		const std::string input_path = argv[1];

		return input_path.substr(0, index + 1) + DEFAULT_OUTPUT_NAME;
	}
	else
	{
		return DEFAULT_OUTPUT_NAME;
	}
}

void parse_int_line(std::istream& in, std::vector<int> &vec, int max_size) {
	int i = 0;
	std::string line;
	int points;
	getline(in, line);
	std::istringstream s(line);
	while (s >> points) {
		if (!check_range(points) || i >= max_size) {
			in.setstate(std::ios::failbit);
			break;
		}
		else {
			vec[i] = points;
		}
		i++;
	}
}