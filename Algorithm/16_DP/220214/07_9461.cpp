#include <iostream>

using namespace std;

long long DP[101];

int main()
{
	int t, n, j;
	j = 4;
	cin >> t;
	DP[0] = 0;
	for (int i = 1; i <= 3; i++)
		DP[i] = 1;
	while (t--)
	{
		cin >> n;
		for (int i = j; i <= n; i++)
		{
			DP[i] = DP[i - 3] + DP[i - 2];
			j = i;
		}
		cout << DP[n] << "\n";
	}
}