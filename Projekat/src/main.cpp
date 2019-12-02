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
	ofstream myFile("./res/input1.bin", ios::binary);

	Student s("Dejan", "Todorovic", "sw17/2018");
	std::vector<int> v1 = { 100, 95, 92, 100, 94, 99 };
	std::vector<int> v2 = { 100, 98, 90, 95 };
	std::vector<int> v3 = { 70, 100, 88, 80, 100, 92, 96, 100, 89, 93 };

	myFile.write((char*)&s, sizeof(Student));
	myFile.write((char*)&v1[0], 6 * sizeof(int));
	myFile.write((char*)&v2[0], 4 * sizeof(int));
	myFile.write((char*)&v3[0], 10 * sizeof(int));

	Student s1("Milos", "Panic", "sw19/2018");
	std::vector<int> v1v1 = { 100, 94, 100, 95, 97, 89 };
	std::vector<int> v1v2 = { 100, 97, 100, 100 };
	std::vector<int> v1v3 = { 80, 90, 86, 82, 99, 100, 94, 84, 100, 91 };

	myFile.write((char*)&s1, sizeof(Student));
	myFile.write((char*)&v1v1[0], 6 * sizeof(int));
	myFile.write((char*)&v1v2[0], 4 * sizeof(int));
	myFile.write((char*)&v1v3[0], 10 * sizeof(int));

	Student s2("Zoran", "Jankov", "sw08/2018");
	std::vector<int>v12 = { 98, 91, 40, 95, 97, 89 };
	std::vector<int>v22 = { 64, 97, 81, 26 };
	std::vector<int>v32 = { 80, 92, 86, 85, 92, 91, 94, 85, 90, 91 };

	myFile.write((char*)&s2, sizeof(Student));
	myFile.write((char*)&v12[0], 6 * sizeof(int));
	myFile.write((char*)&v22[0], 4 * sizeof(int));
	myFile.write((char*)&v32[0], 10 * sizeof(int));

	myFile.close();

	/*std::ifstream in("./res/input1.bin", std::ios::binary);
	Student s;
	std::vector<int> quiz(10);
	std::vector<int> homework(6);
	std::vector<int> test(4);

	in.read((char*)&s, sizeof(Student));
	in.read((char*)&homework, sizeof(homework));
	in.read((char*)&test, sizeof(test));
	in.read((char*)&quiz, sizeof(quiz));
	Courses c(quiz, homework, test);
	std::cout << s << "\n" << c;
	in.close();*/

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
				m.read_students(input_path, type);
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

// Srediti dokumentaciju za out streeam