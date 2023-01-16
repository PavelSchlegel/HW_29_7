#include <iostream>
#include "calculate.h"

int getValue()
{
    while (true)
    {
        int value;
        std::cout << "Enter the number: " << std::endl;
        std::cin >> value;
 
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            std::cout << "Oops, that input is invalid. Please try again." << std::endl;
        }
        else
        {
            std::cin.ignore(32767,'\n');

            return value;
        }
    }
}

char getOperator()
{
    while (true)
    {
        std::cout << "Enter one of the following: +, -, *, /, !, ^ or q for quit ";
        char oper;
        std::cin >> oper;
        std::cin.ignore(32767,'\n');

        switch(oper)
        {
            case '!':
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
            case 'q':
                return oper;
            default:
                std::cout << "Operator is invalid, please try agein" << std::endl;
        }
    }
}

unsigned long long factorial(unsigned long long a)      //long long aдекватно вмещает факториал числа 21
{
    if(a != 1)
    {
        a *= factorial(a - 1);
    }

    return a;
}

long long valuePower(long long a, int b)
{
    if(b != 1)
    {
        a *= valuePower(a, b -1);
    }
    
    return a;
}