#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n * 2 - 1; i++)
    {
        if (i <= n) 
        {
            for (int j = 0; j < i; j++)
                cout << "*";
            for (int k = 0; k < (n - i) * 2; k++)
                cout << " ";
            for (int l = 0; l < i; l++)
                cout << "*";
        }
        else
        {
            for (int j = 0; j < n - (i - n); j++)
                cout << "*";
            for (int k = 0; k < (i - n) * 2; k++)
                cout << " ";
            for (int l = 0; l < n - (i - n); l++)
                cout << "*";
        }
        cout << "\n";
    }
}