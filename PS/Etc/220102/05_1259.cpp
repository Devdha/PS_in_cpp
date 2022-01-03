#include <bits/stdc++.h>
using namespace std;

string c;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> c;
    while (c[0] != '0') {
        int size = c.size();
        for (int i = 0; i <= (size - 1) / 2; i++) {
            if (c[i] != c[size - 1 - i]) { 
                cout << "no\n";
                break;
            }
            if (i == (size - 1) / 2 && c[i] == c[size - 1 - i])
                cout << "yes\n";
        }
        cin >> c;
    }
}