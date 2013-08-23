#include <cmath>
#include <vector>
#include <iostream>
#include "euler.h"

bool Euler::IsPrime(int n)
{

    if (n == 1) return false;
    if (n < 4) return true;
    if ((n % 2) == 0) return false;
    if (n < 9) return true;
    if ((n % 3) == 0) return false;

    int r = floor(sqrt(n));
    int f = 5;

    while (f <= r)
    {
        if ((n % f) == 0) return false;
        if ((n % (f + 2)) == 0) return false;
        f += 6;
    }

    return true;
}

std::vector<unsigned long > Euler::PrimeArray(int n)
{
    std::vector<unsigned long> primeArray;
    unsigned long number = 2;

    while(primeArray.size() < n)
    {
        if(IsPrime(number))
        {
            std::cout << number << std::endl;
            primeArray.push_back(number);
        }

        number++;
    }
}
