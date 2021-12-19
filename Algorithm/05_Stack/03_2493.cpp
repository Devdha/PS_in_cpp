// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>

int n, cur;
stack<int> s;
stack<int> t;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	vector<int> v(n);
	fill(v, v + n, 0);
	for (int i = 0; i < n; i++) {
		cin >> c;
		s.push(c);
	}
	for (int i = n; n > 0; n--) {
		t = s;
		cur = t.top();
		for (int j = i; i > 0; i--) {
			t.pop()
			if (cur <= t.top())
				v[i - 1] = j;
		}
	}
}