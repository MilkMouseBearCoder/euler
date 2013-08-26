#include <iostream>

using namespace std;

unsigned long LatticePaths(unsigned long, unsigned long);
unsigned long SigmaSum(unsigned long);
unsigned long Factorial(unsigned long);
unsigned long Factorial(unsigned long, unsigned long);
int main()
{
	cout << LatticePaths(3, 3);
	//cout << Factorial(20);
	return 0;
}

unsigned long LatticePaths(unsigned long x, unsigned long y)
{
	unsigned long totalSteps = x + y;

	return Factorial(totalSteps - x, totalSteps) / Factorial(x);
}

unsigned long Factorial(unsigned long n1, unsigned long n2)
{
	unsigned long result = 1;

	for(unsigned long i = n2; i > n1; i--)
	{
		result*=i;
	}

	return result;
}

unsigned long Factorial(unsigned long n)
{
	unsigned long result = 1;

	for(unsigned long i = n; i > 0; i--)
	{
		result*=i;
	}

	return result;
}
