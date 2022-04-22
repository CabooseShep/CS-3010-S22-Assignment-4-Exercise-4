/* Nicholas Hortua
   Prof. Edwin Rodriguez, CS 3010 - Spring 2022
   Assignment 4, Exercise 4

   newtonInterpolation.hpp - Contains an implementation of Newton's Interporlation Method along with the function used to evaluate
   the input into the function.
*/

#ifndef NEWTON_INTERPOLATION_H
#define NEWTON_INTERPOLATION_H

#include <iostream>
#include <vector>

using std::vector;

void newton_method(vector<double>& x_val, vector<double>& y_val, vector<double>& c_val)
{

	for (int i = 0; i < y_val.size(); i++)
	{
		c_val.push_back(y_val[i]);
	}

	// now we begin to find the actual c values, by using
	// the base formula of c_i = (y_i+1 - y_i / x_i+1 - x_i)

	for (int j = 1; j < c_val.size(); j++)
	{
		for (int i = c_val.size() - 1; i > j; i--)
		{
			c_val[i] = (c_val[i] - c_val[i - 1]) / (x_val[i] - x_val[i - j]);
		}
	}
}

double newton_evaluation(vector<double>& x_val, vector<double>& c_val, int input)
{
	double result = c_val[c_val.size() - 1]; // beginning with c_0

	for (int i = c_val.size() - 1; i > 0; i--)
	{
		result = result * ((double)input - x_val[i]) + c_val[i];
	}

	return result;
}

#endif

