#include <bits/stdc++.h>
using namespace std;

stack<int> s;
vector<char> res;
vector<int> in;
int n, c, cur;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		in.push_back(i);
	for (int i = 0; i < n; i++) {
		cin >> c;
		while (cur < n && in[cur] <= c) {
			if (in[cur] != 0) {
				s.push(in[cur]);
				res.push_back('+');
			}
			cur++;
		}
		if (s.top() == c) {
			s.pop();
			res.push_back('-');
		} else {
			cout << "NO";
			return 0;
		}
	}
	for (auto i: res) cout << i << '\n';
}