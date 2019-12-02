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
#include "ioutils.h"

using namespace std;

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

	do
	{
		m.display_menu();

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
		case Menu::DISPLAY_STUDENT:
			std::cout << "URADITI ZA ODREdDJENOG STUDENTA";
		case Menu::HIGHEST:
			m.display_highest_score();
			break;
		case Menu::DISPLAY_SORTED:
			m.display_students_sorted();
			break;
		case Menu::DISPLAY_ALL:
			m.display_students();
			break;
		case Menu::WRITE_FILE:
			m.write_students(output_path);
			break;
		}
	} while (option != Menu::EXIT);
	return 0;
}

// Srediti dokumentaciju za out streeam