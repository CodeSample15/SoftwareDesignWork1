// SoftwareDesign2.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

void one(void) 
{
    cout << "Enter your name for GMAIL: ";
    string name;
    cin >> name;
    name = name + "@gmail.com";

    cout << name;
}

void two(void) 
{
    string person = "Charlie Brown"; 
}

int main()
{
    one();
}