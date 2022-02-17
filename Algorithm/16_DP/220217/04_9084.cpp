#include <bits/stdc++.h>

using namespace std;

int	t, n, s;
int coin[25], dp[10001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		for (int j = 1; j <= n; j++)
			cin >> coin[j];
		cin >> s;
		dp[0] = 1;
		for (int j = 1; j <= n; j++)
			for (int k = coin[j]; k <= s; k++)
				dp[k] = dp[k] + dp[k - coin[j]];
		cout << dp[s] << '\n';
		memset(dp, 0, sizeof(dp));
	}
}