/* Nicholas Hortua
   Prof. Edwin Rodriguez, CS 3010 - Spring 2022
   Assignment 4, Exercise 4

   dataSetInput.hpp - Contains the functions responsible for creating and opening the text file to be used for the data sets, as well
   generating the numbers to be inputted.
*/

#ifndef DATA_SET_INPUT_H
#define DATA_SET_INPUT_H

#include <iostream>
#include <random>
#include <fstream>

using std::ofstream;
using std::random_device;
using std::mt19937;
using std::uniform_real_distribution;

// we use the random functions from the C++11 library in order to generate
// truly random numbers vs using srand for pseudorandom

random_device randSeed;
mt19937 numGen(randSeed());

double genRandNumber(uniform_real_distribution<double>& range);

void writeToFile(int size)
{
	ofstream dataFile("polydata.lin");
	uniform_real_distribution<double> numRange(0.0, 10.0);

	// the nested loop is used to write the values in the form: x0  x1  x2  ...  xn
	//														    y0  y1  y2  ...  yn

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < size; j++)
		{
			double curr_num = genRandNumber(numRange);
			dataFile << curr_num << " ";
		}

		dataFile << "\n";
	}

	dataFile.close();
}

double genRandNumber(uniform_real_distribution<double>& range)
{
	double rand_num = range(numGen);
	return rand_num;
}

#endif