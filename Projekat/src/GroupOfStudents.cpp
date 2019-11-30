//============================================================================
// File Name   : GroupOfStudents.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

#include "GroupOfStudents.h"

GroupOfStudents::GroupOfStudents(const std::vector< StudentCourses >& v) :
	st_vec(v)
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
	for (StudentCourses sc : st_vec)
	{
		std::cout << sc;
	}
}

void GroupOfStudents::display_sorted() const
{
}

void GroupOfStudents::display_highest() const
{
}

void GroupOfStudents::write_to_file() const
{
}