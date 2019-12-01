//============================================================================
// File Name   : GroupOfStudents.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

#include "GroupOfStudents.h"

GroupOfStudents::GroupOfStudents()
{
}

GroupOfStudents::GroupOfStudents(const std::vector< StudentCourses >& v) :
	st_vec(v)
{
}

GroupOfStudents::GroupOfStudents(const GroupOfStudents& gof) :
	st_vec(gof.st_vec)
{
}

void GroupOfStudents::search_for_highest(std::vector<int>& indices_max) const
{
}

const std::vector<StudentCourses>& GroupOfStudents::get_student_courses() const
{
	return st_vec;
}

void GroupOfStudents::display() const
{
	std::cout << *this;
}

void GroupOfStudents::display_sorted() const
{
}

void GroupOfStudents::display_highest() const
{
}

void GroupOfStudents::write_to_file(std::ofstream& out) const
{
	// sortitaj po indexu.
	// vector stavi u neki temp a sortirano ovde
	out << *this;
}

std::ostream& operator <<(std::ostream& out, const GroupOfStudents& gof)
{
	for (StudentCourses sc : gof.st_vec)
	{
		out << sc << "\n";
	}

	return out;
}

std::istream& operator >>(std::istream& in, GroupOfStudents& gof)
{
	while (!in.eof())
	{
		StudentCourses sc;
		in >> sc;
		gof.st_vec.push_back(sc);
	}

	return in;
}