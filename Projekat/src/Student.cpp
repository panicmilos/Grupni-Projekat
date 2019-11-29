//============================================================================
// File Name   : Student.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

#include "Student.h"

Student::Student(const std::string fn, const std::string ln, const std::string id)
{
}

std::string Student::get_first_name() const
{
	return firstName;
}

std::string Student::get_last_name() const
{
	return lastName;
}

std::string Student::get_id() const
{
	return ID;
}

void Student::display() const
{
	std::cout << ID << " - " << firstName << " " << lastName << "\n";
}

//komentar