#include <iostream>

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
        case '&':
            std::cout << a << " & " << b << " = " << (a & b) << std::endl;
            break;
        case '|':
            std::cout << a << " | " << b << " = " << (a | b) << std::endl;
            break;
        case '^':
            std::cout << a << " ^ " << b << " = " << (a ^ b) << std::endl;
    }
}

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
        std::cout << "Enter one of the following: +, -, *, /, &, |, ^ or q for quit ";
        char oper;
        std::cin >> oper;
        std::cin.ignore(32767,'\n');

        switch(oper)
        {
            case '+':
            case '-':
            case '*':
            case '/':
            case '&':
            case '|':
            case '^':
            case 'q':
                return oper;
            default:
                std::cout << "Operator is invalid, please try agein" << std::endl;
        }
    }
}


int main()
{

    while(true)
    {
        int vOne = getValue();
        char oP = getOperator();

        if(oP == 'q')
        {
            break;
        }

        int vTwo = getValue();
        operation(vOne, vTwo, oP);
    }

    return 0;
}