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
            for (int k = 0; k < i - 1; k++)
                cout << " ";
            for (int l = 0; l < (n - i) * 2 + 1; l++)
                cout << "*";
        }
        else
        {
            for (int k = 0; k < n - (i - n) - 1; k++)
                cout << " ";
            for (int l = 0; l < (i - n) * 2 + 1; l++)
                cout << "*";
        }
        cout << "\n";
    }
}