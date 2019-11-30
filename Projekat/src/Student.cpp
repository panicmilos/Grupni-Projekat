//============================================================================
// File Name   : Student.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

#include "Student.h"

Student::Student() :first_name("unknown"), last_name("unknown"), ID("unknown")
{
}

Student::Student(const std::string& fn, const std::string& ln, const std::string& id) :
	first_name(fn), last_name(ln), ID(id)
{
}

Student::Student(const Student& s) :
	first_name(s.first_name), last_name(s.last_name), ID(s.ID)
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
	std::cout << *this;
}

std::ostream& operator <<(std::ostream& out, const Student& s)
{
	return out << s.ID << " - " << s.first_name << " " << s.last_name;
}

std::istream& operator >>(std::istream& in, Student& s)
{
	return in;
}

// overload >= <= i napravi sorter kao posebnu /obicnu/ klasu koja prima vektore bilo cega i sortira ih
// koristeci overloadovane <= i >=

// configuration properties/debugging/cmd arg

// underscore notacija