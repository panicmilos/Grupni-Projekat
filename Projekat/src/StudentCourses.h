//============================================================================
// File Name   : StudentCourses.h
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

#ifndef _STUDENTCOURSES_H_
#define _STUDENTCOURSES_H_

#include "Student.h"
#include "Courses.h"

class StudentCourses
{
	Student student;
	Courses courses;

public:

	Student get_student() const;
	double get_final_score() const;
	void display() const;

	friend std::ostream& operator <<(std::ostream& out, const StudentCourses& sc);
};

std::ostream& operator <<(std::ostream& out, const StudentCourses& sc);

#endif
