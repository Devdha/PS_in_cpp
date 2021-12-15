#include <iostream>

using namespace std;

int main()
{
    int num, n;
    int DP[11];
    cin >> num;

    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    for (int i = 0; i < num; i++)
    {
        cin >> n;
        for (int j = 4; j <= n; j++)
            DP[j] = DP[j - 1] + DP[j - 2] + DP[j - 3];
        cout << DP[n] << "\n";
    }
}