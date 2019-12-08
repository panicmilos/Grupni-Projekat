//============================================================================
// File Name	   : Courses.h
// Authors		   : Milos Panic, Dejan Todorovic
// Created         : 29.11.2019.
// Last Modified   : 02.12.2019. By Milos Panic
// Version         : 1.0
// Description     : Klasa Courses koja cuva sve rezultate kvizova, domacih
// zadataka i testova studenta. Cuva konacnu ocenu i njenu znakovu reprezentaciju
// kao i funckije za racunanje istih. Poseduje funkciju za prikazivanje,
// ucitavanje i ispis klase.
//============================================================================

#ifndef COURSES_H_
#define COURSES_H_

#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include "ioutils.h"
#include <string>
#include <sstream>
#include <fstream>

class Courses
{
public:
	static const int NUM_QUIZZES = 10;
	static const int NUM_HW = 6;
	static const int NUM_TESTS = 4;

private:
	static constexpr double QUIZ_WEIGHT = 0.05;
	static constexpr double HOMEWORK_WEIGHT = 0.5;
	static constexpr double TEST_WEIGHT = 0.45;

	std::vector<int> quiz;
	std::vector<int> homework;
	std::vector<int> test;
	double final_score;
	char letter_grade;

	int sum_grades_in_vector(const std::vector<int>& grades) const;
	bool check_grades() const;

public:
	Courses();
	Courses(const std::vector<int>& q, const std::vector<int>& h, const std::vector<int>& t);
	Courses(const Courses& c);

	void do_calculations();
	void calc_final_score();
	void calc_letter_grade();
	void display() const;
	void write_to_binary_file(std::ofstream& out) const;
	void read_from_binary_file(std::ifstream& in);

	double get_final_score() const;
	std::vector<int> get_quiz() const;
	std::vector<int> get_homework() const;
	std::vector<int> get_test() const;

	friend std::ostream& operator <<(std::ostream& out, const Courses& c);
	friend std::istream& operator >>(std::istream& in, Courses& c);
};

std::ostream& operator <<(std::ostream& out, const Courses& c);
std::istream& operator >>(std::istream& in, Courses& c);

#endif
