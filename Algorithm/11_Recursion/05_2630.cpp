#include <bits/stdc++.h>
using namespace std;

int	b[128][128];
int n, ans[2];

bool check(int n, int x, int y) {
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (b[x][y] != b[i][j]) return false;
	return true;
}

void recur(int n, int x, int y) {
	if (check(n, x, y)) ans[b[x][y]]++;
	else {
		int h = n / 2;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				recur(h, x + h * i, y + h * j);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >>	b[i][j];
	recur(n, 0, 0);
	for (auto i: ans) cout << i << '\n';
}