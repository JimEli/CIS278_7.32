/*************************************************************************
* Title: Find the Minimum Value in an Array
* File: rMinTest.cpp
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
*  (3) Made into template function to accept wider variety of arrays.
*  (2) Add (appropriate) boost include and lib diretories to project:
*      C:\Program Files\boost\boost_1_66_0
*      C:\Program Files\boost\boost_1_66_0\stage\lib
*  (3) Submitted in partial fulfillment of the requirements of PCC CIS-278.
*************************************************************************
* Change Log:
*   01/17/2018: Initial release. JME
*   03/10/2018: Add limited bounds checking. JME
*   03/16/2018: Added boost unit testing. JME
*************************************************************************/
#define BOOST_TEST_MODULE rMinTest
#define BOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE
#include <boost/test/unit_test.hpp>

#include <iostream>  // cin/cout/endl
#include <array>
#include <vector>

#include "rMin.h"

BOOST_AUTO_TEST_SUITE(rMinTest)

// Test integer array.
BOOST_AUTO_TEST_CASE(test_integers)
{
	int a[]{ 10, 8, 8, 5, -2, 0, 10, 4, 3, 1 };

	BOOST_CHECK(rMin(a, 0, 9) == -2);
	BOOST_CHECK(rMin(a, 0, 9) == -2);
	BOOST_CHECK(rMin(a, 9, 9) == 1);
	BOOST_CHECK(rMin(a, 0, 0) == 10);
	BOOST_CHECK(rMin(a, 5, 9) == 0);

}

// Test character array.
BOOST_AUTO_TEST_CASE(test_characters)
{
	char a[]{ 'a', '?', 'a', 'A', 'z', '1', '!' };

	BOOST_CHECK(rMin(a, 0, 6) == '!');
	BOOST_CHECK(rMin(a, 0, 0) == 'a');
	BOOST_CHECK(rMin(a, 0, 1) == '?');
	BOOST_CHECK(rMin(a, 6, 6) == '!');
	BOOST_CHECK(rMin(a, 3, 3) == 'A');
}

// Test floating point array.
BOOST_AUTO_TEST_CASE(test_floats)
{
	double a[]{ 10., 8.1, 0.8, 5.25, 10., 0, -2. };

	// Test with floating point.
	BOOST_CHECK(rMin(a, 0, 6) == -2.);
}

// Test integer array pointer.
BOOST_AUTO_TEST_CASE(test_array_pointer)
{
	int *a{ new int[6]{ 10, 8, 8, 5, -2, 0 } };

	// Test integer array pointer.
	BOOST_CHECK(rMin(a, 0, 5) == -2);

	delete[] a;
}

// Test container arrays.
BOOST_AUTO_TEST_CASE(test_array)
{
	std::array<int, 10> a1{ 10, 8, 8, 5, -2, 0, 10, 4, 3, 1 };
	std::array<double, 7> a2{ 10., 8.1, 0.8, 5.25, 10., 0, -2. };

	// Test with arrays and vectors.
	BOOST_CHECK(rMin(a1, 0, 9) == -2);
	BOOST_CHECK(rMin(a2, 0, 6) == -2.);
}

// Test vectors.
BOOST_AUTO_TEST_CASE(test_vetor)
{
	std::vector<int> a1{ 10, 8, 8, 5, -2, 0, 10, 4, 3, 1 };
	std::vector<double> a2{ 10., 8.1, 0.8, 5.25, 10., 0, -2. };
	
	BOOST_CHECK(rMin(a1, 0, 9) == -2.);
	BOOST_CHECK(rMin(a2, 0, 6) == -2.);
}

// Test for our exception message.
bool correctMessage(const std::logic_error& ex)
{
	BOOST_CHECK_EQUAL(ex.what(), std::string("index/end out of bounds"));
	return true;
}

// Test exception.
BOOST_AUTO_TEST_CASE(test_exception)
{
	int a[]{ 1 };

	BOOST_CHECK_EXCEPTION(rMin(a, 2, 1), std::invalid_argument, correctMessage);
	BOOST_CHECK_EXCEPTION(rMin(a, 2, 1), std::invalid_argument, correctMessage);
}

BOOST_AUTO_TEST_SUITE_END()
