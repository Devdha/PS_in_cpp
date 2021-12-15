#include <iostream>
#include <algorithm>

using namespace std;
int input[100001];
int DP[100001];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> input[i];
	
	int o = input[0];
	for (int i = 0; i < n; i++)
	{
		DP[i] = input[i];
		DP[i] = max(DP[i], DP[i] + DP[i - 1]);
		o = max(DP[i], o);
	}
	cout << o;
}