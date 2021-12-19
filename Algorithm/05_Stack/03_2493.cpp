#include <bits/stdc++.h>
using namespace std;

int N, tower;
stack<pair<int, int> > s;

int main() { 
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> tower;
		while (!(s.empty())) {
			if (tower < s.top().second) {
				cout << s.top().first << " ";
				break;
			}
			s.pop();
		}
		if (s.empty()) {
			cout << 0 << " ";
		}
		s.push(make_pair(i + 1, tower));
	}
}




// int n, c, cur;
// stack<int> s;
// stack<int> t;

// int main() {
// 	ios::sync_with_stdio(0); cin.tie(0);
// 	cin >> n;
// 	vector<int> v(n);
// 	fill(v.begin(), v.begin() + n, 0);
// 	for (int i = 0; i < n; i++) {
// 		cin >> c;
// 		s.push(c);
// 	}
// 	for (int i = n; i > 0; i--) {
// 		t = s;
// 		cur = t.top();
// 		for (int j = i - 1; j > 0; j--) {
// 			t.pop();
// 			if (cur <= t.top()) {
// 				v[i - 1] = j;
// 				break;
// 			}
// 		}
// 		s.pop();
// 	}
// 	for (int i = 0; i < n; i++) 
// 		cout << v[i] << " ";
// }