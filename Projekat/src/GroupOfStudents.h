//============================================================================
// File Name   : GroupOfStudents.h
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

#ifndef GROUPOFSTUDENTS_H_
#define GROUPOFSTUDENTS_H_

#include <fstream>
#include <vector>
#include "StudentCourses.h"

class GroupOfStudents
{
private:
	std::vector<StudentCourses> st_vec;
	void search_for_highest(std::vector<int>& indices_max) const; // utility

public:
	GroupOfStudents();
	GroupOfStudents(const std::vector< StudentCourses >& v);
	GroupOfStudents(const GroupOfStudents& gof);

	// add required methods
	const std::vector<StudentCourses>& get_student_courses() const;

	void display() const;
	void display_sorted() const;
	void display_highest() const;
	void write_to_file(std::ofstream& out) const;

	friend std::ostream& operator <<(std::ostream& out, const GroupOfStudents& gof);
	friend std::istream& operator >>(std::istream& in, GroupOfStudents& gof);
};

std::ostream& operator <<(std::ostream& out, const GroupOfStudents& gof);
std::istream& operator >>(std::istream& in, GroupOfStudents& gof);

#endif /*GROUPOFSTUDENTS_H_*/
