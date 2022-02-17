#include <bits/stdc++.h>
using namespace std;

int n, arr[2010];
int dp[2010][2010];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1;
		if (arr[i] == arr[i - 1])
			dp[i - 1][i] = 1;
	}
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= n - i; j++) {
			int k = i + j;
			if(arr[j] == arr[k] && dp[j + 1][k - 1] == 1)
				dp[j][k] = 1;
		}
	
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		cout << dp[x][y] << '\n';
	}
}