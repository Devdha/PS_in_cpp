#include <bits/stdc++.h>
using namespace std;

int n, c1, c2, c3;
string name;
vector<tuple<string, int, int, int> > v;

bool cmp(tuple<string, int, int, int> a, tuple<string, int, int, int> b) {
	if (get<1>(a) != get<1>(b))
		return get<1>(a) > get<1>(b);
	else if (get<2>(a) != get<2>(b))
		return get<2>(a) < get<2>(b);
	else if (get<3>(a) != get<3>(b))
		return get<3>(a) > get<3>(b);
	else
		return get<0>(a) < get<0>(b);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> name >> c1 >> c2 >> c3;
		v[i] = {name, c1, c2, c3};
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++)
		cout << get<0>(v[i]) << '\n';
}