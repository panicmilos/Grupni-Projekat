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
#include "GroupOfStudents.h"

using std::string;

class Menu
{
public:
	struct InvalidData : std::runtime_error {
		InvalidData(): runtime_error("Invalid input data format") {}
	};

	struct InvalidFile : std::runtime_error {
		InvalidFile(): runtime_error("Invalid input file name") {}
	};

	enum OPTIONS{ INFO=1, READ_FILE, DISPLAY, DISPLAY_SORTED, HIGHEST, EXIT }; 
		
private:
	GroupOfStudents gs;

public:
	Menu();

	bool is_id_valid(string id) const;
	void display_menu() const;
	void display_info() const;
	void read_students();
	void display_students() const;
	void display_students_sorted() const;
	void display_highest_score() const;
};

#endif /*MENU_H_*/
