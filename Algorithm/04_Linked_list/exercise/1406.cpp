#include <bits/stdc++.h>
using namespace std;

string str;
int n;
char com;
char sub;

int main() {
	cin >> str;
	list<char> L;
	list<char>::iterator t;
	for (int i = 0; i < str.length(); i++) L.push_back(str[i]);
	t = L.end();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> com;
		if (com == 'L' && t != L.begin()) t--;
		else if (com == 'D' && t != L.end()) t++;
		else if (com == 'B') {
			if (t != L.begin()) {
				t--;
				t = L.erase(t);
			}
		}
		else if (com == 'P') {
			cin >> sub;
			L.insert(t, sub);
		}
	}
	for (list<char>::iterator i = L.begin(); i != L.end(); i++)
		cout << *i;
}