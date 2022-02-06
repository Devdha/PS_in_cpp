#include <bits/stdc++.h>
using namespace std;

int n, m;
int input[9];
int arr[9];
bool check[9];

void bt(int k, int pre) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	int tmp = -1;
	for (int i = pre; i < n; i++) {
		if (!check[i] && tmp != input[i]) {
			tmp = input[i];
			arr[k] = input[i];
			check[i] = true;
			bt(k+1, i+1);
			check[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> input[i];
	sort(input, input + n);
	bt(0, 0);
}