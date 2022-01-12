#include <bits/stdc++.h>
using namespace std;

int n;
char star[3073][6146];

void recur(int n, int x, int y) {
	if (n == 3) {
		star[y][x] = '*';
		star[y + 1][x - 1] = '*';
		star[y + 1][x + 1] = '*';
		for (int i = 0; i < 5; i++)
			star[y + 2][x - 2 + i] = '*';
		return;
	} else {
		int h = n / 2;
		recur(h, x, y);
		recur(h, x + h, y + h);
		recur(h, x - h, y + h);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2 - 1; j++) {
			star[i][j] = ' ';
		}
	}
	recur(n, n - 1, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2 - 1; j++) {
			cout << star[i][j];
		}
		cout << '\n';
	}
}