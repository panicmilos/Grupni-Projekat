//============================================================================
// File Name	   : Student.h
// Authors		   : Milos Panic, Dejan Todorovic
// Created         : 29.11.2019.
// Last Modified   : 03.12.2019. By Dejan Todorovic
// Version         : 1.0
// Description     : Klasa Student predstavlja model studenta sa imenom,
// prezimenom i indexom. Poseduje funkcija za prikazivanje, ucitavanje i
// ispis klase.
//============================================================================

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <iostream>
#include "strutils.h"
#include <fstream>

class Student
{
private:
	std::string first_name;
	std::string last_name;
	std::string ID;

public:
	Student();
	Student(const std::string& fn, const std::string& ln, const std::string& id);
	Student(const Student& s);

	void display() const;
	void write_to_binary_file(std::ofstream& out) const;
	void read_from_binary_file(std::ifstream& in);

	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_id() const;

	friend std::ostream& operator <<(std::ostream& out, const Student& s);
	friend std::istream& operator >>(std::istream& in, Student& s);
};

std::ostream& operator <<(std::ostream& out, const Student& s);
std::istream& operator >>(std::istream& in, Student& s);

#endif /*STUDENT_H_*/
