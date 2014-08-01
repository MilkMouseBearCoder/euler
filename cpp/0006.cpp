#include <iostream>

int sigmaSquare(int);
int sigma(int);

int main()
{
    int sum = sigma(100);
    int square = sigmaSquare(100);

    std::cout << sum << std::endl;
    std::cout << square << std::endl;

    std::cout << (sum * sum) - square;
}

int sigma(int value)
{
    return (value * (value + 1)) / 2;
}

int sigmaSquare(int value)
{
    return (value * (value + 1) * ((2 * value) + 1)) / 6;
}
