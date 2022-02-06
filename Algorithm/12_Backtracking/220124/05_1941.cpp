#include <bits/stdc++.h>
using namespace std;

int b[5][5], answer;
bool select[25];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool moreThanFour() {
	int cnt = 0;
	for (int i = 0; i < 25; i++) {
		if (select[i] == true) {
			int x = i / 5;
			int y = i % 5;
		}
	}
}

void bt(int k, int cnt) {
	if (cnt == 7) {
		if (moreThanFour())
			if (adjacency()) answer++;
		return;
	}
	for (int i = k; i < 25; i++) {

	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> b[i][j];
	bt(0, 0);
}