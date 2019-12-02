//============================================================================
// File Name	   : ioutils.h
// Authors		   : Milos Panic
// Created         : 01.12.2019.
// Last Modified   : 01.12.2019. By Milos Panic
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

#define DEFAULT_OUTPUT_NAME "default_output_name.txt";

std::string find_output_path(int argc, char* argv[]);
void parse_int_line(std::istream& in, std::vector<int>& vec, int max_size);