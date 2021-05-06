#include <iostream>
#include <climits>
#include <math.h>

/**
 * Problem 3
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * 
 * What is the largest prime factor of the number 600851475143 ? 
 *  
 * */

//@Author 	Xavier
//@Date		1 Oct 2013

using namespace std;

int isPrime(long num) // Returns 1 (true) if its prime, or 0 (false) if not
{
	if (num < 2) // 1 is not a prime number
		return 0;

	if (num > 2 && (num % 2) == 0)
		return 0;

	for(int i = 2; i < num; i++ )
	{
		if ( (num % i) == 0)
			return 	0;
	}
	return 1;
}


int main (int argc, char* argv[])
{
	double threshold = 600851475143, i = 1;
	
	cout << "Prime factors of " << threshold << " are:   " << INT_MAX << endl;
	for (; i < INT_MAX; i++)
	{
		if (isPrime(i))
		{
			if (fmod(threshold , i ) == 0.0)
				cout << i << "   ";
		}
		
	}
	
	cout << endl;
	
	
	
	return 0;
}
