//============================================================================
// File Name	   : Courses.cpp
// Authors		   : Milos Panic, Dejan Todorovic
// Created         : 29.11.2019.
// Last Modified   : 08.12.2019. By Dejan Todorovic
// Version         : 1.0
// Description     : Klasa Courses koja cuva sve rezultate kvizova, domacih
// zadataka i testova studenta. Cuva konacnu ocenu i njenu znakovu reprezentaciju
// kao i funckije za racunanje istih. Poseduje funkcije za prikazivanje,
// ucitavanje i ispis klase.
//============================================================================

#include "Courses.h"
#include <iomanip>

/**
 * Podrazumevani konstruktor.
 */
Courses::Courses() :
	quiz(NUM_QUIZZES), homework(NUM_HW), test(NUM_TESTS), final_score(0), letter_grade('F')
{
}

/**
 * Konstruktor sa parametrima.
 */
Courses::Courses(const std::vector<int>& q, const std::vector<int>& h, const std::vector<int>& t)
	: quiz(q), homework(h), test(t), final_score(0), letter_grade('F')
{
	do_calculations();
}

/**
 * Konstruktor kopije.
 */
Courses::Courses(const Courses& c) :
	quiz(c.quiz), homework(c.homework), test(c.test), final_score(c.final_score), letter_grade(c.letter_grade)
{
}

/**
 * Funkcija racuna zbir svih ocena u vektoru.
 *
 * @param grades - vektor koji sadrzi ocene.
 * @return broj koji predstavlja sumu brojeva u vetoru.
 */
int Courses::sum_grades_in_vector(const std::vector<int>& grades) const
{
	const auto accumulation = [](int sum, int number) { return sum + number; };

	return std::accumulate(begin(grades), end(grades), 0, accumulation);
}

/**
 * Funkcija koja proverava da li svi brojevi bodova iz kolekcija testova,
 * domacih zadataka i kvizova odgovaraju uslovu koji postavlja funkcija
 * check_range iz Validations.h.
 *
 * @return - true ako svi brojevi zadovoljavaju uslov inace false;
*/
bool Courses::check_grades() const
{
	const auto in_range = [](int x) { return check_range(x); };

	bool check_flag = std::all_of(homework.begin(), homework.end(), in_range);
	check_flag &= std::all_of(test.begin(), test.end(), in_range);
	check_flag &= std::all_of(quiz.begin(), quiz.end(), in_range);

	return check_flag;
}

/**
 * Getter za final_score.
 */
double Courses::get_final_score() const
{
	return final_score;
}

/**
 * Getter za homework.
 */
std::vector<int> Courses::get_homework() const
{
	return homework;
}

/**
 * Getter za quiz.
 */
std::vector<int> Courses::get_quiz() const
{
	return quiz;
}

/**
 * Getter za test.
 */
std::vector<int> Courses::get_test() const
{
	return test;
}

/**
 * Funkcija koja ispisuje informaciju o oceni studenta na standardnom izlazu.
 */
void Courses::display() const
{
	std::cout << *this;
}

/**
 * Funkcija koja ispisuje ocenu studenta i njegovu znakovnu reprezentaciju
 * u binarnu datoteku.
 *
 * @param out - izlazni tok u koji se upisuje ocena i znak.
*/
void Courses::write_to_binary_file(std::ofstream& out) const
{
	out.write((char*)&final_score, sizeof(double));
	out.write((char*)&letter_grade, sizeof(char));
}

/**
 * Funkcija koja ucitava kolekcije brojeva bodova iz domacih, testova i
 * kvizova iz binarne datoteke. Takodje racuna zavrsnu ocenu i znakovnu
 * reprezentaciju znaka na osnovu bodova.
 *
 * @param in - ulazni tok iz kojeg se cita.
*/
void Courses::read_from_binary_file(std::ifstream& in)
{
	in.read((char*)&homework[0], Courses::NUM_HW * sizeof(int));
	in.read((char*)&test[0], Courses::NUM_TESTS * sizeof(int));
	in.read((char*)&quiz[0], Courses::NUM_QUIZZES * sizeof(int));

	do_calculations();

	if (!check_grades())
	{
		in.setstate(std::ios::failbit);
	}
}

/**
 * Funkcija koja racuna zavrsnu ocenu studenta na osnovu njegovih rezultata
 * sa kvizova, testova i domacih zadataka i smesta u promenjivu final_score.
 * U slucaju da zavrsna ocena nije ceo broj zaokruzuje se na prvu celu vrednost.
 */
void Courses::calc_final_score()
{
	const double points_from_quizzes = sum_grades_in_vector(quiz) * QUIZ_WEIGHT / NUM_QUIZZES;
	const double points_from_hws = sum_grades_in_vector(homework) * HOMEWORK_WEIGHT / NUM_HW;
	const double points_from_tests = sum_grades_in_vector(test) * TEST_WEIGHT / NUM_TESTS;

	final_score = round(points_from_quizzes + points_from_hws + points_from_tests);
}

/**
 * Funckija koja racuna znakovnu reprezentaciju konacne ocene studenta po pravilu:
 * [100, 91] = A
 * [90, 81] = B
 * [80, 71] = C
 * [70, 61] = D
 * [60, 0] = F
 * Znak smesta u promenjivu letter_grade.
 */
void Courses::calc_letter_grade()
{
	if (final_score >= 91)
	{
		letter_grade = 'A';
	}
	else if (final_score >= 81)
	{
		letter_grade = 'B';
	}
	else if (final_score >= 71)
	{
		letter_grade = 'C';
	}
	else if (final_score >= 61)
	{
		letter_grade = 'D';
	}
	else
	{
		letter_grade = 'F';
	}
}

/**
 * Funckija koja izvrsava sve bitne kalkulacije za ocenu.
*/
void Courses::do_calculations()
{
	calc_final_score();
	calc_letter_grade();
}

/**
 * Preklapanje operatora << za ispis na izlaze.
 * Ispis je u formatu: zavrsna_ocena znakovna_reprezentacija_ocene
 *
 * @param out - izlaz na koji se ispisuju podaci.
 * @param c - objekat kursa ciji se podaci pisu na izlaz.
 */
std::ostream& operator <<(std::ostream& out, const Courses& c)
{
	return out << c.final_score << " " << c.letter_grade;
}

/**
 * Funckija ucitava tri linije koje sadrze razlicit broj bodova
 * sa ulaznog toka. U slucaju da je broj bodova neipsravan bice
 * setovan failbit. Nakon toga racuna zavrsnu ocenu i znakovnu
 * reprezentaciju.
 *
 * @param in - ulazni tok sa kojeg se citaju podaci.
 * @param c - objekat kurska u koji se upisuju podaci.
*/
std::istream& operator >>(std::istream& in, Courses& c)
{
	parse_line_of_ints(in, c.homework, Courses::NUM_HW);
	parse_line_of_ints(in, c.test, Courses::NUM_TESTS);
	parse_line_of_ints(in, c.quiz, Courses::NUM_QUIZZES);

	c.do_calculations();

	return in;
}