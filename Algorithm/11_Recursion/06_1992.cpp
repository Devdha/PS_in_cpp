#include <bits/stdc++.h>
using namespace std;

string ans;
int n;
char b[64][64];

bool check(int n, int x, int y) {
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (b[i][j] != b[x][y]) return false;
	return true;
}

void recur(int n, int x, int y) {
	if (check(n, x, y)) ans += b[x][y];
	else {
		ans += '(';
		int h = n / 2;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				recur(h, x + h * i, y + h * j);
		ans += ')';
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> b[i][j];
	recur(n, 0, 0);
	cout << ans;
}