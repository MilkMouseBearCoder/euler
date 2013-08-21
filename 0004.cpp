#include <iostream>
#include <sstream>
#include <string>

bool isPalindrome(int);

int main()
{
    int finalResult = 0;

    for(int x = 999; x > 99; x--)
    { 
        for(int y = x; y > 99; y--)
        {
            int result = x * y;
            if(result < finalResult)
                break;
 
            if(isPalindrome(result))
            {
                if(result > finalResult)
                    finalResult = result;

                std::cout << x << " x " << y << " = " << result << std::endl;
            }
        }
    }
    std::cout << finalResult;
}

bool isPalindrome(int value)
{
    std::string forward, reverse;
    std::ostringstream convert;

    convert << value;
    forward = convert.str();
    reverse = std::string(forward.rbegin(), forward.rend());
 
    return (forward == reverse);
}

