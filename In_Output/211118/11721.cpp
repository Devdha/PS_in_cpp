#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a;
    cin >> a;
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (i != 0 && i % 10 == 0)
            cout << endl;
        cout << a[i];
    }
}