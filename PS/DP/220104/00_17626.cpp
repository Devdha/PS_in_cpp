#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
	int	n;
	int DP[100001];
	cin >> n;
	DP[0] = 0;
	DP[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		DP[i] = i;
		for (int j = 2; j * j <= i; j++)
		{
			DP[i] = min(DP[i], DP[i - j * j] + 1);
		}
	}
	cout << DP[n];
}