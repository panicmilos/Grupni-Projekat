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
	StudentCourses();
	StudentCourses(const Student& s, const Courses& c);
	StudentCourses(const StudentCourses& sc);

	Student get_student() const;
	double get_final_score() const;
	void display() const;

	friend std::ostream& operator <<(std::ostream& out, const StudentCourses& sc);
	friend std::istream& operator >>(std::istream& in, StudentCourses& sc);
};

std::ostream& operator <<(std::ostream& out, const StudentCourses& sc);
std::istream& operator >>(std::istream& in, StudentCourses& sc);

#endif
