#include <bits/stdc++.h>
using namespace std;

int n, c, flag, cc;
vector<tuple<int, int, int> > v;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
	if (get<1>(a) == get<1>(b))
		return get<0>(a) < get<0>(b);
	return get<1>(a) > get<1>(b);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> cc;
		flag = 0;
		for (int j = 0; j < v.size(); j++) {
			if (cc == get<2>(v[j])) {
				get<1>(v[j])++;
				flag = 1;
				break;
			}
		}
		if (!flag)
			v.push_back({v.size() + 1, 1, cc});
	}
	sort(v.begin(), v.end(), cmp);
	for (auto i: v) {
		for (int j = 0; j < get<1>(i); j++)
			cout << get<2>(i) << ' ';
	}
}