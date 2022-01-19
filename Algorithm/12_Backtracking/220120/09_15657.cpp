#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[9];
int ar[9];

void bt(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << ar[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (k == 0 || arr[i] >= ar[k - 1]) {
			ar[k] = arr[i];
			bt(k + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	bt(0);
}