//============================================================================
// File Name   : Menu.h
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

#ifndef MENU_H_
#define MENU_H_

#include <string>
#include <stdexcept>
#include <exception>
#include "GroupOfStudents.h"
#include <fstream>

class Menu
{
public:
	struct InvalidData : std::runtime_error {
		InvalidData() : runtime_error("Invalid input data format") {}
	};

	struct InvalidFile : std::runtime_error {
		InvalidFile() : runtime_error("Invalid input file name") {}
	};

	enum OPTIONS { INFO = 1, READ_FILE, DISPLAY_STUDENT, HIGHEST, DISPLAY_SORTED, DISPLAY_ALL, WRITE_FILE, EXIT };

private:
	GroupOfStudents gs;

public:
	Menu();

	bool is_id_valid(std::string id) const;
	void display_menu() const;
	void display_info() const;
	void read_students(std::string input_path);
	void display_student() const;
	void display_students() const;
	void display_students_sorted() const;
	void display_highest_score() const;
	void write_students(std::string output_path, std::string mode);
	void write_students_to_binary_file(std::string output_path);
};

#endif /*MENU_H_*/
