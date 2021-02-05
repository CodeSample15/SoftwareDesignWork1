/*
*	Luke Crimi
*	Functions.cpp
*	2/5/2021
*/

#include "functions.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

void spacing(void) {
	std::cout << std::endl;
	std::cout << std::endl;
}

std::vector<std::string> getName(void) {
	//declaring variables
	std::string name = "";
	std::vector<std::string> firstLastName;
	bool goodInput = false;

	do {
		//getting user input
		std::cout << "Please enter your name: ";
		std::getline(std::cin, name);

		//checking to see if the name is too long (20 characters)
		if (name.length() > 20) {
			std::cout << "Name is too long! Must be less than 20 characters." << std::endl;
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
			firstLastName.push_back(name.substr(0, name.find(" ")));
			firstLastName.push_back(name.substr(name.find(" ")+1, name.length() - 1));
			goodInput = true;
		}
		else {
			//reject name and give an error
			std::cout << "You must enter your first and last name!" << std::endl;
		}
	} while (!goodInput);

	return firstLastName;
}
