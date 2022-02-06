#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

char b[12][6];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int is_pop() {
	int ret = 0;
	int visited[12][6] = {0,};
	vector<pair<int, int> > v;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (visited[i][j]) continue;
			else visited[i][j] = 1;
			
			if (b[i][j] == '.') continue;
			vector<pair<int, int> > vec;
			queue<pair<int, int> > q;
			vec.push_back({i, j});
			q.push({i, j});
			while (!q.empty()) {
				pair<int, int> cur = q.front(); q.pop();
				for (int k = 0; k < 4; k++) {
					int cx = cur.X + dx[k];
					int cy = cur.Y + dy[k];
					if (cx < 0 || cy < 0 || cx >= 12 || cy >= 6) continue;
					if (visited[cx][cy]) continue;
					if (b[cx][cy] != b[i][j]) continue;
					vec.push_back({cx, cy});
					q.push({cx, cy});
					visited[cx][cy] = 1;
				}
			}
			if (vec.size() >= 4) {
				for (auto k: vec)
					v.push_back(k);
				ret = 1;
			}
		}
	}
	for (auto i: v)
		b[i.X][i.Y] = '.';
	return ret;
}

void pop() {
	for (int i = 0; i < 6; i++) {
		int row_top = 11;
		for (int j = 11; j >= 0; j--) {
			if (b[j][i] == '.') continue;
			if (row_top != j) {
				b[row_top][i] = b[j][i];
				b[j][i] = '.';
			}
			row_top--;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> b[i][j];
	int ans = 0;
	while (is_pop()) {
		pop(); 
		ans++;
	}
	cout << ans;
}