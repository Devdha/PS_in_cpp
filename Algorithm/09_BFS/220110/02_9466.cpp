#include <bits/stdc++.h>
using namespace std;

int t, n, board[100001], vis[100001];
//queue<int> q;

//void BFS(int p) {
//	fill(vis, vis + n, 0);
//	vis[p] = 1;
//	q.push(p);
//	v.push_back(p);
//	while (!q.empty()) {
//		int c = q.front(); q.pop();
//		v.push_back(c);
//		if (board[c] == p) {
//			for (auto i: v)
//				board[i] = 0;
//		}
//		if (board[c] == 0 || vis[board[c]]) return;
//		vis[board[c]] = 1;
//		q.push(board[c]);
//	}
//}

void BFS(int p) {
	int cur = p;
	while (1) {
		vis[cur] = p;
		cur = board[cur];
		if (vis[cur] == p) {
			while (vis[cur] != -1) {
				vis[cur] = -1;
				cur = board[cur];
			}
			return;
		}
		else if (vis[cur] != 0) return;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		fill(vis, vis + n + 1, 0);
		for (int i = 1; i <= n; i++) cin >> board[i];
		for (int i = 1; i <= n; i++) {
			if (vis[i] == 0) {
				BFS(i);
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i] != -1) cnt++;
		}
		cout << cnt << '\n';
	}
}