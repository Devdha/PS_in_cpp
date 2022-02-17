#include <bits/stdc++.h>
using namespace std;

int dp[16], pay[16], day[16], n, ans;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> day[i] >> pay[i];
		for (int j = 0; j < i; j++)
			if (day[j] + j <= i && i + day[i] <= n + 1) {
				dp[i] = max(dp[i], dp[j] + pay[i]);
				ans = max(ans, dp[i]);
			}
	}
	//for (int i = 1; i <= n; i++)
	//	ans = max(ans, dp[i]);
	cout << ans;
}