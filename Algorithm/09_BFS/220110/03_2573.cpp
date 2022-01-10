#include <bits/stdc++.h>
using namespace std;
#define Y first
#define X second

int n, m, _max, year = 1;
int b[301][301];
bool vis[301][301];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void melt_BFS() {
	int near[301][301] = {0,};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[i][j] == 0) continue;
			for (int k = 0; k < 4; k++) {
				int nx = j + dx[k];
				int ny = i + dy[k];
				if (b[ny][nx] == 0) near[i][j]++;
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			b[i][j] = max(0, b[i][j] - near[i][j]);
}

int check_BFS() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cnt && vis[i][j] == 0 && b[i][j])
				return 2;
			if (vis[i][j] == 0 && b[i][j]) {
				cnt++;
				queue<pair<int, int> > q;
				q.push({i, j});
				while (!q.empty()) {
					pair<int, int> cur = q.front(); q.pop();
					for (int k = 0; k < 4; k++) {
						int ny = cur.Y + dy[k];
						int nx = cur.X + dx[k];
						if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
						if (!b[ny][nx] || vis[ny][nx]) continue;
						vis[ny][nx] = 1;
						q.push({ny, nx});
					}
				}
			}
		}
	}
	if (cnt == 1) return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
	 	for (int j = 0; j < m; j++) {
			cin >> b[i][j];
			_max = max(_max, b[i][j]);
		 }
	}
	
	while (year) {
		for (int i = 0; i < n; i++) {
			fill(vis[i], vis[i] + m, 0);
		}
		melt_BFS();
		int cnt = check_BFS();
		if (cnt == 2) {
			cout << year;
			return 0;
		} else if (cnt == 0) {
			cout << 0;
			return 0;
		}
		year++;
	}
}