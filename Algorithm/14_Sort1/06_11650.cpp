#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
vector<pair<int, int> > v;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.X == b.X)
		return (a.Y < b.Y);
	return (a.X < b.X);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].X >> v[i].Y;
	sort(v.begin(), v.end(), cmp);
	for (auto i: v)
		cout << i.X << ' ' << i.Y << '\n';
}