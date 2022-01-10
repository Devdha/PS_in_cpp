// #include <bits/stdc++.h>
#include <iostream>
#include <queue>
// #include <algorithm>
using namespace std;
#define X first
#define Y second

int b[101][101];
int vis[101][101];
int dist[101][101];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, cnt;

void island_BFS() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (b[i][j] && !vis[i][j]) {
				cnt++;
				queue<pair<int, int> > q;
				q.push({i, j});
				vis[i][j] = 1;
				b[i][j] = cnt;
				while (!q.empty()) {
					pair<int, int> cur = q.front(); q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cur.X + dx[k];
						int ny = cur.Y + dy[k];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						if (!b[nx][ny] || vis[nx][ny]) continue;
						b[nx][ny] = cnt;
						vis[nx][ny] = 1;
						q.push({nx, ny});
					}
				}
			}
		}
	}
}

int bridge_BFS() {
	for (int i = 0; i < n; i++)
		fill(dist[i], dist[i] + n, -1);

	int _min = 10001;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (b[i][j] != 0) {
				queue<pair<int, int> > q;
				q.push({i, j});
				dist[i][j] = 0;
				bool escape = false;
				while (!q.empty() && !escape) {
					pair<int ,int> cur = q.front(); q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = cur.X + dx[k];
						int ny = cur.Y + dy[k];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						if (dist[nx][ny] != -1 || b[nx][ny] == b[i][j]) continue;
						if (b[nx][ny] != 0 && b[i][j] != b[nx][ny]) {
							escape = true;
							_min = min(_min, dist[cur.X][cur.Y]);
							break;
						}
						dist[nx][ny] = dist[cur.X][cur.Y] + 1;
						q.push({nx, ny});
					}
				}
				for (int k = 0; k < n; k++)
					fill(dist[k], dist[k] + n, -1);
			}
		}
	}
	return _min;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> b[i][j];
	island_BFS();
	cout << bridge_BFS();
}
