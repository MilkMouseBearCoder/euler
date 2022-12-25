#include <iostream>
#include <cstdlib>
#include <cmath>
#include "euler.h"


int main()
{
    ulong primeTotal = 2;
    int value = 3;

    Euler a;

    while(value < 2000000)
    {
        if(Euler::IsPrime(value))
        {
            primeTotal+=value;
            std::cout << value << '\n';
        }
        value+=2;
    }

    std::cout << primeTotal << '\n';
    return 0;
}

