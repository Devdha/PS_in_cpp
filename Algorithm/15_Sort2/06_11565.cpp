#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> v;

int main() {
	cin >> s;
	v.resize(s.length());
	for (int i = 0; i < s.length(); i++)
		v[i] = s.substr(i, s.length());
	sort(v.begin(), v.end());
	for (int i = 0; i < s.length(); i++)
		cout << v[i] << '\n';
}