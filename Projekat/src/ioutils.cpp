//============================================================================
// File Name	   : ioutils.cpp
// Authors		   : Milos Panic
// Created         : 01.12.2019.
// Last Modified   : 02.12.2019. By Milos Panic
// Version         : 1.0
// Description     : Ovaj moduo sadrzi sve dodatne funkcije nad ulazno/izlaznim
// tokom kao sto su otvaranje toka i pronalazenje izlazne putanje.
//============================================================================

#include "ioutils.h"

/**
 * Funkcija odredjuje izlaznu putanju na osnovu ulaznih parametara. Ukoliko
 * se izlazna putanja nalazi u parametrima onda vraca nju a ako ne onda
 * odredjuje izlaznu putanju na osnovu ulazne.
 *
 * @param argc - broj argumenata komandne linije.
 * @param argv - vrednost argumenata komandne linije.
 * @return izlazna putanja.
 */
std::string find_output_path(const int argc, const char* argv[])
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

/**
 * Funkcija prima izlaznu putanju i sa nje brise .extenziju kako bi
 * mogla da se koristi i sa .bin i sa .txt prilikom cuvanja podataka.
 *
 * @param output_path - putanja sa koje se skida extenzija.
*/
void remove_type_extension(std::string& output_path)
{
	const int index = find_last_char_in_string(output_path, '.');

	if (index != -1)
	{
		output_path = output_path.substr(0, index);
	}
}

/**
 * Funkcija odredjuje izlaznu putanju na osnovu ulaznih parametara.
 * Nakon sto odredi putanju brise extenziju sa imena datoteke.
 *
 * @param argc - broj argumenata komandne linije.
 * @param argv - vrednost argumenata komandne linije.
 * @return izlazna putanja sa imenom bez extenzije.
*/
std::string get_output_path(const int argc, const char* argv[])
{
	std::string outputh_path = find_output_path(argc, argv);
	remove_type_extension(outputh_path);

	return outputh_path;
}

/**
* Funckija prima ulazni tok, vektor i najveci broj koji moze da stane u vektor.
* Funkcija ucitava liniju brojeva iz ulaznog toga a zatim je parsira i smesta u
* vektor. U slicaju da se na liniji ne nalaze samo brojevi, da ih ima vise
* nego sto bi smelo ili da se ne nalaze u zadatom opsegu na ulazni tok se postavlja
* failbit.
*
* @param in - ulazni tok sa kojeg se cita linija.
* @param vec - vektor u koji se smestaju brojevi.
* @param max_size - najveci broj elemenata koje vektor prima.
*/
void parse_line_of_ints(std::istream& in, std::vector<int>& vec, const int max_size)
{
	int i = 0;
	int points;

	std::string line;
	getline(in, line);
	std::istringstream sstream(line);

	std::string temp;
	while (!sstream.eof())
	{
		sstream >> points;

		if (sstream.fail() || !check_range(points) || i >= max_size)
		{
			in.setstate(std::ios_base::failbit);
			break;
		}

		vec[i++] = points;
	}
}