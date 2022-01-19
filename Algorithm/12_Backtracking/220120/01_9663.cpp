#include <bits/stdc++.h>
using namespace std;

int cnt, n, b[15];
bool used[15], used2[30], used3[30];

void bt(int cur) {
	if (cur == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!(used[i] || used2[i + cur] || used3[i - cur + n - 1])) {
			b[cur] = i;
			used[i] = true;
			used2[i + cur] = true;
			used3[i - cur + n - 1] = true;
			bt(cur + 1);
			b[cur] = -1;
			used[i] = false;
			used2[i + cur] = false;
			used3[i - cur + n - 1] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	fill(b, b + 15, -1);
	cin >> n;
	bt(0);
	cout << cnt;
}

//int cnt, n, b[15], flag;

//void bt(int cur) {
//	if (cur == n) {
//		cnt++;
//		return;
//	}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < cur; j++) {
//			if (b[j] == i) flag = 1;
//			if (b[j] + j == i + cur || b[j] - j == i - cur) flag = 1;
//		}
//		if (!flag) {
//			b[cur] = i;
//			bt(cur + 1);
//			b[cur] = -1;
//		}
//		flag = 0;
//	}
//}

//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//	fill(b, b + 15, -1);
//	cin >> n;
//	bt(0);
//	cout << cnt;
//}