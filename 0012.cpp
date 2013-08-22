#include <iostream>
#include <vector>
#include <cmath>
#include "euler.h"

using namespace std;

vector<unsigned long> PrimeFactors(unsigned long);
vector<unsigned long> Factors(unsigned long);
int FactorCount(unsigned long);

int main()
{
//    cout << FactorCount(72);
//    return 0;

    /*vector<unsigned long> factors1 = Factors(21);
    for( std::vector<unsigned long>::const_iterator i = factors1.begin(); i != factors1.end(); ++i)
        cout << *i << ' ';
    return 0;*/
    for (unsigned long x = 2; x < 99999999; x++)
    {
        unsigned long triNum = (x * (x + 1)) / 2;
        vector<unsigned long> factors = Factors(triNum);
        cout << x << " : " << " : " << triNum << " : " << factors.size() << endl;
        if (factors.size() > 10)
        {
            cout << endl <<  x << endl;
            for( std::vector<unsigned long>::const_iterator i = factors.begin(); i != factors.end(); ++i)
                cout << *i << ' ';
            return 0;
        }
    }

}

vector<unsigned long> Factors(unsigned long n)
{
    vector<unsigned long> primeFactors = PrimeFactors(n);
    vector<unsigned long> factors;
    unsigned long tempFactor = 0;

    int vector_size = primeFactors.size();

    // n is always a factor of itself
    factors.push_back(n);

    for (unsigned long x = 0; x < vector_size; x++)
    {
        factors.push_back(primeFactors[x]);
        for (unsigned long  y = 0; y < vector_size; y++)
        {
            tempFactor = primeFactors[x] * primeFactors[y];

            while ((tempFactor < n) && (n % tempFactor == 0))
            {
                for(int v = 0; v < factors.size(); v++)
                {
                    if(factors[v] == tempFactor)
                    {
                        found = true;
                        break;
                    }
                }
                if(!found)
                    factors.push_back(tempFactor);
                tempFactor*=primeFactors[y];
            }
        }
    }
    // 1 is always a factor
    factors.push_back(1);

    return factors;
}

int FactorCount(unsigned long n)
{
    vector<unsigned long> primeFactors = PrimeFactors(n);
    int vector_size = primeFactors.size();
    int count = 1;

    for (unsigned long x = 0; x < vector_size; x++)
    {
        //cout << primeFactors[x] << endl;
        count*=(vector_size - x);
    }

    return count;

}

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
