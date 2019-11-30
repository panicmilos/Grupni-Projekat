//============================================================================
// File Name   : StudentCourses.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

#include "StudentCourses.h"

StudentCourses::StudentCourses()
{
}

StudentCourses::StudentCourses(const Student& s, const Courses& c) :
	student(s), courses(c)
{
}

StudentCourses::StudentCourses(const StudentCourses& sc) :
	student(sc.student), courses(sc.courses)
{
}

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

std::istream& operator >>(std::istream& in, StudentCourses& sc)
{
	return in >> sc.student >> sc.courses;
}