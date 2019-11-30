//============================================================================
// File Name   : Courses.h
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

#ifndef COURSES_H_
#define COURSES_H_

#include <iostream>
#include <vector>
#include <numeric>

class Courses
{
public:
	static const int NUM_QUIZZES = 10;
	static const int NUM_HW = 6;
	static const int NUM_TESTS = 4;

private:
	// this will not compile
	// non-integral constants must be initialized in Courses.cpp
	// with these values 0.05, 0.5, 0.45
	static constexpr double QUIZ_WEIGHT = 0.05;
	static constexpr double HOMEWORK_WEIGHT = 0.5;
	static constexpr double TEST_WEIGHT = 0.45;

	// private data
	std::vector<int> quiz;
	std::vector<int> homework;
	std::vector<int> test;
	double final_score;
	char letter_grade;

	// sum of grades in vector
	int sum_grades_in_vector(std::vector<int>& grades) const;

public:
	// constructors
	Courses() : quiz(NUM_QUIZZES), homework(NUM_HW), test(NUM_TESTS), final_score(0), letter_grade('F') {}
	Courses(const std::vector<int>& q, const std::vector<int>& h, const std::vector<int>& t)
		: quiz(q), homework(h), test(t), final_score(0), letter_grade('F') {}

	// utility functions
	double get_final_score() const;
	void display() const;
	void calc_final_score();
	void calc_letter_grade();

	friend std::ostream& operator <<(std::ostream& out, const Courses& c);
};

std::ostream& operator <<(std::ostream& out, const Courses& c);

#endif
