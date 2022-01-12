#include <bits/stdc++.h>
using namespace std;
int n;

void recur(int n, int x, int y) {
	if ((x / n) % 3 == 1 && (y / n) % 3 == 1)
		cout << ' ';
	else {
		if (n == 1) cout << '*';
		else recur(n / 3, x, y);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			recur(n, i, j);
		cout << '\n';
	}
}