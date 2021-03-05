/*
*   Luke Crimi
*   AlternateAssignment.cpp
*   3/5/2021
*   Extra thing:
*/

#include <iostream>
#include <string>
#include <math.h>
#include "functions.h"

int main()
{
    //printing the area of 1-10 radii:
    printf("%-25s%-10s\n", "Radii", "Area");
    printf("%-25s%-10s\n", "-----", "-----");

    //call printArea function for 1-10 radii
    for (int radius = 0; radius < 10; radius++) {
        printArea(radius+1);
    }

    spacing(); //for cleaning and easier to read output

    //label for the table
    printf("%-25s%-10s\n", "Radii", "Volume");
    printf("%-25s%-10s\n", "-----", "-----");

    //printing the volume of spheres with even radii from 1-10:
    for (int radius = 2; radius <= 10; radius += 2) {
        printVolume(radius);
    }

    spacing();

    //getting user input for two radii with error trapping
    bool goodInput = false;
    float input = 0; //creating an input variable outside of the loop to save memory
    float radii[2] = {0, 0}; //to store the two radii


    //getting the two radii and storing them into an array for easy user later on
    for (int i = 0; i < 2; i++) { //looping twice for two radii

        //looping until the user provides valid input that won't break the program 
        do
        {
            std::cin >> input;

            if (std::cin.fail()) {
                //the user entered a value that caused cin to fail (would normally break the program but this error trap will fix that)
                std::cin.clear();
                std::cin.ignore(256, '\n');
                std::cout << "Invalid input! Please enter a numeric value.";
                continue;
            }
            else {
                radii[i] = input;
                goodInput = true;
            }
        } while (!goodInput);
    }

    //getting the two volumes and then finding the difference
    float volumeOne = calculateVolume(radii[0]);
    float volumeTwo = calculateVolume(radii[1]);

    float difference = abs(volumeOne - volumeTwo);

    //printing the information back to the user
    spacing();

    std::cout << "Volume of first sphere: " << volumeOne << std::endl;
    std::cout << "Volume of second sphere: " << volumeTwo << std::endl;
    std::cout << "Difference between the two volumes: " << difference << std::endl;
}