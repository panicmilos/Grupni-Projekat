//============================================================================
// File Name   : main.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

#include <iostream>
#include "Menu.h"
#include "Validations.h"

using namespace std;

#define DEFAULT_OUTPUT_NAME "default_output_name.txt";

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
		return DEFAULT_OUTPUT_NAME
	}
}

int main(int argc, char* argv[])
{
	if (!validate_arguments(argc, argv))
	{
		std::cout << "Invalid console line arguments\n";
		return -1;
	}

	const std::string input_path = argv[1];
	const std::string type = argv[2];
	const std::string output_path = find_output_path(argc, argv);

	Menu m;
	int option;
	m.display_menu();

	do
	{
		cout << "> ";
		while (!(cin >> option) || option < 1 || option > Menu::EXIT)
		{
			if (cin.fail())	// we found something that wasn’t an integer
			{
				cin.clear();	// we’d like to look at the characters
				char ch;
				while (cin >> ch && !isdigit(ch))
				{
					cerr << "Invalid input; please try again" << "\n";
					cout << "> ";
				}
				cin.unget();
			}
			else
			{	// option < 1 || option > Menu::EXIT */
				cerr << "Invalid input; please try again" << "\n";
				cout << "> ";
			}
		}

		switch (option)
		{
		case Menu::INFO:
			m.display_info();
			break;
		case Menu::READ_FILE:
			try
			{
				m.read_students(input_path);
			}
			catch (const Menu::InvalidFile & excp)
			{
				cerr << excp.what() << "\n";
			}
			catch (const Menu::InvalidData & excp)
			{
				cerr << excp.what() << "\n";
			}
			break;
		case Menu::DISPLAY:
			m.display_students();
			break;
		case Menu::DISPLAY_SORTED:
			m.display_students_sorted();
			break;
		case Menu::HIGHEST:
			m.display_highest_score();
			break;
		}
		m.display_menu();
	} while (option != Menu::EXIT);
	return 0;
}

//proslediti pathove kroz funkcije i otp uraditi citanje.