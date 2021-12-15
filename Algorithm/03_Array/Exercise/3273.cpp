// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n, x;

int main()
{
	ios::sync_with_stdio(false);
	int cnt = 0, l = 0;
	int tmp, r;
	cin >> n;
	r = n - 1;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	cin >> x;
	sort(v.begin(), v.end());
	while (l < r)
	{
		int sum = v[l] + v[r];
		if (sum == x) {
			cnt++;
			l++;
			r--;
		} else if (sum > x) {
			r--;
		} else {
			l++;
		}
	}
	cout << cnt;
}