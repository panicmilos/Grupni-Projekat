//============================================================================
// File Name	   : GroupOfStudents.cpp
// Authors		   : Milos Panic, Dejan Todorovic
// Created         : 29.11.2019.
// Last Modified   : 02.12.2019. By Milos Panic
// Version         : 1.0
// Description     : Ovaj klasa predstavlja kolekciju klasa StudentCourses
// i sadrzi funckije za rad nad kolekcijom kao sto su trazenje najboljih,
// prikaz studenata, prikaz sortiranih studenata, citanje i pisanje u
// fajlove, ...
//============================================================================

#include "GroupOfStudents.h"

/*
 * Podrazumevani konstruktor.
 */
GroupOfStudents::GroupOfStudents()
{
}

/*
 * Konstruktor sa parametrima.
 */
GroupOfStudents::GroupOfStudents(const std::vector<StudentCourses>& v) :
	st_vec(v)
{
}

/*
 * Konstruktor kopije.
 */
GroupOfStudents::GroupOfStudents(const GroupOfStudents& gof) :
	st_vec(gof.st_vec)
{
}

void GroupOfStudents::search_for_highest(std::vector<int>& indices_max) const
{
}

/*
 * Getter za student_courses.
 */
const std::vector<StudentCourses>& GroupOfStudents::get_student_courses() const
{
	return st_vec;
}

/*
 * Funkcija ispisuje sve studente zajedno sa njihovim ocenama na standardnom ulazu.
 * Ispis za svakog studenta je u formatu:
 * br_indexa ime prezime zavrsna_ocena znakovna_reprezentacija_ocene
*/
void GroupOfStudents::display() const
{
	std::cout << *this;
}

/*
 * Funkcija ispisuje sve studente zajedno sa njihovim ocenama na standardnom ulazu.
 * Studenti su sortirani prema alfabetnom redu i to prvo prezime, ime pa tek onda
 * broj indexa.
 * Ispis za svakog studenta je u formatu:
 * br_indexa ime prezime zavrsna_ocena znakovna_reprezentacija_ocene
*/
void GroupOfStudents::display_sorted() const
{
	const std::vector<StudentCourses> vector_copy(st_vec);

	MergeSort::merge_sort<StudentCourses>(st_vec, alphabetical_comparator);
	display();
	st_vec = vector_copy;
}

// TO DO
void GroupOfStudents::display_highest() const
{
}

/*
 * Funkcija ispisuje sve studente zajedno sa njihovim ocenama u izlazni tok.
 * Studenti su sortirani prema broju indexa
 * Ispis za svakog studenta je u formatu:
 * br_indexa ime prezime zavrsna_ocena znakovna_reprezentacija_ocene
 *
 * @param out - izlazni tok na kojem se cuvaju studenti.
*/
void GroupOfStudents::write_to_file(std::ofstream& out) const
{
	const std::vector<StudentCourses> vector_copy(st_vec);

	MergeSort::merge_sort<StudentCourses>(st_vec, id_comparator);

	out << *this;

	st_vec = vector_copy;
}

/*
 * Funkcija ispisuje sve studente zajedno sa njihovim ocenama u izlazni tok
 * u binarnom zapisu. Studenti su sortirani prema broju indexa
 * Ispis za svakog studenta je u formatu:
 * br_indexa ime prezime zavrsna_ocena znakovna_reprezentacija_ocene
 *
 * @param out - izlazni tok na kojem se cuvaju studenti.
*/
void GroupOfStudents::write_to_binary_file(std::ofstream& out) const
{
	const std::vector<StudentCourses> vector_copy(st_vec);

	MergeSort::merge_sort<StudentCourses>(st_vec, id_comparator);

	for (StudentCourses sc : st_vec)
	{
		sc.write_to_binary_file(out);
	}

	st_vec = vector_copy;
}

/*
 * Funkcija ucitava sve studente iz binarne textualne datoteke.
 * Jedan student je opisan sa redom velicine sizeof(Student) +
 * sizeof(int)*20 i smesta ih u st_vec.
 *
 * @param in - ulazni tok sa kojeg se citaju studenti.
*/
void GroupOfStudents::read_from_binary_file(std::ifstream& in) const
{
	while (!in.eof())
	{
		StudentCourses sc;

		sc.read_from_binary_file(in);

		if (in.fail())
		{
			if (in.eof())
			{
				in.clear();
			}

			break;
		}

		st_vec.push_back(sc);
	}
}

/*
 * Funkcija proverava da li u vektoru st_vec postoji student ciji je
 * broj indexa isti kao i zadatom. Ako je student pronadjen onda se
 * vraca pokazivac na njega a ako nije onda se vraca nullprt;
 *
 * @param id - broj indexa koji se trazi.
*/
StudentCourses* GroupOfStudents::find_by_id(const std::string& id) const
{
	StudentCourses* s = new StudentCourses();

	for (StudentCourses sc : st_vec)
	{
		if (sc.get_student().get_id() == id)
		{
			*s = sc;

			return s;
		}
	}

	return nullptr;
}

/*
 * Funckija ispisuje podatke o studentu sa zadatim indexom. U slucaju
 * da ne postoji student sa zadatim indexom ispisace odgovarajucu
 * poruku o tome.
 *
 * @param id - broj indexa koji se trazi.
*/
void GroupOfStudents::display_one_student(const std::string& id) const
{
	const StudentCourses* s = find_by_id(id);

	if (s != nullptr)
	{
		s->display();
		delete s;
	}
	else
	{
		std::cout << "Ne postoji student sa unetim indeksom!\n";
	}
}

/*
 * Preklapanje operatora << za ispis svih studenata na izlaze.
 * Ispis je u formatu:
 * br_indexa ime prezime zavrsna_ocena znakovna_reprezentacija_ocene
 *
 * @param out - izlaz na koji se ispisuju podaci.
 * @param gof - objekat kolekcije StudentCourses ciji se podaci ispisuju.
 *
 */
std::ostream& operator <<(std::ostream& out, const GroupOfStudents& gof)
{
	for (StudentCourses sc : gof.st_vec)
	{
		out << sc;
	}

	return out;
}

/*
 * Funckija ucitava studente i njegove bodove dokle god ih ima u datoteci
 * ili dok ne dodje do neke greske. Sve ucitane studente smesta u st_vec.
 *
 * @param in - ulazni tok sa kojeg se citaju podaci.
 * @param gof - objekat kolekcije StudentCourses u koji se upisuju podaci.
*/
std::istream& operator >>(std::istream& in, GroupOfStudents& gof)
{
	while (!in.eof())
	{
		StudentCourses sc;

		in >> sc;

		if (in.fail())
		{
			break;
		}

		gof.st_vec.push_back(sc);
	}

	return in;
}