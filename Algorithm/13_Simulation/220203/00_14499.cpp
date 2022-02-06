#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, k, com;
int b[21][21];
vector<int> dice(6);
int dy[4] = {0, 0, -1, 1}, dx[4] = {1, -1, 0, 0};

void roll(int com) {
	switch (com) {
		case 0:
			dice = {dice[2], dice[1], dice[5], dice[0], dice[4], dice[3]};
			break;
		case 1:
			dice = {dice[3], dice[1], dice[0], dice[5], dice[4], dice[2]};
			break;
		case 2:
			dice = {dice[1], dice[5], dice[2], dice[3], dice[0], dice[4]};
			break;
		case 3:
			dice = {dice[4], dice[0], dice[2], dice[3], dice[5], dice[1]};
		default:
			break;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> b[i][j];
	for (int i = 0; i < k; i++) {
		cin >> com;
		int cy = dy[com - 1];
		int cx = dx[com - 1];
		if (y + cy < 0 || x + cx < 0 || y + cy >= n || x + cx >= m) continue;
		y += cy;
		x += cx;
		roll(com - 1);

		cout << dice[5] << '\n';
		if (b[y][x] == 0)
			b[y][x] = dice[0];
		else {
			dice[0] = b[y][x];
			b[y][x] = 0;
		}
	}
}

