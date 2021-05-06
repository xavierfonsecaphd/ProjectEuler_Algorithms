#include <iostream>
#include <stdlib.h>

/**
 * Problem 4
 * 
 * A palindromic number reads the same both ways. The largest palindrome made from the 
 * product of two 2-digit numbers is 9009 = 91 x 99.
 * 
 * Find the largest palindrome made from the product of two 3-digit numbers.
 * 
 * */

//@Author 	Xavier
//@Date		1 Oct 2013

using namespace std;

int isPalindrome(char* number, int digits)
{
	for (int i = 0; i < digits / 2; i++)
	{
		if (number[i] != number[digits - 1 - i])
			return 0;	// it is not a palindrome
	}
	
	return 1;
}

int numberOfDigits(int number)
{
	int aux, digits;
	aux = number;
	for (digits = 0; ; )
	{
		if ((aux % 10 != 0) || (aux / 10 != 0))
			digits ++;
		else
			break;
		aux = aux / 10;
	}
	
	return digits;
}

char* custom_itoa(int i)
{
    static char output[10];  
    char* p = &output[9];

	i *= 10; 
    for(*p--=0; i/=10; *p--=i%10+0x30);
    *p = i % 10; 
    return ++p;    
}


int main (int argc, char* argv[])
{
	int number, maxDigits = 3, number1 = 100, 
		number2 = 100, biggestPal = 0, factor1=0, factor2=0, islastcomb1 = 0, islastcomb2 = 0;
	
	
	for (;!islastcomb1 || !islastcomb2;)
	{
		// see if the product is a palindrome
		number = number1 * number2;
		if (isPalindrome(custom_itoa(number), numberOfDigits(number)))
		{
			if (number > biggestPal)
				biggestPal = number;
			factor1 = number1;
			factor2 = number2;
		}
		
		// increment multipliers
		if (!islastcomb1)
		{
			if (numberOfDigits(number1 + 1) > maxDigits)
				islastcomb1 = 1;
			else
				number1 ++;
		}
		else if (!islastcomb2)
		{
			if (numberOfDigits(number2 + 1) > maxDigits)
				islastcomb2 = 1;
			else
			{
				number2 ++;
				
				number1 = 100;
				islastcomb1 = 0;
			}
		}
	}
	cout << "Biggest Palindrome:  " << biggestPal << "  [ " << factor1 << " x " << factor2 << " ]"<< endl;
	return 0;
}
