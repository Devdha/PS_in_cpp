#include <bits/stdc++.h>
using namespace std;

int n, m, k, r, c;
int labtop[41][41];
int stick[11][11];

bool able(int x, int y) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (labtop[x + i][y + j] && stick[i][j])
				return false;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (stick[i][j])
				labtop[x + i][y + j] = 1;
		}
	}
	return true;
}

void rotate() {
	int tmp[11][11];
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			tmp[i][j] = stick[i][j];
	for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
			stick[i][j] = tmp[r - 1 - j][i];
	swap(r, c);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	while (k--) {
		cin >> r >> c;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> stick[i][j];
		for(int rot = 0; rot < 4; rot++) {
			bool done = false;
			for (int i = 0; i <= n - r; i++) {
				if(done) break;
				for (int j = 0; j <= m - c; j++) {
					if (able(i, j)) {
						done = true;
						break;
					}
				}
			}
			if (done) break;
			rotate();
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cnt += labtop[i][j];
	cout << cnt;
}