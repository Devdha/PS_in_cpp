#include <bits/stdc++.h>
using namespace std;

int n, m, r, c, d, ans;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int b[51][51], _visit[51][51];
queue<tuple<int, int, int> > q;

void bfs() {
	q.push({r, c, d});
	while (!q.empty()) {
		tuple<int, int, int> cur = q.front(); q.pop();
		int ny = get<0>(cur), nx = get<1>(cur);
		if (!_visit[ny][nx]) ans++;
		_visit[ny][nx] = 1;
		bool flag = 0;
		for (int i = 0; i < 4; i++) {
			int cd = get<2>(cur) == 0 ? 3 : get<2>(cur) - 1;
			int cy = get<0>(cur) + dx[cd];
			int cx = get<1>(cur) + dy[cd];
			if (cy < 0 || cx < 0 || cx >= m || cy >= n) continue;
			if (!b[cy][cx] && !_visit[cy][cx]) {
				q.push({cy, cx, cd});
				flag = true;
				break;
			}
			get<2>(cur) = cd;
		}
		if (flag) continue;
		int cx = get<1>(cur) - dy[get<2>(cur)];
		int cy = get<0>(cur) - dx[get<2>(cur)];
		if (b[cy][cx]) break;
		q.push({cy, cx, get<2>(cur)});
	}
}

int main() {
	cin >> n >> m >> r >> c >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> b[i][j];
	bfs();
	cout << ans;
}