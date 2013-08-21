#include <iostream>
#include <vector>
#include "euler.h"

using namespace std;

vector<unsigned long> PrimeFactors(unsigned long);
vector<unsigned long> Factors(unsigned long);

int main()
{
    vector<unsigned long> factors =  PrimeFactors(15);

    for( std::vector<unsigned long>::const_iterator i = factors.begin(); i != factors.end(); ++i)
        cout << *i << ' ';
}

vector<unsigned long> Factors(unsigned long n)
{
    vector<unsigned long> primeFactors = PrimeFactors(n);

 
    for(int y = half_n ; y > 1; y-=2)
    {
        if(!Euler::IsPrime(y))
            continue;

        if(n % y == 0)
        {
            factors.push_back(y);
        }
   }

    // n is always a factor of itself
    factors.push_back(n);

    // 1 is always a factor
    factors.push_back(1);

    return factors;
}

vector<unsigned long> PrimeFactors(unsigned long n)
{
    unsigned long half_n = n /2;
    vector<unsigned long> factors;

    if(half_n % 2 == 0)
        half_n--;
 
    // n is always a factor of itself
    factors.push_back(n);

    for(int y = half_n ; y > 1; y-=2)
    {
        if(!Euler::IsPrime(y))
            continue;

        if(n % y == 0)
        {
            factors.push_back(y);
        }
   }

    // 1 is always a factor
    factors.push_back(1);

    return factors;
}
