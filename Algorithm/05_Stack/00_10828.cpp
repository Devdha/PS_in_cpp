#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, cnt = 0;
	string com;
	vector<int> v;
	cin >> n;
	while (n--) {
		cin >> com;
		if (!strcmp(com.c_str(), "push")) {
			int num;
			cin >> num;
			v.push_back(num);
			cnt++;
		} else if (!strcmp(com.c_str(), "top")) {
			if (v.empty()) cout << -1 << '\n';
			else cout << v[cnt - 1] << '\n';
		} else if (!strcmp(com.c_str(), "size")) { 
			cout << cnt << '\n';
		} else if (!strcmp(com.c_str(), "empty")) {
			cout << v.empty() << '\n';
		} else if (!strcmp(com.c_str(), "pop")) {
			if (v.empty()) cout << -1 << '\n';
			else {
				cout << v[cnt - 1] << '\n';
				v.pop_back();
				cnt--;
			}
		}
	}
}