#include <bits/stdc++.h>
using namespace std;
#define D first
#define A second

int n, _max;
pair<int, int> arr[9];

void bt(int k) {
	if (k == n) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (arr[i].D <= 0) cnt++;
		if (_max < cnt) _max = cnt;
		return;
	}
	if (arr[k].D <= 0) bt(k + 1);
	else {
		bool flag = 0;
		for (int i = 0; i < n; i++) {
			if (i != k && arr[i].D > 0) {
				arr[k].D = arr[k].D - arr[i].A;
				arr[i].D = arr[i].D - arr[k].A;
				flag = 1;
				bt(k + 1);
				arr[k].D = arr[k].D + arr[i].A;
				arr[i].D = arr[i].D + arr[k].A;
			}
		}
		if (flag == 0) bt(n);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int def;
		int atk;
		cin >> def >> atk;
		arr[i] = {def, atk};
	}
	bt(0);
	cout << _max;
}