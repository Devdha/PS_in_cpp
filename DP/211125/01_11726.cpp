#include <iostream>

using namespace std;

int main()
{
    int DP[1001];
    int n;
    cin >> n;
    
    DP[0] = 1;
    DP[1] = 1;
    for (int i = 2; i <= n; i++)
        DP[i] = DP[i - 1] + DP[i - 2];
    cout << DP[n] % 10007;
}