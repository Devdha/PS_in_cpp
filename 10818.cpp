#include <iostream>

using namespace std;

int main()
{
    int max, min, cnt, input;

    cin >> cnt >> input;
    max = min = input;
    for (int i = 1; i < cnt; i++)
    {
        cin >> input;
        if (input > max)
            max = input;
        if (input < min)
            min = input;
    }
    cout << min << " " << max;
}