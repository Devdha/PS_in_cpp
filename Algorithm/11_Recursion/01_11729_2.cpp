#include <bits/stdc++.h>
using namespace std;

int cnt;

void cntRecur(int a, int b, int n) {
	if (n == 1) { 
		cnt++;
		return;
	}
	cntRecur(a, 6-a-b, n - 1);
	cnt++;
	cntRecur(6-a-b, b, n - 1);
}

void recur(int a, int b, int n) {
	if (n == 1) { 
		cout << a << ' ' << b << '\n';
		return;
	}
	recur(a, 6-a-b, n - 1);
	cout << a << ' ' << b << '\n';
	recur(6-a-b, b, n - 1);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	cntRecur(1, 3, n);
	cout << cnt << '\n';
	recur(1, 3, n);
}