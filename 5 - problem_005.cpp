#include <iostream>
#include <stdlib.h>

/**
 * Problem 5
 * 
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 
 * without any remainder.
 * 
 * What is the smallest positive number that is evenly divisible by all of the numbers 
 * from 1 to 20?
 * 
 * */

//@Author 	Xavier
//@Date		2 Oct 2013

using namespace std;

int main (int argc, char* argv[])
{
	bool found = false;
	long number = 1890; 
	int i;
	/* I could initialize this at 0 and go from the beginning, 
	 * but there are for sure certain numbers that I don't need to try. 
	 * 1890 came because I multiplied 2 x 3 x 5 x 7 x 9. My guess is that
	 * nothing below that is divisible by all these prime numbers all together.
	 */
	
	while (!found)
	{
		number ++;
		found = true;
		for (i = 2; i <= 20; i++)
		{
			if ((number % i != 0) || ((number % i) % 2) != 0)
			{
				found = false;
				break;
			}
		}
		
	}
	
	cout << "Number found: " << number << endl;
	
	return 0;
}
