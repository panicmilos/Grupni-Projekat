//============================================================================
// File Name	   : StudentCourses.cpp
// Authors		   : Milos Panic, Dejan Todorovic
// Created         : 29.11.2019.
// Last Modified   : 03.12.2019. By Milos Panic
// Version         : 1.0
// Description     : Klasa StudentCourses objedinjuje studenta i njegove
// ocene. Poseduje funkcija za prikazivanje, ucitavanje i ispis klase.
//============================================================================

#include "StudentCourses.h"

/**
 * Podrazumevani konstruktor.
 */
StudentCourses::StudentCourses()
{
}

/**
 * Konstruktor sa parametrima.
 */
StudentCourses::StudentCourses(const Student& s, const Courses& c) :
	student(s), courses(c)
{
}

/**
 * Konstruktor kopije.
 */
StudentCourses::StudentCourses(const StudentCourses& sc) :
	student(sc.student), courses(sc.courses)
{
}

/**
 * Getter za student.
 */
Student StudentCourses::get_student() const
{
	return student;
}

/**
 * Getter za final_score.
 */
double StudentCourses::get_final_score() const
{
	return courses.get_final_score();
}

/**
 * Funkcija koja ispisuje informaciju o studentu i njegovoj oceni
 * na standardnom izlazu.
 */
void StudentCourses::display() const
{
	std::cout << *this;
}

/**
 * Funkcija koja upisuje podatke o studentu i podatke o njegovoj oceni
 * u binarnu datoteku.
 *
 * @param out - izlazni tok u koji se upisuje student i ocena.
*/
void StudentCourses::write_to_binary_file(std::ofstream& out) const
{
	student.write_to_binary_file(out);
	courses.write_to_binary_file(out);
}

/**
 * Funkcija koja ucitava sve podatke o studentu i njegovim ocenama
 * iz binarne datoteke.
 *
 * @param in - ulazni tok iz kojeg se cita.
*/
void StudentCourses::read_from_binary_file(std::ifstream& in)
{
	student.read_from_binary_file(in);
	courses.read_from_binary_file(in);
}

/**
 * Komparator funkcija koja poredi dva prezimena dva studenta. Ako su ima prezimena
 * ista onda poredi imena a ako su i imena ista onda poredi indexe. Koristi se kao
 * parametar Merge Sorta.
 *
 * @param sc1 - prvi student
 * @param sc2 - drugi student
 * @return true ako student 1 ima prezime sa vecim alphabetnim slovom, imenom ili indexom.
 */
bool alphabetical_comparator(const StudentCourses& sc1, const StudentCourses& sc2)
{
	const int last_name_difference = sc1.student.get_last_name().compare(sc2.student.get_last_name());

	if (last_name_difference)
	{
		return (last_name_difference > 0) ? true : false;
	}

	const int first_name_difference = sc1.student.get_first_name().compare(sc2.student.get_first_name());

	if (first_name_difference)
	{
		return (first_name_difference > 0) ? true : false;
	}

	return id_comparator(sc1, sc2);
}

/**
 * Komparator funkcija koja poredi dva indexa studenata. Koristi se kao parametar
 * Merge Sorta.
 *
 * @param sc1 - prvi student
 * @param sc2 - drugi student
 * @return true ako student 1 ima veci index od studenta 2.
 */
bool id_comparator(const StudentCourses& sc1, const StudentCourses& sc2)
{
	return (sc1.student.get_id().compare(sc2.student.get_id()) > 0) ? true : false;
}

/**
 * Komparator funkcija koja ocene za dva studenta.
 * Koristi se kao parametar Merge Sorta.
 *
 * @param sc1 - prvi student
 * @param sc2 - drugi student
 * @return true ako student 2 ima vecu ocenu od studenta 1.
 */
bool grades_comparator(const StudentCourses& sc1, const StudentCourses& sc2)
{
	return (sc1.get_final_score() - sc2.get_final_score()) < 0 ? true : false;
}

/**
 * Preklapanje operatora << za ispis na izlaze.
 * Ispis je u formatu: br_indexa ime prezime zavrsna_ocena znakovna_reprezentacija_ocene
 *
 * @param out - izlaz na koji se ispisuju podaci.
 * @param sc - objekat StudentCourses ciji se podaci pisu na izlaz tj podaci o
 * studentu i njegovim ocenama.
 */
std::ostream& operator <<(std::ostream& out, const StudentCourses& sc)
{
	return out << sc.student << " " << sc.courses << "\n";
}

/**
 * Funckija ucitava sve podatke o studentu i njegovim ocenama
 * sa ulaznog toka.
 *
 * @param in - ulazni tok sa kojeg se citaju podaci.
 * @param sc - objekat StudentCourses u koji se upisuju podaci o studentu i njegovim ocenama.
*/
std::istream& operator >>(std::istream& in, StudentCourses& sc)
{
	return in >> sc.student >> sc.courses;
}