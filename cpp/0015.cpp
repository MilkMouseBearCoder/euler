// Shuld have used Pascal's triangle

#include <iostream>
#include <vector>

using namespace std;

unsigned long LatticePaths(unsigned long, unsigned long);
unsigned long SigmaSum(unsigned long);
vector<unsigned long> FactorialNumbers(unsigned long);
vector<unsigned long> FactorialNumbers(unsigned long, unsigned long);
int main()
{
	cout << LatticePaths(20, 20);
	//cout << Factorial(20);
	return 0;
}

unsigned long LatticePaths(unsigned long x, unsigned long y)
{
	unsigned long totalSteps = x + y;

	vector<unsigned long> factorsTop, factorsBottom;

	factorsTop = FactorialNumbers(totalSteps - x, totalSteps);
	factorsBottom = FactorialNumbers(x);

	for (int t = 0; t < factorsTop.size(); t++)
	{
		for (int b = 0; b < factorsBottom.size(); b++)
		{
			if(factorsTop[t] % factorsBottom[b] == 0)
			{
				factorsTop[t]/=factorsBottom[b];
				factorsBottom[b]= 1;
			}
		}
	}

	unsigned long top = 1;
	for (int t = 0; t < factorsTop.size(); t++)
	{
		top*=factorsTop[t];
	}

	unsigned long bottom = 1;
	for (int b = 0; b < factorsBottom.size(); b++)
	{
		bottom*=factorsBottom[b];
	}

	return top / bottom;
}

vector<unsigned long> FactorialNumbers(unsigned long n1, unsigned long n2)
{
	vector<unsigned long> result;

	for(unsigned long i = n2; i > n1; i--)
	{
		result.push_back(i);
	}

	return result;
}

vector<unsigned long> FactorialNumbers(unsigned long n)
{
	vector<unsigned long> result;

	for(unsigned long i = n; i > 1; i--)
	{
		result.push_back(i);
	}

	return result;
}
