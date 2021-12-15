// #inlcude <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	int a[26] = {0,};
	
	cin >> str;
	for (int i = 0; str[i] != '\0'; i++)
		a[str[i] - 'a']++;
	for (int i = 0; i < 26; i++)
		cout << a[i] << ' ';
}