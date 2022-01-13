#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

typedef unsigned long long ull;
ull n, m;

pair<int, int> recur(int side, ull walk) {
	if (side == 2) {
		switch(walk) {
			case 1:
				return {1, 1};
			case 2:
				return {1, 2};
			case 3:
				return {2, 2};
			case 4:
				return {2, 1};
		}
	}
	int h = side / 2;
	ull section = h * h;
	pair<int, int> r;
	if (walk <= section) {
		r = recur(h, walk);
		return {r.Y, r.X};
	} else if (walk <= section * 2) {
		r = recur(h, walk - section);
		return {r.X, h + r.Y};
	} else if (walk <= section * 3) {
		r = recur(h, walk - section * 2);
		return {r.X + h, r.Y + h};
	} else {
		r = recur(h, walk - section * 3);
		return {2 * h - r.Y + 1, h - r.X + 1};
	}
}

int main() {
	cin >> n >> m;
	pair<int, int> ans = recur(n, m);
	cout << ans.X << ' ' << ans.Y;
}

