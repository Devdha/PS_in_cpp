#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool used[10];

void bt(int k, int pre) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if(!used[i] && pre < i) {
			arr[k] = i;
			used[i] = 1;
			bt(k + 1, i);
			used[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	bt(0, 0);
}