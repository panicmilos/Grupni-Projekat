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

using std::vector;

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
	vector<int> quiz;
	vector<int> homework;
	vector<int> test;
	double final_score;
	char letter_grade;

public:
	// constructors
	Courses() : quiz(NUM_QUIZZES), homework(NUM_HW), test(NUM_TESTS), final_score(0), letter_grade('F') {}
	Courses(const vector<int>& q, const vector<int>& h, const vector<int>& t)
		: quiz(q), homework(h), test(t), final_score(0), letter_grade('F') {}

	// utility functions
	double get_final_score() const;
	void display() const;
	void calc_final_score();
	void calc_letter_grade();
};

#endif
