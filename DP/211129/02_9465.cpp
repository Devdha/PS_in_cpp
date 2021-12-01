#include <iostream>
#include <algorithm>

using namespace std;
long long input[2][100001];
long long DP[2][100001];

int main()
{
	int tcase;
	cin >> tcase;
	int column;

	for (int i = 0; i < tcase; i++)
	{
		cin >> column;
		for (int j = 0; j < 2; j++)
		{
			for (int k = 1; k <= column; k++)
				cin >> input[j][k];
		}
		
		DP[0][0] = 0;
		DP[1][0] = 0;
		DP[0][1] = input[0][1];
		DP[1][1] = input[1][1];
		for (int j = 2; j <= column; j++)
		{
			DP[0][j] = max(DP[1][j - 2], DP[1][j - 1]) + input[0][j];
			DP[1][j] = max(DP[0][j - 2], DP[0][j - 1]) + input[1][j];
		}
		cout << max(DP[0][column], DP[1][column]) << "\n";
	}
}