#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> v;

bool cmp (string a, string b) {
	if (a.length() != b.length())
		return a.length() < b.length();
	return a < b;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++) {
		if (i == 0 || v[i] != v[i - 1])
			cout << v[i] << '\n';
	}
}