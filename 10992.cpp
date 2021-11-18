#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
            cout << " ";
        if (i != 1)
            cout << "*";
        for (int k = 0; k < i * 2 - 3; k++)
            cout << " ";
        cout << "*" << "\n";
    }
    for (int l = 0; l < n * 2 - 1; l++)
        cout << "*";
}