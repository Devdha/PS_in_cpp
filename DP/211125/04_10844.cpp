#include <iostream>

using namespace std;

int main()
{
    int n;
    int DP[100][10]= {0,};
    int output = 0;

    cin >> n;
    for (int i = 0; i < 10; i++)
        DP[0][i] = i ? 1 : 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
                DP[i][j] = DP[i - 1][j + 1] % 1000000000;
            else if (j == 9)
                DP[i][j] = DP[i - 1][j - 1] % 1000000000;
            else
                DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;
        }
    }

    for (int i = 0; i < 10; i++)
        output = (output + DP[n - 1][i]) % 1000000000;
    cout << output;
}