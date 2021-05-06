#include <iostream>

/**
 * Problem 1
 * 
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, 
 * we get 3, 5, 6 and 9. The sum of these multiples is 23. Find the sum of all 
 * the multiples of 3 or 5 below 1000.
 * */

//@Author 	Xavier
//@Date		1 Oct 2013

using namespace std;

int main (int argc, char* argv[])
{
	int count = 0, sum = 0;
	cout << "Number to finish the search of multiples of 3 and 5:  ";
	cin >> count;
	
	
	for (int i = 3; i < count; i++)
	{
		if ((i % 3 == 0) || (i % 5 == 0))
		{
			cout << i << "  ";
			sum += i;
		}
	}
	
	cout << endl << "Its Sum:  " << sum << endl;
	
	return 0;
}
