#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		list<char> L;
		list<char>::iterator t = L.begin();
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '<') {
				if (t != L.begin()) t--;
			}
			else if (str[i] == '>') {
				if (t != L.end()) t++;
			}
			else if (str[i] == '-') {
				if (t != L.begin()) {
					t--;
					t = L.erase(t);
				}
			}
			else L.insert(t, str[i]);
		}
		for (list<char>::iterator i = L.begin(); i != L.end(); i++)
			cout << *i;
		cout << "\n";
	}
}