//============================================================================
// File Name   : StudentCourses.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

#include "StudentCourses.h"

Student StudentCourses::get_student() const
{
	return student;
}

double StudentCourses::get_final_score() const
{
	return courses.get_final_score();
}

void StudentCourses::display() const
{
	std::cout << *this;
}

std::ostream& operator <<(std::ostream& out, const StudentCourses& sc)
{
	return out << sc.student << sc.courses;
}