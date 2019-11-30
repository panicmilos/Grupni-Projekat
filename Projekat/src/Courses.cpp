﻿//============================================================================
// File Name   : Courses.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

#include "Courses.h"

int Courses::sum_grades_in_vector(std::vector<int>& grades) const
{
	const auto accumulation = [](int sum, int number) { return sum + number; };

	return std::accumulate(begin(grades), end(grades), 0, accumulation);
}

double Courses::get_final_score() const
{
	return final_score;
}

void Courses::display() const
{
	std::cout << *this;
}

void Courses::calc_final_score()
{
	const double points_from_quizzes = sum_grades_in_vector(quiz) / NUM_QUIZZES * QUIZ_WEIGHT;
	const double points_from_hws = sum_grades_in_vector(homework) / NUM_HW * HOMEWORK_WEIGHT;
	const double points_from_tests = sum_grades_in_vector(test) / NUM_TESTS * TEST_WEIGHT;

	final_score = round(points_from_quizzes + points_from_hws + points_from_tests);
}

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
	else if (final_score >= 51)
	{
		letter_grade = 'E';
	}
	else
	{
		letter_grade = 'F';
	}
}

std::ostream& operator <<(std::ostream& out, const Courses& c)
{
	return out << c.final_score << " " << c.letter_grade;
}