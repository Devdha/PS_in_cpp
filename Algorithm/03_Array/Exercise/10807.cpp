// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, x;
	int cnt = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cin >> x;
	for (int i = 0; i < n; i++)
		if (x == v[i]) cnt++;
	cout << cnt;
}