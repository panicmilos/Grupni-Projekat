#include "Validations.h"

bool validate_num_of_args(int argc)
{
	return argc == 3 || argc == 4;
}

bool validate_type(std::string type)
{
	return type == "t" || type == "b";
}

bool validate_arguments(int argc, char* argv[])
{
	return validate_num_of_args(argc) && validate_type(argv[2]);
}