#include <iostream>

bool isPrime(int);

int main()
{
    for(int x = 10000; x > 1; x--)
    {
        if((isPrime(x)) && (600851475143 % x == 0))
        {
            std::cout << "largest prime factor:" << x << std::endl;
            return 0;
        }
    }
    std::cout << "done!";
}

bool isPrime(int number)
{
    for(int x = number / 2; x > 1; x--)
    {
        if((number % x) == 0)
        {
            return false;
        }
    }
    return true;
}
