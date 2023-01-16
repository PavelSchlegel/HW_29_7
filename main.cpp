#include <iostream>
#include "calculate.h"

int main()
{

    while(true)
    {
        int vOne = getValue();
        char oP = getOperator();

        if(oP == '!') //пока ограничемся факториалом макс. число 21
        {
                if(vOne < 22)
                {
                    unsigned long long fact = vOne;
                    std::cout << factorial(fact) << std::endl;
                    continue;
                }
                else
                {
                    std::cout << "The factorial of 22 is too large, please enter a smaller number!" << std::endl;
                    continue;
                }
        }

        if(oP == 'q')
        {
            break;
        }

        int vTwo = getValue();
        operation(vOne, vTwo, oP);
    }

    return 0;
}