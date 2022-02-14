#include <bits/stdc++.h>
using namespace std;

int n, _max = -1, idx, tmp;
vector<long long> v;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 1; i < n; i++) {
		if (v[i] == v[i - 1]) tmp++;
		else tmp = 0;
		if (_max < tmp) {
			idx = i - 1;
			_max = tmp;
		}
	}
	cout << v[idx];
}