#include <bits/stdc++.h>
using namespace std;

int n, input[13], arr[13];
bool used[13];

void bt(int k) {
	if (k == 6) {
		for (int i = 0; i < 6; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!used[i] && (k == 0 || input[i] > arr[k - 1])) {
			arr[k] = input[i];
			used[i] = true;
			bt(k+1);
			used[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	while (n != 0) {
		for (int i = 0; i < n; i++)
			cin >> input[i];
		bt(0);
		cout << '\n';
		cin >> n;
	}
}