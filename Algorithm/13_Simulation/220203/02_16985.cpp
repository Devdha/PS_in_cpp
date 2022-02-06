#include <bits/stdc++.h>
using namespace std;

int b[5][5][5], cp[5][5][5], ret;
int dz[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dx[6] = {0, 0, 0, 0, 1, -1};

int bfs() {
	if (cp[0][0][0] == 0) return -1;
	int d[5][5][5];
	memset(d, -1, sizeof(d));
	queue<tuple<int, int, int> > q;
	d[0][0][0] = 0;
	q.push({0, 0, 0});

	while (!q.empty()) {
		int z = get<0>(q.front());
		int y = get<1>(q.front());
		int x = get<2>(q.front());
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nz < 0 || ny < 0 || nx < 0) continue;
			if (nz >= 5 || ny >= 5 || nx >= 5) continue;
			if (cp[nz][ny][nx] && d[nz][ny][nx] == -1) {
				d[nz][ny][nx] = d[z][y][x] + 1;
				q.push({nz, ny, nx});
			}
		}
	}
	return d[4][4][4];
}

void rotate(int k) {
	int tmp[5][5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			tmp[i][4 - j] = cp[k][j][i];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cp[k][i][j] = tmp[i][j];
}

void solve(int begin) {
	if (begin == 5) return;
	for (int i = 0; i < 4; i++) {
		if (begin == 4) {
			int check = bfs();
			if (check != -1) {
				if (ret == -1 || ret > check)
					ret = check;
			}
		}
		solve(begin + 1);
		rotate(begin);
	}
}

void shuffle() {
	vector<int> order(5);
	order = {0, 1, 2, 3, 4};
	int ans = -1;
	ret = -1;
	do {
		for (int i = 0; i < 5; i++)
			memcpy(cp[order[i]], b[i], sizeof(b[i]));
		solve(0);
		if (ret != -1) {
			if (ans == -1 || ans > ret)
				ans = ret;
		}
	} while (next_permutation(order.begin(), order.end()));
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				cin >> b[i][j][k];
	shuffle();
}