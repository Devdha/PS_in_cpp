#include <iostream>

using namespace std;

int	DP[201][201];
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++)
		{
			DP[i][j] = 0;
			for (int k = 1; k <= j; k++)
			{
				DP[i][j] += DP[i][k];
			}
		}
}