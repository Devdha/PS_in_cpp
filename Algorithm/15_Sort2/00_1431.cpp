#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> v;

bool cmp(string s1, string s2) {
	if (s1.length() != s2.length())
		return s1.length() < s2.length();
	int n1 = 0, n2 = 0;
	for (int i = 0; s1[i]; i++) {
		if (isdigit(s1[i])) n1 = n1 + s1[i] - '0';
		if (isdigit(s2[i])) n2 = n2 + s2[i] - '0';
	}
	if (n1 != n2)
		return n1 < n2;
	else return s1 < s2;
}

int main() {
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++)
		cout << v[i] << '\n';
}