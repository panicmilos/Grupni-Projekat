//============================================================================
// File Name	   : GroupOfStudents.h
// Authors		   : Milos Panic, Dejan Todorovic
// Created         : 29.11.2019.
// Last Modified   : 02.12.2019. By Milos Panic
// Version         : 1.0
// Description     : Ovaj klasa predstavlja kolekciju klasa StudentCourses
// i sadrzi funckije za rad nad kolekcijom kao sto su trazenje najboljih,
// prikaz studenata, prikaz sortiranih studenata, citanje i pisanje u
// fajlove, ...
//============================================================================

#ifndef GROUPOFSTUDENTS_H_
#define GROUPOFSTUDENTS_H_

#include <fstream>
#include <vector>
#include "StudentCourses.h"
#include "Sorter.h"
#include "Sorter.cpp"
#include <set>

class GroupOfStudents
{
private:
	mutable std::vector<StudentCourses> st_vec;
	StudentCourses* find_by_id(const std::string& id) const;

public:
	GroupOfStudents();
	GroupOfStudents(const std::vector<StudentCourses>& v);
	GroupOfStudents(const GroupOfStudents& gof);

	bool check_for_duplicates() const;
	void display_one_student(const std::string& id) const;
	void display() const;
	void display_sorted() const;
	void display_highest() const;
	void write_to_file(std::ofstream& out) const;
	void write_to_binary_file(std::ofstream& out) const;
	void read_from_binary_file(std::ifstream& in) const;

	const std::vector<StudentCourses>& get_student_courses() const;

	friend std::ostream& operator <<(std::ostream& out, const GroupOfStudents& gof);
	friend std::istream& operator >>(std::istream& in, GroupOfStudents& gof);
};

std::ostream& operator <<(std::ostream& out, const GroupOfStudents& gof);
std::istream& operator >>(std::istream& in, GroupOfStudents& gof);

#endif /*GROUPOFSTUDENTS_H_*/
