#include <bits/stdc++.h>
using namespace std;

int n, k;
int vis[2000002];
deque<int> dq;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	dq.push_back(n);
	vis[n] = 1;
	while (!dq.empty()) {
		int c = dq.front(); dq.pop_front();
		if (c == k) break;
		if (c * 2 < 200000 && vis[c * 2] == 0) {
			dq.push_front(c * 2);
			vis[c * 2] = vis[c];
		}
		for (int i : {c - 1, c + 1}) {
			if (i < 0 || i > 200000 || vis[i] != 0) continue;
			vis[i] = vis[c] + 1;
			dq.push_back(i);
		}
	}
	cout << vis[k] - 1;
}