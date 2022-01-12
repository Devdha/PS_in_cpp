#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > v;

void recur(int a, int b, int n) {
	if (n == 1) { 
		v.push_back({a, b});
		return;
	}
	recur(a, 6-a-b, n - 1);
	v.push_back({a, b});
	recur(6-a-b, b, n - 1);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	recur(1, 3, n);
	cout << v.size() << '\n';
	for (auto i: v)
		cout << i.first << ' ' << i.second << '\n';
}