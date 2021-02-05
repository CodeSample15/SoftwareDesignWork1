/*
*	Luke Crimi
*	functions.h
*	2/5/2021
*/

#pragma once
#include <string>
#include <vector>

void spacing(void); //to make cleaner output

std::vector<std::string> getName(void); //will return an array of a first and last name
std::vector<int> getGrades(void); //will return an int vector with all of the user's grades
bool hasDisciplinaryIssue(void); //has a 5% chance of giving the user a disciplinary issue and returning true
void printResults(std::string* name, std::vector<int> grades, bool disciplinaryIssue); //will print a formatted output of the user's input and will tell them if they got into honors or not
