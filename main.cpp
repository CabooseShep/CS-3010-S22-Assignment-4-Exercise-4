/* Nicholas Hortua
   Prof. Edwin Rodriguez, CS 3010 - Spring 2022
   Assignment 4, Exercise 4

   main.cpp - Driver program that handles function calls
*/

#include <iostream>
#include <vector>
#include <string>
#include <random>

#include "polyInput.hpp"
#include "dataSetInput.hpp"
#include "newtonInterpolation.hpp"

using namespace std;

int main()
{
	int num_input = 0;
	double final_value = 0.0;
	vector<double> x_numbers{};
	vector<double> y_numbers{};
	vector<double> c_numbers{};
	uniform_int_distribution<int> numRange(0, 100);
	random_device randSeed;
	mt19937 numGen(randSeed());

	cout << "=== Newton's Interpolation Program - Exercise 4 == \n \n";
	cout << "Please enter the amount of data points you would like to create: ";
	cin >> num_input;

	writeToFile(num_input);

	file_Reading(x_numbers, y_numbers);
	
	newton_method(x_numbers, y_numbers, c_numbers);
	cout << "Polynomial function successfully created! \n \n";
	cout << "Now we will evaluate this polynomial at random points up to 10 times: \n \n";

	for (int i = 0; i < 10; i++)
	{
		int rand_num = numRange(numGen);
		final_value = newton_evaluation(x_numbers, c_numbers, rand_num);
		cout << "Point: x = " << rand_num << "  |  Evaluation: " << final_value << "\n \n";
	}



	return 0;

}
