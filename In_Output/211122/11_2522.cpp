#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i < n * 2; i++)
    {
        if (i <= n)
        {
            for (int j = 0; j < n - i; j++)
                cout << " ";
            for (int k = 0; k < i; k++)
                cout << "*";
        }
        else
        {
            for (int j = 0; j < i - n; j++)
                cout << " ";
            for (int k = 0; k < n - (i - n); k++)
                cout << "*";
        }
        cout << "\n";
    }
}