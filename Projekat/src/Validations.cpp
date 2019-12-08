//============================================================================
// File Name	   : Validations.cpp
// Authors		   : Milos Panic
// Created         : 30.11.2019.
// Last Modified   : 30.11.2019. By Milos Panic
// Version         : 1.0
// Description     : Ovaj moduo sadrzi sve potrebne funkcije za proveru
// parametara komandne linije kao sto su kolicina parametara i tip, kao i 
// proveru opsega ocena.
//============================================================================

#include "Validations.h"

/**
 * Funkcija koja proverava da li je broj parametara u granicama
 * izmedju MIN_NUM_OF_ARGS i MAX_NUM_OF_ARGS
 *
 * @param argc - broj argumenata komandne linije.
 * @return Vraca true ako se broj argumenata nalazi u zadatom
 * intervalu u suprotnom vraca false.
 */
bool validate_num_of_args(const int argc)
{
	return MIN_NUM_OF_ARGS <= argc && argc <= MAX_NUM_OF_ARGS;
}

/**
 * Funkcija koja proverava da li zadat tip datoteke odgovara
 * binarnomm textualnom ili ne.
 *
 * @param type - tip zadate datoteke sa komandne linije.
 * @return Vraca true ako se je tip binarni ili textualni a
 * u suprotnom vraca false.
 */
bool validate_type(const std::string& type)
{
	return type == TEXTUAL_SYMBOL || type == BINARY_SYMBOL;
}

/**
 * Funkcija koja u isto vreme proverava broj parametara
 * komandne linije i zadati tip.
 *
 * @param argc - broj argumenata komandne linije.
 * @param argv - vrednost argumenata komandne linije.
 * @return Vraca true ako su oba uslova ispunjena a
 * u suprotnom vraca false.
 */
bool validate_arguments(const int argc, const char* argv[])
{
	return validate_num_of_args(argc) && validate_type(argv[2]);
}

/**
 * Funkcija koja proverava da li je broj bodova u granicama
 * izmedju MIN_POINTS i MAX_POINTS
 *
 * @param points - broj bodova.
 * @return Vraca true ako se broj bodova nalazi u zadatom
 * intervalu u suprotnom vraca false.
 */
inline bool check_range(const int points)
{
	return MIN_POINTS <= points && points <= MAX_POINTS;
}