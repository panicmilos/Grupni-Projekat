//============================================================================
// File Name	   : ioutils.h
// Authors		   : Milos Panic
// Created         : 01.12.2019.
// Last Modified   : 02.12.2019. By Milos Panic
// Version         : 1.0
// Description     : Ovaj moduo sadrzi sve dodatne nad funkcije ulazno/izlaznim
// tokom kao sto su otvaranje toka i pronalazenje izlazne putanje.
//============================================================================

#pragma once
#include <string>
#include "strutils.h"
#include <vector>
#include <sstream>
#include "Validations.h"

const std::string DEFAULT_OUTPUT_NAME = "default_output_name";

std::string find_output_path(const int argc, const char* argv[]);
void remove_type_extension(std::string& output_path);
std::string get_output_path(const int argc, const char* argv[]);
void parse_line_of_ints(std::istream& in, std::vector<int>& vec, const int max_size);