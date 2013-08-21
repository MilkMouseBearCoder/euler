#include <iostream>

int main()
{
    int divNumber = 2500;
    bool div = false;

    while(!div)
    {
        divNumber += 20;
        for(int x = 2; x < 21; x++)
        {
            div = true;
            if(divNumber % x != 0)
            {
                div = false;
                break;
            }
        }
    }
    std::cout << divNumber << std::endl;
}
