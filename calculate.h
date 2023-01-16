#include <iostream>

#ifndef CALCULATE_H
#define CALCULATE_H

int getValue();
char getOperator();
unsigned long long factorial(unsigned long long a);             //рекурсия факториал
long long valuePower(long long a, int b);                       //рекурсия степень

template<typename T>
void division(const T& a, const T& b)
{
    if(b != 0)
    {
        std::cout << a << " / " << b << " = " << static_cast<double>(a) / b << std::endl;
    }
    else
    {
        std::cout << "The second number you entered is 0, division by 0 is not allowed!" << std::endl;
    }
}

template<typename T>
void operation(const T& a, const T& b, const char& x)
{
    switch (x)
    {
        case '^':
            std::cout << valuePower(a, b) << std::endl;
            break;
        case '+':
            std::cout << a << " + " << b << " = " << a + b << std::endl;
            break;
        case '-':
            std::cout << a << " - " << b << " = " << a - b << std::endl;
            break;
        case '*':
            std::cout << a << " * " << b << " = " << a * b << std::endl;
            break;
        case '/':
            division(a, b);
            break;
    }
}

#endif