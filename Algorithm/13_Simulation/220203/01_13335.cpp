#include <bits/stdc++.h>
using namespace std;

int n, w, L;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> w >> L;
	vector<int> v;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	queue<int> q;
	int onBrid = 0, time = 0;
	for (int i = 0; i < n; i++) {
		while (1) {
			if (q.size() == w) {
				onBrid -= q.front();
				q.pop();
			}
			if (v[i] + onBrid <= L)
				break;
			q.push(0);
			time++;
		}
		q.push(v[i]);
		time++;
		onBrid += v[i];
	}
	cout << time + w;
}