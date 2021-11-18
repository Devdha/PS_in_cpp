#include <iostream>

int main()
{
    int a;
    int b;
    while (1)
    {
        std::cin >> a;
        std::cin >> b;
        if (a == 0 && b == 0)
            break;
        std::cout << a + b << std::endl;
    }
}