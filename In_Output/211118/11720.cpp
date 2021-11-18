#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string input;
    int total;

    cin >> n;
    cin >> input;
    total = 0;
    for (int i = 0; i < n; i++)
        total += input[i] - '0';
    cout << total;
}
