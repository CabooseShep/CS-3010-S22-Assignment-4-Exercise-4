/* Nicholas Hortua
   Prof. Edwin Rodriguez, CS 3010 - Spring 2022
   Assignment 4, Exercise 3

   polyInput.hpp - Handles the file processing the program requires in order to read in a polynomial from the attached file
   *Modified version of the file input handling code I used for Assignment 3 
*/

#ifndef POLYINPUT_H
#define POLYINPUT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <errno.h>

using std::cout;
using std::cerr;
using std::string;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::vector;

void file_Reading(vector<double>& x_values, vector<double>& y_values)
{
	double value = 0;
	int line_count = 0;
	ifstream my_File;

	my_File.open("polydata.lin");

	string line;

	// the istringstream object reads the values until it reaches '\0', line_count is incremented 
	// by 1 which is used as a trick to push the values of the next line into y values vector.

	if (my_File)
	{
		while (getline(my_File, line))
		{
			istringstream fp(line); 

			while (fp >> value) 
			{
				if (line_count == 1)
				{
					y_values.push_back(value);
				}

				else 
				{
					x_values.push_back(value);
				}
			}

			line_count++;
		}
	}

	// minor error message

	else
	{
		cerr << "Error: File could not be processed correctly! \n";
	}

	my_File.close();
}

#endif