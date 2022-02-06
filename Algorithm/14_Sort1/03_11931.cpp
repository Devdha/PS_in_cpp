#include <bits/stdc++.h>
using namespace std;

bool num[2000001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		num[c + 1000000] = 1;
	}
	for (int i = 2000001; i >= 0; i--)
		if (num[i])
			cout << i - 1000000 << '\n';
}