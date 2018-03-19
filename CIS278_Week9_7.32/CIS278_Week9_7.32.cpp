/*************************************************************************
* Title: Find the Minimum Value in an Array
* File: CIS278_Week9_7.32.cpp
* Author: James Eli
* Date: 2/6/2018
*
* Exercise 7.32 on page 336, Find the Minimum Value in an Array
* Write a recursive function recuriveMinimum that takes an integer array, 
* a starting subscript and ending subscript as arguments and returns the 
* smallest element of the array. The function should stop processing and 
* return when the starting subscript equals the ending subscript.
*
* Notes:
*  (1) Compiled with MS Visual Studio 2017 Community (v141).
*
* Submitted in partial fulfillment of the requirements of PCC CIS-278.
*************************************************************************
* Change Log:
*   01/17/2018: Initial release. JME
*   03/10/2018: Add bounds checking. JME
*************************************************************************/
#include <iostream>  // cout/endl
#include <algorithm> // min
#include <array>
#include <vector>
#include <cassert>

#include "rMin.h"

using namespace std;

int main()
{
	// Test recursive function with int, chars, double array & vector.
	try
	{
		{
			// Test integers.
			int a[]{ 10, 8, 8, 5, -2, 0, 10, 4, 3, 1 };
			assert(rMin(a, 0, 9) == -2);
			assert(rMin(a, 9, 9) == 1);
			assert(rMin(a, 0, 0) == 10);
			assert(rMin(a, 5, 9) == 0);
		}

		{
			// Test characters.
			char a[]{ 'a', '?', 'a', 'A', 'z', '1', '!' };
			assert(rMin(a, 0, 6) == '!');
		}

		{
			// Test floating point.
			double a[]{ 10., 8.1, 0.8, 5.25, 10., 0, -2. };
			assert(rMin(a, 0, 6) == -2.);
		}

		{
			// Test integer array pointer.
			int *a{ new int[6]{ 10, 8, 8, 5, -2, 0 } };
			assert(rMin(a, 0, 5) == -2);
			delete[] a;
		}

		{
			array<int, 10> arr1{ 10, 8, 8, 5, -2, 0, 10, 4, 3, 1 };
			array<double, 7> arr2{ 10., 8.1, 0.8, 5.25, 10., 0, -2. };
			vector<int> vec1{ 10, 8, 8, 5, -2, 0, 10, 4, 3, 1 };
			vector<double> vec2{ 10., 8.1, 0.8, 5.25, 10., 0, -2. };
			// Test with container arrays and vectors.
			assert(rMin(arr1, 0, 9) == -2);
			assert(rMin(arr2, 0, 6) == -2.);
			assert(rMin(vec1, 0, 9) == -2.);
			assert(rMin(vec2, 0, 6) == -2.);
		}
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
		exit(EXIT_FAILURE);
	}

	cout << "Recurive minimum function passed all tests!\n";
	return 0;
}
