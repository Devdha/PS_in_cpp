#include <bits/stdc++.h>
using namespace std;

int dp[1500001], pay[1500001], day[1500001], n, ans;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> day[i] >> pay[i];
	for (int i = 1; i <= n + 1; i++) {
		ans = max(ans, dp[i]);
		if (i + day[i] > n + 1)
			continue;
		else
			dp[i + day[i]] = max(dp[i + day[i]], ans + pay[i]);
	}
	cout << ans;
}