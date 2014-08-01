#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

int main()
{
    ostringstream power;

    power << std::fixed << std::setprecision(0) << pow(2, 1000);

    string longNumber = power.str();
    int longNumberLength = longNumber.length(), temp;
    unsigned long result = 0; 

    for(int i = 0; i < longNumberLength; i++)
    {
        stringstream (string(1, longNumber[i])) >> temp;
        result+=temp;
    }

    cout << result;

    return 0;
}
