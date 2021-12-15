#include <bits/stdc++.h>
using namespace std;

int N, K, len = 0;

int pre[5001];
int nxt[5001];
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		pre[i] = (i == 1) ? N : i - 1;
		nxt[i] = (i == N) ? 1 : i + 1;
		len++;
	}

	int i = 1;
	for (int cur = 1; len != 0; cur = nxt[cur]) {
		if (i == K) {
			pre[nxt[cur]] = pre[cur];
			nxt[pre[cur]] = nxt[cur];
			v.push_back(cur);
			i = 1;
			len--;
		} else i++;
	}

	cout << "<";
	for (size_t i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i != v.size() - 1) cout << ", ";
	}
	cout << ">";
}

// int main() {
// 	int n, k;
// 	int cnt = 0;
// 	list<int> L;
// 	cin >> n >> k;
// 	for (int i = 1; i <= n; i++)
// 		L.push_back(i);
// 	list<int>::iterator t = L.begin();
// 	cout << "<";
// 	while (cnt < n) {
// 		for (int i = k; i > 0; i--) {
// 			if (t == L.begin() && cnt == 0) i--;
// 			if (t == L.end()) t = L.begin();
// 			else t++;
// 		}
// 		cout << *t << ", ";
// 		t = L.erase(t);
// 		t--;
// 		cout << "--" << *t << "--";
// 		cnt++;
// 	}
// }