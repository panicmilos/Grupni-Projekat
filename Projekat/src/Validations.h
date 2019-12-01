//============================================================================
// File Name	   : Validations.h
// Authors		   : Milos Panic
// Created         : 30.11.2019.
// Last Modified   : 30.11.2019. By Milos Panic
// Version         : 1.0
// Description     : Ovaj moduo sadrzi sve potrebne funkcije za proveru
// parametara komandne linije kao sto su kolicina parametara i tip.
//============================================================================

#pragma once
#include <string>

#define MAX_NUM_OF_ARGS 4
#define MIN_NUM_OF_ARGS 3

#define TEXTUAL_SYMBOL "t"
#define BINARY_SYMBOL "b"

bool validate_num_of_args(int argc);
bool validate_type(std::string type);
bool validate_arguments(int argc, char* argv[]);