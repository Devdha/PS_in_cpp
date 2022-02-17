#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1001][1001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string a, b;
	cin >> a >> b;
	int as = a.length();
	int bs = b.length();
	for(int i = 1; i <= as; i++)
		for (int j = 1; j <= bs; j++) {
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	cout << dp[as][bs];
}