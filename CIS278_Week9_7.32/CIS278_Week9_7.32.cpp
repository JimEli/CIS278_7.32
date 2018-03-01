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
*************************************************************************/
#include <iostream>  // cin/cout/endl
#include <algorithm> // min
#include <vector>   

using namespace std;

// Recursive minimum template function.
template <typename T>
T recursiveMinimum(T t[], size_t index, const size_t end) {
	if (index == end)
		return t[index];
	else
		return min(t[index], recursiveMinimum(t, index + 1, end));
}

int main()
{
	// Test recursive function with int, vector, double and chars
	int a1[]{ 10, 8, 8, 5, -2, 0, 10, 4, 3, 1 };
	cout << recursiveMinimum(a1, 0, 9) << endl;

	vector<int> a2{ 10, 1, 9, -2, 8, 3, 7, 4, 6, 5 };
	cout << recursiveMinimum(&a2[0], 0, a2.size() - 1) << endl;

	double a3[]{ 10., 8.1, 0.8, 5.25, 10., 0, -2. };
	cout << recursiveMinimum(a3, 0, 6) << endl;
	
	char a4[]{ 'a', '!', 'a', 'A', 'z', '1', '?' };
	cout << recursiveMinimum(a4, 0, 6) << endl;

	return 0;
}
