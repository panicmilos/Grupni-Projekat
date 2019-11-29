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

using std::string;

class Student
{
private:
	// add required members

public:
	// add required constructors

	string get_first_name() const;
	string get_last_name() const;
	string get_id() const;
	void display() const;
};

#endif /*STUDENT_H_*/
