//============================================================================
// File Name	   : StudentCourses.h
// Authors		   : Milos Panic, Dejan Todorovic
// Created         : 29.11.2019.
// Last Modified   : 02.12.2019. By Milos Panic
// Version         : 1.0
// Description     : Klasa StudentCourses objedinjuje studenta i njegove
// ocene. Poseduje funkcija za prikazivanje, ucitavanje i ispis klase.
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

	friend bool alphabetical_comparator(const StudentCourses& sc1, const StudentCourses& sc2);
	friend bool id_comparator(const StudentCourses& sc1, const StudentCourses& sc2);

	friend std::ostream& operator <<(std::ostream& out, const StudentCourses& sc);
	friend std::istream& operator >>(std::istream& in, StudentCourses& sc);
};

bool alphabetical_comparator(const StudentCourses& sc1, const StudentCourses& sc2);
bool id_comparator(const StudentCourses& sc1, const StudentCourses& sc2);

std::ostream& operator <<(std::ostream& out, const StudentCourses& sc);
std::istream& operator >>(std::istream& in, StudentCourses& sc);

#endif
