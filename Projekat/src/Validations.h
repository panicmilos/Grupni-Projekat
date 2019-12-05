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

const int MAX_NUM_OF_ARGS = 4;
const int MIN_NUM_OF_ARGS = 3;

const int MAX_POINTS = 100;
const int MIN_POINTS = 0;

const std::string TEXTUAL_SYMBOL = "t";
const std::string BINARY_SYMBOL = "b";

bool validate_num_of_args(const int argc);
bool validate_type(const std::string& type);
bool validate_arguments(const int argc, const char* argv[]);
extern inline bool check_range(const int points);