#include <iostream>
#include <algorithm>

using namespace std;
int input[1001];
int DP[1001];

int main()
{
	int n;
	int o = 0;
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
		int maxDP = 0;

		for (int j = 0; j < i + 1; j++)
		{
			if (input[i] > input[j])
			{
				if (maxDP < DP[j])
					maxDP = DP[j];
			}
			DP[i] = maxDP + 1;
			o = max(o, DP[i]);
		}
	}
	cout << o;
}

// int main()
// {
// 	int n;
// 	int cnt = 1;

// 	cin >> n;
// 	input[0] = 0;
// 	for (int i = 1; i <= n; i++)
// 		cin >> input[i];
// 	DP[0] = 0;
// 	DP[1] = 1;
// 	for (int i = 2; i <= n; i++)
// 	{
// 		if (input[i] > input[DP[i - 1]])
// 		{
// 			DP[i] = i;
// 			cnt++;
// 		}
// 		else if (input[i] < input[DP[i - 1]] && input[i] > input[DP[i - 2]])
// 		{
// 			DP[i] = i;
// 			DP[i - 1] = DP[i - 2];
// 		}
// 		else
// 		{
// 			DP[i] = DP[i - 1];
// 			DP[i - 1] = DP[i - 2];
// 		}
// 	}
// 	cout << cnt;
// }