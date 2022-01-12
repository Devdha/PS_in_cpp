#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, ans[3];
int b[2188][2188];

bool check(int n, int x, int y) {
	int start = b[x][y];
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (start != b[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void recur(int n, int x, int y) {
	if (check(n, x, y)) {
		ans[b[x][y] + 1]++;
	} else {
		int devide = n / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				recur(devide, x + devide * i, y + devide * j);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> b[i][j];
	recur(n, 0, 0);
	for (auto i: ans) cout << i << '\n';
}