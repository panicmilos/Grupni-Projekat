//============================================================================
// File Name	   : Menu.h
// Authors		   : Milos Panic
// Created         : 01.12.2019.
// Last Modified   : 02.12.2019. By Milos Panic
// Version         : 1.0
// Description     : Ovaj moduo sadrzi sve dodatne funkcije menija koji omogucava
// interakciju sa korisnikom kao i dva korisnicka izuzetka za pogresno ime datoteke
// i pogresan sadrzaj.
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
	Menu(const GroupOfStudents& gos);
	Menu(const Menu& m);

	void display_menu() const;
	void display_info() const;
	void read_students(const std::string& input_path, const std::string& type);
	void read_students_from_txt(const std::string& input_path);
	void read_students_from_binary(const std::string& input_path);
	void display_student() const;
	void display_students() const;
	void display_students_sorted() const;
	void display_highest_score() const;
	void write_students(const std::string& output_path, const std::string& type);
	void write_students_to_binary_file(const std::string& output_path);
};

#endif /*MENU_H_*/
