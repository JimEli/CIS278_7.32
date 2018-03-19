/*************************************************************************
* Title: Find the Minimum Value in an Array
* File: rMin.h
* Author: James Eli
* Date: 3/16/2018
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
*   03/17/2018: Added array and vector support. JME
*************************************************************************/
#pragma once

#include <algorithm> // min
#include <array>
#include <vector>

// Recursive minimum template functions.
// Basic type(s).
template<typename T>
inline T rMin(T *t, const size_t index, const size_t end)
{
	// Check index and end.
	if (index < 0 || index > end)
		throw std::invalid_argument("index/end out of bounds");
	// Perform tail recursion.
	return (index == end) ? *(t + index) : std::min(*(t + index), rMin(t, index + 1, end));
}

// Container array specialization.
template<class T, size_t n>
inline T rMin(std::array<T, n> a, const size_t index, const size_t end)
{
	return (index == end) ? a.at(index) : std::min(a.at(index), rMin(a, index + 1, end));
}

// Vector specialization.
template<typename T, typename A>
inline T rMin(std::vector<T, A> v, const size_t index, const size_t end)
{
	return (index == end) ? v.at(index) : std::min(v.at(index), rMin(v, index + 1, end));
}

