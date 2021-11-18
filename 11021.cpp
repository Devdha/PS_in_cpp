#include <iostream>

int main()
{
    int cnt;
    int num;
    int a;
    int b;

    std::cin >> num;
    cnt = 1;
    while (cnt <= num)
    {
        std::cin >> a >> b;
        std::cout << "Case #" << cnt << ": " << a + b << std::endl;
        cnt++;
    }
}