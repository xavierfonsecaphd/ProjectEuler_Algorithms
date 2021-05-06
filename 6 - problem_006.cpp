#include <iostream>
#include <math.h>

/**
 * Problem 6
 * 
 * The sum of the squares of the first ten natural numbers is,
 * 			12 + 22 + ... + 102 = 385
 * 
 * The square of the sum of the first ten natural numbers is,
 * 			(1 + 2 + ... + 10)2 = 552 = 3025
 * 
 * Hence the difference between the sum of the squares of the first ten natural 
 * numbers and the square of the sum is 3025  385 = 2640.
 * Find the difference between the sum of the squares of the first one hundred natural 
 * numbers and the square of the sum.
 * 
 * */

//@Author 	Xavier
//@Date		2 Oct 2013

using namespace std;

int main (int argc, char* argv[])
{
	long sumOfSquares = 0, squareOfSum = 0;
	int i;
	
	for (i = 1; i <= 100; i ++)
	{
		squareOfSum += i;
		sumOfSquares += pow(i, 2);
	}
	squareOfSum = pow(squareOfSum, 2);
		
	cout << "Difference:  " << squareOfSum - sumOfSquares << endl;
	
	return 0;
}
