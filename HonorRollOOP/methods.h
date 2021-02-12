/*
*	Luke Crimi
*	methods.h
*	2/12/2021
*/

#pragma once

#include <string>
#include <vector>

class Methods {
public:
	//constructors
	Methods(void);

	//public variables for other files to access
	std::string firstName;
	std::string lastName;
	std::vector<std::string> courses;
	std::vector<int> grades;
	int numberOfCourses;
	double average;
	bool disciplinaryIssue;

	//methods for other files to use
	void getName(void);
	void getCourses(void);
	void getGrades(void);
	void hasDisciplinaryIssue(void);
	void printResults(void);

	void spacing(void); //for making the output of the program easier to read
};