//============================================================================
// File Name   : StudentCourses.h
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

#ifndef _STUDENTCOURSES_H_
#define _STUDENTCOURSES_H_

#include "Student.h"
#include "Courses.h"

class StudentCourses
{
	Student student;
	Courses courses;
public:

	Student get_student() const {
		// dodato samo da bi se compile
		return Student("m", "m", "M");// return student; }
	}
};

#endif
