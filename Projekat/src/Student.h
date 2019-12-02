//============================================================================
// File Name   : Student.h
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
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

	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_id() const;
	void display() const;
	void write_to_binary_file(std::ofstream& out) const;
	void read_from_binary_file(std::ifstream& in) const;

	friend std::ostream& operator <<(std::ostream& out, const Student& s);
	friend std::istream& operator >>(std::istream& in, Student& s);
};

std::ostream& operator <<(std::ostream& out, const Student& s);
std::istream& operator >>(std::istream& in, Student& s);

#endif /*STUDENT_H_*/
