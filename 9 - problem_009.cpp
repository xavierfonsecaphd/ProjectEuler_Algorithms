#include <iostream>
#include <math.h>

/**
 * Problem 9
 * 
 * A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,
 * a^2 + b^2 = c^2
 * 
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 * 
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 * 
 * */

//@Author 	Xavier
//@Date		2 Oct 2013

using namespace std;

int main (int argc, char* argv[])
{
	int a=1, b=1, c=1;
	double aux;

	for (; a < 1000; a ++)
	{
		for (b = a + 1; b < 1000; b ++) // a < b always
		{
			aux = pow (a,2) + pow(b, 2);
			aux = sqrt(aux);
			
			if (fmod(aux,1) == 0) // natural
			{
				c = (int) aux;
				if (c > b && b > a)
				{
					if (a + b + c == 1000) // solution found
					{
						cout << "a:  " << a << endl;
						cout << "b:  " << b << endl;
						cout << "c:  " << c << endl;
						cout << "abc:  " << a * b * c << endl;
						
						return 0;
					}
					if (a + b + c > 1000) b = 2000; // forces to renew a
				}
			}
		}
	}		
		
	cout << "Not Found." << endl;
	
	return 1;
}
