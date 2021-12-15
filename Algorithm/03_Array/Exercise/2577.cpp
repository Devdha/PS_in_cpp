// #include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int main() {
	int a, b, c, d;
	int res[10] = {0,};
	string str;
	cin >> a >> b >> c;
	d = a * b * c;
	
	str = to_string(d);
	for (int i = 0; str[i] != '\0'; i++)
		res[str[i] - '0']++;
	for (int i = 0; i < 10; i++)
		cout << res[i] << '\n';
}