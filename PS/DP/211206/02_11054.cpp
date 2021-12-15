#include <iostream>
#include <algorithm>

using namespace std;
int input[1001];
int R_DP[1001] = {0,};
int L_DP[1001] = {0,};

int main()
{
	int n;
	int o = 0;
	
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> input[i];
	for (int i = 0; i < n; i++)
	{
		int maxDP = 0;
		for (int j = 0; j < i + 1; j++)
		{
			if (input[i] > input[j])
			{
				if (maxDP < L_DP[j])
					maxDP = L_DP[j];
			}
		}
		L_DP[i] = maxDP + 1;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		int maxR_DP = 0;
		for (int j = n - 1; j >= i; j--)
		{
			if (input[i] > input[j])
			{
				if (maxR_DP < R_DP[j])
					maxR_DP = R_DP[j];
			}
		}
		R_DP[i] = maxR_DP + 1;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "\n" << L_DP[i] << "/" << R_DP[i];
		o = max(o, L_DP[i] + R_DP[i]);
	}

	cout << o - 1;
}