//============================================================================
// File Name	   : main.cpp
// Authors		   : Milos Panic, Dejan Todorovic
// Created         : 01.12.2019.
// Last Modified   : 03.12.2019. By Milos Panic
// Version         : 1.0
// Description     : Main proverava argumente komandne linije i nakon toga
// instancira objekat menija gde je omogucena interakcija sa korisnikom.
//============================================================================

#include <iostream>
#include "Menu.h"
#include "Validations.h"
#include "ioutils.h"

using namespace std;

int main(const int argc, const char* argv[])
{
	if (!validate_arguments(argc, argv))
	{
		std::cout << "Invalid console line arguments\n";
		return -1;
	}

	const std::string input_path = argv[1];
	const std::string type = argv[2];
	const std::string output_path = get_output_path(argc, argv);

	Menu m;
	int option;
	bool students_inputed = false;

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

		if (!students_inputed && option != Menu::INFO && option != Menu::READ_FILE)
		{
			std::cout << "Prvo morate ucitati studente.\n";
			continue;
		}

		switch (option)
		{
		case Menu::INFO:
			m.display_info();
			break;
		case Menu::READ_FILE:
			try
			{
				m.read_students(input_path, type);
				students_inputed = true;
			}
			catch (const Menu::InvalidFile & excp)
			{
				cerr << excp.what() << "\n";
			}
			catch (const Menu::InvalidData & excp)
			{
				cerr << excp.what() << "\n";
			}
			catch (const std::exception & e)
			{
				cerr << e.what() << "\n";
			}
			break;
		case Menu::DISPLAY_STUDENT:
			m.display_student();
			break;
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
			m.write_students(output_path, type);
			break;
		}
	} while (option != Menu::EXIT);
	return 0;
}

// najbolji
// zastota da ne moze dva ptua da ce ucita