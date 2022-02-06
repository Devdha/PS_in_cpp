#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

vector<pair<int, int> > c;
vector<pair<int, int> > h;
int n, m, board[51][51];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) h.push_back({i, j});
			if (board[i][j] == 2) c.push_back({i, j});
		}
	}
	vector<int> brute(c.size(), 1);
	fill(brute.begin(), brute.begin() + c.size() - m, 0);
	int _min = 2501;
	do {
		int dist = 0;
		for (auto i : h) {
			int tmp = 2501;
			for (int j = 0; j < c.size(); j++) {
				if (!brute[j]) continue;
				tmp = min(tmp, abs(c[j].X - i.X) + abs(c[j].Y - i.Y));
			}
			dist += tmp;
		}
		_min = min(_min, dist);
	} while (next_permutation(brute.begin(), brute.end()));
	cout << _min;
}