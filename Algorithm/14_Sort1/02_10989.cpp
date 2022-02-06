#include <bits/stdc++.h>
using namespace std;

int num[10001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		num[c]++;
	}
	for (int i = 0; i < 10001; i++)
		for (int j = 0; j < num[i]; j++)
			cout << i << '\n';
}