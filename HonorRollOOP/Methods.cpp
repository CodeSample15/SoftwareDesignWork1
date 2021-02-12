/*
*	Luke Crimi
*	Methods.cpp
*	2/12/2021
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "methods.h"

//constructor class
Methods::Methods(void) 
{
	//initializing the Methods variables to make the program more stable
	Methods::firstName = "";
	Methods::lastName = "";
	Methods::average = 0;
	Methods::numberOfCourses = 0;
	Methods::disciplinaryIssue = false;
}

void Methods::spacing(void) {
	std::cout << std::endl;
	std::cout << std::endl;
}

void Methods::getName(void) 
{
	std::string name = "";
	bool goodInput = false;

	do {
		//getting user input
		std::cout << "Please enter your name: ";
		std::getline(std::cin, name);

		if (name.length() < 3) {
			//if the user entered a blank name
			std::cout << "Your entry was invalid!" << std::endl;
			continue;
		}

		//checking for a space in the name
		bool space = false;
		for (int i = 0; i < name.length() - 1; i++) {
			if (name[i] == ' ') {
				space = true;
				break;
			}
		}

		if (space) {
			//accept name and split into first and last
			Methods::firstName = name.substr(0, name.find(" "));
			Methods::lastName = name.substr(name.find(" ") + 1, name.length() - 1);
			goodInput = true;
		}
		else {
			//reject name and give an error
			std::cout << "You must enter your first and last name!" << std::endl;
		}
	} while (!goodInput);
}

void Methods::getCourses(void) 
{
	//Declaring variables
	std::string courseName = ""; //declaring a variable to hold the string name and grade
	int numCourses = 0;
	bool goodInput = false;

	//getting number of courses from the user
	do {
		std::cout << "Enter the number of courses you are taking (minimum: 1, maximum: 8): ";
		std::cin >> numCourses;

		if (!std::cin.fail()) {
			//valid integer entered
			goodInput = !(numCourses < 1 || numCourses > 8);

			if (!goodInput)
				std::cout << "Number entered was out of bounds!" << std::endl;
		}
		else {
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Invalid input!" << std::endl;
			continue;
		}
	} while (!goodInput);

	Methods::numberOfCourses = numCourses; //setting the object variable for later use

	Methods::spacing(); //to make everything easier to read

	std::cout << "Please enter course names " << std::endl;
	std::cout << "Course names will be truncated to 20 characters." << std::endl;
	std::cin.ignore(1000, '\n');

	for (int i = 0; i < numCourses; i++) {
		//getting user input
		std::cout << "Enter name of course #" << (i + 1) << ": ";
		std::getline(std::cin, courseName);

		//checking to see how long the name is
		if (courseName.length() > 20) {
			//make the course name 20 characters long
			std::cout << "Course name too long! Shortened version recorded instead." << std::endl;
			courseName = courseName.substr(0, 20);
		}

		Methods::courses.push_back(courseName);
	}
}

void Methods::getGrades(void)
{
	int MAX_GRADE = 120; //setting the max grade

	if (courses.size() > 0) {
		//print only if the user acutally entered 
		std::cout << "Please enter your grades in integer form (minimum: 0, maximum: " << MAX_GRADE << "): " << std::endl;
	}

	//loop through the number of courses and ask the user for a grade for each class
	for (int i = 0; i < courses.size(); i++) {
		//defining variables
		int input; //making the variable a string variable just in case the user tries to enter a string value instead of a number

		//looping until the user enters a valid grade number
		while (true) {
			std::cout << "Enter grade for " << courses[i] << ": ";
			std::cin >> input;

			if (!std::cin.fail()) {
				//valid integer entered

				if (input < 0 || input > MAX_GRADE) {
					//integer is out of bounds
					std::cout << "Grade entered was outside the allowed range!" << std::endl;
					continue;
				}
				else {
					//the user entered a valid input, the loop is broken
					break;
				}
			}
			else {
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cout << "Invalid input!" << std::endl;
				continue;
			}
		}

		Methods::average += input; //for calculating the average
		Methods::grades.push_back(input);
	}

	//finding the average
	Methods::average /= Methods::numberOfCourses;
}

void Methods::hasDisciplinaryIssue(void)
{
	//generating a random number between 1 and 100
	int chance = rand() % 100 + 1;

	Methods::disciplinaryIssue = chance <= 5;
}

void Methods::printResults(void)
{
	//printing formatted output
	std::cout << Methods::firstName << " " << Methods::lastName << std::endl; // printing name first

	//spacing
	std::cout << std::endl;

	printf("%-25s%-10s\n", "Class", "Grade");
	for (int i = 0; i < Methods::courses.size(); i++) {
		printf("%-25s%-10i\n", Methods::courses[i].c_str(), Methods::grades[i]);
	}

	std::cout << std::endl; //spacing to make output easier to read

	std::cout << "Average: " << round(Methods::average) << "%" << std::endl;
	std::cout << "Disciplinary Infraction: " << (Methods::disciplinaryIssue ? "Yes" : "No") << std::endl;

	//finding out if the user is qualified for the honor roll
	bool honorRoll = (!Methods::disciplinaryIssue && round(Methods::average) >= 90 && Methods::courses.size() >= 5);

	if (honorRoll)
		std::cout << "Congratulations " << Methods::firstName << " " << Methods::lastName << "! You have made the honor roll." << std::endl;
	else
		std::cout << "I'm sorry " << Methods::firstName << " " << Methods::lastName << " but you didn’t qualify for the honor roll." << std::endl;
}