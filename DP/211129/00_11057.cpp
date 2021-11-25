#include <iostream>

using namespace std;

int main()
{
    int DP[1000][10] = {0,};
    int tot = 0;
    int n;

    cin >> n;
    for (int i = 0; i < 10; i++)
        DP[0][i] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = j; k < 10; k++)
                DP[i][j] = (DP[i][j] + DP[i - 1][k]) % 10007;
        }
    }
    for (int i = 0; i < 10; i++)
        tot = (tot + DP[n - 1][i]) % 10007;
    cout << tot;
}