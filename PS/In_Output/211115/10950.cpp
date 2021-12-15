#include <iostream>

int main()
{
    int cnt;
    int a;
    int b;

    std::cin >> cnt;
    while (cnt)
    {
    std::cin >> a;
    std::cin >> b;
    std::cout << a + b << std::endl;
    cnt--;
    }
    return 0;
}