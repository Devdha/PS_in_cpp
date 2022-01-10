#include <bits/stdc++.h>
using namespace std;

int b[201][201];
int vis[32][201][201];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int kdx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int kdy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
queue<tuple<int, int, int> > q;
int k, y, x;

void BFS() {
	while (!q.empty()) {
		int ck, cx, cy;
		tie(ck, cx, cy) = q.front(); q.pop();
		if (ck < k) {
			for (int i = 0; i < 8; i++) {
				int nx = cx + kdx[i];
				int ny = cy + kdy[i];
				if (nx < 0 || ny < 0 || nx >= x || ny >= y) continue;
				if (b[nx][ny] || vis[ck + 1][nx][ny]) continue;
				vis[ck + 1][nx][ny] = vis[ck][cx][cy] + 1;
				q.push({ck + 1, nx, ny});
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= x || ny >= y) continue;
			if (b[nx][ny] || vis[ck][nx][ny]) continue;
			vis[ck][nx][ny] = vis[ck][cx][cy] + 1;
			q.push({ck, nx, ny});
		}
	}
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> k >> y >> x;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			cin >> b[i][j];
	
	q.push({0, 0, 0});
	vis[0][0][0] = 1;
	BFS();
	int min_ = 1200001;
	for (int i = 0; i < k + 1; i++) {
		if (vis[i][x - 1][y - 1])
			min_ = min(min_, vis[i][x - 1][y - 1]);
	}
	if (min_ != 1200001) cout << min_ - 1;
	else cout << -1;
}