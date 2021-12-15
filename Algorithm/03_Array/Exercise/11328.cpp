#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
string l;
string r;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> l;
		cin >> r;
		sort(l.begin(), l.end());
		sort(r.begin(), r.end());
		if (strcmp(l.c_str(), r.c_str()) == 0)
			cout << "Possible\n";
		else
			cout << "Impossible\n";
	}
}