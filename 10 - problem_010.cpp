#include <iostream>
#include <math.h>
#include <fstream>

/**
 * Problem 10
 * 
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * 
 * Find the sum of all the primes below two million.
 * 
 * */

//@Author 	Xavier
//@Date		2 Oct 2013

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
	long prime = 0;
	bool quit = false;
	double sum = 0.0;
	ofstream myfile;
	myfile.open ("example.txt");
	
	
	
	do 
	{
		if (isPrime(++ prime)) 
		{
			if (prime < 2000000)
			{
				sum += prime;
				myfile << prime << endl;
			}
			else quit = true;
		}
		if (prime > 2000000)
			quit = true;
	}
	while (!quit);
	
	cout << "Sum of primes is:  " << fixed << sum << endl;	
	myfile.close();
	
	return 0;
}
