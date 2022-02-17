#include <bits/stdc++.h>
using namespace std;

int n, c, ans, dp[501][501];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> c;
			if (i == 0) dp[i][j] = c;
			else if (j == 0) dp[i][j] = dp[i - 1][j] + c;
			else if (j == i) dp[i][j] = dp[i - 1][j - 1] + c;
			else dp[i][j] = max(dp[i - 1][j] + c, dp[i - 1][j - 1] + c);
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}