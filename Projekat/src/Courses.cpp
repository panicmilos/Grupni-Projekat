//============================================================================
// File Name	   : Courses.cpp
// Authors		   : Milos Panic, Dejan Todorovic
// Created         : 29.11.2019.
// Last Modified   : 30.11.2019. By Milos Panic
// Version         : 1.0
// Description     : Klasa Courses koja cuva sve rezultate kvizova, domacih
// zadataka i testova studenta. Cuva konacnu ocenu i njenu znakovu reprezentaciju
// kao i funckije koje za racunanje istih. Poseduje funkcija za prikazivanje,
// ucitavanje i ispis klase.
//============================================================================

#include "Courses.h"
#include "ioutils.h"
#include <string>
#include <sstream>

/*
 * Podrazumevani konstruktor.
 */
Courses::Courses() :
	quiz(NUM_QUIZZES), homework(NUM_HW), test(NUM_TESTS), final_score(0), letter_grade('F')
{
}

/*
 * Konstruktor sa parametrima.
 */
Courses::Courses(const std::vector<int>& q, const std::vector<int>& h, const std::vector<int>& t)
	: quiz(q), homework(h), test(t), final_score(0), letter_grade('F')
{
	calc_final_score();
	calc_letter_grade();
}

/*
 * Konstruktor kopije.
 */
Courses::Courses(const Courses& c) :
	quiz(c.quiz), homework(c.homework), test(c.test), final_score(c.final_score), letter_grade(c.letter_grade)
{
}

/*
 * Funkcija racuna zbir svih ocena u vetoru.
 *
 * @param grades - vektor koji sadrzi ocene.
 * @return broj koji predstavlja sumu brojeva u vetoru.
 */
int Courses::sum_grades_in_vector(const std::vector<int>& grades) const
{
	const auto accumulation = [](int sum, int number) { return sum + number; };

	return std::accumulate(begin(grades), end(grades), 0, accumulation);
}

/*
 * Getter za final_score.
 */
double Courses::get_final_score() const
{
	return final_score;
}

std::vector<int> Courses::get_homework() {
	return homework;
}

std::vector<int> Courses::get_quiz() {
	return quiz;
}

std::vector<int> Courses::get_test() {
	return test;
}

/*
 * Funkcija koja ispisuje informaciju o oceni studenta na standardnom izlazu.
 */
void Courses::display() const
{
	std::cout << *this;
}

/*
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

/*
 * Funckija koja racuna znakovnu reprezentaciju konacne ocene studenta po pravilu:
 * [100, 90] = A
 * [89, 80] = B
 * [79, 70] = C
 * [69, 60] = D
 * [59, 0] = F
 * Znak smesta u promenjivu letter_grade.
 */
void Courses::calc_letter_grade()
{
	if (final_score >= 90)
	{
		letter_grade = 'A';
	}
	else if (final_score >= 80)
	{
		letter_grade = 'B';
	}
	else if (final_score >= 70)
	{
		letter_grade = 'C';
	}
	else if (final_score >= 60)
	{
		letter_grade = 'D';
	}
	else
	{
		letter_grade = 'F';
	}
}

/*
 * Preklapanje operatora << za ispis na izlaze.
 * Ispis je u formatu: zavrsna_ocena znakovna_reprezentacija_ocene
 */
std::ostream& operator <<(std::ostream& out, const Courses& c)
{
	return out << c.final_score << " " << c.letter_grade;
}

// Dodati dokumentaciju
// @throws se koristi za exceptione ako baca.
std::istream& operator >>(std::istream& in, Courses& c)
{
	parse_int_line(in, c.homework, 5);
	parse_int_line(in, c.test, 4);
	parse_int_line(in, c.quiz, 10);

	c.calc_final_score();
	c.calc_letter_grade();

	return in;
}