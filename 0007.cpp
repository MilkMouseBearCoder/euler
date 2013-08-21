#include <iostream>
#include <cstdlib>
#include <cmath>

bool probablyPrime(ulong);

int main()
{
    int primesFound = 1;
    ulong value = 3;


//    probablyPrime(29);
//    return 0;

    while(primesFound < 10001)
    {
        if(probablyPrime(value))
        {
            primesFound++;
            std::cout << primesFound << ": " << value << std::endl;
        }
        else
        {
//            std::cout << value << std::endl;
        }
        value+=2;
    }

    return 0;
}

bool probablyPrime(ulong value)
{
    if((value % 2) == 0)
    {
        return value == 2;
    }

    ulong end = value / 2;

    for(ulong x = 3; x <= end; x+=2)
    {
//        std::cout << x << " : " << (value % x) <<std::endl;
        if((value % x) == 0)
        {
            return false;
        }
    }
    return true;
}

/*
bool probablyPrime(long value)
{
    bool maybe = false;

    for (int x = 0; x < 2; x++)
    {
        double a = (random() % (value / 2)) + 2;
        double b = pow(a, value - 1);
        //std::cout << a << " : " << b << std::endl;
        if(fmod(b, value) == 1)
        {
            maybe = true;
        }
        else
        {
            maybe = false;
            break;
        }
    }

    return maybe;
}
*/
