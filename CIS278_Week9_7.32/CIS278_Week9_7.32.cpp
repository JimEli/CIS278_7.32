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
#include <iostream>  // cin/cout/endl
#include <algorithm> // min
#include <array>
#include <vector>
#include <cassert>

using namespace std;

// Recursive minimum template function.
template<typename T>
inline const T rMin(const T *t, const size_t index, const size_t end) {
	// Check index and end.
	if (index < 0 || end < index)
		throw invalid_argument("index/end out of bounds");
	// Tail recursion.
	if (index == end)
		return *(t + index);
	else
		return min(*(t + index), rMin(t, index + 1, end));
}

template<class T, size_t N>
inline const T rMin(const array<T, N> a, const size_t index, const size_t end) {
	// Check index and end.
	if (index < 0 || end < index)
		throw invalid_argument("index/end out of bounds");
	// Tail recursion.
	if (index == end)
		return a.at(index);
	else
		return min(a.at(index), rMin(a, index + 1, end));
}

template<class T>
inline const T rMin(const vector<T> v, const size_t index, const size_t end) {
	// Check index and end.
	if (index < 0 || end < index)
		throw invalid_argument("index/end out of bounds");
	// Tail recursion.
	if (index == end)
		return v.at(index);
	else
		return min(v.at(index), rMin(v, index + 1, end));
}

int main()
{
	// Test recursive function with int, chars, double array & vector.
	int a1[]{ 10, 8, 8, 5, -2, 0, 10, 4, 3, 1 };
	char a2[]{ 'a', '?', 'a', 'A', 'z', '1', '!' };
	double a3[]{ 10., 8.1, 0.8, 5.25, 10., 0, -2. };
	int *a4{ new int[6]{ 10, 8, 8, 5, -2, 0 } };
	array<int, 10> a5{ 10, 8, 8, 5, -2, 0, 10, 4, 3, 1 };
	array<double, 7> a6{ 10., 8.1, 0.8, 5.25, 10., 0, -2. };
	vector<int> a7{ 10, 8, 8, 5, -2, 0, 10, 4, 3, 1 };
	vector<double> a8{ 10., 8.1, 0.8, 5.25, 10., 0, -2. };

	try
	{
		// Test with integers.
		assert(rMin(a1, 0, 9) == -2);
		assert(rMin(a1, 9, 9) == 1);
		assert(rMin(a1, 0, 0) == 10);
		assert(rMin(a1, 5, 9) == 0);

		// Test with characters.
		assert(rMin(a2, 0, 6) == '!');

		// Test with floating point.
		assert(rMin(a3, 0, 6) == -2.);

		// Test integer array pointer.
		assert(rMin(a4, 0, 5) == -2);

		// Test with arrays and vectors.
		assert(rMin(a5, 0, 9) == -2);
		assert(rMin(a6, 0, 6) == -2.);
		assert(rMin(a7, 0, 9) == -2.);
		assert(rMin(a8, 0, 6) == -2.);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
		exit(EXIT_FAILURE);
	}

	cout << "Recurive Minimum passes test!\n";

	return 0;
}
