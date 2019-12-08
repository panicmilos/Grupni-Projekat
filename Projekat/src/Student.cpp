//============================================================================
// File Name	   : Student.cpp
// Authors		   : Milos Panic, Dejan Todorovic
// Created         : 29.11.2019.
// Last Modified   : 03.12.2019. By Milos Panic
// Version         : 1.0
// Description     : Klasa Student predstavlja model studenta sa imenom,
// prezimenom i indexom. Poseduje funkcija za prikazivanje, ucitavanje i
// ispis klase.
//============================================================================

#include "Student.h"

/**
 * Podrazumevani konstruktor.
 */
Student::Student() :first_name("unknown"), last_name("unknown"), ID("unknown")
{
}

/**
 * Konstruktor sa parametrima.
 */
Student::Student(const std::string& fn, const std::string& ln, const std::string& id) :
	first_name(fn), last_name(ln), ID(id)
{
}

/**
 * Konstruktor kopije.
 */
Student::Student(const Student& s) :
	first_name(s.first_name), last_name(s.last_name), ID(s.ID)
{
}

/**
 * Getter za first_name.
 */
std::string Student::get_first_name() const
{
	return first_name;
}

/**
 * Getter za last_name.
 */
std::string Student::get_last_name() const
{
	return last_name;
}

/**
 * Getter za ID.
 */
std::string Student::get_id() const
{
	return ID;
}

/**
 * Funkcija koja ispisuje informaciju o studentu na standardnom izlazu.
 */
void Student::display() const
{
	std::cout << *this;
}

/**
 * Funkcija koja ispisuje broj indexa, ime i prezime studenta u binarnu datoteku.
 *
 * @param out - izlazni tok u koji se upisuje ocena i znak.
*/
void Student::write_to_binary_file(std::ofstream& out) const
{
	const std::string student_str = first_name + " " + last_name + " " + ID;
	const int length = student_str.length();

	out.write((char*)&length, sizeof(int));
	out.write(student_str.c_str(), length);
}

/**
 * Funkcija koja ucitava objekat studenta iz binarne datoteke to jest
 * broj indexa, ime i prezime studenta.
 *
 * @param in - ulazni tok iz kojeg se cita.
*/
void Student::read_from_binary_file(std::ifstream& in)
{
	int length;
	in.read((char*)&length, sizeof(int));

	std::string line_from_file;
	line_from_file.resize(length);
	in.read(&line_from_file[0], length);

	if (count_words(line_from_file) != 3)
	{
		in.setstate(std::ios::failbit);
	}
	else
	{
		std::istringstream sstream(line_from_file);
		sstream >> first_name >> last_name >> ID;
	}
}

/**
 * Preklapanje operatora << za ispis na izlaze.
 * Ispis je u formatu: br_indexa ime prezime
 *
 * @param out - izlaz na koji se ispisuju podaci.
 * @param s - objekat studenta ciji se podaci pisu na izlaz.
 */
std::ostream& operator <<(std::ostream& out, const Student& s)
{
	return out << s.ID << " " << s.first_name << " " << s.last_name;
}

/**
* Funckija ucitava liniju koja sadrze ime, prezime i broj indexa
* studenta sa ulaznog toka. U slucaju da je broj reci na liniji
* razlicit od 3 bice setovan failbit.
*
* @param in - ulazni tok sa kojeg se citaju podaci.
* @param s - objekat studenta u koji se upisuju podaci.
*/
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
