#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int a, b, c;

ull recur(int a, int b, int c) {
	if (b == 0) return 1;
	if (b % 2) return (a * recur(a, b - 1, c) % c);
	ull half = recur(a, b/2, c);
	return half * half % c;
}

int main() {
	cin >> a >> b >> c;
	int d = 1;
	cout << recur(a, b, c);
}