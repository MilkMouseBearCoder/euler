#include <iostream>
#include <vector>
#include <cmath>
#include "euler.h"

using namespace std;

vector<unsigned long> PrimeFactors(unsigned long);
int FactorCount(unsigned long);

int main()
{
    for (unsigned long x = 2; x < 99999999; x++)
    {
        unsigned long triNum = (x * (x + 1)) / 2;
        int factorCount = FactorCount(triNum);

        if(factorCount > 500)
        {
            cout << triNum << " : " << factorCount << endl;
            return 0;
        }
    }
}

int FactorCount(unsigned long n)
{
    vector<unsigned long> primeFactors = PrimeFactors(n);
    int vector_size = primeFactors.size();
    int count = 1;
    int expCount;
    int factor;

    for (unsigned long x = 0; x < vector_size; x++)
    {
        expCount = 0;
        factor = primeFactors[x];
        while(n % factor == 0)
        {
            n/=factor;
            expCount++;
        }
        expCount++;
        count*=expCount;
    }

    return count;
}

/*
    Can be impromved by creating a prime array.
*/
vector<unsigned long> PrimeFactors(unsigned long n)
{
    unsigned long half_n = sqrt(n) ;
    vector<unsigned long> factors;

    if (n % 2 == 0)
    {
        factors.push_back(2);
    }

    if(half_n % 2 == 0)
    {
        half_n--;
    }
 
    for(unsigned long y = half_n ; y > 1; y-=2)
    {
        if(!Euler::IsPrime(y))
            continue;

        if(n % y == 0)
        {
            factors.push_back(y);
        }
   }

    return factors;
}
