#include <iostream>

using namespace std;

unsigned long LatticePaths(unsigned long, unsigned long);
unsigned long SigmaSum(unsigned long);

int main()
{
	cout << LatticePaths(3, 3);

	return 0;
}

unsigned long LatticePaths(unsigned long x, unsigned long y)
{
	unsigned long totalSteps = x + y;

	return SigmaSum(totalSteps) / (SigmaSum(totalSteps - x) * SigmaSum(x));
}

unsigned long SigmaSum(unsigned long n)
{
	return (n * (n + 1)) / 2;
}
