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
	return first_name;
}

std::string Student::get_last_name() const
{
	return last_name;
}

std::string Student::get_id() const
{
	return ID;
}

void Student::display() const
{
	std::cout << ID << " - " << first_name << " " << last_name << "\n";
}

// overload >= <= i napravi sorter kao posebnu /obicnu/ klasu koja prima vektore bilo cega i sortira ih
// koristeci overloadovane <= i >=

//komentar
//neki_test_primer
//komentar
//komentar2

// configuration properties/debugging/cmd arg

// underscore notacija