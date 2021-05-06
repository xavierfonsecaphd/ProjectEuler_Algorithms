#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <cstring>

using namespace std;
/**
 * Problem 438
 * 
 * Example:
 * x^4-(1/2)x^3-(30)x^2+x+2 = 0
 * a=	-(1/2)
 * b=	-30
 * c=	1
 * d=	2
 * x1=	 0.2751
 * x2=	-0.24275
 * x3=	-5.24368
 * x4=	 5.71133
 * 
 * 
 * */

//@Author 	Xavier
//@Date		4 Oct 2013
// Newton horner's method:
// http://ganeshtiwaridotcomdotnp.blogspot.pt/2009/12/c-c-code-newton-horners-method-for.html

// x1, ..., xn SORTED, ⌊xi⌋ = i for 1 ≤ i ≤ n

int computePolynomial(double *solution ,int n, double *coeficients)
{
	// limit of 50 iterations to find the roots
	int i, limit = 50, rootCount = 0;
	double x = 1.0, a[n], b[n],c[n];
	
	while(n>0 && limit > 0)
    {
        c[0]=b[0]=a[0];
        for(i=1;i<=n;i++)
            b[i]=a[i]+b[i-1]*x;
        for(i=1;i<n;i++)
            c[i]=b[i]+c[i-1]*x;
        if(fabs(c[n-1])==0.0)   // "Divide by Zero : ERROR !! "
			break;
        x-=b[n]/c[n-1];
        if(fabs(b[n]/c[n-1])<0.00001)
        {
            solution[rootCount++] = x;
            for(i=1;i<n;i++)
                a[i]=b[i];
            n--;
        }
        limit --;
    }
    if (!limit) return 0; // no solution
    return 1; // true
}

void *threadExec()
{
	int i, j, n = 4;
	double* solution, *coeficients , aux, sum = 0.0, reset = -10000.0;
    bool conditionMet = false;
    
    solution = (double*) malloc (n * sizeof(double));
    memset(solution, 0, n * sizeof(double));
    coeficients[0] = 1.0;
    coeficients[1] = reset;
    coeficients[2] = reset;
    coeficients[3] = reset;
    coeficients[4] = reset;
    
	do
	{
		if (computePolynomial(solution, n, coeficients))
		{
			for (i = 1; i <= n; i++)
			{
				cout << "[" << coeficients[i-1] << "] X" << i << " is: " << fixed << solution[i - 1] << endl;
			}
			cout << "[" << coeficients[n] << "]" << endl; 
			// you found roots. sort solutions
			for (i = 0; i < n; i++)
			{
				for (j = i + 1; j < n; j++)
				{
					if (solution[j] < solution[i])
					{
						aux = solution[i];
						solution[i] = solution[j];
						solution[j] = aux;
					}
				}
			}
			
			conditionMet = true;
			for (i = 1; i <= n; i++)
			{
				if (floor(solution[i - 1]) != i) conditionMet = false;
			}
			
			if (conditionMet) // we found a solution
			{
				for (i = 1; i <= n; i++) sum += fabs(coeficients[i]);
				
				cout << "conditions Met! SUM:  " << sum << endl;
				return (void*)1;
			}
			
		}
		
		// increment coeficients
		if (coeficients[4] < 10000)
		{
			//cout << "[\t" <<coeficients[1] << "\t|\t" <<coeficients[2] << "\t|\t"  <<coeficients[3] << "\t|\t"  <<coeficients[4] << "\t]" << endl;
			coeficients[4] ++;
		}
		else if (coeficients[3] < 10000)
		{
			//cout << "[\t" <<coeficients[1] << "\t|\t" <<coeficients[2] << "\t|\t"  <<coeficients[3] << "\t|\t"  <<coeficients[4] << "\t]" << endl;
			coeficients[3] ++;
			coeficients[4] = reset;
		}
		else if (coeficients[2] < 10000)
		{
			//cout << "[\t" <<coeficients[1] << "\t|\t" <<coeficients[2] << "\t|\t"  <<coeficients[3] << "\t|\t"  <<coeficients[4] << "\t]" << endl;
			coeficients[2] ++;
			coeficients[3] = reset;
			coeficients[4] = reset;
		}
		else if (coeficients[2] < 10000)
		{
			cout << "[\t" <<coeficients[1] << "\t|\t" <<coeficients[2] << "\t|\t"  <<coeficients[3] << "\t|\t"  <<coeficients[4] << "\t]" << endl;
			coeficients[2] ++;
			coeficients[3] = reset;
			coeficients[4] = reset;
		}
		else if (coeficients[1] < 10000)
		{
			cout << "[\t" <<coeficients[1] << "\t|\t" <<coeficients[2] << "\t|\t"  <<coeficients[3] << "\t|\t"  <<coeficients[4] << "\t]" << endl;
			coeficients[1] ++;
			coeficients[2] = reset;
			coeficients[3] = reset;
			coeficients[4] = reset;
		}
		else 
		{
			cout << "No solution found" << endl;
			return (void*) 0;
		}
	}
	while(!conditionMet);
	
	return (void*) 0;
}

int main()
{     
    int i,n = 4;
   double *coeficients;
    cout << "The degree of equations is : " << n << endl;
    
    coeficients = (double*) malloc ((n + 1) * sizeof(double));
   
	threadExec();
		
	return 1;
}
