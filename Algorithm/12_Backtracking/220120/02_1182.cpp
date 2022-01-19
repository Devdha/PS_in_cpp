#include <bits/stdc++.h>
using namespace std;

int n, s, cnt;
int arr[21];

void bt(int cur, int tot) {
	if (cur == n) {
		if (tot == s) cnt++;
		return;
	}
	bt(cur + 1, tot);
	bt(cur + 1, tot + arr[cur]);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	bt(0, 0);
	if (s == 0) cnt--;
	cout << cnt;
}