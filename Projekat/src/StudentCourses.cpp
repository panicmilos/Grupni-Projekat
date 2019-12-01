//============================================================================
// File Name	   : StudentCourses.cpp
// Authors		   : Milos Panic, Dejan Todorovic
// Created         : 29.11.2019.
// Last Modified   : 30.11.2019. By Milos Panic
// Version         : 1.0
// Description     : Klasa StudentCourses objedinjuje studenta i njegove
// ocene. Poseduje funkcija za prikazivanje, ucitavanje i ispis klase.
//============================================================================

#include "StudentCourses.h"

/*
 * Podrazumevani konstruktor.
 */
StudentCourses::StudentCourses()
{
}

/*
 * Konstruktor sa parametrima.
 */
StudentCourses::StudentCourses(const Student& s, const Courses& c) :
	student(s), courses(c)
{
}

/*
 * Konstruktor kopije.
 */
StudentCourses::StudentCourses(const StudentCourses& sc) :
	student(sc.student), courses(sc.courses)
{
}

/*
 * Getter za student.
 */
Student StudentCourses::get_student() const
{
	return student;
}

/*
 * Getter za final_score.
 */
double StudentCourses::get_final_score() const
{
	return courses.get_final_score();
}

/*
 * Funkcija koja ispisuje informaciju o studentu i njegovoj oceni
 * na standardnom izlazu.
 */
void StudentCourses::display() const
{
	std::cout << *this;
}

/*
 * Preklapanje operatora << za ispis na izlaze.
 * Ispis je u formatu: br_indexa ime prezime zavrsna_ocena znakovna_reprezentacija_ocene
 */
std::ostream& operator <<(std::ostream& out, const StudentCourses& sc)
{
	return out << sc.student << " " << sc.courses;
}

// Dodati dokumentaciju
// @throws se koristi za exceptione ako baca.
std::istream& operator >>(std::istream& in, StudentCourses& sc)
{
	return in >> sc.student >> sc.courses;
}