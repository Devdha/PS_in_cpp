#include <bits/stdc++.h>
using namespace std;

vector<long> v;
int n, c;
string s;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> s;
		reverse(s.begin(), s.end());
		v[i] = atol(s.c_str());
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
		cout << v[i] << '\n';
}