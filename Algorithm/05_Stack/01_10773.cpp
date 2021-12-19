#include <bits/stdc++.h>
using namespace std;

int s[100001];
int sum, n, c, cnt;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	while (n--) {
		cin >> c;
		if (c == 0) {
			cnt--;
			s[cnt] = 0;
		}
		else {
			s[cnt] = c;
			cnt++;
		}
	}
	for (int i = 0; i <= cnt; i++)
		sum += s[i];
	cout << sum;
}

// int main() {
// 	ios::sync_with_stdio(0); cin.tie(0);
// 	int n, c, sum = 0, cnt = 0;
// 	cin >> n;
// 	vector<int> v;
// 	while (n--) {
// 		cin >> c;
// 		if (c == 0) {
// 			sum -= v[cnt - 1];
// 			v.pop_back();
// 			cnt--;
// 		} else {
// 			v.push_back(c);
// 			cnt++;
// 			sum += c;
// 		}
// 	}
// 	cout << sum;
// }