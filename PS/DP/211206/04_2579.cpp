#include <iostream>
#include <algorithm>

using namespace std;

int input[301];
int DP[301];

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> input[i];
	DP[0] = 0;
	DP[1] = input[1];
	DP[2] = max(DP[1] + input[2], input[2]);

	for (int i = 3; i <= n; i++)
	{
		DP[i] = max(DP[i - 2] + input[i], DP[i - 3] + input[i - 1] + input[i]);
	}
	cout << DP[n];
}