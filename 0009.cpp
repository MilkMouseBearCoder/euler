#include <iostream>

using namespace std;

void findPythagoreanValues(int, int&, int&, int&);

int main()
{
    int a = 0, b = 0, c = 0;

    findPythagoreanValues(1000, a, b, c);

    cout << a << " + " << b << " + " << c << endl;
    cout << a *b * c;
}

void findPythagoreanValues(int total, int &a, int &b, int &c)
{
    for(int m = 1; m < 100; m++)
    {
        for(int n = m + 1; n < 100; n++)
        {

            a = (n * n) - (m * m);
            b = 2 * m * n;
            c = (m * m) + (n * n);

            if((a + b + c) > total)
                break;
            if((a + b + c) == total)
                return;

        }
    }

    a = 0;
    b = 0;
    c = 0;
}
