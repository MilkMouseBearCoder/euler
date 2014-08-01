#include <iostream>

using namespace std;

int CollatzLength(long);

int main()
{
    int longest = 0, num = 0, length;

    for (int x = 1000000; x > 0; x--)
    {
        length = CollatzLength(x);
        if(length > longest)
        {
            num = x;
            longest = length;
        }
    }
    cout << longest << " : " << num << endl;
    return 0;
}

int CollatzLength(long n)
{
    int count=0;
    while(n != 1)
    {
        if(n % 2 == 0)
        {
            n/=2;
        }
        else
        {
            n = (n * 3) + 1;
        }
        count++;
    }

    return count;
}

