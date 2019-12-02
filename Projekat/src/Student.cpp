//============================================================================
// File Name	   : Student.cpp
// Authors		   : Milos Panic, Dejan Todorovic
// Created         : 29.11.2019.
// Last Modified   : 30.11.2019. By Milos Panic
// Version         : 1.0
// Description     : Klasa Student predstavlja model studenta sa imenom,
// prezimenom i indexom. Poseduje funkcija za prikazivanje, ucitavanje i
// ispis klase.
//============================================================================

#include "Student.h"

/*
 * Podrazumevani konstruktor.
 */
Student::Student() :first_name("unknown"), last_name("unknown"), ID("unknown")
{
}

/*
 * Konstruktor sa parametrima.
 */
Student::Student(const std::string& fn, const std::string& ln, const std::string& id) :
	first_name(fn), last_name(ln), ID(id)
{
}

/*
 * Konstruktor kopije.
 */
Student::Student(const Student& s) :
	first_name(s.first_name), last_name(s.last_name), ID(s.ID)
{
}

/*
 * Getter za first_name.
 */
std::string Student::get_first_name() const
{
	return first_name;
}

/*
 * Getter za last_name.
 */
std::string Student::get_last_name() const
{
	return last_name;
}

/*
 * Getter za get_id.
 */
std::string Student::get_id() const
{
	return ID;
}

/*
 * Funkcija koja ispisuje informaciju o studentu na standardnom izlazu.
 */
void Student::display() const
{
	std::cout << *this;
}

/*
 * Preklapanje operatora << za ispis na izlaze.
 * Ispis je u formatu: br_indexa ime prezime
 */
std::ostream& operator <<(std::ostream& out, const Student& s)
{
	return out << s.ID << " " << s.first_name << " " << s.last_name;
}

// Dodati dokumentaciju
// @throws se koristi za exceptione ako baca.
std::istream& operator >>(std::istream& in, Student& s)
{
	std::string line_from_file;
	getline(in, line_from_file);

	if (count_words(line_from_file) != 3)
	{
		in.setstate(std::ios::failbit);
	}
	else
	{
		std::istringstream sstream(line_from_file);
		sstream >> s.first_name >> s.last_name >> s.ID;
	}

	return in;
}

// overload >= <= i napravi sorter kao posebnu /obicnu/ klasu koja prima vektore bilo cega i sortira ih
// koristeci overloadovane <= i >=

// configuration properties/debugging/cmd arg

// underscore notacija