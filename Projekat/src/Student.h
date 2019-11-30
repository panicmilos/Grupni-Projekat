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

class Student
{
private:
	std::string first_name;
	std::string last_name;
	std::string ID;

public:
	Student(const std::string& fn, const std::string& ln, const std::string& id);

	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_id() const;
	void display() const;

	friend std::ostream& operator <<(std::ostream& out, const Student& s);
};

std::ostream& operator <<(std::ostream& out, const Student& s);

#endif /*STUDENT_H_*/
