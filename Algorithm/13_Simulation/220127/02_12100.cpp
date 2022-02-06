#include <bits/stdc++.h>
using namespace std;

int n, board[20][20];
int maxBlock;

void shift(int dir) {
	queue<int> q;
	switch(dir) {
	case 0:
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j])
					q.push(board[i][j]);
				board[i][j] = 0;
			}
			int idx = 0;
			while (!q.empty()) {
				int cur = q.front(); q.pop();
				if (board[i][idx] == 0)
					board[i][idx] = cur;
				else if (board[i][idx] == cur) {
					board[i][idx] *= 2;
					idx++;
				} else {
					idx++;
					board[i][idx] = cur;
				}
			}
		}
		break;
	case 1:
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (board[i][j])
					q.push(board[i][j]);
				board[i][j] = 0;
			}
			int idx = n - 1;
			while (!q.empty()) {
				int cur = q.front(); q.pop();
				if (board[i][idx] == 0)
					board[i][idx] = cur;
				else if (board[i][idx] == cur) {
					board[i][idx] *= 2;
					idx--;
				} else {
					idx--;
					board[i][idx] = cur;
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[j][i])
					q.push(board[j][i]);
				board[j][i] = 0;
			}
			int idx = 0;
			while (!q.empty()) {
				int cur = q.front(); q.pop();
				if (board[idx][i] == 0)
					board[idx][i] = cur;
				else if (board[idx][i] == cur) {
					board[idx][i] *= 2;
					idx++;
				} else {
					idx++;
					board[idx][i] = cur;
				}
			}
		}
		break;
	case 3:
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (board[j][i])
					q.push(board[j][i]);
				board[j][i] = 0;
			}
			int idx = n - 1;
			while (!q.empty()) {
				int cur = q.front(); q.pop();
				if (board[idx][i] == 0)
					board[idx][i] = cur;
				else if (board[idx][i] == cur) {
					board[idx][i] *= 2;
					idx--;
				} else {
					idx--;
					board[idx][i] = cur;
				}
			}
		}
		break;
	}
}

void dfs(int k) {
	if (k == 5) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				maxBlock = max(maxBlock, board[i][j]);
		return;
	}
	int tmp[20][20];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[i][j] = board[i][j];
	for (int i = 0; i < 4; i++) {
		shift(i);
		dfs(k + 1);
		for (int l = 0; l < n; l++)
			for (int j = 0; j < n; j++)
				board[l][j] = tmp[l][j];
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	dfs(0);
	cout << maxBlock;
}