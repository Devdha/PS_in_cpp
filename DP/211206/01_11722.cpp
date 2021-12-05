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
			if (input[i] < input[j])
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