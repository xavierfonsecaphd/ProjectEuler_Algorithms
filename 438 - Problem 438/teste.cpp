#include <iostream>
#include <math.h>
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
int computePolynomial(double *solution ,int n, double *coeficients)
{
	// limit of 50 iterations to find the roots
	int i, limit = 50, rootCount = 0;
	double x = 1.0, b[n],c[n];
	
	while(n>0 && limit > 0)
    {
        c[0]=b[0]=coeficients[0];
        for(i=1;i<=n;i++)
            b[i]=coeficients[i]+b[i-1]*x;
        for(i=1;i<n;i++)
            c[i]=b[i]+c[i-1]*x;
        if(fabs(c[n-1])==0.0)   // "Divide by Zero : ERROR !! "
			break;
        x-=b[n]/c[n-1];
        if(fabs(b[n]/c[n-1])<0.00001)
        {
            solution[rootCount++] = x;
            for(i=1;i<n;i++)
                coeficients[i]=b[i];
            n--;
        }
        limit --;
    }
    if (!limit) return 0; // no solution
    return 1; // true
}

int main()
{     
    int n,i;
    double* solution, *coeficients;
    

    cout << "Enter the degree of equations : ";
    cin >> n;
    
    solution = (double*) malloc (n * sizeof(double));
    coeficients = (double*) malloc ((n + 1) * sizeof(double));
    memset(solution, 0, n * sizeof(double));
    
    cout<<"Enter all coefficients \n";
    for(i = 0; i <= n; i++)
        cin >> coeficients[i];

	if (computePolynomial(solution, n, coeficients))
	{
		for (i = 1; i <= n; i++)
		{
			cout << "\nRoot X" << i << " is: " << fixed << solution[i - 1] << endl;
		}
	}
	else
		cout << "No Solution Found!" << endl;
	
	return 0;
}
