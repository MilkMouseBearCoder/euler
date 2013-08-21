#include <iostream>
#include <vector>

using namespace std;

vector<unsigned long> getFactors(unsigned long);

int main()
{
    vector<unsigned long> factors =  getFactors(28);

    for( std::vector<unsigned long>::const_iterator i = factors.begin(); i != factors.end(); ++i)
        cout << *i << ' ';

}

vector<unsigned long> getFactors(unsigned long n)
{
    unsigned long half_n = n /2;
    vector<unsigned long> factors;

    // n is always a factor of itself
    factors.push_back(n);

    for(int y = half_n ; y > 1; y--)
    {
        if(n % y == 0)
        {
            factors.push_back(y);
        }
   }

    // 1 is always a factor
    factors.push_back(1);

    return factors;
}
